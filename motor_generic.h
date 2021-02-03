#ifndef MOTOR_GENERIC_H
#define MOTOR_GENERIC_H

#include "Arduino.h"

class motor_generic{
private:
	int pinA, pinB;
	int maxPWM;
public:
	motor_generic(int _pinA, int _pinB);
	// Destructor probably not needed
	void change_pins(int _pinA, int _pinB);
	void attach();

	void motor_move(int speed);				// Moves based on integer value
	void motor_forward();
	void motor_forward(unsigned int speed);
	void motor_reverse();
	void motor_reverse(unsigned int speed);
	void motor_stop();
	void motor_hold();
};

#endif
