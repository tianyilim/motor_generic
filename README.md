# motor_generic

I always find myself reinventing the wheel when starting a new Arduino project with simple motor drivers. The fact is they are mostly H-bridge drivers that have the same underlying control logic. The following functions should cover it all:

- `motor_generic(int _pinA, int _pinB)` : Class constructor. Initialise pins here.

- `void change_pins(int _pinA, int _pinB)` : In the weird case where one might need to reassign control to different pins during runtime.

- `void attach()` : calls `pinMode(..., OUTPUT)`.

- `void motor_move(int speed)` : Moves motor forward if `speed` +ve, backwards if `speed` is -ve.

- `void motor_forward()` : Move motor forwards at full speed.

- `void motor_forward(unsigned int speed)` : Moves motor forwards from speed 0-255.

- `void motor_reverse()` : Move motor backwards at full speed.

- `void motor_reverse(unsigned int speed)` : Moves motor backwards from speed 0-255.

- `void motor_stop()` : Holds both control pins low, motor should stop moving.

- `void motor_hold()` : Holds both control pins high for braking.
