class Solution {
public:
    int findPeak(vector<int> &nums, int l, int r) {
        int mid = l + (r-l)/2;
        int left = mid == 0 ? INT_MIN : nums[mid-1];
        int right = mid == nums.size()-1? INT_MIN : nums[mid+1];
        int cur = nums[mid];
        
        if(cur < left) {
            return findPeak(nums, l, mid);
        }
        if(cur<right) {
            return findPeak(nums, mid, r);
        }
        return mid;
    }
    int findPeakElement(vector<int>& nums) {
          return findPeak(nums, 0, nums.size());
    }
};