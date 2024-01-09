class Solution {
public:
//here we solve like atmost k subarray - atmost k-1 subarray.
int subArray(vector<int>& nums, int k){
    int count = 0, ans = 0, i = 0, j = 0;
        int n = nums.size();
        while(j<n){
            if(nums[j]%2!=0){
                count++;
            }
            while(count>k){
                if(nums[i]%2!=0){
                    count--;
                }
               i++;
            }
            ans += j-i+1;
            j++;
        }
        return ans;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
    //this is because if we have array like this 
    //arr=0,0,1,1,2,1,1,0,0
   // here when odd number==k ,there subarray was 3 instead of 1 i.e 0,0,1,1,2,1 || 0,1,1,2,1 || 1,1,2,1 .same for array end also.
     return subArray(nums, k) - subArray(nums,k-1);
    }
};