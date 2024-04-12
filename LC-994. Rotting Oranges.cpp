class Solution {
public:
//Same as  burn tree problem ?
//here we make queue which store index where grid ==2 (i,j) and time which initerally is 0.updating visited array also for grid=2 or 0. cnt and cntfresh if any fresh orange is left or not .vis[nRow][nCol]==0 &&grid[nRow][nCol]!=2 && grid[nRow][nCol]==1).alos update maxTime each time.
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int vis[n][m];
        int cntFresh=0;//(edge case -1)
        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }else{
                    vis[i][j]=0;
                }
                
                if(grid[i][j]==1) cntFresh++;
            }
        }
        //created for 4 side traversal.
        int dRow[]={-1,0,1,0};
        int dCol[]={0,1,0,-1};
        int cnt=0;
         int timeMax=0;
        while(!q.empty()){
               int r=q.front().first.first;
               int c=q.front().first.second;
               int time=q.front().second;
            timeMax=max(timeMax,time);
            q.pop();
               //4 direction traverse
               for(int i=0;i<4;i++){
                   int nRow =r+dRow[i];
                   int nCol= c+ dCol[i];
                   if(nRow < n && nRow>=0 && nCol>=0 && nCol <m && vis[nRow][nCol]==0 &&grid[nRow][nCol]!=2 && grid[nRow][nCol]==1){
                    q.push({{nRow,nCol},time+1});
                     vis[nRow][nCol]=2;
                     cnt++;
                   }
               }
         }
         if(cnt!=cntFresh) return -1;
         
          return timeMax;

    }
};