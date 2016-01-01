// Implementation of disjoin set union find by parent array representation and weighted union
// Time Complextiy : O(log2N)

#include<iostream>
#include<algorithm>

#define MAX  1000

using namespace std ; 

// Manage the connectivity of elements
//store the parent corresponding to the index
//initially the parent of index is the index itself
int parent[MAX];
// Will keep track of size of each subset
int size[MAX];
int lenParent ; 

void makeSet(){
    for(int i = 0; i<lenParent ;i++){
        parent[i] = i;
        // Modified to contain the size of the subset
        size[i] = 1 ;
    }
}

//Returns the root of the input index
//The root is found if the parent of index is the index itself
int root(int i){
    if(parent[i] == i)
        return i;
    // If i is not the root, then move upper to find the root
    else
        root(parent[i]);
}

// Union by changing the parent of the element
// a is being merged to b so the root of either will be changed
int weighted_union(int a, int b){ 
    int rootA = root(a);
    int rootB = root(b) ;
    if (size[rootA] < size[rootB]){
        parent[rootA] = rootB ;
        size[rootB] += size[rootA];
    }
    else{
        parent[rootB] = rootA;
        size[rootA] += size[rootB] ;
    }
}

//The elements are in same set if their roots are same
bool isConnected(int a , int b){
    if(root(a) == root(b)){
        return true;
    }
    else
        return false;
}

//Display parent array
void displayParents(){
    for(int i= 0 ; i<lenParent; i++){
        cout << parent[i] << " ";
    }
    cout << endl ;
}

// Driver program to test the above implementation
int main()
{
    int n, t;
    //int arr[MAX] /*You can use arr[MAX] to store the elements and then perfom disjoint set operations according to index of arr*/
    
    cout << "Enter the number of elements..Min-10..Max Limit("<<MAX<<")\t";
    cin >> n;

    lenParent = n;

    // Make the set for n elements
    makeSet();

    cout << "After make set \n";
    displayParents();

    weighted_union(2,1);
    cout << "After union of 1 and 2\n" ; 
    displayParents();

    weighted_union(4,3);
    weighted_union(8,4);
    weighted_union(9,3);
    cout << "After union of 4,3,8,9 \n";
    displayParents();

    cout <<"Parent of element with index 4\n";
    cout << parent[4] << endl;
    cout << "Root of element with index 4\n";
    cout << root(4) << endl;

    cout <<"Is 1 and 2 connected or in same set\n";
    if(isConnected(1,2))
        cout << "True" << endl ;
    else
        cout << "False" << endl ;

    cout << "Is 4 and 8 connected or in same set\n" ;
    if(isConnected(4,8))
        cout << "True" << endl;
    else
        cout << "False" << endl ;

    cout << "Is 4 and 7 connected or in same set\n";
    if(isConnected(4,0))
        cout << "True" << endl ;
    else
        cout << "False" << endl ;
return 0 ;
}
