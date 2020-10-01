Program Name: ComplexNumberCalculator
Programmer: Daniel Takyi
Files: main.cpp
Date: 2020-09-30
Compiler: clang 4.2.1


Description

This program parses a line of user console input and performs either addition, 
subtraction, multiplication, or division of two complex numbers in rectangular 
form. The first component in the line is either 'A', 'S', 'M', or 'D' which 
indicates which operation (addition, subtraction, multiplication or division) 
to perform. Lowercase characters also work. After the operation the result is 
printed out in rectangular form. The character 'Q' or 'q' quits the program. 
After inputting	the first component of the line the user inputs two sets of 
complex numbers and enters.
The program has two different modes:
	1. Interactive mode (Receives input from command line)
	   To run this mode delete any "data.txt" file from the directory, 
	   then compile and run the program at the command line like this:
  	   $ g++ -o assign1 main.cpp
	   $ ./assign1
	2. Batch mode (Receives input from an external file and write to external file)
	   To run this mode create a "data.txt" file in the directory and enter your 
	   desired inputs in it, then compile and run the program at the command line 
	   like this:
  	   $ g++ -o assign1 main.cpp
	   $ ./assign1 <data.txt> output.txt


