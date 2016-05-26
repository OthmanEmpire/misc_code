
from subprocess import Popen

def printIndexFile():
    """
    Prints the text file (and extra headers) that contains the information
    about which save slot corresponds to which world.
    """
    fileName = "world_index_data.txt"

    with open(fileName, "r") as file:
        readData = file.read()
    print("The current worlds saved are:\n")
    print(readData)

def promptUserForWorld():
    """
    Prompts the user to choose a world. Only integer values between 1-6
    inclusive are valid
    """
    while(True):
        try:
            worldChosen = int(input("Save slot chosen: "))
            if(not (1 <= worldChosen <= 6)):
                raise TypeError
            else:
                return worldChosen
        except TypeError as e:
            print("ERROR: Invalid save slot number.")
        except ValueError as e:
            print("ERROR: Save slot must be a digit.")

def writeSaveSlot(saveSlotChosen):
    """
    Writes the given save slot to the DST server configuration file.
    """
    fileName = "C:\\Users\\Ozkh\\Documents\\Klei\\myFOODserver\\settings.ini"
    saveSlotIdentifier = "server_save_slot = "

    # Reads the settings file
    with open(fileName, "r+") as file:
        configData = file.readlines()

        # Scans the read data to find the save slot line
        for lineNum, configLine in enumerate(configData):
            if(saveSlotIdentifier in configLine):
                saveSlotLine = lineNum
                break

        # Modifies the save slot line to select the required save slot
        configData[saveSlotLine] = saveSlotIdentifier + str(saveSlotChosen)
        configData = "".join(configData)

        # Prepares the file to be overriden
        file.seek(0)
        file.truncate()
        file.write(configData)

def runServer():
    """
    Runs the .bat file that runs the servers
    """
    fileDir = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\Don't " \
              "Starve Together Dedicated Server\\bin\\scripts\\"
    fileName = "launch_food.bat"
    filePath = fileDir + fileName

    p = Popen(filePath, shell=True)
    stdout, stderr = p.communicate()

def main():
    """
    Runs the program that simplifies setting up a DST server.
    """
    printIndexFile()
    saveSlotChosen = promptUserForWorld()
    writeSaveSlot(saveSlotChosen)
    runServer()

if __name__ == "__main__":
    main()
