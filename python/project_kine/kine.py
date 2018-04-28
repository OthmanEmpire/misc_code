################################################################################
# Author: Othman Alikhan                                                       #
# Year Initiated: 2012                                                         #
#                                                                              #
# An AI designed to answer a specific branch of questions on Yahoo Answers     #
# --Kinematics of constant acceleration bodies                                 #
################################################################################

# TODO: include GUI interface

# Project modules
import res

# Python Standard modules
import time as time
import sys as sys
import io as io
import unittest as unittest
import urllib.request   #TODO: Is using "as" actually good practice?
import re as re
from unittest.mock import patch as patch


# The main UI for navigation in KINE
class Terminal:

### NO CONSTRUCTOR IMPLIES?

    def printWelcome(self):
        """
        Prints the startup welcome message.
        """
        print(res.TERMINAL_MSG_PRINT_WELCOME_1)

    def promptUserForKineCode(self):
        """
        Prompts the user to enter a password to continue further on.
        """
        kineCode = input(res.TERMINAL_MSG_PROMPT_USER_FOR_KINE_CODE_1)

        return kineCode

    def verifyKineCode(self, kineCode):
        """
        Verifies whether the startup password should be as it is. Returns a
        boolean indicating so.
        """
        if(kineCode == res.TERMINAL_MSG_VERIFY_KINE_CODE_1):
            print(res.TERMINAL_MSG_VERIFY_KINE_CODE_2)

            return True

        else:
            print(res.TERMINAL_MSG_VERIFY_KINE_CODE_3)

            for i in range(3):
                print(res.TERMINAL_MSG_VERIFY_KINE_CODE_4, end='')
                time.sleep(1)
            print('\n')

            for i in range(6):
                time.sleep(0.8)
                print(res.TERMINAL_MSG_VERIFY_KINE_CODE_5)

            print(res.TERMINAL_MSG_VERIFY_KINE_CODE_6)
            time.sleep(2)

            print(res.TERMINAL_MSG_VERIFY_KINE_CODE_7)
            time.sleep(1)

            return False

    def printMainMenu(self):
        """
        Prints the main menu in the Kine Terminal, indicating the choices the
        user can make.
        """
        print(res.TERMINAL_MSG_PRINT_MAIN_MENU_1)

    def promptUserForMainMenuChoice(self):
        """
        Prompts the user to enter a choice for main menu.
        """
        choice = input(res.TERMINAL_MSG_PROMPT_USER_FOR_MAIN_MENU_CHOICE_1)

        return choice

    # TODO: Eventually add all the print menu choices
    def getProblemClass(self, choice):
        """
        Returns the print menu function for the given choice.
        """
        choiceToPrintMenuDict = {"A": InclinedPlane,
                                 "B": NotImplementedError,
                                 "C": NotImplementedError,
                                 "D": NotImplementedError,
                                 "E": NotImplementedError}

        return choiceToPrintMenuDict[choice]

    def run(self):
        """
        Runs the Kine terminal which starts the program
        """
        self.printWelcome()

        isCorrectPassword = self.verifyKineCode(self.promptUserForKineCode())
        if not isCorrectPassword:
            sys.exit()

        self.printMainMenu()

        problemChosen = self.promptUserForMainMenuChoice()
        self.getProblemClass(problemChosen)


# A type of physics problem that KINE can solve
class InclinedPlane:

    def printMenu(self):
        """
        prints the main menu which displays two choices.
        """
        print(res.INCLINEDPLANE_MSG_PRINT_MENU_1)

    def promptUserForMainMenuChoice(self):
        """
        Prompts the user to enter a choice for main menu.
        """
        choice = input(res.INCLINEDPLANE_MSG_PROMPT_USER_FOR_MAIN_MENU_CHOICE_1)

        return choice

    def getChoice(self, choice):
        """
        Returns the print menu function for the given choice.
        """
        choiceToPath = {"A": self.fetchQuestionFromInternet,
                        "B": NotImplementedError,
                        "C": NotImplementedError}

        return choiceToPath[choice]

    def fetchQuestionFromInternet(self):
        """
        Fetches a a potential inclined plane question from Yahoo Answers
        to be analyzed thereafter.
        """

        try:
            url = "http://www.yahoo.com"
            values = {"s": "basic",
                      "submit": "search"}

            data = urllib.parse.urlencode(values)
            data = data.encode("utf-8")

            req = urllib.request.Request(url, data)

            resp = urllib.request.urlopen(req)
            respData = resp.read()

            # print(respData)

            paragraphs = re.findall(r"<p(.*?)</p>", str(respData))

            for p in paragraphs:
                print(p)

        except:
            raise Exception("GG")



    # def calculateCorrelationCoefficient(self):
    #     """
    #     Calculates how closely the question resembles an inclined plane physics
    #     problem.
    #     """
    #     pass


