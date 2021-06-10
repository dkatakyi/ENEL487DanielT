Program Name: Intersection Controller (ItC)
ENEL 487 Lab Project
Programmer: Daniel Takyi
User created & edited files: main.c, CLI.h, CLI.c, TrafficLight.h, TrafficLight.c
Date: 2020-12-08


Description

This program is an embed Intersection Controller using the nucleo-64 f103rb 
microcontroller board. In this application, the user/operator can communicate with 
the target microcontroller board in order to enter different modes of the ItC and 
test its functionality. This is done using the command line. When booted, a 
welcome message is printed out on the command line and stays on the screen for a 
couple of seconds. Afterwards the CLI prints out a prompt which tells the user to
type in "help" for a list of the ItC's commands. The mode of the ItC is shown in 
the top left corner of the status window. Below the status window is a scrollable 
window, this is where the commands are typed out. If the input is malformed the 
CLI will print an error message and then print out the malformed command. Entering 
blank lines will not print out an error message, it will merely create a new line 
for input. The commands are case sensitive. The user is able to use the backspace 
key to correct typing errors. The user is also able to the command history. This application has been implemented as a real time operating system due to it's hard deadlines. This was done using CMSIS-RTOS2.


Modes

1. Failsafe mode (FSM): 4-way flashing red, at 0.5Hz with a 75% duty cycle. Upon a 
			system reset this mode is invoked.

2. Staticcycle mode (FSM): Regular traffic light cycle with fixed cycle times.


Commands

1. "help" - displays a list of valid commands.

2. "mode fsm" - switches controller to Failsafe mode.

3. "mode scm" - switches controller to Static Cycle mode.

4. "atm x" - puts microcontroller into accelerated test mode with multiplication 
	     factor x, when 0 < x < 101. This factor will speed up the ItC state 
	     transitions by that factor.

5. "clear" - this command clears the scroll screen of its command history and 
	     brings the cursor back to the top of the scroll screen.


Errors

The one issue with the current ItC is that the blue LED which is supposed to 
signify the walk warning light when it flashes, does not flash. Instead it turns off.
However it is still a unique state from the others and is still an adequate 
signification of the walk warning light in my opinion. Another newly noted issue, is 
that the commands other than "help" are only executed when there is a state change. 
They cannot be executed when the traffic light is in the middle of a state. Thinking 
back further to the last lab, Trevor told us about this issue.
