class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto pivot_index = find_pivot_index(nums);

        auto target_index = binary_search(nums, 0, pivot_index, target);
        if (target_index != -1) {
            return target_index;
        }
        return binary_search(nums, pivot_index, nums.size() - 1, target);
    }

    int find_pivot_index(vector<int>& nums) {
        auto l = 0;
        auto r = nums.size() - 1;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (nums[mid] <= nums[r]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    int binary_search(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            auto mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};
