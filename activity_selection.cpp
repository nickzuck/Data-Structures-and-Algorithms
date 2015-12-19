#include<iostream>
#include<algorithm>

#define MAX 1002
using namespace std ;

pair<int , int>  a[MAX];

//a[].first denotes the finish time
//a[].second denotes the start time


void selectActivities(int n){
    int last , count = 0 ;
    last = -1 ;
    for(int i = 0 ; i<n ;i++){
        if(a[i].second >= last){
            cout << "Activity " << i+1 << endl; 
            count ++ ;
            last = a[i].first ;
        }
    }
    cout << "Number of activities are " << count << endl ;
}
int main()
{
    int i , n ;
    
    cout << "Enter the number of activities\t";
    cin >> n ;

    cout << "Enter the activities with start time and finish time (start time as the first argument)\n";
    for(i = 0; i<n ; i++){
        cin >> a[i].second >> a[i].first ; 
    }

    //sort accordin to the first one i.e finish time
    sort(a , a+n);

    selectActivities(n);
            
return 0 ;
}
