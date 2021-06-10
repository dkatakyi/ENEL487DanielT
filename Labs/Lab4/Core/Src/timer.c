/*
 * timer.c
 *
 *  Created on: Oct 30, 2020
 *      Author: danieltakyi
 */


#include "timer.h"


uint16_t timer_start()
{
	return __HAL_TIM_GET_COUNTER(&htim4);
}

uint16_t timer_stop(uint16_t first)
{
	uint16_t temp = __HAL_TIM_GET_COUNTER(&htim4);

	if(temp > first)
	{
		return (first + (0xFFFF - temp));
	}

	return (first - temp);
}

