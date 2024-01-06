class Solution {
public:
//still have doublt same as MAXIMUM OF ALL SUBSARRY of SIZE K GFG (Aditiya verma)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     std::deque<int> dq;  // Using deque instead of list
    std::vector<int> ans;
    int i = 0, j = 0;

    while (j < nums.size()) {

        while (dq.size()>0 && nums[j] > dq.back()) {
            dq.pop_back();
        }
        dq.push_back(nums[j]);

        if (j - i + 1 < k) {
            j++;
        } else if (j - i + 1 == k) {
            ans.push_back(dq.front());

            if (nums[i] == dq.front()) {
                dq.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
    }
};