//aditiya verma
class Solution {
public:
//the subsequence can we always 2^n where n is size of string here we also count "" empty string in our subsequence.

int dp[1001][1001];
int lcs(string& text1,string& text2,int n,int m){
    if(n==0 || m==0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    //here we get a subsequence same in both string ,also we add 1 as we get our one subsequence.
    if(text1[n-1]==text2[m-1]){
        dp[n][m]=1+lcs(text1,text2,n-1,m-1);
        return dp[n][m];
    }else{
         //here is 2 case either we keep n and reduce m-1
        // or either we keep m and reduce n-1 (ex. abcde ,xcdea) or(abcdw,xcpda);
       dp[n][m]=max(lcs(text1,text2,n-1,m),lcs(text1,text2,n,m-1));
       return dp[n][m];
    }
}
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        memset(dp,-1,sizeof(dp));
        return lcs(text1,text2,n,m);
        

    }
};