/*
 * CLI.c
 *
 *  Created on: Oct 8, 2020
 *      Author: danieltakyi
 */

#include "CLI.h"

uint8_t* welcomeMessage()
{
	//strcpy((char *)cliBufferTX, "\nWelcome to the CLI!\r\n");

	return "\nWelcome to the CLI!\r\n";
}

bool isCompleteLine(char recBuffer[10])
{
	//if enter was hit, then it is a complete line, else it isnt
	if(recBuffer[0] == '\r')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void copyCharTo(char recBuffer[10], char s[20], int coun)
{

		  if(recBuffer[0] == '\b')
		  {
			  printString("\b \b");

		  }
		  else
		  {
			  s[coun] = recBuffer[0];
			  printString(recBuffer);

		  }
}
//
void executeCommand(char recBuffer[20])
{
	  if(recBuffer[0] == 'h' && recBuffer[1] == 'e' && recBuffer[2] == 'l' && recBuffer[3] == 'p' && recBuffer[4] == '\r')
	  {
		  printString("\n1. \"ledon\" turns the green LED on\r\n");
		  printString("\n2. \"ledoff\" turns the green LED off\r\n");
		  printString("\n3. \"ledquery\" returns the state of the green LED\r\n");

	  }
	  else if(recBuffer[0] == 'l' && recBuffer[1] == 'e' && recBuffer[2] == 'd' && recBuffer[3] == 'o' && recBuffer[4] == 'n' && recBuffer[5] == '\r')
	  {
		  printString("\nDone!\r\n");
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
	  }
	  else if(recBuffer[0] == 'l' && recBuffer[1] == 'e' && recBuffer[2] == 'd' && recBuffer[3] == 'o' && recBuffer[4] == 'f' && recBuffer[5] == 'f' && recBuffer[6] == '\r')
	  {
		  printString("\nDone!\r\n");
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
	  }
	  else if(recBuffer[0] == 'l' && recBuffer[1] == 'e' && recBuffer[2] == 'd' && recBuffer[3] == 'q' && recBuffer[4] == 'u' && recBuffer[5] == 'e' && recBuffer[6] == 'r' && recBuffer[7] == 'y' && recBuffer[8] == '\r')
	  {
		  if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5) == 0x1)
		  {
			  printString("\nThe LED is on!\r\n");
		  }
		  else
		  {
			  printString("\nThe LED is off!\r\n");
		  }

	  }
	  else if(recBuffer[0] == '\r')
	  {

	  }
	  else
	  {
		  strcpy((char *)recBuffer, "\nError. Try again.\r\n");
		  HAL_UART_Transmit(&huart3, recBuffer, strlen((char *)recBuffer), 1000);
	  }
}

void printString(const char* mess)
{
	int i = 0;
	HAL_StatusTypeDef  st;

	while(huart3.gState == HAL_UART_STATE_BUSY_TX){}

	for(const char* p = mess; *p; ++p)
	{
		cliBufferTX[i] = *p;
		i++;
	}

	st = HAL_UART_Transmit(&huart3, cliBufferTX, i, 1000);
	if(st != HAL_OK)
	{
		Error_Handler();
	}

}





