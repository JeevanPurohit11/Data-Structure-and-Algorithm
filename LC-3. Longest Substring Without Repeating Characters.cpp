class Solution {
public:
//Same as longest Subarray with K unique character 
//also here our greater mp.size()>j-i+1 not work as mp.size() can never we greater than window 
//so it not requiered.
//slight variation
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i=0,j=0,ans=0;
        while(j<s.size()){
            mp[s[j]]++;
            //Just here we are taking the (j-i+1) instead of K in previous question .
            //here the logic is to when mp.size() ans j-i+1 will same ,then there will be all unique character in that particular window.
             //as you can se the number of char store in mp is always distinct just the count is increasing.
              if(mp.size()==j-i+1){
                 ans=max(ans,j-i+1);
                   
              }else if(mp.size()<j-i+1 ){
                  while(mp.size()<j-i+1 && mp.size()>0){
                      mp[s[i]]--;
                      if(mp[s[i]]==0){
                          mp.erase(s[i]);
                      }
                      i++;
                  }
                 
              }
              j++;
        }
        return ans;
    }
};