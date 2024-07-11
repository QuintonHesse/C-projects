#include <iostream>
#include <iomanip>
// Quinton Hesse
// Programming languages
// project one clock
using namespace std; // intitialize variables
int inputHours;
int inputMinutes;
int inputSeconds;
int twelveHours;
int twelveMinutes;
int twelveSeconds;


void displayMenu() { // display menu function
	cout << "1 - Add One Hour" << endl;
	cout << "2 - Add One Minute" << endl;
	cout << "3 - Add One Second" << endl;
	cout << "4 - Exit Program" << endl << endl;
}

void display24Clock() { // 24 hour clock

	cout << "24 Hour Clock" << endl;
	cout << std::setw(2) << std::setfill('0') << inputHours << ":" << std::setw(2) << std::setfill('0') << inputMinutes << ":" << std::setw(2) << std::setfill('0') 
		<< inputSeconds << endl; // split line as it got too long
}

void display12Clock() { //12 hour clock
	twelveHours = inputHours;
	twelveMinutes = inputMinutes;
	twelveSeconds = inputSeconds; //variables

	if (twelveHours <= 12) { // if else staements for AM PM and ensuring 12 hours
		if (twelveHours <= 0) { // special case for midnight
			cout << "Twelve Hour Clock" << endl;
			cout << std::setw(2) << std::setfill('0') << "12" << ":" << std::setw(2) << std::setfill('0') << twelveMinutes << ":" << std::setw(2) << std::setfill('0')
				<< twelveSeconds << " AM" << endl; // split line, got too long, midnight out statement
		}
		else {
			cout << "Twelve Hour Clock" << endl; // Am after midnight
			cout << std::setw(2) << std::setfill('0') <<  twelveHours << ":" << std::setw(2) << std::setfill('0') << twelveMinutes << ":" << 
				std::setw(2) << std::setfill('0') << twelveSeconds << " AM" << endl; // split line got too long , AM out statment
		}
	}
	else if (twelveHours >= 12) { //Pm if else branch
		twelveHours = twelveHours % 12; // modulo for proper output
		cout << "Twelve Hour Clock" << endl;
		cout << std::setw(2) << std::setfill('0') << twelveHours << ":" << std::setw(2) << std::setfill('0') << twelveMinutes << ":" 
			<< std::setw(2) << std::setfill('0') << twelveSeconds << " PM" << endl; // split line got too long, PM out statement
	}
}

int main() {
	bool quit = false; // main variables
	int userChoice;
	cout << "Enter current hour." << endl; // user inputs
	cin >> inputHours;
	cout << "Enter the current minute." << endl;
	cin >> inputMinutes;
	cout << "Enter the current second." << endl;
	cin >> inputSeconds;

	while (!quit) {
		if (inputHours >= 24) { // clock logic could only get it to work in main
			inputHours = 0;
		}
		if (inputMinutes >= 59) {
			inputMinutes = 0;
			inputHours = inputHours + 1;
		}
		if (inputSeconds >= 59) {
			inputSeconds = 0;
			inputMinutes = inputMinutes + 1;

		}
		displayMenu(); // call to menu function
		cin >> userChoice;
		switch (userChoice) { // switch case for menu options
		case 1:
			inputHours = inputHours + 1;
			display24Clock();
			display12Clock();
			break;
		case 2:
			inputMinutes = inputMinutes + 1;
			display24Clock();
			display12Clock();
			break;
		case 3:
			inputSeconds = inputSeconds + 1;
			display24Clock();
			display12Clock();
			break;
		case 4:
			quit = true;
			break;
		default:		
			cout << "Invalid Input" << endl;
			break;

		}
	}



	return 0;
}