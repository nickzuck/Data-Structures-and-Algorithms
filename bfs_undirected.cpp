[UNTESTED] [COMPILED]
/*For un-directed graph*/
#include<iostream>
#include<vector>
#include<queue>

#define MAX 100

using namespace std ; 

vector<int> adj[MAX] ; 
bool visited[MAX] ;
queue<int> q ;

void initialize(int  nodes){
	for (int i = 1; i<=nodes ;i++){
		visited[i] = false ;
	}
}

void bfs(int current){
	if(visited[current] == false){
		for(int i = 0; i<adj[current].size() ; i++){
			if (visited[i] == false){
				q.push(i) ;
			}
		}
	}
	int next = q.front(); 
	q.pop();
	if (visited[next] == false)
		bfs(next) ;
}
int main ()
{
	int nodes , edges , i , x , y ; 
	cout  << "Enter the number of nodes\t" ; 
	cin >> nodes ; 
	cout << "Enter the total number of edges\t" ; 
	cin >> edges ; 

	cout <<"Enter the edges pairs of the graph (eg : a b , for a-b)\n";
	
	for (i = 0; i<edges ;i++){
		cin >> x >> y ; 
		adj[x].push_back(y) ; 
		adj[y].push_back(x) ;
	}

	initialize(nodes) ;
	
	cout << "Breadth first traversal\n";
	for (int i = 1 ; i<=nodes ;i++){
		bfs(i) ;
	}	
	
return 0 ; 
}