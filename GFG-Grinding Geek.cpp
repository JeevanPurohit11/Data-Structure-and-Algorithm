class Solution{
    public:
    int maxCors(int currentIndex,vector<int> &cost,int n,int total,vector<vector<int>>&dp){
        if(currentIndex>=n){
            return 0;
        }
        if(dp[currentIndex][total]!=-1){
            return dp[currentIndex][total];
        }
        int consider=0;
        if(cost[currentIndex]<=total){
            consider=1+maxCors(currentIndex+1,cost,n,total+(floor)(cost[currentIndex]*(0.9))-cost[currentIndex],dp);
        }
        int notConsider=maxCors(currentIndex+1,cost,n,total,dp);
        dp[currentIndex][total]=max(consider,notConsider);
        return dp[currentIndex][total];
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        
           vector<vector<int>>dp(n,vector<int>(total+1,-1));
        return maxCors(0,cost,n,total,dp);
    }
}