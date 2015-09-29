/*After reading the tutorial of segment tree from code monk .. Now I think I can try to code the segment tree */

#include<iostream>

#define MAX 20

using namespace std ;
// total number of nodes for an array of n elements  = 2*n - 1 

int A[MAX] , tree[2*MAX +1] ; 
void build (int node , int start , int end)
{
    if (start == end){
        //leaf node
        tree[node] = A[start] ; 
    }
    
    else {
        int mid = (start + end) / 2 ; 
        
        //Perfom build on the left subtree
        build(node*2  , start , mid) ; 
    
        //Perfom build on the right subtree
        build(node*2 + 1 , mid+1 , end) ; 

        //internal nodes will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1] ;
    }
}

int main ()
{
    int n,i ;
    cin >> n ;

    for (i = 0 ; i<n ; i++)
        cin >> A[i]; 

    build(1 , 0 , n-1); // node , start , end 
    
    cout << "The array corresponding to segment tree is\n" ; 
    for (i = 1 ; i <= 2*n-1 ; i++)
        cout << tree[i] << " "; 

    cout << "\n" ; 
return 0 ;
}
