//using maxheap (nlogk)
class Solution {
public:
//Priority queue maxheap aditiya verma
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    //here  maxheap applied at first pair only bydefault (i.e) according to difference 
        priority_queue<pair<int,int>>maxHeap;
        for(int i=0;i<arr.size();i++){
            maxHeap.push({abs(arr[i]-x),arr[i]});
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        vector<int>ans;
        while(maxHeap.size()>0){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        //here using sort because in maxheap we only get nax element at top //not in sorted order 
        sort(ans.begin(),ans.end());
        return ans;

    }
};

//2nd approach 2 pointer(o(N))
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //2 pointer sliding window
        int left=0,right=arr.size()-1;

        while (right - left + 1 > k) {
            
            if (arr[right] - x < x - arr[left]) left++;
            else right--;
        }
        return vector<int>(arr.begin()+left,arr.begin()+right+1);
    }
};
//optimized
//3rd approach binary search(o(logn))
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lo = 0, hi = arr.size()-k;
        while (lo < hi){
            
            int mid = lo + (hi - lo)/2;
            if(x - arr[mid] > arr[mid + k] - x){
                lo = mid + 1;
            }else{
                hi = mid;
            }
            
        }
        
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(arr[lo+i]);
        }
        
        return ans;
        
    }
};