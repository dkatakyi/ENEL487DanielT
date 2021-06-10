/*
 * TrafficLight.c
 *
 *  Created on: Dec 5, 2020
 *      Author: danieltakyi
 */

#include "TrafficLight.h"


char lightState(char st)
{
	switch(st){

	case 'a':
		HAL_GPIO_WritePin(GPIOA, R1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, Y1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, G1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, B1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, R2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, Y2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, G2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, B2_Pin, GPIO_PIN_SET);
		st = 'b';
		break;

	case 'b':
		HAL_GPIO_WritePin(GPIOA, R1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, Y1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, G1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, B1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, R2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, Y2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, G2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, B2_Pin, GPIO_PIN_SET);
		st = 'c';
		break;

	case 'c':
		HAL_GPIO_WritePin(GPIOA, R1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, Y1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, G1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, B1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, R2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, Y2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, G2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, B2_Pin, GPIO_PIN_SET);
		st = 'd';
		break;

	case 'd':
		HAL_GPIO_WritePin(GPIOA, R1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, Y1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, G1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, B1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, R2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, Y2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, G2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, B2_Pin, GPIO_PIN_SET);
		st = 'e';
		break;

	case 'e':
		HAL_GPIO_WritePin(GPIOA, R1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, Y1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, G1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, B1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, R2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, Y2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, G2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, B2_Pin, GPIO_PIN_SET);
		st = 'f';
		break;

	case 'f':
		HAL_GPIO_WritePin(GPIOA, R1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, Y1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, G1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, B1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, R2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, Y2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, G2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, B2_Pin, GPIO_PIN_RESET);
		st = 'g';
		break;

	case 'g':
		HAL_GPIO_WritePin(GPIOA, R1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, Y1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, G1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, B1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, R2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, Y2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, G2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, B2_Pin, GPIO_PIN_SET);
		st = 'h';
		break;

	case 'h':
		HAL_GPIO_WritePin(GPIOA, R1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, Y1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, G1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, B1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, R2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, Y2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, G2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, B2_Pin, GPIO_PIN_SET);
		st = 'a';
		break;

	case 'x':
		HAL_GPIO_WritePin(GPIOA, R1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, Y1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, G1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, B1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, R2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, Y2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, G2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, B2_Pin, GPIO_PIN_SET);
		st = 'y';
		break;

	case 'y':
		HAL_GPIO_TogglePin(GPIOA, R1_Pin);
		HAL_GPIO_TogglePin(GPIOB, R2_Pin);

	default:
		st = 'x';
		break;
	}

	return st;
}

int periodState(char st, int x)
{
	int pd;

	switch(st){

	case 'a':
		pd = 6000;
		break;

	case 'b':
		pd = 70500;
		break;

	case 'c':
		pd = 13500;
		break;

	case 'd':
		pd = 3500;
		break;

	case 'e':
		pd = 6000;
		break;

	case 'f':
		pd = 20000;
		break;

	case 'g':
		pd = 8000;
		break;

	case 'h':
		pd = 3500;
		break;

	case 'x':
		pd = 1500;
		break;

	case 'y':
		pd = 500;

	default:

		break;
	}

	return pd / x;
}

