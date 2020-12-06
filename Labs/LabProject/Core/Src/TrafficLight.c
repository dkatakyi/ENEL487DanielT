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
		HAL_GPIO_WritePin(GPIOB, R2_Pin, GPIO_PIN_SET);
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

int periodState(char st, int pd)
{

	switch(st){

	case 'a':
		pd = 600;
		break;

	case 'b':
		pd = 7050;
		break;

	case 'c':
		pd = 1350;
		break;

	case 'd':
		pd = 350;
		break;

	case 'e':
		pd = 600;
		break;

	case 'f':
		pd = 2000;
		break;

	case 'g':
		pd = 800;
		break;

	case 'h':
		pd = 350;
		break;

	case 'x':
		pd = 600;
		break;

	case 'y':
		pd = 600;

	default:

		break;
	}
}

