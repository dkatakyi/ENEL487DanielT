/*
 * TrafficLight.h
 *
 *  Created on: Dec 5, 2020
 *      Author: danieltakyi
 */

#ifndef SRC_TRAFFICLIGHT_H_
#define SRC_TRAFFICLIGHT_H_

#include "main.h"

/**
 Function name: lightState
 Preconditions: n/a
 Postconditions: Sets and resets different GPIO pins, and changes the state
 Return type: Character
 Purpose: Sets the LEDs based on the current state and then switches to the next state
 */
char lightState(char st);

/**
 Function name: periodState
 Preconditions: 0 < x < 101
 Postconditions: n/a
 Return type: Integer
 Purpose: Set the delay period based on the current state and atm factor
 */
int periodState(char st, int x);

#endif /* SRC_TRAFFICLIGHT_H_ */
