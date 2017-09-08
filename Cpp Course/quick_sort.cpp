/***************************************************************************
 *
 * Username:		mbyx6ar2
 * Full name:		Andrew Rowe
 * Date:			12/12/2008
 *
 **************************************************************************/

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
using namespace std;				// include any headers needed

const int max_file_name_length = 15;
const int max_name_length = 15;				// Keep up good habits with any "magic numbers"
											// e.g. names are not longer than 14 characters

struct phone_book {
	char first_name[max_name_length];
	char last_name[max_name_length];
	int phone_number;
};									// declare any struct(s) here

// function prototype declarations

int main(void){

	char in_file_name[max_file_name_length];
	char out_file_name[max_file_name_length];
	char a;

cout << "Please enter the input file name:" << endl;
cin >> in_file_name;

cout << "Please enter the output file name:" << endl;
cin >> out_file_name;										// read in the input and output filenames

phone_book temp;

	ifstream in(in_file_name);
		if(!in){
			cerr << "Failed to open input file " << in_file_name << endl;
			exit(1);
		}
		
	int i = 0;
		while(in){
			if(in >> temp.first_name >> temp.last_name >> temp.phone_number) ++i;
		}															// count the number of records in the file by reading them in
	
	in.clear();										// reset the input file status after reading to the end
	in.seekg(0);										// rewind the file using seekg()

	
	phone_book* data_base = new phone_book[i];																// create an array (of structs) to hold all persons in the file
	phone_book** p_data_base = new phone_book*[i];					// do you need any other arrays?

	phone_book* pp_data_base = data_base;

		for(int j = 0; j < i; ++j){
			in >> data_base[j].first_name >> data_base[j].last_name >> data_base[j].phone_number;
			p_data_base[j] = pp_data_base++;
		}																					// read the data for real this time

	in.close();

ofstream out(out_file_name);
	out << "The unsorted list:\n\t" << endl;
		for (int j = 0; j < i; ++j){

		 out << data_base[j].first_name << "\t" << data_base[j].last_name << "\t" << "07" << data_base[j].phone_number << endl;
		 }																					// print out the unsorted list

	cout << "Do you wish to sort by [f]irst name, [s]econd name, or [m]obile number?" << endl;
	cin >> a;		
while (a != 'f' && a != 'F' && a != 's' && a != 'S' && a != 'm' && a != 'M'){
	cout << "You entered an invalid choice. Do you wish to sort by [f]irst name, [s]econd name, or [m]obile number?" << endl;
	cin >> a;
}




		switch (a){

		case 'f':
		case 'F':
			for (int j = 0; j < i - 1; ++j){
				for (int k = 0; k < i - 1; ++k){
					if (strcmp(data_base[k].first_name , data_base[k + 1].first_name) > 0) {
						phone_book temp;
						temp = data_base[k];
						data_base[k] = data_base[k + 1];
						data_base[k + 1] = temp;
					}
				}
			}
			
	out << "\n\nThe sorted list:\n(sorted by first name)\n\t" << endl;
	for (int k = 0; k < i; ++k){
			out << data_base[k].first_name << "\t" << data_base[k].last_name << "\t" << "07" << data_base[k].phone_number << endl;
		}
	break;
	
		case 's':
		case 'S':
			for (int j = 0; j < i - 1; ++j){
				for (int k = 0; k < i - 1; ++k){
					if (strcmp(data_base[k].last_name , data_base[k + 1].last_name) > 0 ) {
						phone_book temp;
						temp = data_base[k];
						data_base[k] = data_base[k + 1];
						data_base[k + 1] = temp;
					}
				}
			}
			
	out << "\n\nThe sorted list:\n(sorted by second name)\n\t" << endl;
	for (int k = 0; k < i; ++k){
			out << data_base[k].first_name << "\t" << data_base[k].last_name << "\t" << "07" << data_base[k].phone_number << endl;
		}
	break;
	
		case 'm':
		case 'M':
			for (int j = 0; j < i - 1; ++j){
				for (int k = 0; k < i - 1; ++k){
					if (data_base[k].phone_number > data_base[k + 1].phone_number){
						phone_book temp;
						temp = data_base[k];
						data_base[k] = data_base[k + 1];
						data_base[k + 1] = temp;
					}
				}
			}
			
	out << "\n\nThe sorted list:\n(sorted by mobile number)\n\t" << endl;
	for (int k = 0; k < i; ++k){
			out << data_base[k].first_name << "\t" << data_base[k].last_name << "\t" << "07" << data_base[k].phone_number << endl;
		}
	break;												// Now sort either on first_name, second_name or mobile number
	
			// ask the question again if the user does not give a valid answer
		}



	// call your sorting function (it needs to be fast...)

	// now print out the sorted list
out.close();
delete [] data_base;	// remember to tidy up any dynamical memory allocations, close any
						// open files etc.	

}		// end of main()

// function definitions here