//dfs

class Solution {
public:
void dfs(vector<bool>&vis,int i,vector<vector<int>>& isConnected,int n){
     if(vis[i]==true){
        return ;
     }
     vis[i]=true;
     for(int j=0;j<n;j++){
        if(!vis[j] && isConnected[i][j]==1){
            dfs(vis,j,isConnected,n);
        }
     }
     return;

}
    int findCircleNum(vector<vector<int>>& isConnected) {
         int n=isConnected.size();
         int cnt=0;
         vector<bool>vis(n,false);
         for(int i=0;i<n;i++){
                if(!vis[i]){
                    dfs(vis,i,isConnected,n);
                    cnt++;
                }
         }
         return cnt;
        }
};

//BFS
class Solution {
public:
void bfs(vector<bool>&visited,int currentcity,vector<vector<int>>& isConnected,int n){
 //   queue<Node*>q can also we work for adjacent list.;
    queue<int>q;
  q.push(currentcity);
  while(!q.empty()){
      //we are using current vertex/currentcity for visited array comparison only  
          int currentvertex=q.front();
          q.pop();
          if(visited[currentvertex]){
              continue;
          }
          visited[currentvertex]=true;

          for(int i=0;i<n;i++){
              if(!visited[i] && isConnected[currentvertex][i]==1){
                      q.push(i);
              }
          }
  }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
       // using BFS
       int n=isConnected.size(),count=0;
       vector<bool>visited(n,false);
       for(int i=0;i<n;i++){
           if(!visited[i]){
              count++;
              bfs(visited,i,isConnected,n);
           }
       }
return count;
    }
};