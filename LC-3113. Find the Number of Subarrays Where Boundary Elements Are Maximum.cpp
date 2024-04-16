class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
       vector<pair<int,int>> ans;
        long long res = 0;
        for(int i = 0; i < nums.size(); i++){
            // if previous elements are lesser than nums[i] then it's not important bcz 
            // now they can't make any subarray.
            while(!ans.empty() && ans.back().first < nums[i]){
                ans.pop_back();
            }   
            // if it's same number as previous one than we will increase frequency of 
            // that number indicating 'subarrays are increasing' 
           if(!ans.empty() && ans.back().first==nums[i]){
               ans.back().second++;
           }else{
               ans.push_back({nums[i],1});
           }

            // last add the last frequency to answer
           res+=ans.back().second;
        }
        return res;
    }
};