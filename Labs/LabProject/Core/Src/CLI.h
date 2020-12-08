/*
 * CLI.h
 *
 *  Created on: Oct 8, 2020
 *      Author: danieltakyi
 */

#ifndef SRC_CLI_H_
#define SRC_CLI_H_

#include "main.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

extern UART_HandleTypeDef huart3;

/**
 Function name: isCompleteLine
 Preconditions: n/a
 Postconditiions: n/a
 Return type: boolean
 Purpose: Checks if the user has hit the enter button
 */
bool isCompleteLine(char recBuffer[10]);

/**
 Function name: copyCharTo
 Preconditions: n/a
 Postconditiions: s[] has character appended to it and character gets transmitted
 Return type: n/a
 Purpose: Copy the received character to the saved string and print character on the terminal
 */
void copyCharTo(char recBuffer[10], char s[100], int coun);

//void executeCommand(char recBuffer[]);

/**
 Function name: printString
 Preconditions: n/a
 Postconditiions: character array transmitted
 Return type: n/a
 Purpose: Print out a message to terminal via USART transmit
 */
void printString(const char* mess);


#endif /* SRC_CLI_H_ */
