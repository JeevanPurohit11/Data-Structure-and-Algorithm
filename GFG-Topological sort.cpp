//find indegree of all V
//if indegree==0 push into queue.
//traversal over all indegree 0 element/node.
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    
	     int indegree[V]={0};
	     for(int i=0;i<V;i++){
	          for(auto j : adj[i]){
	              indegree[j]++;
	          }
	      }
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	      
	      vector<int>topo;
	      while(!q.empty()){
	          int top= q.front();
	          q.pop();
	          topo.push_back(top);
	          
	          for(auto i : adj[top]){
	              indegree[i]--;
	              if(indegree[i]==0) q.push(i);
	          }
	      }
	      return topo;
	    
	}
};
