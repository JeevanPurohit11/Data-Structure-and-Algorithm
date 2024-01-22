class Solution {
public:
//Binary Search
long long findTime(vector<int>& piles,int h,int mid){
    long long sum=0;
    for(int i=0;i<piles.size();i++){
        //here we can also be use ceil  //sum += ceil(static_cast<double>(piles[i]) / mid);
        //but instead this is nice approach 
        //we get here ceil value 
         sum += (piles[i] + mid - 1) / mid;
    }
    return sum;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
       int start=1,end=piles[n-1];
  int ans=-1;
       while(start<=end){
        int mid=start + (end - start) / 2;
                  long long requiredTime=findTime(piles,h,mid);
                  if(requiredTime<=h){
                      //it will always be a smaller value because here we are moving in let only  
                      ans=mid;
                      end=mid-1;
                  }else if(requiredTime>h){
                      start=mid+1;
                  }
       }
       return ans;

    }
};