/*
 * TimingTest.c
 *
 *  Created on: Oct 30, 2020
 *      Author: danieltakyi
 */


#include "TimingTest.h"

uint32_t rand32()
{
	return (rand() | (rand() << 15) | ((rand() & 0x6000) << 17));
}

uint64_t rand64()
{
	return (rand() | (rand() << 15) | (rand() << 30) | (rand() << 45) | ((rand() & 0xF000) << 49));
}

uint32_t add32(uint32_t op1, uint32_t op2)
{
	return op1 + op2;
}

uint64_t add64(uint64_t op1, uint64_t op2)
{
	return op1 + op2;
}

uint64_t mult32(uint32_t op1, uint32_t op2)
{
	return op1 * op2;
}

uint64_t mult64(uint64_t op1, uint64_t op2)
{
	return op1 * op2;
}

uint32_t div32(uint32_t op1, uint32_t op2)
{
	if(op2 == 0)
	{
		return 0xFFFFFFFF;
	}
	return op1 / op2;
}

uint64_t div64(uint64_t op1, uint64_t op2)
{
	if(op2 == 0)
	{
		return 0xFFFFFFFFFFFFFFFF;
	}
	return op1 / op2;
}

