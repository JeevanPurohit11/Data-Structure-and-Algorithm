class Solution {
public:
//sliding window aditiya verma
//hard sliding 
    string minWindow(string s, string t) {
        string ans="";
        unordered_map<int,int>mp;
        int i=0,j=0;
        for(auto i: t){
            mp[i]++;
        }
        int count=mp.size(),start=0,mini=INT_MAX;
        while(j<s.size()){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;
                }
            }
            if(count==0){
                while(count==0){
                     if(mp.find(s[i])!=mp.end()){
                         mp[s[i]]++;
                         if(mp[s[i]]==1){
                             count++;
                         }
                         if(j-i+1<mini){
                             mini=j-i+1;
                             start=i;
                         }
                     }   
                     i++;    
                }
            }
            j++;
        }
        if(mini==INT_MAX) return ans;
        else return s.substr(start,mini);
    }
};