/*Using the algorithm from Introduction to Algorithms by Thomas H Cormen */

#include<iostream>
#include<cmath>

#define MAX 10

using namespace std ;

int arr[MAX] ;

void swap(int &a , int &b){
	int temp = b ; 
	b = a ;
	a= temp ;
}


void maxheapify(int i , int n) {
	int l ,r , largest;

	l = 2*i ; 
	r = 2*i +1 ;

	if (l < n  && arr[l] > arr[i])
		largest = i;
	else
		largest = l ; 

	if(r<n && arr[r] > arr[largest])
		largest = r ; 
	if(largest != i){
		swap(arr[i],arr[largest]) ;
		maxheapify(largest , n) ; 
	}
}

/*We can use the procedure maxheapify in a bottom up manner to convert the array into max-heap.So to build heap we need to use the maxheapify procedure from a.length/2 downto 1 */

void build_maxheap(int n){
	for(int i = n/2 ; i>=1 ; i--){
		maxheapify(i , n) ;
	}
}

void heapsort(int n ){
	build_maxheap(n);
	for (int i = n ; i>=2 ; i--){
		swap(arr[1] , arr[i]);
		n -- ;
		maxheapify(1 , n) ;
	}
}
int main()
{
 	int i , n  ; 

	cout << "Enter the number of elements\t" ; 
	cin >> n  ; 
	cout << "Enter the elements of the array\n" ;
	for(int i=1  ; i<= n ;i++){
		cin >> arr[i] ;
	}

		heapsort(n);
return 0 ; 
}