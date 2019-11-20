###### PONG CONSOLE APPLICATION GAME

## This is my second year object oriented programming (in c++) course project.

### THE .EXE FILE IS IN THE DEBUG FOLDER



### Requirements and Guidelines

This exercise required implementing a game combining in some way two known games: Pong and Tetris.

**Note:** the exercise is implemented in Visual Studio 2015 or later, with standard C++ libraries and run on Windows with Console screen of standard size (80*25).


This a pong game for two players.
Pong game requires the player to move a “Board” using the keyboard, in order to hit a ball and “return” it to the other player, as in a tennis game.
In our Pong game, once a player misses the ball a “copy” of his board will “drop” as in tetris game to the “lowest” position on his side of the screen (for the player on the right => board will go to the right, for the player on the left => board will go to the left) - and the new position of the board will go “up” by one, making him one step closer to losing.
In case “dropped boards” complete a full line, the entire line would disappear and the board would gain back five lines (go back five lines) - note: if there are old boards in these lines they will be deleted.
The player whose board reaches the position of “¼ of screen” as defined below - loses.


### Keys:

| 		        | Left Player   | Right Player  |
| ------------- |:-------------:| -------------:|
| UP   		    | q or Q 		| p or P 		|
| DOWN     		| a or A    	| l or L 		|


### Menu
The game have the following entry menu:

**(1)** Start a new game

**(2)** Continue a paused game

**(8)** Present instructions and keys

**(9)** EXIT

## Pausing a game
Pressing the ESC key during a game pauses the game, clears the screen* and presents the main menu with option (2) being presented!
