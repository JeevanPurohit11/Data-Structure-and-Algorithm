class Solution {
public:
//method1 bruteforce approach was right but TLE (brute forces)
    int subarraySum(vector<int>& nums, int k) {
    //     int sum;
    //     int count=0;
    //    for(int i=0;i<nums.size();i++){
    //        //this was done to find that the element itself is k then count++(below 3 line code)
    //      int  sum=nums[i];//we are not doing each time sum=0;for suming each i+1 to n loop  instead we are directly dong each of i as sum only at start.
    //        if(sum==k)
    //            count++;

    //        for(int j=i+1;j<nums.size();j++){
    //            sum+=nums[j];
    //            if(sum==k){
    //                count++;
    //            }
    //        }
    //    }
    //   return count; 
  

  //Here remember we are seeing the 
  //If the cumulative sum minus k is present in the hash table, increment count by the number of times that sum has occurred.
    int sum=0,count=0;
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++){
         sum+=nums[i];
         if(sum==k){
             count++;
         }
         //here we are seeing cumulative sum -k is present in map ,if yes then there exist subarray (we store such all sum subarray);
         if(mp.find(sum-k)!=mp.end()){
             count+=mp[sum-k];
         }
         mp[sum]++;
    }
    return count;
    }  
};
//3rd approach (prefix sum);