#include "main.h"

// THIS program is intended soley for demonstrating how the field control system
// interacts with the V5 based robot
//
// For this you need a competition switch to mimic the real field

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	  // Write to the debug console
    // Let get the system up time and show it as well
		std::uint32_t now = pros::millis();   // time stamp in milli sec
		std::cout << "Entering intialize routine - started at: " << pros::millis() << "\n";

		// Write to the V5 LCD as well
		pros::lcd::initialize();          // Initialize the LCD display
		pros::lcd::print(1, "Intitialize task started at %3d", now );

		// We are going to delay the Initialize function for 300millisec to show
		// it is active and running "pseudo code"
		pros::delay(300);
		pros::lcd::print(2, "Intitialize task stopped at %3d", pros::millis() );

		std::cout << "Intialize task stopped at: " << pros::millis() << "\n";
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
	// Show if we are in disabled state - can happen multiple times during competition
	std::cout << "\nEntered disabled state at: " << pros::millis() << "\n";

}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
	// Show if we are in competition_initialized state
	std::cout << "\nEntered competition initialized state at: " << pros::millis() << "\n";
	//We are going to run a slight delay task
	int loopCount = 0;
  std::cout << "Starting delay: ";
	while(loopCount < 20){
		std::cout << "*";
    pros::delay(100);
		loopCount++;
	}
	std::cout << "\nEnded competition initialized at: " << pros::millis() << "\n";
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	// Entering autonomous routine -- we are simulating runnign code by delaying
	// through a loop with a counter of 50 and 200millisec per lopp the program
	// simulating running actual code.

	int loopCount = 0;
	std::cout << "\nAutonomous task started at: " << pros::millis() << "\n";
	std::cout << "Running: ";
  while(loopCount < 50) {
		pros::lcd::print(3, "Autonomous running - loop %3d ", loopCount);
    std::cout << "*";
		pros::delay(200);
		loopCount++;
	}
	pros::lcd::print(4, "Autonomous task ended at %3d", pros::millis() );
	std::cout << "\nAutonomous task ended at: " << pros::millis() << "\n";

}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {

  int loopCount = 0;
	std::cout << "\nOpcontrol task started at: " << pros::millis() << "\n";
	std::cout << "Running: ";
	while (loopCount < 100) {
    pros::lcd::print(5, "Opcontrol running - loop %3d ", loopCount);
    std::cout << "*";
		pros::delay(200);
		loopCount++;
	}
 	pros::lcd::print(6, "Opcontrol task ended at %3d", pros::millis() );
	std::cout << "\nOpcontrol task ended at: " << pros::millis() << "\n";
}
