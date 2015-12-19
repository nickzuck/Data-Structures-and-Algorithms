#include<iostream>

#define MAX 1002
using namespace std ;

void specialMerge(int start[] , int end [] , int low , int high , int mid){
    int i , j , k , c[MAX] , d[MAX] ;
    i = low ;
    k = low ;
    j = mid +1 ;
    
    while(i<= mid && j<=high){
        if(end[i] < end[j]){
            c[k]  = end[i];
            d[k] = start[i];
            k++ ; 
            i++ ;
        }
        else {
            c[k] = end[j] ;
            d[k]= start[j];
            k++ ; 
            j++ ; 
        }
    }
    while(i<=mid){
        c[k] = end[i]  ;
        d[k] = start[i] ;
        k++ ;
        i++ ;
    }

    while(j <=high){
        c[k]  = end[j];
        d[k] = start[j];
        k++ ;
        j++ ;
    }
    for(i = low ;i<k ;i++){
        end[i] = c[i];
        start[i] = d[i];
    }
}

int getMid(int a , int b){
    return (a+b)/2 ;
}

void specialMergeSort(int start[] , int end[]  , int p , int r){
    if(p<r){
        int q = getMid(p , r);
        specialMergeSort(start , end , p , q);
        specialMergeSort(start , end , q+1 , r );
        specialMerge(start , end , p , q , r);
    }
}

int main()
{
    int n , start[MAX] , end[MAX];
    cout << "Enter the number of activites  ";
    cin >> n ;
    
    cout << "Enter the start and end time for each activities\n";
    for(int i = 0 ; i<n;  i++){
        cin >> start[i] ;
        cin >> end[i] ;
    }
    
    specialMergeSort(start , end , 0 , n-1);
    cout << "AFter merge sort ..Activities are ;\n" ;
    for(int i = 0 ; i< n; i++){
        cout << start[i] << " " << end[i] << endl; 
    }
return 0 ;
}
