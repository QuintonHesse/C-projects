//Quinton Hesse
//project two
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double calcInterest(double investment, double interest, double years) {  //calculates amount earned without months
	double finalAmount;
	double power;
	double base;
	double rate;
	rate = interest / 100;
	base = (1.00 + (rate / 12));
	power = 12.00 * years;
	finalAmount = (investment * pow(base, power));
	return finalAmount;
}

double calcInterestMonths(double investment, double interest, double years, double monthly) { //calculates amount earned with months
	double finalAmount;
	double power;
	double base;
	double rate;
	double monthReturn;
	double monthlyRateBase;
	double monthlyRaised;
	rate = interest / 100;
	base = (1.00 + (rate / 12.00));
	power = 12.00 * years;
	monthlyRaised = pow(base, power);
	monthlyRateBase = ((monthlyRaised - 1.00));
	monthReturn = monthly * (monthlyRateBase / (rate/12));
	finalAmount = (investment * pow(base, power));
	finalAmount = monthReturn + finalAmount;
	return finalAmount;
}

double calcInterestEarned(double investment, double interest, double years) { //calculates just the interest earned without months
	double finalAmount;
	double power;
	double base;
	double rate;
	rate = interest / 100;
	base = (1.00 + (rate / 12));
	power = 12.00 * years;
	finalAmount = (investment * pow(base, power));
	finalAmount = finalAmount - investment;
	return finalAmount;
}

double calcInterestMonthsEarned(double investment, double interest, double years, double monthly) { //calculates just the interest earned with months
	double finalAmount;
	double power;
	double base;
	double rate;
	double monthReturn;
	double monthlyRateBase;
	double monthlyRaised;
	double monthlyEarned;
	rate = interest / 100;
	base = (1.00 + (rate / 12.00));
	power = 12.00 * years;
	monthlyRaised = pow(base, power);
	monthlyRateBase = ((monthlyRaised - 1.00));
	monthReturn = monthly * (monthlyRateBase / (rate / 12));
	finalAmount = (investment * pow(base, power));
	finalAmount = monthReturn + finalAmount;
	monthlyEarned = monthly * (12.00 * years);
	finalAmount = (finalAmount - investment) - monthlyEarned;
	return finalAmount;
}




int main() {
	double initialInvest; //initialize variables
	double interestAmnt;
	double yearsAmnt;
	double monthlyCont;
	double yearsCount;
	double yearsCount1;
	double yearsCount2;
	double yearsCount3;
	double yearsCount4;
	double year1Bal;
	double year1Int;
	double year2Bal;
	double year2Int;
	double year3Bal;
	double year3Int;
	double year4Bal;
	double year4Int;
	double year5Bal;
	double year5Int;
	bool quit = false;
	string cont;

	while (!quit) { //while loop that lets you quit
		cout << "type q to quit or c to continue: " << endl;
		cin >> cont;
		if (cont == "q") {
			quit = true;
			break;
		}

		cout << "Initial Investment Amount: $" << endl; //user inputs
		cin >> initialInvest;
		cout << "Percent Interest: %" << endl;
		cin >> interestAmnt;
		cout << "Number of Years: " << endl;
		cin >> yearsAmnt;
		cout << "Monthly contribution: $" << endl;
		cin >> monthlyCont;

		year1Bal = calcInterestMonths(initialInvest, interestAmnt, yearsAmnt, monthlyCont); //calls to functions adding 1 year 4 times so user can see growth
		year1Int = calcInterestMonthsEarned(initialInvest, interestAmnt, yearsAmnt, monthlyCont);
		yearsCount1 = yearsAmnt + 1;
		year2Bal = calcInterestMonths(initialInvest, interestAmnt, yearsCount1, monthlyCont);
		year2Int = calcInterestMonthsEarned(initialInvest, interestAmnt, yearsCount1, monthlyCont);
		yearsCount2 = yearsAmnt + 2;
		year3Bal = calcInterestMonths(initialInvest, interestAmnt, yearsCount2, monthlyCont);
		year3Int = calcInterestMonthsEarned(initialInvest, interestAmnt, yearsCount2, monthlyCont);
		yearsCount3 = yearsAmnt + 3;
		year4Bal = calcInterestMonths(initialInvest, interestAmnt, yearsCount3, monthlyCont);
		year4Int = calcInterestMonthsEarned(initialInvest, interestAmnt, yearsCount3, monthlyCont);
		yearsCount4 = yearsAmnt + 4;
		year5Bal = calcInterestMonths(initialInvest, interestAmnt, yearsCount4, monthlyCont);
		year5Int = calcInterestMonthsEarned(initialInvest, interestAmnt, yearsCount4, monthlyCont);


		cout << "Years       Year End Balance       Year End Earned Interest" << endl;
		cout << fixed << setprecision(0) << yearsAmnt << "           $" << fixed << setprecision(2) << year1Bal << "                $" << year1Int << endl; //output to user
		cout << fixed << setprecision(0) << yearsCount1 << "           $" << fixed << setprecision(2) << year2Bal << "                $" << year2Int << endl;
		cout << fixed << setprecision(0) << yearsCount2 << "           $" << fixed << setprecision(2) << year3Bal << "                $" << year3Int << endl;
		cout << fixed << setprecision(0) << yearsCount3 << "           $" << fixed << setprecision(2) << year4Bal << "                $" << year4Int << endl;
		cout << fixed << setprecision(0) << yearsCount4 << "           $" << fixed << setprecision(2) << year5Bal << "                $" << year5Int << endl;
	}
}