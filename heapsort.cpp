/*Using the algorithm from Introduction to Algorithms by Thomas H Cormen */

#include<iostream>
#include<cmath>
#include<algorithm>

#define MAX 100

using namespace std ;

inline void swap(int &a , int &b){
	int temp = b; 
	b = a ; 
	a = temp ;
}

void max_heapify(int *a, int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2*i;
    while (j <= n)
    {
        if (j < n && a[j+1] > a[j])
            j = j+1;
        if (temp > a[j])
            break;
        else if (temp <= a[j])
        {
            a[j/2] = a[j];
            j = 2*j;
        }
    }
    a[j/2] = temp;
    return;
}

void build_maxheap(int *a , int n){
	int i ; 
	for (i = n/2 ; i>=1 ;i--){
		max_heapify(a , i ,n);
	}
}


void heapsort(int *a , int n){
	int i , temp ; 
	for (i=  n ; i>=2 ;i--){
		swap(a[i], a[1]);
		max_heapify(a, 1, i - 1);
	}
}
int main ()
{	
	int arr[MAX] , n ,i;
	cout << "Enter the number of array elements\t";
	cin >> n ; 
	cout << "Enter the elements of the array\n" ;
	for (i=1 ; i<=n ;i++){
		cin >> arr[i] ;
	}

	build_maxheap(arr , n) ;

	heapsort(arr , n); 
	cout << "ouput after heapsort\n" ;
	for (i = 1 ; i<=n ; i++)
		cout <<arr[i] << " " ;
	cout << endl;
return 0 ; 
}