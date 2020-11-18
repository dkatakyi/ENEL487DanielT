Program Name: Command-Line Interface Ver3
Lab #: 4
Programmer: Daniel Takyi
Date: 2020-11-18


Description

This program is a Command-Line Interface (CLI) using through which a user can 
communicate with a target microcontroller board. When booted, the CLI prints 
out a welcome message which stays on the screen for a couple seconds. 
Afterwards the CLI prints the prompt "Enter a command for the LED:" in a 
scrollable window. From then the user can input a command. Entering blank lines 
merely repeat the prompt and an error message appears if the command was 
malformed. The user must is able to use the backspace key to correct typing 
errors.

In the current version there are five commands: 

1. "ledon" turns the green LED on and prints out "Done!" on the command line as 
   confirmation.

2. "ledoff" turns the green LED off and prints out "Done!" on the command line as 
   confirmation.

3. "ledquery" prints out the state of the green LED on the command line.

4. "timetest" shows the average time it takes the processor to perform certain 
   general operations, such as addition and assignments.

5. "help" prints out a screen of help containing the different commands that can be 
   used in the CLI.


Errors

-When you repeatedly type in "timetest", after numerous entries the program will lock.
-Very rarely the "timetest" operation will give results of all 0. Once the previous 
 error came about this one hasn't been seen since.


TIMING RESULTS FOR VARIOUS OPTIMIZATIONS
None(-O0)

Variable		Time(ms)
--------------------------------------------------------
timA32		|	0.0088749999999999992	
timA64		|	0.010874999999999999	
timM32		|	0.00944125	
timM64		|	0.01194125	
timD32		|	0.010024999999999999	
timD64		|	0.023311250000000002	
timStrc8	|	0.0060662499999999996	
timStrc128	|	0.1365325	
timStrc1024	|	1.0383374999999999	

********************************************************

Optimize more (-O2)

Variable		Time(ms)
--------------------------------------------------------
timA32		|	0.0032500000000000003	
timA64		|	0.0042500000000000003	
timM32		|	0.0033750000000000004	
timM64		|	0.0056237499999999994	
timD32		|	0.0038250000000000003	
timD64		|	0.016279999999999999	
timStrc8	|	0.0024112500000000002	
timStrc128	|	0.0023749999999999999	
timStrc1024	|	0.0023749999999999999	

********************************************************

Optimize most (-O3)

timA32		|	0.0032500000000000003	
timA64		|	0.0042862500000000001	
timM32		|	0.0033750000000000004	
timM64		|	0.0056237499999999994	
timD32		|	0.0038612500000000001	
timD64		|	0.016282499999999998	
timStrc8	|	0.0023749999999999999	
timStrc128	|	0.0023749999999999999	
timStrc1024	|	0.0024112500000000002	

********************************************************

Optimize for Speed (-Ofast)

Variable		Time(ms)
--------------------------------------------------------
timA32		|	0.0032500000000000003	
timA64		|	0.0042500000000000003	
timM32		|	0.0034112500000000002	
timM64		|	0.0056612500000000005	
timD32		|	0.0038625000000000005	
timD64		|	0.016323750000000001	
timStrc8	|	0.0023750000000000004	
timStrc128	|	0.0023750000000000004	
timStrc1024	|	0.0023750000000000004	

