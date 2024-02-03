class Solution {
public:
//striver  front partition
int dp[500];
int largestSum(int currentIndex,vector<int>& arr, int k,int n){
    if(currentIndex>=arr.size()){
        return 0;
    }
    if(dp[currentIndex]!=-1){
        return dp[currentIndex];
    }
    int len=0,maxi=INT_MIN,maxSum=0;
    for(int i=currentIndex;i < min(currentIndex+k,n);i++){
         len++;
         maxi=max(maxi,arr[i]);
        int sum=(len*maxi)+largestSum(i+1,arr,k,n);
         maxSum=max(maxSum,sum);
    }
    dp[currentIndex]=maxSum;
    return dp[currentIndex];
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        int n=arr.size();
        return largestSum(0,arr,k,n);
      
    }
};