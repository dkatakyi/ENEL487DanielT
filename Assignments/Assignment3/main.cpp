/**
 Course: ENEL 487
 Program Name: ComplexNumberCalculator Ver2
 Programmer: Daniel Takyi
 Date: 2020-10-17
 Description: This program parses a line of user console
 input and performs either addition, subtraction,
 multiplication, or division of two complex numbers in
 rectangular form. The result is printed out in
 rectangular form. Additonally in Ver2 this program can
 perform the operations "abs", "arg", "argdeg", "exp",
 and "inv".
 
 Copyright © 2020 Daniel Takyi. All rights reserved.
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>


using namespace std;


ifstream inData;
ofstream outData;
#define pi 3.141592


/**
 Class name: ComplexNumbers
 Purpose: Exists to represent complex number data type
 */
class ComplexNumbers
{
public:
    double real;                 //real part of the complex number
    double imaginary;            //imaginary part of the complex number
    
    /**
     Default constructor
     */
    ComplexNumbers();
    
    /**
     Constructor
     */
    ComplexNumbers(double rl, double imgy);
   
    /**
     Setter function
     */
    void setComplex(double rl, double imgy);
};


/**
 Function name: add
 Purpose: Adds two complex numbers together
 */
void add(ComplexNumbers a, ComplexNumbers b);

/**
 Function name: subtract
 Purpose: Subtracts a complex number from another
 */
void subtract(ComplexNumbers a, ComplexNumbers b);

/**
 Function name: multiply
 Purpose: Multiplies two complex numbers together
 */
void multiply(ComplexNumbers a, ComplexNumbers b);

/**
 Function name: divide
 Purpose: Divides a complex number by another
 */
void divide(ComplexNumbers a, ComplexNumbers b);

/**
 Function name: absolute
 Purpose: Finds the magnitude fo a complex number
 */
void absolute(ComplexNumbers a);

/**
 Function name: argument
 Purpose: Finds the angle of a complex number
 */
void argument(ComplexNumbers a, string l);

/**
 Function name: exponential
 Purpose: Finds the exponential value of a complex number
 */
void exponential(ComplexNumbers a);

/**
 Function name: inverse
 Purpose: Finds the inverse of a complex number
 */
void inverse(ComplexNumbers a);

/**
 Function name: printResult
 Purpose: Prints a complex number
 */
void printResult(ComplexNumbers result);

/**
 Function name: printResult
 Purpose: Prints a real floating point number
 */
void printResult(double result);

/**
 Function name: parseLine
 Purpose: Takes a line of user input and sorts the data
          from the line
 */
void parseLine(char co[100], double& firstRl, double& firstIy,
               double& secondRl, double& secondIy);

/**
 Function name: lowerCaseConvert
 Purpose: Helper function that converts uppercase letters
          in a string to lowercase
 */
void lowerCaseConvert(char array[100]);

int main() {
    
    inData.open("data.txt");
    if (inData)
    {
        outData.open("output.txt");
    }
    char command[100];
    double oneReal, oneImgy, twoReal, twoImgy;
    string line, saved;
    ComplexNumbers operand1(oneReal, oneImgy);
    ComplexNumbers operand2(twoReal, twoImgy);

    
    cerr << "Type a letter to specify the arithmetic operator (A, S, M, D)";
    cerr << endl;
    cerr << "followed by two complex numbers expressed as pairs of doubles.";
    cerr << endl << "Type Q to quit." << endl;


    do
    {
        if (inData)
        {
            getline(inData, line);
        }
        else
        {
            cerr << "Enter exp: ";
            getline(cin, line);
        }

        saved = line;
        if(line == "q" || line == "Q")
        {
            break;
        }
        if(line.size() != 0)
        {
            for(int i = 0; i < line.size(); i++)
            {
                command[i] = line.at(i);
            }
            for(int i = line.size(); i < 100; i++)
            {
                command[i] = NULL;
            }
            parseLine(command, oneReal, oneImgy, twoReal, twoImgy);
            line = command;
        }
        operand1.setComplex(oneReal, oneImgy);
        operand2.setComplex(twoReal, twoImgy);


        if(line == "a")
        {
            add(operand1, operand2);
        }
        else if(line == "s")
        {
            subtract(operand1, operand2);
        }
        else if(line == "m")
        {
            multiply(operand1, operand2);
        }
        else if(line == "d")
        {
            divide(operand1, operand2);
            if(operand2.real == 0 && operand2.imaginary == 0)
            {
                cerr << "Division by 0: input line was: ";
                cerr << saved << endl;
            }
        }
        else if(line == "abs")
        {
            absolute(operand1);
        }
        else if(line == "arg" || line == "argdeg")
        {
            argument(operand1, line);
        }
        else if(line == "exp")
        {
            exponential(operand1);
        }
        else if(line == "inv")
        {
            inverse(operand1);
        }
        else if(line == "q")
        {
            continue;
        }
        else
        {
            cerr << "Malformed command: input line was: ";
            cerr << saved << endl;
        }
    } while(line != "q");
    
    
    inData.close();
    outData.close();
    return 0;
}

