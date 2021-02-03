#include "motor_generic.h"

motor_generic::motor_generic(int _pinA, int _pinB){
	pinA = _pinA;
	pinB = _pinB;
	// user has to write speed based on architecture's PWM speed.
}

// For whatever reason at runtime
void motor_generic::change_pins(int _pinA, int _pinB){
	pinA = _pinA;
	pinB = _pinB;

	pinMode(pinA, OUTPUT);
	pinMode(pinB, OUTPUT);
}

// what it says on the tin.
void motor_generic::attach(){
	pinMode(pinA, OUTPUT);
	pinMode(pinB, OUTPUT);
}

// Moves based on integer value
void motor_generic::motor_move(int speed){
	if (speed > 0){
		motor_generic::motor_forward(speed);
	} else {
		motor_generic::motor_reverse(-speed);
	}
}

// just go ahead at max speed
void motor_generic::motor_forward(){
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, LOW);
}

// Forward, max speed determined by architecture
void motor_generic::motor_forward(unsigned int speed){
	analogWrite(pinA, speed);
	digitalWrite(pinB, LOW);
}

// just reverse at max speed
void motor_generic::motor_reverse(){
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, HIGH);
}

// Reverse, max speed determined by architecture
void motor_generic::motor_reverse(unsigned int speed){
	analogWrite(pinB, speed);
	digitalWrite(pinA, LOW);
}

// No current input into the motor
void motor_generic::motor_stop(){
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, LOW);
}

// Holds the h-bridge high; maybe useful for braking?
void motor_generic::motor_hold(){
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
}