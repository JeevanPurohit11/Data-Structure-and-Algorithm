class Solution {
public:
//slight change compare to combination sum I
void comSum(int ind,int sum,vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&temp,int n){
  if(sum==target){
      ans.push_back(temp);
      return;
  }else if(sum>target){
      return;
  }  
  for(int i=ind;i<n;i++){
      //here if i!=ind for 2 same element not include (i.e ) same element like 2 2 2 .. or 1,1,1 here 1 repeated.because there was only 2 ones .(in comSum I we are including sigle element multiple time .here not ,(that was only change in this question))
      if(i!=ind && candidates[i]==candidates[i-1]){
          continue;
      }
      sum+=candidates[i];
      temp.push_back(candidates[i]);
      comSum(i+1,sum,candidates,target,ans,temp,n);
      sum-=candidates[i];
      temp.pop_back();
  }

}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<vector<int>>ans;
       sort(candidates.begin(),candidates.end());
     //  int sum=0;
       int n=candidates.size();
       vector<int>temp;
       comSum(0,0,candidates,target,ans,temp,n);
       return ans; 
    }
};