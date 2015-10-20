#include<stdio.h>

int main ()
{

    int i , j , key  , a[100] , n ; 

    printf ("Enter the number of elements of the array\t"); 
    scanf ("%d",&n) ; 
    for (i = 0 ;i<n ; i++){
      scanf ("%d",&a[i]) ; 
    }

    for (j = 1 ; j<n ; j++){
        key = a[j]; 
        i = j-1 ; 
        while(i>=0 && a[i]>key){
            a[i+1] = a[i] ; 
            i-- ; 
        } 
        a[i+1] =  key ; 
    }    

    printf ("sorted array \n") ; 
    for (i =0 ; i<n ;i++){
        printf ("%d ",a[i]) ; 
    }
return 0 ;
}
