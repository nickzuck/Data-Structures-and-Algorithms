// Function to print matrix in spiral order
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // int start = 0 ; 
        int m  = matrix.size() ;
        int n = matrix[0].size();
        
        
        int up = 0 , left = 0 ;
        int right = n -1;
        int down = m -1;
        
        // bool visited[n+1][m+1] ;
        int VISITED = 101 ;
        vector<int> ans ; 
        while(ans.size() < n * m){
            int i, j ;
            for(j = left ; j <= right; j++){
                ans.push_back(matrix[up][j]) ;
            }
             
            for(i = up+1; i <= down ;i++){
                ans.push_back(matrix[i][right]);
            }
            
            if (up != down){
                for(j = right-1; j >= left; j--){
                    ans.push_back(matrix[down][j]) ;
                }
            }
           
            if (left != right){
                for(i = down-1 ; i >up ; i-- ){
                    ans.push_back(matrix[i][left]);
                }
            }
            
            up ++ ;
            down -- ;
            left ++ ;
            right -- ;
        }
        return ans ;   
    }