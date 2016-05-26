## OthmanEmpire: Miscellaneous Code Repository

This repository is mainly setup for historical reasons, namely, I would like to keep a collection of all my old code, especially when I first started programming. A short summary of the main highlights, or the lack of, is provided below:



## Python 

### *Boss Loot*
 
* **Objective:** 
   * Gain a better understanding of the probabilities associated with boss loot drops in games.

* **Features Complete:** 
   * Simulates loot dropped from boss runs based on initial probabilties given
   * Plots the probability of obtaining all possible loot against the number of boss runs
 
* **Notes:** 
   * The code was designed initially for a game I was playing called "Warframe" which involved boss runs. 
   * I've posted the results this code generates on the Warframe forums (but alas received no replies): https://forums.warframe.com/topic/587854-warframe-blueprint-drop-chances/ 

* **Progress:** 
   * 100/100


### *FAH (Folding@Home) Analysis*
 
* **Objective:** 
   * Gain a better understanding of global client contributions for a distributed computing application known as Folding@Home.

* **Features Complete:** 
   * Plots the total amount of points earned by a client against their ranking using a python implementation of matlab (matplotlib). 
 
* **Notes:** 
   * The folder contains an image of the results (a graph of points vs rank)
   * The data used to plot the results contains ~1.6 million users entries from the FAH website in 07-01-2016

* **Progress:** 
   * 100/100



## C

### *Project KINE*
 
* **Objective:** 
   * Develop an AI that learns and solves a very specific branch of psysics questions (kinematics of linear motion) on Yahoo answers. 

* **Features Complete:** 
   * An incomplete text based terminal that navigates around. 
 
* **Notes:** 
   * Perhaps my earliest real programming project.
   * This project was inspired during the time when I was answering basic science questions on Yahoo answers. 
   * The time taken to type up the answer and draw ASCII art per question took ~1hr but answering the question itself took around 5-10 minutes. 
   * There were a large amount of similar repetitive questions but phrased slightly differently.

* **Progress:** 
   * 5/100 (RETIRED)
   * I later learned that C wasn't the best language suited for this task so I switched languages to Python eventually.


### *Risk Of Rain Network Analysis*
 
* **Objective:** 
   * Assist in solving one of the wierdest network problems I encountered for a game (quite a good one might I add) called "Risk of Rain" for someone on the Risk of Rain forums.
   * Namely, the code is meant to parse a file containing port numbers (obtained through CMD) and plot port numbers against time.
   * The main idea was to figure out whether the port allocation was assigned by the game engine.

* **Features Complete:** 
   * No specific feature completed but there is some code related to reading and parsing the file, handling dynamic arrays and a simple text based terminal. 
 
* **Notes:** 
   * One of my earlier programming projects mainly created in the process of learning more about networking through helping people on the Risk of Rain forums.
   * Since the problem seemed out of my league, I posted else where to seek advice but unfortunately didn't make it that far: http://superuser.com/questions/752242/game-clients-listening-server-unable-to-establish-a-successful-tcp-connection

* **Progress:** 
   * 30/100 (RETIRED)
   * In the end, I didn't need to plot the data strictly but I just needed to roughly understand the range of port numbers the data file swept across, so the project was abandoned. 
