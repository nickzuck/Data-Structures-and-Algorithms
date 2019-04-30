// Topological sorting of graph nodes using dfs
// Algorithm taken from Cormen

#include<iostream>
#include<vector>
#include<list>

#define MAX 50

using namespace std ;

vector <int> adj[MAX] ; 
list <int> linkedList ;
bool visited[MAX] ;


/*Initialize the boolean values to the visited part ..Since no nodes got traversed till now */
void initialize(int nodes)
{
    for (int i = 1 ; i<=nodes ;i++){
        visited[i] = false ;        
    }
    linkedList.clear() ;
}

//to perform depth first search
void dfs(int current)
{
    cout << current << "\t";
    visited[current] = true ; 
    for(int i = 0 ; i< adj[current].size() ; i++){
        if (visited[adj[current][i]] == false){
            dfs(adj[current][i]) ;
        }
    }
    linkedList.push_front(current);
}
 
int main ()
{
    int nodes , edges , x , y  , i ; 
    cout << "Enter the total nodes in the graph\t" ;
    cin >> nodes ; 
    cout << "Enter the total edges of the graph\t" ;
    cin >> edges ;  
    cout << "Enter the edges pairs of the graph (eg : a b , for a->b)\n" ;
    for (i = 0 ; i <edges ; i++){
        cin >> x >> y ; 
        adj[x].push_back(y);
    }

    initialize(nodes) ; 
    
    cout << "The dfs traversal sequence is given as\n" ;
    for (i = 1 ; i<=nodes ; i++){
        if(visited[i] == false){
            dfs(i);
        }
    }

    cout << "\nThe topological sorted sequence is: " ;
    list<int>::iterator it ; 
    for (it = linkedList.begin() ; it != linkedList.end() ; ++it){
        cout << *it << " " ;
    }

return 0 ; 
}