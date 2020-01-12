#include<iostream>
#include<vector>
#include<string>

using namespace std ;

vector<int> computePrefixFunc(string s){
    int n = s.size();
    vector<int> prefix(n) ;
    int longestBorder = 0 ;
    prefix[0] = 0 ;
    for (int i = 1; i < n ; ++i){
        while(longestBorder > 0 and s[i] != s[longestBorder]){
            longestBorder = prefix[longestBorder-1] ;
        }
        if (s[i] == s[longestBorder]){
            longestBorder ++ ;;
        }
        prefix[i] = longestBorder ;
    }
    return prefix ;
}

int main(){
    string str ;
    getline(cin, str);
    vector<int> prefixArr = computePrefixFunc(str) ;
    int n = prefixArr.size() ;
    for(int i = 0 ; i < n ; i++){
        cout << prefixArr[i] << " "  ;
    }
}