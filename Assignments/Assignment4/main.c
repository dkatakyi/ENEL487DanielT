/**********************************************************************
 *
 * Filename:    main.c
 * 
 * Description: A simple test program for the CRC implementations.
 *
 * Notes:       To test a different CRC standard, modify crc.h.
 *
 * 
 * Copyright (c) 2000 by Michael Barr.  This software is placed into
 * the public domain and may be used for any purpose.  However, this
 * notice must not be changed or removed and no warranty is either
 * expressed or implied by its publication or distribution.
 **********************************************************************/

/****************************************************************
 * File modified by Daniel Takyi
 * Modification Date: November 11, 2020
 * Assignment #: 4
 ***************************************************************/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "crc.h"

/***************************************************************
 * Function: crcSlowCheck()
 * Description: Check the correctness of the crcSlow() function
 * Notes: Prints out if the result is correct or not
 * Returns: True if the CRC is as expected and false if not
 **************************************************************/
bool crcSlowCheck(char msg[], int N)
{
    if(crcSlow((const unsigned char *)msg, N) == CHECK_VALUE)
    {
        printf("%s\n", "The crcSlow() result is correct.");
        return true;
    }
    printf("%s\n", "The crcSlow() result is incorrect.");
    return false;
}

/***************************************************************
 * Function: crcFastCheck()
 * Description: Check the correctness of the crcFast() function
 * Notes: Prints out if the result is correct or not
 * Returns: True if the CRC is as expected and false if not
 **************************************************************/
bool crcFastCheck(char msg[], int N)
{
    if(crcFast((const unsigned char *)msg, N) == CHECK_VALUE)
    {
        printf("%s\n", "The crcFast() result is correct.");
        return true;
    }
    printf("%s\n", "The crcFast() result is incorrect.");
    return false;
}


int main(void)
{
	unsigned char  test[] = "123456789";
    FILE *fileP;
    double slwTime, fstTime, tmpTime1, tmpTime2;
    crcInit();
    
    //ASSUMES THE WAR & PEACE FILE NAME IS "data.txt"
    fileP = fopen("data.txt","r");
    feof(fileP);
    fseek(fileP, 0, SEEK_END);
    long lengthF = ftell(fileP);
    char *tmp = (char *)malloc(sizeof(char)*lengthF);
    fseek(fileP, 0, SEEK_SET);
    fread(tmp, lengthF, sizeof(char), fileP);
    fclose(fileP);

    tmpTime1 = (double)clock() / CLOCKS_PER_SEC;
    crcSlow((const unsigned char *)tmp, (int)strlen(tmp));
    tmpTime2 = (double)clock() / CLOCKS_PER_SEC;
    slwTime = tmpTime2 - tmpTime1;

    tmpTime1 = (double)clock() / CLOCKS_PER_SEC;
    crcFast((const unsigned char *)tmp, (int)strlen(tmp));
    tmpTime2 = (double)clock() / CLOCKS_PER_SEC;
    fstTime = tmpTime2 - tmpTime1;
    
    printf("The speed of the crcSlow() for the file data.txt is %f\n", slwTime);
    printf("The speed of the crcFast() for the file data.txt is %f\n", fstTime);
    
    crcInit();
    
//    /*
//     * Print the check value for the selected CRC algorithm.
//     */
//    printf("The check value for the %s standard is 0x%X\n", CRC_NAME, CHECK_VALUE);
//
//    /*
//     * Compute the CRC of the test message, slowly.
//     */
//    printf("The crcSlow() of \"123456789\" is 0x%X\n", crcSlow(test, (int)strlen((const char *)test)));
//
//    /*
//     * Compute the CRC of the test message, more efficiently.
//     */
//    crcInit();
//    printf("The crcFast() of \"123456789\" is 0x%X\n", crcFast(test, (int)strlen((const char *)test)));
    
    crcFastCheck((char *)test, (int)strlen((const char *)test));
    crcSlowCheck((char *)test, (int)strlen((const char *)test));
    
}   /* main() */
