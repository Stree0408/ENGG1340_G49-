# Customizable Minesweeper - ENGG1340_G49
  * Welcome to the Customizable Minesweeper! This game is a text-based Minesweeper, try our game by setting your own board!
  *  3 Minute Demo Video:
https:// 

  
## Team Members:
  * Park Chanhyuk (3036086804)
  * Son Ye Ryung (3036050312)
  * Kim Minju (3035978531)
  * Jung Se Yeon (3036050518)

### How to Play
1.	Compile the program and run the executable.
2.	Set the board size 
3.	Click the cell to reveal 
4.	If

### The introduction and rule of the game
1. play new game
2. see the Leaderboard

### Rule of the game
1. Complie and run the program
2. choose from 1 and 2
3. Customize your board size
4. Play the game

<br/>

### The introduction and rules of the game
1. Choose a cell and press 'o' to start the game
2. The number on each cell represents the number of mines around the cell
3. uncover the cell if you think it does not have a mine
4. flag the cell if you think it has a mine
5. If you uncover a mine, you will lose 200 points
6. To end the game, uncover or flag all the cells

<br/>

### **Game Components**
1.	main.cpp: The `main.cpp` file contains the main game loop and logic.

2.	mechanics.h: The `mechanics.h` file contains the main logic of the game.

4.	display.h: The `display.h` file contains the display of the game.

5.	score.h: The `score.h` file 
<br/>

### **Dependencies**
* C++ Standard Library
* `<iostream>`
* `<string>`
* `<vector>`
* `<fstream>`
* `<cstdlib>`
* `<ctime>`
* `<algorithm>`
<br/>

***
## Components

### Main.cpp
> Running the game and supporting file input and output

|Name|Type|Purpose|
|:-:|:-:|:-:|
|runGame|void|runs the game minesweeper|


### mechanics.cpp
> various functions that we used to run the game

|Name|Type|Purpose|
|:-:|:-:|:-:|
|column|int|asks the user for the number of columns|
|row|int|asks the user for the number of columns|
|numberOfFlags|int|counts the number of flags left|
|numberOfMines|int|counts the number of Mines on the board|
|currentScore|int|counts the current score of the player|
|xLocation|int|expresses the xLocation of the player|
|yLocation|int|expresses the yLocation of the player|
|**mineBoard|char|Dynamically created 2-d array which represents a board filled with randomly scattered mines|
|**playerBoard|char|Dynamically created 2-d array which presents a board which reflects the player's input|
|setBoardSize|void|takes player input for row and column|
|setBoard|void|generates a board with from the player input|
|placeMines|void|randomly places the mines on the board|
|delDynamic|void|destroys the 2-d array objects which are dynamically created|
|printBoard|void|prints the board so it is visible to players|
|getPlayerInput|char|gets the player input and processes the command|
|uncover|void|uncovers the mine, or generates surrounding numbers|
|flagging|void|flags the location|
|endGame|void||
|checkEndGame|bool|Checks if all the cells are revealed, ends the game if all the cells are revealed|




### display.cpp
> various functions that we used to display the game

|Name|Type|Purpose|
|:-:|:-:|:-:|
|displayBanner|void|displays the banner minesweeper|
|mainMenu|void|displays the main menu of the game|
|displayControls|void|displays the directions to play the game|
|displayFlags|void|displays the current score and number of flags left|


### score.cpp
> This code defines a `Map` class that manages a board game map, handling player locations, mapping between different coordinate systems, and updating the game board's visual representation.

|Name|Type|Purpose|
|:-:|:-:|:-:|
|TicketResult|int|Stores the result of the ticket roll|
|input|string|Stores user input|
|malSelect|int|Stores the selected Mal index|
|tickets|vector<int>|Stores the remaining tickets|
|malVector|vector<string>|Stores the list of Mal names to be displayed|


### The Coding Requirements
>Coding requirement demonstration

|Requirenment name|Explanation|
|:-:|:-:|
|Generation of random game sets or events|The placeMines() function simulates a random distribution of mines at the rows and columns by generating a random integer.|
|Data structures for storing game status|This code initializes a Player object with a name and three Mals, represented as a custom data structure, storing their initial positions and game states in a vector called Mals. This Player Class is used in the main function to store status of each player.|
|Dynamic memory management| To make the customizable board, our group has dynamically allocated memory for the 2D array named **mineBoard|
|File input/output (e.g., for loading/saving game status)|This code appends a given filename to the "Games.txt" file, using file output operations to save game names persistently, while handling potential file opening errors.|
|Program codes in multiple files| Our group divided our code to multiple files in terms of their purposes.|
|Proper indentation and naming styles| We have done proper indentation, and named the functions so the names represent their function in the code.|
|In-code documentation| we have put explanations for codes to help the reader's understanding.|


### How to Compile and Run
> Type "make game" 
> Type "./game" to launch the game
> Type "make clean", if you want to delete saved scores of the players.
