#include<iostream>
#include<cmath>
#include<algorithm>

#define INF  65535

void youngify(int i, int j);
int young[100][100] ;
int arr[100];
int m , n ; 
using namespace std ;

int extract_min(){
    int x = young[0][0] ;
    young[0][0] = INT_MAX;
    youngify( 0, 0);
}


void youngify(int i, int j)
{
    int downVal  = (i+1 < m)? young[i+1][j]: INF;
    int rightVal = (j+1 < n)? young[i][j+1]: INF;
 
    if (downVal==INF && rightVal==INF)
        return;
 
    if (downVal < rightVal)
    {
        young[i][j] = downVal;
        young[i+1][j] = INF;
        youngify(i+1, j);
    }
    else
    {
        young[i][j] = rightVal;
        young[i][j+1] = INF;
        youngify(i, j+1);
    }
}

void initialize(){
    int i , j, k;
    k = m*n-1 ;
    for(i = m-1; i>=0 ; i--){
        for(j = n-1; j>=0; j--){
            young[j][i] = arr[k--];   
        }
    }
}
// Insertion
void insert_key(int i, int j){
    
}
int main()
{
    int i, j ;
    cin >> m >> n ; 
    for(i = 0 ; i<m*n ; i++){
        cin >> arr[i];
    }

    sort(arr, arr+m*n) ;
    cout << "After sorting\n" ; 
    for(i = 0 ; i<m*n ; i++)
        cout << arr[i] << " ";
    cout << endl ;

    initialize();

    youngify(m,n);

    for(i = 0 ;i<m ; i++){
        for(j = 0 ;j<n ; j++){
            cout << young[i][j] << " " ; 
        }
        cout <<endl ;
    }

return 0 ;
}
