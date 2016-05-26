# Calculates the cumulative probability of obtaining all n items from a
# a boss after some k runs. We assume that each item has an equal chance
# of dropping. We resort to numerical estimations in doing so.

import matplotlib.pyplot as plt
import numpy as np
import string as string

class Item():
    """
    Representation of an in-game item that can be dropped.
    """

    itemsGenerated = 0

    def __init__(self, probability=0.0, isWanted=True):
        """
        Assigns an alphabet ID to the item generated and initializes.
        """
        self.id = string.ascii_lowercase[Item.itemsGenerated]
        Item.itemsGenerated += 1

        self.probability = probability
        self.isWanted = isWanted

        self.hasDroppedRecently = False     # Flag used to simplify code
        self.totalDrops = 0
        self.totalAttempts = 0

class Instance():
    """
    Representation of an in-game instance which drops items.
    """

    def __init__(self, itemsList):
        """
        Constructs the instance. Extracts the total amount of wanted items
        to be dropped. Also, extracts the probabilities for each item to be
        dropped.
        """
        self.runNum = 1
        self.totalAttempts = 0
        self.totalWantedItems = 0
        self.droppedWantedItems = 0

        self.itemsList = itemsList
        self.itemsProbabilityList = []
        for item in itemsList:
            self.itemsProbabilityList.append(item.probability)
            if(item.isWanted):
                self.totalWantedItems += 1

    def plotSimulationProbabilities(self, maxRuns, iterations=10000):
        """
        maxRuns - maximum number of boss runs

        Plots the probability and cumulative probability of successfully getting
        all items from the boss against the number of runs on a 2D graph using
        matplotlib.
        """

        title = "Items Dropped By Boss: {} ({})"\
            .format(len(self.itemsList), iterations)
        fileName = "Items {} Iterations {}"\
            .format(len(self.itemsList), iterations)

        # Initializing the y-axis tick marks
        yticksList = []
        for i in range(11):
            yticksList.append(i/10)

        # Generating the data
        runList, runsProbabilityList, runsCumulativeProbabilityList = \
            self.generateData(maxRuns, iterations)

        # Plotting the data
        fig = plt.figure()
        fig.canvas.set_window_title(fileName)
        subplot = fig.add_subplot(111)

        plt.plot(runList,
                 runsProbabilityList,
                 color="r",
                 label="Probability")
        plt.plot(runList,
                 runsCumulativeProbabilityList,
                 color="g",
                 label="Cumulative Probability")

        # Shrinking graph to allow extra information to be placed on the it's
        # right (items and their drop chances)
        box = subplot.get_position()
        subplot.set_position([box.x0, box.y0, 0.8*box.width, box.height])

        for i, item in enumerate(self.itemsList):
            plt.figtext(0.78, 0.7 - i/20,
                        "Item {}: {:<3.0f}%"
                        .format(item.id, 100*item.probability),
                        bbox=dict(facecolor="white", alpha=0.5, width=130),
                        fontweight='bold',
                        fontsize=12)

        # Adjusting graph settings
        plt.title(title, fontweight="bold")
        plt.legend(loc='upper right', fontsize=12)
        plt.ylabel('Probability')
        plt.yticks(yticksList)
        plt.ylim(plt.ylim()[0], 1.2)
        plt.xlabel('Runs')

        plt.show()

    def generateData(self, maxRuns, iterations=10000):
        """
        Executes the consecutive runs simulation, obtains data, calculates
        probabilities for each set of successful consecutive runs, then returns
        the processed data ready to be plotted.
        """

        runsDroppedDict = self.simulateConsecutiveRuns(maxRuns, iterations)

        return self.calculateSimulationProbabilities(runsDroppedDict)

    def simulateConsecutiveRuns(self, maxRuns, iterations=10000):
        """
        maxRuns     - maximum number of tries
        iterations  - number of times to repeat the consecutive runs

        Per iteration, generates a consecutive sequence of runs until the upper
        limit is reached or until all the items have dropped in the sequence.

        Returns a dictionary that contains items of form (runNumber : Number
        of times successfully obtained all wanted items)
        """

        runsDroppedDict = {i:0 for i in range(1, maxRuns+1)}

        # Generating Data:
        # The inner while-loop represents items dropping in consecutive runs up
        # to a maximum of maxRuns runs. The outer-loop is solely to repeat this
        # process multiple times for a better numerical solution.
        for _ in range(iterations):
            # Initialization per new series of runs
            self.reset()

            while(self.runNum <= maxRuns):
                self.dropItem()

                # Checks if all items have dropped yet
                if(self.haveAllItemsDropped()):
                    runsDroppedDict[self.runNum] += 1
                    break

                self.runNum += 1

        return runsDroppedDict

    def calculateSimulationProbabilities(self, runsDroppedDict):
        """
        Calculates the probabilities from the data generated by the
        simulation function. The runs, probabilities and cumulative
        probabilities are calculated.
        """

        dimension = len(runsDroppedDict)

        runsList = dimension*[0]
        runsProbabilityList = dimension*[0]
        runsCumulativeProbabilityList = dimension*[0]

        # Calculating Data:
        # The probabilities of successful runs
        print("\nProbabilities:")
        for i, (run, drops) in enumerate(runsDroppedDict.items()):
            runsList[i] = run
            runsProbabilityList[i] = drops / self.totalAttempts
            print("Runs: {:<3} {:<3} Probability: {:<3.4f}"
                  .format(run, "||", runsProbabilityList[i]))

        # The cumulative probabilities of successful runs
        runsCumulativeProbabilityList =\
            self.calculateCumulativeProbabilities(runsProbabilityList)
        print("\nCumulative Probabilities:")
        for i, _ in enumerate(runsCumulativeProbabilityList):
            print("Runs: {:<3} {:<3} Cumulative Probability: {:<3.4f}"
                  .format(runsList[i], "||", runsCumulativeProbabilityList[i]))

        # The estimated drop chance of each item
        print("\nItem Drop Chances From Simulation Data:")
        for item in self.itemsList:
            print("Item '{}' drop chance in sample: {:.4f}"
                  .format(item.id, item.totalDrops/item.totalAttempts))

        return runsList, runsProbabilityList, runsCumulativeProbabilityList

    def dropItem(self):
        """
        Selects an item to drop based on weighted probabilities and updates
        the instance correspondingly.
        """
        itemChosen = np.random.choice(self.itemsList,
                                      p=self.itemsProbabilityList)

        # Updates by checking if the item is wanted and has dropped before
        if(itemChosen.hasDroppedRecently is False):
            itemChosen.hasDroppedRecently = True
            if(itemChosen.isWanted):
                self.droppedWantedItems += 1

        # Updates by incrementing the drop variables of the item objects
        itemChosen.totalDrops += 1
        for item in self.itemsList:
            item.totalAttempts += 1

    def haveAllItemsDropped(self):
        """
        Checks whether all wanted items have dropped from the instance.
        """
        if(self.droppedWantedItems == self.totalWantedItems):
             return True
        else:
            return False

    def reset(self):
        """
        Resets the instance to allow a new set of consecutive runs.
        """
        self.totalAttempts += 1

        self.runNum = 1
        self.droppedWantedItems = 0
        for item in self.itemsList:
            item.hasDroppedRecently = False

    def calculateCumulativeProbabilities(self, probabilityList):
        """
        Calculates and returns the cumulative probabilities list when given a
        probability list.
        """
        cumulativeProbability = 0
        cumulativeProbabilityList = []

        for probability in probabilityList:
            cumulativeProbability += probability
            cumulativeProbabilityList.append(cumulativeProbability)

        return cumulativeProbabilityList

def main():
    """
    Creates items, then runs the simulation with the specified items and
    subsequently plots.
    """
    iterations = 100000
    runs = 50

    item1 = Item(4/10)
    item2 = Item(4/10)
    item3 = Item(2/10)

    item2.isWanted = False
    item3.isWanted = False
    itemsList = [item1, item2, item3]

    instance = Instance(itemsList)
    instance.plotSimulationProbabilities(runs, iterations)

if __name__ == "__main__":
    main()
