/**
 Course: ENEL 487
 Program Name: ComplexNumberCalculator
 Programmer: Daniel Takyi
 Date: 2020-09-26
 Description: This program parses a line of user console
 input and performs either addition, subtraction,
 multiplication, or division of two complex numbers in
 rectangular form. The result is printed out in
 rectangular form.
 
  Copyright © 2020 Daniel Takyi. All rights reserved.
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream inData;
ofstream outData;

/**
 Class name: ComplexNumbers
 Purpose: Exists to represent complex number data type
 */
class ComplexNumbers
{
public:
    float real;                 //real part of the complex number
    float imaginary;            //imaginary part of the complex number
    
    /**
     Default constructor
     */
    ComplexNumbers();
    
    /**
     Constructor
     */
    ComplexNumbers(float rl, float imgy);
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
 Function name: printResult
 Purpose: Prints a complex number
 */
void printResult(ComplexNumbers result);

int main() {

    inData.open("data.txt");
    if (inData)
    {
    outData.open("output.txt");
    }
    
    char choice = 'c';
    float oneReal, oneImgy, twoReal, twoImgy;
    
    cerr << "Type a letter to specify the arithmetic operator (A, S, M, D)";
    cerr << endl;
    cerr << "followed by two complex numbers expressed as pairs of doubles.";
    cerr << endl << "Type Q to quit." << endl;
    
    do
    {
        if (inData)
        {
            inData >> choice;
            if (choice == 'q' || choice == 'Q')
            {
                inData.close();
                outData.close();
                return 0;
            }
            inData >>  oneReal;
            inData >> oneImgy;
            inData >> twoReal;
            inData >> twoImgy;
        }
        else
        {
            cerr << "Enter exp: ";
            cin >> choice;
            if (choice == 'q' || choice == 'Q')
            {
                inData.close();
                outData.close();
                return 0;
            }
            cin >> oneReal;
            cin >> oneImgy;
            cin >> twoReal;
            cin >> twoImgy;
        }
        
        ComplexNumbers operand1(oneReal, oneImgy);
        ComplexNumbers operand2(twoReal, twoImgy);
    
        switch (choice) {
            case 'a':
            case 'A':
                add(operand1, operand2);
                break;
            case 's':
            case 'S':
                subtract(operand1, operand2);
                break;
            case 'm':
            case 'M':
                multiply(operand1, operand2);
                break;
            case 'd':
            case 'D':
                divide(operand1, operand2);
                break;
            default:
                break;
        }
    } while(choice != 'q' && choice != 'Q');
    
    inData.close();
    outData.close();
    return 0;
}

ComplexNumbers::ComplexNumbers()
{
    real = 0;
    imaginary = 0;
}

ComplexNumbers::ComplexNumbers(float rl, float imgy)
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
