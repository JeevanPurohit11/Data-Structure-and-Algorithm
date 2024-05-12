class Solution {
public:
//after the arr is sorted and at the time of merging we will see the 2 array start index is it was same then we directly all element on the left .and if not then we will increase our left index from arr1 and again check for right element in our arr 2 
int merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int cnt = 0; // Count of reverse pairs

    // Counting the reverse pairs
    while (left <= mid && right <= high) {
        if ((long long)nums[left] > 2 * (long long)nums[right]) {
            cnt += (mid - left + 1);
            right++;
        } else {
            left++;
        }
    }

    // Merging the arrays
    left = low;
    right = mid + 1;
    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        } else {
            temp.push_back(nums[right]);
            right++;
        }
    }
    while (left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(nums[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }

    return cnt;
}
    int mergeSort(vector<int>& nums, int low, int high) {
        int cnt = 0;
        if (low>=high) return 0;
        int mid = low + (high - low) / 2;
        cnt+= mergeSort(nums, low, mid);
        cnt+= mergeSort(nums, mid + 1, high);
        cnt += merge(nums, low, mid, high);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};
