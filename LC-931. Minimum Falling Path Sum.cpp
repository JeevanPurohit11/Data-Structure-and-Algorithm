class Solution {
public:
//DP MEMO 
//key point for last test case is we intialized our dp vector to INT_MIN
// This is happening because -1 can also be considered in taking the min sum so its deviating the answer hence we'd taken INT_MIN to initialise the dp.
//Using mod for when currentCol index goes out of bound
int mod = 1e9 + 7;
int dfs(int currentRow,int currentCol,int row,int col,vector<vector<int>>&dp,vector<vector<int>>& matrix){
  if(currentCol<0 || currentCol>col-1){
    return mod;
  }
   if(currentRow==0){
      return matrix[currentRow][currentCol];
  }
    if(dp[currentRow][currentCol]!=INT_MIN){
      return dp[currentRow][currentCol];
    }
 

  int up=matrix[currentRow][currentCol] + dfs(currentRow-1,currentCol,row,col,dp,matrix);
  int upLeft=matrix[currentRow][currentCol] + dfs(currentRow-1,currentCol-1,row,col,dp,matrix);
  int upRight=matrix[currentRow][currentCol] + dfs(currentRow-1,currentCol+1,row,col,dp,matrix);
  dp[currentRow][currentCol]=min(up,min(upLeft,upRight));
  return dp[currentRow][currentCol];
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
      int ans=INT_MAX;
      vector<vector<int>>dp(row,vector<int>(col,INT_MIN));
    for(int j=0;j<col;j++){
        
        ans=min(ans,dfs(row-1,j,row,col,dp,matrix));
    }
    return ans;
    }
};