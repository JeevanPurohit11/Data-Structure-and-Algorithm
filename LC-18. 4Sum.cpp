//optimized

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size(); 
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            if(j>1 && nums[j]==nums[j-1] && j-1!=i) continue;
            int l=j+1;
            int k=n-1;
          while(l<k){
             long long  sum=(long long)nums[i]+nums[j]+nums[l]+nums[k];
            if(sum>target){
  //if we want to decrease our sum so surely we have to decrease k instead of j increment
                k--;
            }else if(sum <target ){
  //if we want to increase our sum so surely we have to increase j instead of k decrement
                 l++;
            }else{
               //here it will surely be a sorted 3 integer those sum==0
               vector<int>temp={nums[i],nums[j],nums[l],nums[k]};
               ans.push_back(temp);
               l++;
               k--;
               //here also the case that if nums[k--] still same then nums[k] value so we not have to considered that value same for nums[j--] ans nums[j];//so we increase there index accordingly ;
               while(l<k && nums[l]==nums[l-1]) l++;
               while(l<k && nums[k]==nums[k+1]) k--;

            }
          }
          }
        }
        return ans;
    }
};