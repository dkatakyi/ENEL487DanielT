Program Name: ComplexNumberCalculator Ver2
Programmer: Daniel Takyi
Files: main.cpp, Makefile
Date: 2020-10-20
Compiler: clang 4.2.1


Description

This program parses a line of user console input and performs either addition, 
subtraction, multiplication, or division of two complex numbers in rectangular 
form. The first component in the line is either 'A', 'S', 'M', or 'D' which 
indicates which operation (addition, subtraction, multiplication or division) 
to perform. Lowercase characters also work. After the operation the result is 
printed out in rectangular form. The character 'Q' or 'q' quits the program. 
After inputting	the first component of the line the user inputs two sets of 
complex numbers and enters. Additionally in Ver2, this program now has the 
functionality to find the magnitude, angle in radians, angle in degrees, 
exponential value and inverse of a complex number. The user can type the 
commands "abs", "arg", "argdeg", "exp", and "inv" before entering a complex 
number to use the aforementioned functions, respectively.

The program has two different modes:

	1. Interactive mode (Receives input from command line)
	   To run this mode delete any "data.txt" file from the directory, 
	   then compile and run the program at the command line like this:
  	   $ g++ -o assign3 main.cpp
	   $ ./assign3

	   Alternatively, you can use the command "make clean", to prepare 
	   the space for the program run, and then "make assign3" to compile 
	   the code. The standard method for compilation and running is:
	   $ make clean
	   $ make assign3
	   $ ./assign3
	   
	2. Batch mode (Receives input from an external file and write to external file)
	   To run this mode create a "data.txt" file in the directory and enter your 
	   desired inputs in it, then compile and run the program at the command line 
	   like this:
  	   $ g++ -o assign3 main.cpp
	   $ ./assign3 <data.txt> output.txt

	   Alternatively, after adding creating "data.txt" and filling in the inputs, 
	   you can use the command "make assign3", to compile the code, and then "make 
	   assign2" to compile the code. The standard method for compilation and 
	   running is:
	   $ make clean
	   $ make assign3
	   $ ./assign3 <data.txt> output.txt
