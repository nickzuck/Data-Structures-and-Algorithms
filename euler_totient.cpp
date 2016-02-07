#include<iostream>

using namespace std ;

// Taken from topcoder
int totient(int n){
    int result = n ,i ;
    for(i = 2 ; i*i <= n ;i++){
        if(n%i == 0) 
            result -= result/i;
        while(n%i ==0)
            n /= i ;
    }
    if(n>1)
        result -= result/n ;
    return result ;
}

int main()
{
    int n ; 
    cout << "Enter the number " ; 
    cin >> n ;
    cout << totient(n) << endl;

return 0;
}
