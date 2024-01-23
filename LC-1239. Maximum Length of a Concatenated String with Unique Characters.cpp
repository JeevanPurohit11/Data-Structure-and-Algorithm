class Solution {
public:
//using DFS
//key point here we are using (pass by value) unordered_set<char>s 
int dfs(int currentIndex,string temp,unordered_set<char>s,vector<string>& arr,int n){
     //we are inserting arr[i]
     s.insert(temp.begin(),temp.end());
     //edge chance where arr element is dublicate example {(aa,bb)}) here set value will not equal temp .so we return 0;
     if(temp.length()!=s.size()){
         return 0;
     }
     int maxLen=temp.length();
     for(int i=currentIndex;i<n;i++){
         maxLen=max(maxLen,dfs(i+1,temp+arr[i],s,arr,n));
     }
     return maxLen;
}
    int maxLength(vector<string>& arr) {
        unordered_set<char>s;
        int n=arr.size();
        int maxi=dfs(0,"",s,arr,n);
        return maxi;
    }
};