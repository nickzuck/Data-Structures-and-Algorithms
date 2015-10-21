#include<iostream>
#include<math>

#define MAX 100

using namespace std ;

void swap(int &a , int &b){
	int temp = b ; 
	b = a ;
	a= temp ;
}


void maxheapify(int a[] , int i , int n) {
	int l ,r , largest

	l = 2*i ; 
	r = 2*i +1 ;

	if (l < n  && a[l] > a[i])
		largest = i;
	else
		largest = l ; 

	if(r<n && a[r] > a[largest])
		largest = r ; 
	if(largest != i){
		swap(a[i],a[largest]) ;
		max-heapify(a , largest , n) ; 
	}
}
int main()
{
 	int i , n , arr[MAX] ; 

	cout << "Enter the number of elements\t" ; 
	cin >> n  ; 
	cout << "Enter the elements of the array\n" ;
	for(int i=1  ; i<= n ;i++){
		cin >> a[i] ;
	}

	build_max_heap(A)
return 0 ; 
}