# All the unit tests carried out on the Terminal object
class TerminalTestCase(unittest.TestCase):

    def setUp(self):
        """
        Creates a new Terminal object prior to each test run.
        """
        self.terminal = Terminal()

    @patch("sys.stdout", new=io.StringIO())
    def testPrintWelcome(self):
        """
        Checks the printed output of the printWelcome method against a literal
        string.
        """
        self.terminal.printWelcome()
        self.assertEqual(sys.stdout.getvalue().rstrip(),
                         res.TERMINAL_MSG_PRINT_WELCOME_1.rstrip())

    @patch("builtins.input", return_value="Feeding")
    def testPromptUserForMainMenuChoice(self, mockInputtedKineCode):
        """
        Checks whether inputted password is actually the returned password by
        testing it against a literal string.
        """
        self.assertEqual(self.terminal.promptUserForKineCode(), "Feeding")

    @patch("time.sleep")    # removes the sleep delay to speed up testing
    def testVerifyKineCode(self, mockSleepDelay):
        """
        Checks whether the kineCode password is indeed what it seem to be by
        testing it against two samples--one correct and the other one incorrect.
        """
        truePassword = res.TERMINAL_MSG_VERIFY_KINE_CODE_1
        trueCase = self.terminal.verifyKineCode(truePassword)
        self.assertTrue(trueCase, msg="Apparently, {} is not the password. "
                                      "The real password should be: {}"
                        .format(truePassword,
                                res.TERMINAL_MSG_VERIFY_KINE_CODE_1))

        falsePassword = "YogHurt"
        falseCase = self.terminal.verifyKineCode(falsePassword)
        self.assertFalse(falseCase, msg="Apparently, {} is the password. "
                                        "The real password should be: {}"
                         .format(falsePassword,
                                 res.TERMINAL_MSG_VERIFY_KINE_CODE_1))

    @patch("sys.stdout", new=io.StringIO())
    def testPrintMainMenu(self):
        """
        Checks the printed output of the printMainMenu method against a literal
        string.
        """
        self.terminal.printMainMenu()
        self.assertEqual(sys.stdout.getvalue().rstrip(),
                         res.TERMINAL_MSG_PRINT_MAIN_MENU_1.rstrip())

    @patch("builtins.input", return_value="GG")
    def testPromptUserForChoice(self, mockInputtedChoice):
        """
        Checks whether inputted choice for the main menu is actually the
        returned choice by testing it against a literal string.
        """
        self.assertEqual(self.terminal.promptUserForMainMenuChoice(), "GG")

    def testGetProblemClass(self):
        """
        Checks whether the getProblemClass method returns the correct class of
        problem by testing it against a valid and invalid key choice.
        """
        invalidChoice = "QQ"
        self.assertRaises(KeyError,
                          self.terminal.getProblemClass,
                          invalidChoice)

        validChoice = "A"
        self.assertEqual(InclinedPlane,
                         self.terminal.getProblemClass(validChoice))


# All the unit tests carried out on the InclinedPlane object
class InclinedPlaneTestCase(unittest.TestCase):

    def setUp(self):
        """
        Creates a new InclinedPlane object prior to each test run
        """
        self.inclinedPlane = InclinedPlane()

    @patch("sys.stdout", new=io.StringIO())
    def testPrintMenu(self):
        """
        Checks the printed output of printMenu method against a literal string.
        """
        self.inclinedPlane.printMenu()
        self.assertEqual(sys.stdout.getvalue().rstrip(),
                         res.INCLINEDPLANE_MSG_PRINT_MENU_1.rstrip())

    @patch("builtins.input", return_value="Feeding")
    def testPromptUserForMainMenuChoice(self, mockInputtedKineCode):
        """
        Checks whether inputted choice is actually the returned choice by
        testing it against a literal string.
        """
        self.assertEqual(self.inclinedPlane.promptUserForMainMenuChoice(),
                         "Feeding")

    def testGetChoice(self):
        """
        Checks whether the getChoice method returns the correct activity by
        testing it against a valid and invalid key choice.
        """
        invalidChoice = "QQ"
        self.assertRaises(KeyError,
                          self.inclinedPlane.getChoice, invalidChoice)

        validChoice = "A"
        self.assertEqual(self.inclinedPlane.fetchQuestionFromInternet,
                         self.inclinedPlane.getChoice(validChoice))


# The integration test carried out on the Terminal object
class TerminalIntegrationTest(unittest.TestCase):

    def setUp(self):
        """
        Creates a Terminal object that is used as the basis of testing
        """
        self.terminal = Terminal()

    @patch("builtins.input", return_value="Feeding")
    @patch("time.sleep")    # removes the sleep delay to speed up testing
    def testRunWithFalseKineCode(self, mockInputtedKineCode, mockSleepDelay):
        """
        Executes the run method while supplying an incorrect KineCode after the
        welcome menu. The expected outcome should be a boot from Kine.
        """
        self.assertRaises(SystemExit, self.terminal.run)


# Runs all the test cases
@patch("sys.stdout", new=io.StringIO())
def main():
    unittest.main(verbosity=0)


if __name__ == "__main__":
    InclinedPlane().fetchQuestionFromInternet()
    main()