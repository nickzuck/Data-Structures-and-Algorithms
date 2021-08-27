// Just next smaller index from the current element

stack<long long> stack ; 
        
int n = arr.size() ;
vector<int> nse(n) ;

for(int i = 0 ; i < n; i++){
    // Next smallest element
    while(!stack.empty() and arr[stack.top()] > arr[i]){
        nse[stack.top()] = i ;
        stack.pop() ;
    }
    stack.push(i) ;
}
while(!stack.empty()){
    nse[stack.top()] = n;
    stack.pop() ;
}