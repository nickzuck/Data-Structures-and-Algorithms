#include<iostream>
#include<math.h>

#define MAX 100

using namespace std ;

void swap(int &a , int &b){
	int temp = b ;
	b = a ;
	a = temp ; 
}

int main()
{
	int i ,j , n, temp , arr[MAX];
	cout << "Enter the number of elements in array\t" ;
	cin >> n;

	cout << "Enter the elements of the array\n" ;
	for (i = 0 ; i<n ;i++){
		cin >>arr[i] ;
	}
	
	//Bubble sorting the array in ascending order 
	//for descending order change the sign in the if loop after the inner for loop
	for(i = 0; i<n ;i++){
		for (j = i+1; j<n; j++){
			if (arr[i]>arr[j]){
				swap(arr[i] , arr[j]) ;
			}
		}
	}

	cout << "Soted array\n" ;
	//printing the array
	for (i = 0 ;i<n;i++){
		cout << arr[i] << " " ; 
	}
return 0; 
}
