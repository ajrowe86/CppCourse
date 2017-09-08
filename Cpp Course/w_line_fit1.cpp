/**************************************************************************************
 *
 *	Username:	
 *	Name:		
 *	Date:
 *
 *************************************************************************************/
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
using namespace std;										// include all headers needed here

const int max_length = 1000;
const int max_file_name_length = 15;

struct datapoint {
	double x;
	double y;
	double sigma;
	double weight;
	double x2;
	double xy;
};															// write the structure declaration here

datapoint sum (datapoint a[], int max_length);					// prototype function declaration(s)

int main(){
		
	double D;
	double m;
	double dm;
	double c;
	double dc;
	double xsq;
	double residual[max_length];

	char in_file_name[max_file_name_length];
	char out_file_name[max_file_name_length];

	cout << "Please enter the input file:" << endl;
	cin >> 	in_file_name;						
	
	cout << "Please enter the output file:" << endl;
	cin >> 	out_file_name;			// read the input and output filenames

	datapoint a[max_length]; 
	
	ifstream in(in_file_name);
		if(!in){
			cerr << "Failed to open input file " << in_file_name << endl;
			exit(1);
		}
		
	int i = 0;
		while(in){
			if(i >= max_length) break;

			if(in >> a[i].x >> a[i].y >> a[i].sigma) ++i;

		}				// declare array of structs, open input file and read sets of 3 numbers
						// (x, y sigma) into array

	in.clear();
	in.close();		
	
	ofstream out(out_file_name);
		if(!out){
			cerr << "Failed to open output file " << out_file_name << endl;
			exit(2);
		}				// close the input file and open the output file
datapoint weighted_sums = sum(a, i);
D = (weighted_sums.weight *	weighted_sums.x2) - (pow(weighted_sums.x, 2));
m = (weighted_sums.weight * weighted_sums.xy - weighted_sums.x * weighted_sums.y) / D;

dm = sqrt(weighted_sums.weight / D);
c = (weighted_sums.y * weighted_sums.x2 - weighted_sums.x * weighted_sums.xy) / D;
dc = sqrt(weighted_sums.x2 / D);

xsq = 0;
for (int j = 0; j < i; ++j){
	residual[j] = (m * a[j].x + c - a[j].y) / a[j].sigma;

	xsq += pow(residual[j], 2);
}			// compute fit parameters and errors, using a struct to collect the weighted sums

out << "For y = mx + c, with errors on y of sigma, the line of best fit has\n\n" << endl;
out << "\tm = " << m << " +/- " << dm <<  endl;
out << "\tc = " << c << " +/- " << dc << "\n\n" << endl;
out << "The data and the fitted values are:\n" << endl;
out << "\tx\ty\tsigma\tmx+c\tresidual" << endl;
out << "\n" << endl;

for (int j = 0; j < i; j++){
	out << "\t" << a[j].x << "\t" << a[j].y << "\t" << a[j].sigma << "\t" << m * a[j].x + c << "\t" << residual[j] << endl;
}

out << "\n\n" << endl;
out << "Chi-squared = " << xsq << endl;

out.close();	// write to output file and close it

}		

datapoint sum (datapoint a[], int max_length){
	datapoint temp;
	temp.x = 0;
	temp.y = 0;
	temp.weight = 0;
	temp.sigma = 0;
	temp.x2 = 0;
	temp.xy = 0;

for(int j = 0; j < max_length; ++j){
    double w = 1/pow(a[j].sigma, 2);
	temp.x = temp.x + a[j].x * w ;
	temp.y = temp.y + a[j].y * w;
	temp.weight = temp.weight + w;
	temp.sigma = temp.sigma + a[j].sigma;
	temp.x2 = temp.x2 + a[j].x * a[j].x * w ;
	temp.xy = temp.xy + a[j].x * a[j].y * w;
	
}
return temp;	
}			// function definition(s) here
