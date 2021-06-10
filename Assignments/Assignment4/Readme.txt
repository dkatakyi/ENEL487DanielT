Program Name: CRCTest
Assignment #: 4
Student: Daniel Takyi
Files: main.cpp, crc.c, crc.h, data.txt
Date: 2020-11-11

Purpose
The objectives of this assignment are:
(1) Implement the crcSlow() and crcFast() functions in C. This 
    can be done using the code from Michael Barr. I can legally 
    include his code as a part of the project, because of the 
    header comment included in the code which states I can use 
    it. The only limitation of use that I see in the header 
    comment is that the header must not be removed nor modified.

(2) The code should test the correctness of the output of each 
    function. I did this by creating two boolean functions that 
    compare the CRC outputs to the check value. The functions 
    are called crcSlowCheck() and crcFastCheck(). These function
    also print out whether or not the result was correct.

(3) Measure the implementation's performance. For this section I
    did the CRC for a file called 'data.txt' and timed how long 
    it took for both crcSlow and crcFast(). Since I could not 
    find the copy of 'War & Peace' on URcourses, I just copied 
    the contents of the 'as4.pdf' handout given to us and pasted 
    it into the 'data.txt' file that the program is reading from.
    This objective was done on snoopy using the gcc command.

Important Commands
To link: $ gcc -c crc.c main.c
To create execution file: $ gcc -o runTest crc.o main.o
To run program: $ ./runTest


**************************************************

CRC_CCITT				|
----------------------------------------|
optimization | Slow time | Fast time	|
-O		0.000229   0.000024	|
-O2		0.000231   0.000024	|
-O3		0.000231   0.000025	|
-Os		0.000384   0.000040	|

-size main.o
   text	   data	    bss	    dec	    hex	filename
   1101	      0	      0	   1101	    44d	main.o

-size crc.o
   text	   data	    bss	    dec	    hex	filename
    572	      0	      0	    572	    23c	crc.o

**************************************************

CRC16					|
----------------------------------------|
optimization | Slow time | Fast time	|
-O		0.000392   0.000181	|
-O2		0.000392   0.000182	|
-O3		0.000392   0.000182	|
-Os		0.000392   0.000182	|

-size main.o
   text	   data	    bss	    dec	    hex	filename
   1101	      0	      0	   1101	    44d	main.o

-size crc.o
   text	   data	    bss	    dec	    hex	filename
    640	      0	      0	    640	    280	crc.o

**************************************************

CRC32					|
----------------------------------------|
optimization | Slow time | Fast time	|
-O		0.000248   0.000181	|
-O2		0.000415   0.000301	|
-O3		0.000249   0.000181	|
-Os		0.000265   0.000181	|

-size main.o
   text	   data	    bss	    dec	    hex	filename
   1115	      0	      0	   1115	    45b	main.o

-size crc.o
   text	   data	    bss	    dec	    hex	filename
    626	      0	      0	    626	    272	crc.o

**************************************************
