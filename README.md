# pros5fieldTest
Demonstrate how field control interacts with the robot in various states

The VEX V5 field control system, interacts with the robot, and switches the robot modes from autonomous to opcontrol, with two additional states.  At initial connection to the field control system, competition_initialize() is run - this is run EVERY time a the field control cable is connecected to the remote.  Everytime the field control triggers disable (stop autonomous or opcontrol) it will trigger the disabled() function.

However the states triggered - disabled, competition_initialized differs when simulating fhte field usign the V5 remote versus the competition switch and the real field.

The inention of thsi program is to demonstrate which state is triggered when and how by the different ways the robot system os controlled - competition switch, remote control or true field.
