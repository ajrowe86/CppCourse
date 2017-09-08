/*************************************************
** 	Full Name: 
** 	Username :
** 	Date     :
*************************************************/

#include <iostream>
using namespace std;

int main () {
	double j, k, l;
	char a, option;
	
do {
		cout << "Please enter the mass (kg) :" << endl;
		cin >> j;
		cout << "Are you going to enter a [S]peed or a [M]omentum ?" << endl;
		cin >> a;
		switch (a){
			case 'S':
			case 's':
				cout << "Please enter the speed (m/s) :" << endl;
				cin >> k;
				cout << "A mass of " << j << " kg at a speed of " << k << " m/s has a kinetic energy of " << 0.5*j*k*k << " J." << endl;
				break;
			case 'M':
			case 'm':
				cout << "Please enter the momentum (kgm/s) :" << endl;
				cin >> l;
				cout << "A mass of " << j << " kg with a momentum of " << l << " kgm/s has a kinetic energy of " << 0.5*(l*l)/j << " J." << endl;
				break;
			default:
				cout << "You entered a mass of " << j << " kg but the choice of speed or momentum was not a valid choice." << endl;
		}
		cout << "Do you wish to perform another calculation ([Y]es or [N]o)?" << endl;
		cin >> option;
	}
	while (option == 'Y'||option == 'y');
	
	// end of loop
cout << "Thank you for using the kinetic energy calculator." << endl;
	//sign off politely

}			//end of main()
