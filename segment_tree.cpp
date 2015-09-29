/*After reading the tutorial of segment tree from code monk .. Now I think I can try to code the segment tree */

#include<iostream>

#define MAX 20

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
        build(2*node  , start , mid) ; 
    
        //Perfom build on the right subtree
        build(2*node + 1 , mid+1 , end) ; 

        //internal nodes will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1] ;
    }
}

int main ()
{
return 0 ;
}
