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


//idx is the index where update is to be performed
//value is the value to be updated 
void update (int node , int start , int end , int idx , int value) {
    if  (start == end){
        //leaf node ..simply update the value of the arrray 
        A[idx] += val ; 
        tree[node] += val ; 
    }
    else{
        int mid  = (start + end)/2 ; 

        //Left subtree case
        if (start <= idx && idx<= mid) {
            update(2* node , start , mid ,idx , value) ; 
        }

        //Right subtree case
        else{
            update(2*node +1 , mid+1 , end , idx ,value) ;
        }

        //updating the internal node accordingly
        tree[node] = tree[2*node] + tree[2*node +1]; 
    }
}

int query(int node , int start , int end , int l , int r) {
    
    //range represented by node is completely outside 
    if (r < start ||  end < l ){
        return 0 ;
    }

    //range represented by node is completely inside the node
    if (l < = start && end  <= r){
        return tree[node] ;
    }

    //else : range represented by node is partially inside and partially outside the given range
    int mid = (start + end)/2 ; 
    int p1 = query(2* node , start , mid , l , r) ; 
    int p2 = query(2*node +1 , mid+1 , end , l , r) ;
    return (p1 + p2) ;
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
