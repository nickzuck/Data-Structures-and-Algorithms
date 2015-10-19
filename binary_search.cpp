/*Again doing it for ADA lab ..This one is at least better than linear search */ 

#include<iostream>
#include<math.h>

#define MAX 100 

using namespace std ;
 
int main ()
{
	int arr[MAX] , i , n , search , low , mid , high , ans = -1;
	cout << "Enter the number of  elements in the array\t" ; 
	cin >> n; 

	cout << "Enter the elements of the array\n" ; 
	for(i = 0;  i<n ; i++){
		cin >> arr[i] ; 
	} 
	
	cout << "Enter the element to be searched\t" ; 
	cin >> search ;  
	low = 0 ; 
	high = n -1;
	while(low <= high){
		mid = (low + high)/2 ; 
		if(arr[mid] == search){
			ans = mid ;
			break ; 
		}
		else if(arr[mid] < search){
			//recurse on right subtree
			low = mid + 1 ;
		}
		else if (arr[mid] > search){
			//recurse on left subtree
			high = mid -1 ;
		}
	}

	cout << ans <<endl;
	if (ans>=0){
		cout << "The number is located at the index " << ans  << endl;  
	}
	else {
		cout << "Element not found\n" ;
	}
return 0 ; 
}