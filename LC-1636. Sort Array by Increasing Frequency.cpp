//Priority queue aditiya verma
class Solution {
public:
//same as k frequent element (LC)
//new thing done.
//here at the time we adding i.second in maxheap we add negative(freq count) 
//and at last while  poping element we run for loop there we set range with negation freq.
//which overall make our freq positive 
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto i: nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>>maxHeap;
        for(auto i : mp){
            maxHeap.push({-i.second,i.first});
        }
        while(maxHeap.size()>0){
            for(int i=0;i< -maxHeap.top().first;i++){
                ans.push_back(maxHeap.top().second);
            }
            maxHeap.pop();
        }
        return ans;
    }
};