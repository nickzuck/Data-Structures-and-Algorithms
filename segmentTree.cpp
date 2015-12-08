#include<iostream>
#include<algorithm>
#include<cstring> //For memset

#define MAX  101
using namespace std ;

int arr[MAX];
int tree[2*MAX + 1];

//function definition
void update(int node, int a, int b, int i, int j , int value);
void query();
void build_tree(int , int , int );

//function to find the middle value
inline int getMid (int a , int b){
    return (a+b)/2;
}

inline int max(int a , int b , int c){
    if (a > b){
        if(a > c)
            return a ;
        else 
            return c ;
    }
    else{
        if(b > c)
            return b ;
        else 
            return c ;
    }
}

//Build segment tree
void build_tree(int node , int a , int b){
    if (a > b){
        return ; // out of range
    }
    if(a == b){
        tree[node] = arr[a];
        return ;
    }
    int mid = getMid(a , b);
    build_tree(node*2 , a , mid);
    build_tree(node*2+1 , mid+1 , b );
    tree[node] = max(tree[node*2] + tree[node*2 + 1] , tree[node*2] , tree[node*2 + 1]);
}

//Driver Program
int main()
{
    int n ,i ; 
    cout << "Enter the number of elements in the array\t";
    cin >> n ;

    //Input
    for(i = 0 ;i<n;i++){
        cin >> arr[i];
    }

    //initializing the arrays 
    memset(tree , 0 , sizeof(tree));
    //Build Tree
    build_tree(1 , 0 , n-1);

    cout << "After tree build\n";
    for(i = 1 ; i <= 2*n -1; i++)
        cout << tree[i] << " " ;
return 0 ;
}