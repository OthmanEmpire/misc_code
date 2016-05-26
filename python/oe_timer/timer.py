################################################################################
# Author: Othman Alikhan                                                       #
# Year Initiated: 2016                                                         #
#                                                                              #
# A timer designed to help Othman manage life.                                 #
# It includes two types of timing mechanisms:                                  #
# Interval timing (e.g. every 20 min timer) and singular timing (one-time      #
# event)                                                                       #
################################################################################

import unittest as unittest
from unittest.mock import patch as patch
import io as io
import sys as sys

class Hourglass:
    """"
    The main class that functions as a timer by recording events.

    It includes two types of timing mechanisms:
    Interval timing - timer that alerts the user every X time units.
    Singularity timing - timer that alerts the user only once after X time
    units.
    """

    def __init__(self):
        """
        A simple constructor.
        """
        self.singularityTimerList = []
        self.intervalTimerList = []

    def createSingularityTimer(self, time):
        """
        Creates a SingularityTimer object and adds it to the list of
        singularity timers.
        """
        singularityTimer = SingularityTimer(time)
        self.singularityTimerList.append(singularityTimer)

    def printSingularityTimerList(self):
        """
        Prints the list of all stored Singularity Timer objects.
        """
        for singularity in self.singularityTimerList:
            print(singularity)


class HourglassTestCase(unittest.TestCase):
    """
    Carries out unit tests on the Hourglass class.
    """

    def setUp(self):
        """
        Creates a new Hourglass object prior to each test run.
        """
        self.hourglass = Hourglass()

    def testSingularTimer(self):
        """
        Tests the singularTimer method.
        """


class SingularityTimer():
    """
    A class that times a single one-time event.
    """

    def __init__(self, time):
        """
        A simple constructor.
        """
        self.time = time

    def __str__(self):
        """
        """
        return "Gg"

    def hasSingularityCollapsed(self):
        """
        """

        return

class EventTestCase(unittest.TestCase):
    """
    Carries out unit tests on the Event class.
    """

#    def setUp(self):
#        """
#        Creates a new Event object prior to each test run.
#        """
#        self.singularityTimer = SingularityTimer()

    @patch("sys.stdout", new=io.StringIO())     # Removes print statements
    def testPrint(self):
        """
        Tests the overridden print statement.
        """
        singularity = SingularityTimer("3")
        print(singularity)

#        self.assertEqual(True, False)
#        self.assertEqual(sys.stdout.getvalue().rstrip(),
#           res.TERMINAL_MSG_PRINT_WELCOME_1.rstrip())









def main():
    """
    Starts the program.
    """
    hourglass = Hourglass()

if __name__ == "__main__":
    main()
