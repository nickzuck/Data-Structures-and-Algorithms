#include<iostream>
#include<algorithm>
#include<queue>

#define MAX 1000

using namespace std; 



//Radix SORT
/*radix = 10 for decimal numbers you may pass another variable if you want to change the radix*/
void radix_sort(int *a , int n , int digits , int radix = 10) 
{
	queue <int> radix_queues[radix] ; 
	for(int i = 0, factor = 1; i < digits; factor *= radix, i++)
	{
		for(int j = 0; j < n; j++)
			radix_queues[((a[j]/factor)%radix)].push(a[j]);
		int k = 0;
		for(int j = 0; j < radix; j++)
		{
			while(!radix_queues[j].empty())
			{
				a[k] = radix_queues[j].front();
				radix_queues[j].pop();
				k++;
			}
		}
		cout << endl ;
	}	
}


//to get the maximum digits present in the given array
int getmaxdigit(int number){
	int count = 0 ; 
	while(number >0){
		number /= 10 ;
		count ++ ;
	}	

return count  ;
}



//driver program
int main ()
{
	int i , n , arr[MAX] , maximum ;
	cout << "Enter the number of elements int the array\t" ; 
	cin>> n;
	cout << "Enter the elements of the array\n";
	maximum = 0 ; 
	for(i = 0 ; i<n ;i++){
		cin >> arr[i];
		maximum = max(maximum , arr[i]) ;
	} 
	int digits = getmaxdigit(maximum);
	cout << digits << endl;
	radix_sort(arr , n, digits );
	cout << "sorted array\n";
	for (int i =0 ;i <n ;i++)
		cout << arr[i] << " ";
return 0 ;
}