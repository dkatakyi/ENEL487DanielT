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
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "timer.h"
#include "TimingTest.h"
#include "time.h"


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
TIM_HandleTypeDef htim4;

/* USER CODE BEGIN PV */
int num = 0;
uint16_t volatile timStart;
uint32_t operand1, operand2;
uint64_t operand3, operand4;

struct strc8
{
	int dat[2];
};
struct strc128
{
	int dat[32];
};
struct strc1024
{
	int dat[256];
};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM4_Init(void);
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
  static struct strc8 src8, dst8;
  static struct strc128 src128, dst128;
  static struct strc1024 src1024, dst1024;

  for(int k = 0; k < 2; k++)
  {
	  dst8.dat[k] = 0;
  }
  for(int k = 0; k < 32; k++)
  {
	  dst128.dat[k] = 0;
  }
  for(int k = 0; k < 256; k++)
  {
	  dst1024.dat[k] = 0;
  }

  static double timA32 = 0;
  static double timA64 = 0;
  static double timM32 = 0;
  static double timM64 = 0;
  static double timD32 = 0;
  static double timD64 = 0;
  static double timStrc8 = 0;
  static double timStrc128 = 0;
  static double timStrc1024 = 0;

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
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */

  srand(timer_start());

  while (num < 100)
  {
	  operand1 = rand32();
	  operand2 = rand32();
	  operand3 = rand64();
	  operand4 = rand64();

	  for(int k = 0; k < 2; k++)
	  {
		  src8.dat[k] = rand();
	  }
	  for(int k = 0; k < 32; k++)
	  {
		  src128.dat[k] = rand();
	  }
	  for(int k = 0; k < 256; k++)
	  {
		  src1024.dat[k] = rand();
	  }

	  timStart = timer_start();
	  add32(operand1, operand2);
	  timA32 += (double)timer_stop(timStart);

	  timStart = timer_start();
	  add64(operand3, operand4);
	  timA64 += (double)timer_stop(timStart);

	  timStart = timer_start();
	  mult32(operand1, operand2);
	  timM32 += (double)timer_stop(timStart);

	  timStart = timer_start();
	  mult64(operand1, operand2);
	  timM64 += (double)timer_stop(timStart);

	  timStart = timer_start();
	  div32(operand1, operand2);
	  timD32 += (double)timer_stop(timStart);

	  timStart = timer_start();
	  div64(operand1, operand2);
	  timD64 += (double)timer_stop(timStart);

	  timStart = timer_start();
	  dst8 = src8;
	  timStrc8 += (double)timer_stop(timStart);

	  timStart = timer_start();
	  dst128 = src128;
	  timStrc128 += (double)timer_stop(timStart);

	  timStart = timer_start();
	  dst1024 = src1024;
	  timStrc1024 += (double)timer_stop(timStart);

	  num++;
  }

  timA32 = timA32 / 8000 / 100;					//divide by 8000 to get milliseconds, and divide by 100 to get average trial
  timA64 = timA64 / 8000 / 100;
  timM32 = timM32 / 8000 / 100;
  timM64 = timM64 / 8000 / 100;
  timD32 = timD32 / 8000 / 100;
  timD64 = timD64 / 8000 / 100;
  timStrc8 = timStrc8 / 8000 / 100;
  timStrc128 = timStrc128 / 8000 / 100;
  timStrc1024 = timStrc1024 / 8000 / 100;

  /* USER CODE END 2 */

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
  * @brief System Clock Configuration)
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
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  __HAL_RCC_TIM4_CLK_ENABLE();

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 0;
  htim4.Init.CounterMode = TIM_COUNTERMODE_DOWN;
  htim4.Init.Period = 65535;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  HAL_TIM_Base_MspInit(&htim4);
  HAL_TIM_Base_Init(&htim4);
  HAL_TIM_Base_Start(&htim4);

  /* USER CODE END TIM4_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

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