ComplexNumbers::ComplexNumbers()
{
    real = 0;
    imaginary = 0;
}

ComplexNumbers::ComplexNumbers(double rl, double imgy)
{
    real = rl;
    imaginary = imgy;
}

void ComplexNumbers::setComplex(double rl, double imgy)
{
    real = rl;
    imaginary = imgy;
}

void add(ComplexNumbers a, ComplexNumbers b)
{
    ComplexNumbers res;
    res.real = a.real + b.real;
    res.imaginary = a.imaginary + b.imaginary;
    
    printResult(res);
}

void subtract(ComplexNumbers a, ComplexNumbers b)
{
    ComplexNumbers res;
    res.real = a.real - b.real;
    res.imaginary = a.imaginary - b.imaginary;
    
    printResult(res);
}

void multiply(ComplexNumbers a, ComplexNumbers b)
{
    ComplexNumbers res;
    res.real = a.real * b.real - a.imaginary * b.imaginary;
    res.imaginary = a.imaginary * b.real + b.imaginary * a.real;
    
    printResult(res);
}

void divide(ComplexNumbers a, ComplexNumbers b)
{
    ComplexNumbers res;
    res.real = (a.real * b.real + a.imaginary * b.imaginary)
    / (b.real * b.real + b.imaginary * b.imaginary);
    res.imaginary = (a.imaginary * b.real - a.real * b.imaginary)
    / (b.real * b.real + b.imaginary * b.imaginary);
    
    printResult(res);
}

void absolute(ComplexNumbers a)
{
    double mag;
    mag = sqrt(pow(a.real, 2) + pow(a.imaginary, 2));
    printResult(mag);
}

void argument(ComplexNumbers a, string l)
{
    double angle;
    angle = atan(a.imaginary / a.real);
    if(a.real < 0)
    {
        if(a.imaginary >= 0)
        {
            angle = angle + pi;
        }
        else
        {
            angle = angle - pi;
        }
    }
    if(l == "argdeg")
    {
        angle = angle / pi * 180;
    }
    printResult(angle);
}

void exponential(ComplexNumbers a)
{
    ComplexNumbers res;
    res.real = exp(a.real) * cos(a.imaginary);
    res.imaginary = exp(a.real) * sin(a.imaginary);
    printResult(res);
}

void inverse(ComplexNumbers a)
{
    ComplexNumbers res;
    res.real = a.real / (pow(a.real, 2) + pow(a.imaginary, 2));
    res.imaginary = -a.imaginary / (pow(a.real, 2) + pow(a.imaginary, 2));
    printResult(res);
}

void printResult(ComplexNumbers result)
{
    bool pos = true;
    if(result.imaginary < 0)
    {
        pos = false;
        result.imaginary *= -1;
    }
    
    if(inData)
    {
        if(pos == true)
        {
            outData << result.real << " + j " << result.imaginary << endl;
        }
        else
        {
            outData << result.real << " - j " << result.imaginary << endl;
        }
    }
    else
    {
        if(pos == true)
        {
            cout << result.real << " + j " << result.imaginary << endl;
        }
        else
        {
            cout << result.real << " - j " << result.imaginary << endl;
        }
    }
}

void printResult(double result)
{
    if(inData)
    {
        outData << result << endl;
    }
    else
    {
        cout << result << endl;
    }
}

void parseLine(char c[100], double& firstRl, double& firstIy,
               double& secondRl, double& secondIy)
{
    char tempOne[20], tempTwo[20], tempThree[20], tempFour[20], t[20];
    lowerCaseConvert(c);
    sscanf(c, "%s %s %s %s %s", t, tempOne, tempTwo, tempThree, tempFour);
    firstRl = strtod(tempOne, NULL);
    firstIy = strtod(tempTwo, NULL);
    secondRl = strtod(tempThree, NULL);
    secondIy = strtod(tempFour, NULL);
    strcpy(c,t);
}

void lowerCaseConvert(char array[100])
{
    for (int i = 0; array[i] != '\0'; i++)
    {
        if (array[i] >= 'A' && array[i] <= 'Z')
        {
            array[i] = array[i] + 32;
        }
    }
}

