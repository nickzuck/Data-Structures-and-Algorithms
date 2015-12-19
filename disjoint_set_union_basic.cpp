/*Basic and naive implementation of disjoint set data structure*/

#include<iostream>
#include<algorithm>

#define MAX 1000
using namespace std ; 

//Manage the connectivity of elements
//stores the set number corresponding to an element of array
//storage[i] gives the set number of ith element
int storage[MAX] ; 
int lenStorage ;


//Makes the individual set for each element in the array ...for n elements of the array n sets are formed
void make_set(int a[] ){
	int n = lenStorage;
    	for(int i = 0; i<n ; i++){
        	storage[i] = i ;
    	}
}

//union of destination(index) and source(index)...just like friendship of two more people..source element going to be friend with destinaton
//So the entire group(set number) of source will be changed
void union_set(int source , int destination)
{
	int n = lenStorage;
	//retrive the set number of source element
	int temp = storage[source] ; 
	
	//if a element set number belongs to source set number..then change it's set number to destination set number
    	for(int i = 0 ;i<n ;i++){
		if(storage[i] == temp){
			storage[i] = storage[destination];			
		}
	}
}


//find the set number of the element
int find_set(int element){
	return storage[element];
}

//checks wether A and B are connected or not
bool isConnected(int A , int B){
	if(storage[A] == storage[B]){
		return true ;
	}
	else
		return false;
}

void displayStorage(){
	for(int i = 0 ;i<lenStorage ; i++){
		cout << storage[i] << " " ;
	}
	cout << endl;
}

//Driver program
int main()
{
	int arr[MAX] , n , t;
	cout << "Enter the number of elements..Min - 10...Max limit(" << MAX << ")\t";
	cin >> n ;
	lenStorage = n ; 
	//cout << "Enter the elements of the array\n";
	//for(int i = 0 ; i<n ;i++){
	//	cin >> arr[i];
	//}
	
	make_set(arr);
	cout << "After make set\n";
	displayStorage();
	
	union_set(2,1);
	cout << "After union of 1 and 2\n";
	displayStorage();

	union_set(4,3);
	union_set(8,4); 
	union_set(9,3);
	cout << "After union of 4 ,3 , 8 ,9\n" ;
	displayStorage();

	cout << "Set of element with index 4 = ";
	cout << find_set(4) << endl;

	cout << "Is 1 and 2 connected ? " ;
	if(isConnected)
		cout << "True" << endl ;
	else
		cout << "False" << endl;
return 0 ; 
}