/*************************************************
** 	Full Name: Andrew Rowe
** 	Username : mbyx6ar2
** 	Date     : 23/10/2008
*************************************************/

#include <iostream>
#include <cmath>
// include any other libraries you need here

using namespace std;
	double c = 299792458.0;
	char option;
	double m, v, p, KE, g;

// declare and initialise any global (const !) variables here
double krel (double p, double m);
double vtop (double m, double v);
double gamma (double v);

// function prototype declarations here

int main () {

	do {
		char a;
		cout << "Please enter the mass (kg) :" << endl;
		cin >> m;
		cout << "Are you going to enter a [S]peed or a [M]omentum ?" << endl;
		cin >> a;

		switch (a){

			case 'M':
			case 'm':
				cout << "Please enter the momentum (kgm/s) :" << endl;
				cin >> p;
				KE=krel(p,m);
				cout << "A mass of " << m << " kg with a momentum of " << p << " kgm/s has a kinetic energy of " << KE << " J." << endl;
				break;

			case 'S':
			case 's':
				cout << "Please enter the speed (m/s) :" << endl;
				cin >> v;

				while (v > c){
					cout << "The speed must be less than the speed of light." << endl;
					cout << "Please enter the speed (m/s) :" << endl;
					cin >> v;
				}
				g=gamma(v);
				p=vtop(m,v);
				KE=krel(p, m);
				cout << "A mass of " << m << " kg at a speed of " << v << " m/s has a kinetic energy of " << KE << " J." << endl;
				break;

			default:
				cout << "You entered a mass of " << m << " kg but the choice of speed or momentum was not a valid choice." << endl;

		}
		cout << "Do you wish to perform another calculation ([Y]es or [N]o)?" << endl;
		cin >> option;

	}
	while (option == 'Y'||option == 'y');
	cout << "Thank you for using the relativistic kinetic energy calculator.";

	// this bit is just like eloop, but using your functions
	// to calculate the energy
	
}			// end of main()

// function definitions here
double krel (double p, double m){
	double krel = sqrt((pow(p, 2)*pow(c, 2)) + (pow(m, 2)*pow(c, 4))) - m*pow(c, 2);
	return krel;
}

double vtop (double m, double v){
	double vtop = gamma(v)*m*v;
	return vtop;
}

double gamma (double v){
	double gamma = 1/(sqrt(1 - ((pow(v, 2))/(pow(c, 2)))));
	return gamma;
}