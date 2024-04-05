//4 approach
//linear search,sorting,map,set

class Solution {
public:
//brute force= linear solution
    int longestConsecutive(vector<int>& nums) {
       //better solution (sorting logic ex. 1,1,1,2,2,2,123,124,125,125,126,127)
       //3 thing when 2 element equal we do nothing,when lastsamller same as nums[i]-1 we increment and if not we reset values
       if(nums.size()==0) return 0;
       sort(nums.begin(),nums.end());
       int cnt=1,lastSmaller=INT_MIN;
       int maxi=INT_MIN;
       for(int i=0;i<nums.size();i++){
            if(nums[i]-1==lastSmaller){
                cnt++;
                lastSmaller=nums[i];
            }else if(nums[i]!=lastSmaller){
                cnt=1;
                lastSmaller=nums[i];
            }
            maxi=max(maxi,cnt);
       }
return maxi;
    }
};

class Solution {
public:
//brute force= linear solution
    int longestConsecutive(vector<int>& nums) {
       //optimized solution (set logic ex. 102 ,4,101,1,100,3,2 )
       if(nums.size()==0) return 0;
        set<int>st;
        int longest=1;
        for(auto i : nums) st.insert(i);

        for(auto i : st){
            //first we see if that element not find //thatis we get minimum value of x.
            if(st.find(i-1)==st.end()){
                int cnt=1;
                int currValue=i;
                while(st.find(currValue+1)!=st.end()){
                    cnt++;
                    currValue+=1;
                }                
              longest=max(longest,cnt);
            }
        }
        return longest;
    }
};