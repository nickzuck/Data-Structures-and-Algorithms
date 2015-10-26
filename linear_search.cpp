/*I don't why the fuck I'am writing this code*/
//yes I know, it for the ADA lab ..Fuck it 

#include<iostream>
#include<math.h>

#define MAX 100
using namespace std ;

int main ()
{
	int arr[MAX] , i , n , search ;

	cout << "Enter the number of elements in the array\t" ; 
	cin >> n ; 

	cout << "Enter the elements of the array\n" ; 
	for (i = 0 ; i<n ; i++){
		cin >> arr[i];
	}

	cout << "Enter the element to be searched in the array\t" ; 
	cin >> search ; 	
	
	for (i = 0 ; i < n ; i++){
		if (search == arr[i]){
			break ; 
		}
	}
	cout << "The element is located at the position " << i << endl ;
return 0 ; 
}

