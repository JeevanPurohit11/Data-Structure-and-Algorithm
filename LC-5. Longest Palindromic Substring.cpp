class Solution {
public:
    string longestPalindrome(string s) {
        //next time try using DP,in dp also TC- was 0(n^2) but SC-is 0(N);
       // but using below way TC was same But SC-0(1)
       //optimized way  
        if(s.size()<=1) return s;
        int n=s.size();
        int left,right;
          int start=0,end=0,max_len=1;
          //odd length of substring 
          for(int i=0;i<n-1;i++){
              left=i,right=i;
              while(left>=0 && right<n){
                  if(s[left]==s[right]){
                      left--;right++;
                  }else{
                      break;
                  }
              }  
          int len=right-left-1;
          if(len>max_len){
              max_len=len;
              start=left+1;
              end=right-1;
          }
          }
          //even length of substring
         for(int i=0;i<n-1;i++){
              left=i,right=i+1;
              while(left>=0 && right<n){
                  if(s[left]==s[right]){
                      left--;right++;
                  }else{
                      break;
                  }
              }   
      int   len=right-left-1;
          if(len>max_len){
              max_len=len;
              start=left+1;
              end=right-1;
          }
         }    
return s.substr(start,max_len);
         
    }
};