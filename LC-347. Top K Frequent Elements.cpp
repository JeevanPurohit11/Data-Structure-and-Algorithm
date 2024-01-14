//using minHeap(new )
class Solution {
public:
//3 step using heap
// i) store key value in unordered_map
//ii).store key value pair inside minheap (according to frequency)
//iii) then store rest element element.(Note here we print /store arr[i] element i.e i.second or minheap and i.first for mp)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto i: nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;

        for(auto i : mp){
            minHeap.push({i.second,i.first});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        vector<int>ans;
        while(minHeap.size()>0){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
return ans;
    }
};