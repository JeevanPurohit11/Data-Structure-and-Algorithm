class Solution {
public:
//DP+MEMO
//using map get TLE only 22 case pass 
//used 2d vector to store element
//remember to take prevIndex+1 to store in vector because it will store negative key-value
int longLength(vector<int>& nums,int currentIndex,int prevIndex,vector<vector<int>>&dp){
   if(currentIndex == nums.size()){
      return 0;
   }

 //  string currentKey=to_string(currentIndex)+"#"+to_string(prevIndex);
   if(dp[currentIndex][prevIndex+1]!=-1){
       return dp[currentIndex][prevIndex+1];
   } 
   int consider=0;
   if(prevIndex==-1 || nums[currentIndex] > nums[prevIndex]){
     consider=1+ longLength(nums,currentIndex+1,currentIndex,dp);
   }
   int notConsider=0 + longLength(nums,currentIndex+1,prevIndex,dp);
  dp[currentIndex][prevIndex+1]=max(consider,notConsider);
  return dp[currentIndex][prevIndex+1];

}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
      vector<vector<int>>dp(n,vector<int>(n+1,-1));
       return longLength(nums,0,-1,dp);
    }
};