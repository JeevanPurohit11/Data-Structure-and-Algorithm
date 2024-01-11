Variation of LC-239 //using map only 
//try using sliding window

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
 unordered_map<int,int>mp;
 int sum=0,ans=0;
 //To handle the Edge case to find length where 1st time get (sum-k)=0 starting place get .nsubsarry divisble by K
 //( for that condition i-mp[0] =length)  
 mp[0]=-1;
 for(int i=0;i<N;i++){
     sum+=A[i];
    if(mp.find(sum)==mp.end()){
      mp[sum]=i;   
    }
     if(mp.find(sum-K)!=mp.end()){
         ans=max(ans,i-mp[sum-K]);
     }
 }
 return ans;
}
};


