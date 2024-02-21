//brute f
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      for(int i=0;i<nums.size()-1;i++){
          if(nums[i]==nums[i+1]) return nums[i];
      }
      return -1;
    }
};

//new approach Flyord(linked list cycle) +tortoise
class Solution {
public:
//new approach Using Floyd Cycle Detection Algorithm Of Linked List :
//as in tortoise ,their will we one slow and other fast pointer .
//here when our slow and fast pointer meets our while condition break .
//and nowonward their we will move fast pointer at start
//then compare both fast and slow pointer and move at first place where they meet .is our dublicate element. 
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        do{
        slow=nums[slow];
        fast=nums[nums[fast]];
        }while(slow!=fast);

        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        //you can return fast also both are same .
        return slow;
    }
};