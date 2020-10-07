Program Name: Command-Line Interface
Programmer: Daniel Takyi
Date: 2020-10-06


Description

This program is a Command-Line Interface (CLI) through which a user can communicate
with a target microcontroller board. When booted, the CLI prints the prompt "Enter a 
command for the LED:". From then the user can input a command. Entering blank lines 
merely repeat the prompt and an error message appears if the command was malformed. 
The user must is able to use the backspace key to correct typing errors.

In the current version there are four commands: 

1. "ledon" turns the green LED on and prints out "Done!" on the command line as 
   confirmation.

2. "ledoff" turns the green LED off and prints out "Done!" on the command line as 
   confirmation.

3. "ledquery" prints out the state of the green LED on the command line.

4. "help" prints out a screen of help containing the different commands that can be 
   used in the CLI.


Errors

Upon booting the start prompt is repeated.

