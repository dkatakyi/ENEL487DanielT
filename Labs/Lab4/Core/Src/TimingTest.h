/*
 * TimingTest.h
 *
 *  Created on: Oct 30, 2020
 *      Author: danieltakyi
 */

#ifndef SRC_TIMINGTEST_H_
#define SRC_TIMINGTEST_H_


#include "main.h"


uint32_t rand32();

uint64_t rand64();

uint32_t add32(uint32_t op1, uint32_t op2);

uint64_t add64(uint64_t op1, uint64_t op2);

uint64_t mult32(uint32_t op1, uint32_t op2);

uint64_t mult64(uint64_t op1, uint64_t op2);

uint32_t div32(uint32_t op1, uint32_t op2);

uint64_t div64(uint64_t op1, uint64_t op2);

#endif /* SRC_TIMINGTEST_H_ */
