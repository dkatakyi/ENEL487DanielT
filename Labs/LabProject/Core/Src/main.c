/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "CLI.h"
#include "TrafficLight.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart3;

/* Definitions for LightController */
osThreadId_t LightControllerHandle;
const osThreadAttr_t LightController_attributes = {
  .name = "LightController",
  .priority = (osPriority_t) osPriorityAboveNormal,
  .stack_size = 128 * 4
};
/* Definitions for RX_CLI */
osThreadId_t RX_CLIHandle;
const osThreadAttr_t RX_CLI_attributes = {
  .name = "RX_CLI",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* Definitions for Status_CLI */
osThreadId_t Status_CLIHandle;
const osThreadAttr_t Status_CLI_attributes = {
  .name = "Status_CLI",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 128 * 4
};
/* Definitions for Command_Queue */
osMessageQueueId_t Command_QueueHandle;
const osMessageQueueAttr_t Command_Queue_attributes = {
  .name = "Command_Queue"
};
/* Definitions for Message_Queue */
osMessageQueueId_t Message_QueueHandle;
const osMessageQueueAttr_t Message_Queue_attributes = {
  .name = "Message_Queue"
};
/* USER CODE BEGIN PV */
char state = 'a';

uint8_t cliBufferTX[56];
uint8_t cliBufferRX[10];
uint8_t save[40];
int j = 0;
uint8_t period_str[10];
bool update = false;

const char *CLEAR_SCREEN = "\x1b[2J";
const char *SCROLL_WINDOW = "\x1b[10;r";
const char *GO_TO_SCROLL = "\x1b[10;0H";
const char *GO_TO_TOP = "\x1b[0;0H";
const char *GO_TO_COUNT = "\x1b[0;9H";
const char *HIDE_CURS = "\x1b[?25l";
const char *SHOW_CURS = "\x1b[?25h";
const char *SAVE_CURS = "\x1b[s";
const char *RETURN_CURS = "\x1b[u";

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART3_UART_Init(void);
void StartLightController(void *argument);
void StartRX_CLI(void *argument);
void StartStatus_CLI(void *argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
  printString(CLEAR_SCREEN);
  printString(GO_TO_TOP);
  printString("Welcome to the CLI!\r\n");
  HAL_Delay(2000);

  //Formats the screen to show counter and create a scroll window
  printString(CLEAR_SCREEN);
  printString(GO_TO_TOP);
  printString("period: ");
  printString("400");
  printString("\x1b[9;0H");
  printString("Enter \"period x\" to change the period of the LED flash, where x > 0");
  printString(SCROLL_WINDOW);
  printString(GO_TO_SCROLL);

  printString("\n~>$ ");
  printString(SAVE_CURS);
  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of Command_Queue */
  Command_QueueHandle = osMessageQueueNew (1, sizeof(uint16_t), &Command_Queue_attributes);

  /* creation of Message_Queue */
  Message_QueueHandle = osMessageQueueNew (1, sizeof(uint16_t), &Message_Queue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of LightController */
  LightControllerHandle = osThreadNew(StartLightController, NULL, &LightController_attributes);

  /* creation of RX_CLI */
  RX_CLIHandle = osThreadNew(StartRX_CLI, NULL, &RX_CLI_attributes);

  /* creation of Status_CLI */
  Status_CLIHandle = osThreadNew(StartStatus_CLI, NULL, &Status_CLI_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, R1_Pin|Y1_Pin|G1_Pin|B1_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, R2_Pin|Y2_Pin|G2_Pin|B2_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : R1_Pin Y1_Pin G1_Pin B1_Pin */
  GPIO_InitStruct.Pin = R1_Pin|Y1_Pin|G1_Pin|B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : R2_Pin Y2_Pin G2_Pin B2_Pin */
  GPIO_InitStruct.Pin = R2_Pin|Y2_Pin|G2_Pin|B2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartLightController */
/**
  * @brief  Function implementing the LightController thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartLightController */
void StartLightController(void *argument)
{
  /* USER CODE BEGIN 5 */
	uint16_t cmd = 0;
	uint16_t msg = cmd;
	int period = 400;
	/* Infinite loop */
	for(;;)
	{

		if(osMessageQueueGet(Command_QueueHandle, &cmd, NULL, 0U) == osOK)
		{
			if(cmd != msg)
			{
				msg = cmd;
				if(msg == 1)
				{
					state = 'x';
				}
				else if(msg == 0)
				{
					state = 'a';
				}
			}
		}

		if(osMessageQueuePut(Message_QueueHandle, &msg, 1U, 0U)!= osOK)
		{
			Error_Handler();
		}
		period = periodState(state, period);
		state = lightState(state);



		osDelay(period);
	}
	osThreadTerminate(NULL);
  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_StartRX_CLI */
/**
* @brief Function implementing the RX_CLI thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartRX_CLI */
void StartRX_CLI(void *argument)
{
  /* USER CODE BEGIN StartRX_CLI */
	uint16_t cmd = 0;
  /* Infinite loop */
	for(;;)
	{
		if(HAL_UART_Receive(&huart3, cliBufferRX, 1, 300) == HAL_OK)
		{
			printString(RETURN_CURS);
			printString(SHOW_CURS);

			copyCharTo((char *)cliBufferRX, (char *)save, j);
			printString(SAVE_CURS);
			//backspace incidence
			if(cliBufferRX[0] == '\b')
			{
				j--;
			}
			else
			{
				j++;
			}

			//when enter is hit execute the command
			if(isCompleteLine((char *)cliBufferRX))
			{
				//				char *cmd;
				//				char *token;

				printString("\r\n");
				while(j < 20 && save[j] != '\0')
				{
					save[j] = '\0';
					j++;
				}

				if(strcmp((char *)save, "staticcycle\r") == 0)
				{
					cmd = 0;
					printString("Command read.\r");
//					if(osMessageQueuePut(Command_QueueHandle, &cmd, 1U, 0U)!= osOK)
//					{
//						Error_Handler();
//					}
				}
				else if(strcmp((char *)save, "failsafe\r") == 0)
				{
					cmd = 1;
					printString("Command read.");
//					if(osMessageQueuePut(Command_QueueHandle, &cmd, 1U, 0U)!= osOK)
//					{
//						Error_Handler();
//					}
				}
				else if(strcmp((char *)save, "help\r") == 0)
				{
					printString("Help list************");
				}
				else
				{
					printString("Error message************");
				}

				if(osMessageQueuePut(Command_QueueHandle, &cmd, 1U, 0U)!= osOK)
				{
					Error_Handler();
				}


				//				token = strtok((char *)save, " ");
				//				cmd = token;
				//				token = strtok(NULL, " ");
				//				if(strcmp(cmd, "period") == 0 && atoi(token) > 0)
				//				{
				//					period = atoi(token);
				//					update = true;
				//				}
				//				else if(save[0] != '\r')
				//				{
				//					printString("Invalid input. Try again.");
				//				}
				//				printString("\r\n");

				j = 0;
				for(int i = 0; i < 20; i++)
				{
					save[i] = '\0';
				}
				printString("\r\n~>$ ");

				printString(SAVE_CURS);
				osDelay(10);
			}
		}
	}
	osThreadTerminate(NULL);
  /* USER CODE END StartRX_CLI */
}

/* USER CODE BEGIN Header_StartStatus_CLI */
/**
* @brief Function implementing the Status_CLI thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartStatus_CLI */
void StartStatus_CLI(void *argument)
{
  /* USER CODE BEGIN StartStatus_CLI */
	uint16_t msg;
  /* Infinite loop */
	for(;;)
	{
		if(osMessageQueueGet(Message_QueueHandle, &msg, NULL, 0U ))
		{
			sprintf((char *)period_str, "%d", msg);
			printString(HIDE_CURS);
			printString(GO_TO_COUNT);
			printString("                           ");
			printString(GO_TO_COUNT);
			printString((const char *)period_str);

		}

		osDelay(5);
	}
	osThreadTerminate(NULL);
  /* USER CODE END StartStatus_CLI */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM4 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM4) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
