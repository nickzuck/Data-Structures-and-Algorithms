#include<iostream>
#include<cmath>
#include<algorithm>

#define MAX  65535

void youngify(int i, int j);
int young[100][100] ;
int m , n ; 
using namespace std ;

int extract_min(){
    int x = young[0][0] ;
    young[0][0] = INT_MAX;
    youngify( 0, 0);
}

void youngify(int i, int j){
    int x, y ; 
    x  = i ; 
    y = j ;
    int temp ;
    if (i +1 <= m){
        if(young[i][j] > young[i+1][j]){
            x  = i+1 ;
            y = j ;
        }
    }
    if(j+1 <n){
        if(young[x][y] > young[i][j+1]){
            x = i ; 
            y = j+1; 

        }
    }

    if(x != i || y != j){
        temp = young[x][y] ;
        young[x][y] = young[i][j] ; 
        young[i][j] = temp ; 
        youngify(x, y);
    }
}

// Insertion
//void insert_key(
int main()
{
    int i, j ;
    cin >> m >> n ; 
    for(i = 0 ; i<m ; i++){
        for(j = 0 ; j<n ; j++){
            cin >> young[i][j];
        }
    }

    youngify(m,n);
    for(i = 0 ;i<m ; i++){
        for(j = 0 ;j<n ; j++){
            cout << young[i][j] << " " ; 
        }
        cout <<endl ;
    }

return 0 ;
}
