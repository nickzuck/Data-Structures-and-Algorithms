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

/*We can use the procedure maxheapify in a bottom up manner to convert the array into max-heap.So to build heap we need to use the maxheapify procedure from a.length/2 downto 1 */

void build_maxheapify(int a[]  , int n){
	for(int i = n/2 ; i>=1 ; i--){
		maxheapify(a , i , n) ;
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