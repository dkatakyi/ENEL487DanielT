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

extern uint8_t cliBufferTX[56];
extern UART_HandleTypeDef huart3;

bool isCompleteLine(char recBuffer[10]);

void copyCharTo(char recBuffer[10], char s[20], int coun);

//void executeCommand(char recBuffer[]);

void printString(const char* mess);


#endif /* SRC_CLI_H_ */
