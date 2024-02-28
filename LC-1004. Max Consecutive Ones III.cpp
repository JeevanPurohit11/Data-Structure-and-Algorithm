class Solution {
public:
//we totally focus on zeros ,our window will slide when the zeroCount>k we decrease our window from that point 
// i to j =new window (sliding window)
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int zeroCount=0,maxi=INT_MIN;
        while(j<nums.size()){
            if(nums[j]==0){
                zeroCount++;
            }
            while(zeroCount>k){
                    if(nums[i]==0){
                        zeroCount--;
                    }
                    i++;
                }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};