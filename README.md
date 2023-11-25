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
5. If you uncover a mine, you will
6. To end the game, uncover or flag all the cells

<br/>

### **Game Components**
1.	main.cpp: The `main.cpp` file contains the main game loop and logic.

2.	mechanics.h: The `board.h` file contains the main logic of the game.

4.	display.h: The `display.h` file contains the display of the game.

5.	score.h: The `score.h` file 
<br/>

### **Dependencies**
* C++ Standard Library
* `<iostream>`
* `<string>`
* `<vector>`
* `<fstream>`
<br/>

***
## Components

### Main.cpp
> Running the game and supporting file input and output

|Name|Type|Purpose|
|:-:|:-:|:-:|
|runGame|void|runs the game minesweeper|
|player1|Player|Represents the first player|
|player2|Player|Represents the second player|
|counter|int|Counts the number of turns|
|turn|int|Indicates whose turn it is (0 for player1, 1 for player2)|
|TicketResult|int|Stores the result of the ticket roll|
|input|string|Stores user input|
|tickets|vector<int>|Stores the remaining tickets|
|malVector|vector<string>|Stores the list of Mal names to be displayed|

### mechanics.cpp
> various functions that we used to run the game

|Name|Type|Purpose|
|:-:|:-:|:-:|
|save_game|void|Saves the game state to a file|
|load_game|bool|Loads the game state from a file|
|askWhichTicket|int|Asks the user which ticket they want to use|
|askMalMovement|vector<string>|Asks the user which mal they want to move|
|getTicket|int|Generates and returns a random ticket|
|getTicketName|string|Returns the name of a ticket based on the ticket number|
|move_or_carry_Mal|void|Moves or carries a mal based on the malSign string|
|killMal|void|Kills an opponent's mal based on its location|
|moveMalDisplay|void|Updates the game map after moving a mal|
|addMalDisplay|void|Adds Mal display when loading the saved game|
|PrintExplain|void|Prints out the explanation of the location|


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

|Requirenment name|Code|Explanation|
|:-:|:-:|:-:|
|Generation of random game sets or events| <img src= "https://user-images.githubusercontent.com/125568011/235907659-8400837f-6e08-4ad7-a468-c2c3dc0ca04e.png" width = "900px">|The getTicket() function simulates a random distribution of tickets with different rarity levels by generating a random integer and using conditional statements to determine the ticket type, with probabilities skewed towards more common types.|
|Data structures for storing game status|<img src= "https://user-images.githubusercontent.com/125568011/235909056-39aedd6a-aa30-4b67-84d3-e44bdbd8376a.png" width = "900px">|This code initializes a Player object with a name and three Mals, represented as a custom data structure, storing their initial positions and game states in a vector called Mals. This Player Class is used in the main function to store status of each player.|
|Dynamic memory management|<img src= "https://user-images.githubusercontent.com/125568011/235911029-5ba1024a-b11c-4a47-8085-e65ea2f1a16d.png" width = "500px">| This code reads game names from a file into a vector of strings, dynamically resizing the vector as needed to accommodate the names, and then prints the saved game names to the console.|
|File input/output (e.g., for loading/saving game status)|<img src= "https://user-images.githubusercontent.com/125568011/235911571-ff747506-4078-4a04-b062-52692ef5f630.png" width = "900px">|This code appends a given filename to the "Games.txt" file, using file output operations to save game names persistently, while handling potential file opening errors.|
|Program codes in multiple files|<img src= "https://user-images.githubusercontent.com/125568011/235912113-4183c594-286e-449d-ada9-00414f6bb9b1.png" width = "900px">| Our group have divided our code to multiple files in terms of their purposes.|
|Proper indentation and naming styles|<img src= "https://user-images.githubusercontent.com/125568011/235912686-bb9e2895-c413-4753-a56a-ff7033f4a146.png" width = "900px">| We have done proper indentation and naming styles for functions, so the names represent their function in the code.|
|In-code documentation|<img src= "https://user-images.githubusercontent.com/125568011/235913947-d72d9b1b-585f-4fe3-874c-09cb4e10e31a.png" width = "900px">| we have explained each code to help readers to understand the code.|


### How to Compile and Run
> Type "make game" in the same directory
> Type "./game" to launch the game
> Type "make clean", if you want to delete saved games.
