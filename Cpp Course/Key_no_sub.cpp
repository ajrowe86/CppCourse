/*********************************************************************************
 *
 *	Name:		
 *	Username:	
 *	Date:		
 *
 *********************************************************************************/
#include <iostream>

using namespace std;
const int n =1000;		// library headers, function prototype declaration(s) if any, etc

int main(){
	int bubble[n];		// declare an array big enough to hold largest number of elements to sort
	int count=0;
	int* pointer_array[n];		// and another array of pointers to hold the addresses
		
		while ( count < n){
		 *(pointer_array + count) = &*(bubble + count);
		 cout << "Please enter an integer (0 to end):" << endl;
		 cin >> *(bubble + count);
		 if (*(bubble + count) == 0) break;
		 ++count;
		}		// read in values; stop if number exceeds maximum, or if zero entered

// ensure you have counted the number of values for both end reasons
			
	cout << "The unsorted array is:\n" << endl;
				
	for (int i = 0; i < count; ++i){

	cout << "Element " << i << ":\t" << *(bubble + i) << endl;
	}		// write out unsorted array (read out through pointer array)
				
	for (int j = 0; j < count - 1; ++j){
					
		for (int i = 0; i < count - 1; ++i){
						
			if ((**(pointer_array + i)) > (**(pointer_array + (i + 1)))){
				int* temp;
				temp = *(pointer_array + i);
				*(pointer_array + i) = *(pointer_array + (i + 1));
				*(pointer_array + (i + 1)) = temp;
			}
		}
	}		// bubble sort the array, by comparing and swapping the pointers, not the values
					
	cout << "\nThe sorted array is:\n" << endl;
						
		for (int i = 0; i < count; ++i){
		cout << "Element " << i << ":\t" << **(pointer_array + i) << endl;
	}		// write out the sorted array(read out through pointer array
}		// function definition(s) if any


