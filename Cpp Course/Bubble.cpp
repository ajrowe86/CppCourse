/*********************************************************************************
 *
 *	Name:		
 *	Username:	
 *	Date:		
 *
 *********************************************************************************/
#include <iostream>

using namespace std;
const int n =1000;
// library headers, function prototype declaration(s) if any, etc

int main(){
       int bubble[n];
	   int count=0;
	while ( count < n){
		
		 cout << "Please enter an integer (0 to end):" << endl;
		 cin >> bubble[count];
		 if (!(bubble[count]))
		 break;
		 ++count;
	}
	
	// read in values; stop if number exceeds maximum, or if zero entered


     
	// ensure you have counted the number of values for both end reasons
		cout << "The unsorted array is:" << endl;
		for (int i = 0; i < count; ++i){

		 cout << "Element " << i << ":" << bubble[i] << endl;
		 }
	// write out unsorted array
		for (int j = 0; j < count - 1; ++j){
			for (int i = 0; i < count - 1; ++i){
				if (bubble[i] > bubble[i + 1]){
					int temp;
					temp = bubble[i];
					bubble[i] = bubble[i + 1];
					bubble[i + 1] = temp;
				}
			}
		}
	// bubble sort the array
		cout << "The sorted array is:" << endl;
		for (int i = 0; i < count; ++i){
			cout << "Element " << i << ":" << bubble[i] << endl;
		}
	// write out the sorted array
}

// function definition(s) if any
