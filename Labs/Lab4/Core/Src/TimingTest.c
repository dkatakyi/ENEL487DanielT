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
	uint64_t x;
	x = rand();
	x |= (rand() << 15);
	x |= (rand() << 30);
	x |= (rand() << 45);
	x |= ((rand() & 0xF000) << 49);
	return x;
	//return (rand() | (rand() << 15) | (rand() << 30) | (rand() << 45) | ((rand() & 0xF000) << 49));
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

void runTime()
{
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

	volatile struct strc8 src8, dst8;
	volatile struct strc128 src128, dst128;
	volatile struct strc1024 src1024, dst1024;

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

	volatile double timA32 = 0;
	volatile double timA64 = 0;
	volatile double timM32 = 0;
	volatile double timM64 = 0;
	volatile double timD32 = 0;
	volatile double timD64 = 0;
	volatile double timStrc8 = 0;
	volatile double timStrc128 = 0;
	volatile double timStrc1024 = 0;

	uint8_t textTX[56];

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

	  sprintf(textTX, "32 bit addition: %lfms\r\n", timA32);
	  printString((const char *)textTX);

	  sprintf(textTX, "64 bit addition: %lfms\r\n", timA64);
	  printString((const char *)textTX);

	  sprintf(textTX, "32 bit multiplication: %lfms\r\n", timM32);
	  printString((const char *)textTX);

	  sprintf(textTX, "64 bit multiplication: %lfms\r\n", timM64);
	  printString((const char *)textTX);

	  sprintf(textTX, "32 bit division: %lfms\r\n", timD32);
	  printString((const char *)textTX);

	  sprintf(textTX, "64 bit division: %lfms\r\n", timD64);
	  printString((const char *)textTX);

	  sprintf(textTX, "8-byte struct copy: %lfms\r\n", timStrc8);
	  printString((const char *)textTX);

	  sprintf(textTX, "128-byte struct copy: %lfms\r\n", timStrc128);
	  printString((const char *)textTX);

	  sprintf(textTX, "1024-byte struct copy: %lfms\r\n", timStrc1024);
	  printString((const char *)textTX);


}

