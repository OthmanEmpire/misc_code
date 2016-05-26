# Plots the graph of Team Rank vs Points (Score) for the default assigned
# team in Folding@Home.
# Date of data: 07-01-2016

import matplotlib.pyplot as plt
import csv as csv
import string as string

class Statistics:
    """
    A container to store statistical data.
    """

    def __init__(self):
        """
        A constructor that initializes:
        Global Rank, Team Rank, Names, Points, and WU Amount fields.
        """
        self.globalRankList = []
        self.teamRankList = []
        self.nameList = []
        self.pointsList = []
        self.wuList = []

        self.statsList = [self.globalRankList,
                          self.teamRankList,
                          self.nameList,
                          self.pointsList,
                          self.wuList]


def parseStatistics(csvFileName):
    """
    Extracts Global Rank, Team Rank, Names, Points, WU Amount, from an csv file
    and stores each statistic as a separate list.
    Returns a list that contains all the statistic lists.
    """
    headerLines = 3
    statistics = Statistics()

    with open(csvFileName, newline='') as csvStatsFile:
        statsReader = csv.reader(csvStatsFile, delimiter=",")

        # Skips the header rows
        for _ in range(headerLines):
            next(statsReader)

        # Extracts the statistics (Note: the order of statsList is static and
        # must not be changed)
        for statsRow in statsReader:
            if(isValidData(statsRow)):
               for i, stat in enumerate(statistics.statsList):
                  stat.append(statsRow[i])

    return statistics

def isValidData(statsRow):
    """
    Checks whether the given row is valid
    """
    columns = 6     # Last column included as well

    # Checks if the row is of correct size
    if(len(statsRow) != columns):
        return False

    # Checks whether integer data are indeed integers
    for i, stat in enumerate(statsRow):
        try:
            # Skips verifying the name
            if(i == 2):
                continue
            int(stat)
        except Exception as e:
            return False
    return True

def plotStatistics(statistics):
    """
    Plots Team Rank against (Points, WU amount, Global rank) using matplotlib.
    """
    title = "Folding@Home"
    fileName = "Folding@Home_Statistics (07-01-2016)"


    # Plotting the data
    fig = plt.figure()
    fig.canvas.set_window_title(fileName)
    subplot = fig.add_subplot(111)

    subplot.plot(statistics.teamRankList,
                 statistics.pointsList,
                 color="r",
                 label="Points")

    subplot.set_yscale("log", basey=10)

    # Adjusting graph settings
    plt.title(title, fontweight="bold")
    plt.legend(loc='upper right', fontsize=12)
    plt.xlabel('Team Rank')
    plt.ylabel('Points')

    # Allows better visibility of the graph
    plt.ylim(0, 2*plt.ylim()[1])
    plt.xlim(-10000, plt.xlim()[1])

    plt.show()

def main():
    """
    Main point of execution (runs the program).
    """
    csvFileName = "Data.csv"
    statsList = parseStatistics(csvFileName)
    plotStatistics(statsList)

    row = ["1", "2", "3", "4", "5", "6"]
    print(isValidData(row))

if __name__ == "__main__":
    main()