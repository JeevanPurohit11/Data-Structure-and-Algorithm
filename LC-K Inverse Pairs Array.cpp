class Solution {
public:
//approach in notes
int mod=1e9+7;
int pairs(int n,int k,vector<vector<int>>&dp){
    if(k<=0) return k==0;
    if(dp[n][k]!=-1){
        return dp[n][k];
    }
    int ans=0;
    for(int i=0; i<=k && i<n;i++){
        ans=(ans+ pairs(n-1,k-i,dp))%mod;
    }
    dp[n][k]=ans;
    return dp[n][k];

}
//memo 2
    int kInversePairs(int n, int k) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return pairs(n,k,dp);
    }
};