/* ESC controller library.
 *
 *
 *							Vignesh Natarajan(Viki)
 */
#include "esc_controller.hpp"

/*  min_pw : minimum pulse width for ESC in microseconds
 *  max_pw : maximum pulse width for ESC in microseconds
 *  arm_pw : pulse width to arm ESC in microseconds
 */
esc_controller::esc_controller
	(int esc_pin, int arm_value, int min_output, int max_output)
{
	this->Min = min_output;
	this->Max = max_output;
	this->Arm = arm_value;
	this->Port = esc_pin;	
	this->armed = false;	
}


esc_controller::~esc_controller(void)
{
	this->disarm();
}

int esc_controller::arm(void)
{
	if(this->armed == false){
		this->motor.attach(this->Port);
		this->motor.writeMicroseconds(this->Arm);
		this->armed = true;
	}

  return 0;

}

int esc_controller::calibrate(void)
{
	this->motor.attach(this->Port); //Servo Libary
	this->motor.writeMicroseconds(this->Max);
	delay(ESC_CALIBRATE_DELAY);
	this->motor.writeMicroseconds(this->Min);
	delay(ESC_CALIBRATE_DELAY);
	this->arm();
  return 0;
}


int esc_controller::set_speed(int value)
{
	if(value>this->Max){
		this->speed = this->Max;
	}else if(value < this->Min){
		this->speed = this->Min;
	}else{
		this->speed = value;
	}
	this->motor.writeMicroseconds(this->speed);
  return 0;
}

int esc_controller::disarm(void)
{
	this->armed = false;
	this->motor.writeMicroseconds(this->Arm);
  return 0;
}
