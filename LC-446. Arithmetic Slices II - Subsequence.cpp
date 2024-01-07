//seen in coding dicoding 
//not done by me
class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& nums) {
        int ans = 0;
        int len = nums.size();
        std::vector<std::unordered_map<int, int>> map(len);

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = static_cast<long long>(nums[j]) - nums[i];
                if (diff <= INT_MIN || diff > INT_MAX) continue;

                int dif = static_cast<int>(diff);
                int n2 = map[i].count(dif) ? map[i][dif] : 0;
                int n1 = map[j].count(dif) ? map[j][dif] : 0;
                ans += n1;
                int freq = n1 + n2 + 1;
                map[i][dif] = freq;
            }
        }

        return ans;
    }
};