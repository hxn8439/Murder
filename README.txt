README
**************
File included: main.cpp, makefile, MurderMystery.cpp, MurderMystery.h, backstory.txt, instructions.txt, README.txt cancel.png, clue.png, image.jpg, location.png, McGruff.png, play1.png, solved.jpg, Suspect.png, unsolved.jpg, Weapon.jpg
**************
This program is designed for users that are interested in solving a murder in a game. The user is shown a Welcome window with two buttons, "Play Now" and "Cancel". The "Cancel" button will exit the program, the "Play Now" button will advance the program to the next window. The next window will have the Game Rules and a "continue" button. The "continue" button will advance the program. The next window will have the Background Information and a "continue" button. The "continue" button will advance the program. The next window will have 5 clues and buttons that will allow the user to see an individual's alibi for the night of the murder. Under those buttons will be an image of the suspects and buttons to choose who the user thinks is the murder. After selecting the suspected murder, an image with different weapons will pop up with buttons to choose the suspected murder weapon. User gets 3 chances to guess the murderer and murder weapon. If the user guesses correctly a window will pop up with a congradulations and a button that will take them back to the Welcome window. If the user does not guess correctly in 3 turns, a window will pop up with a game over screen and a button that will take them back to the Welcome Window.

The user Input is completely reliant on the buttons the user presses.
	

**************
Compilation instructions:
->This is built in a Lubuntu virtual machine
->In terminal:
			make
			./murder
			
	