/* ESC controller library.
 *
 *
 *							Vignesh Natarajan(Viki)
 */
#include "Arduino.h"
#include <Servo.h>

#define ESC_CALIBRATE_DELAY 10000

class esc_controller
{
	public: 
    /*  min_pw : minimum pulse width for ESC in microseconds
     *  max_pw : maximum pulse width for ESC in microseconds
     *  arm_pw : pulse width to arm esc in microseconds
     */
		esc_controller(int esc_pin, int arm_pw, int min_pw, int max_pw);
		~esc_controller(void);
		int calibrate(void);
		int arm(void);
		int disarm(void);
		int set_speed(int value);
	private:
		int Min;
		int Max;
		int Arm;
		int Port;
		bool armed;
    int speed;
		Servo motor;	
};
