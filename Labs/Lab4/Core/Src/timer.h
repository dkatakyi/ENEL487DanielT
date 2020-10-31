/*
 * timer.h
 *
 *  Created on: Oct 30, 2020
 *      Author: danieltakyi
 */

#ifndef SRC_TIMER_H_
#define SRC_TIMER_H_


#include "main.h"


extern TIM_HandleTypeDef htim4;


uint16_t timer_start();

uint16_t timer_stop(uint16_t first);



#endif /* SRC_TIMER_H_ */
