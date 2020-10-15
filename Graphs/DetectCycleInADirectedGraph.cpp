// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
 
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool cyclic(int i, int V, vector<int> adj[],bool visited[], bool inTheCall[])
{
    visited[i]=true;
    inTheCall[i]=true;
    for(int j =0;j<adj[i].size();j++)
    { 
        if(!visited[adj[i][j]] &&  cyclic(adj[i][j],V,adj,visited,inTheCall))
        {
            return true;
        }
        else{
            if(inTheCall[adj[i][j]])
            return true;
        }
    }
    inTheCall[i]=false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    bool visited[V];
    bool inTheCall[V];
    for(int  i=0;i<V;i++)
    {
        visited[i]=false;
        inTheCall[i]= false;
    }   
    for(int i =0;i<V;i++)
    {  if(!visited[i]){
      if(cyclic(i,V,adj,visited,inTheCall))
      return true;
    }
    }
    return false;
}
// { Driver Code Starts.
int main() 
{
	int t;
	cin >> t;
	while(t--){
	    int v, e;
	    cin >> v >> e;
	    vector<int> adj[v];
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    cout << isCyclic(v, adj) << endl;   
	return 0;
}  // } Driver Code Ends
