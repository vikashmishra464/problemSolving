// Strongly Connected Components (Kosaraju's Algo)
// SSC -> it is subgraph in which you can travel from every node to every node.
//Kosaraju Algo -> It is bascially a algo used to solve the ssc problem ..
//there are step to solve this problem 
//Step 1 -> Sort the graph (Topological sort)
//Step 2 -> Transpose the graph
// Step 3 -> Use DFS to traverse the graph on the bases of topological sort elements

// Solution:

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void topologicalSort(unordered_map<int,vector<int>>&m,int source,
	vector<int>&ts,vector<int>&vis){
	    vis[source]=1;
	    for(auto i:m[source]){
        
	        if(vis[i]==0){
	            topologicalSort(m,i,ts,vis);
	        }
	    }
	    ts.push_back(source);
	}
	void DFS(unordered_map<int,vector<int>>&m,vector<int>&vis,int source){
	    vis[source]=1;
	    for(auto i:m[source]){
	        if(vis[i]==0){
	            DFS(m,vis,i);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        
        //Step 1--> Topological Sort
        
        vector<int>vis(V,0);
        unordered_map<int,vector<int>>m;
        for(int i=0;i<V;i++){
            for( auto j:adj[i]){
                m[i].push_back(j);
            }
        }
        vector<int>ts;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                topologicalSort(m,i,ts,vis);
                }
        }
        
        //Step 2--> Transpose of the graph
        
        unordered_map<int,vector<int>>mt;
        for(int i=0;i<V;i++){
            for( auto j:adj[i]){
                mt[j].push_back(i);
            }
        }
        
        //Step 3 --> Dfs on the bases of the order
        
        fill(vis.begin(),vis.end(),0);
        int ssc=0;
        for(int i=ts.size()-1;i>=0;i--){
            if(vis[ts[i]]==0){
                DFS(mt,vis,ts[i]);
                ssc++;
            }
        }
        return ssc;
        
        
    }
};