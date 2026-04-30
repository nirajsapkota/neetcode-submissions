class Solution {
public:
    int findMin(vector<int> &nums) {
        auto i = 1;
        auto cur = nums[0];
        while (i < nums.size()) {
            if (nums[i] < cur) {
                return nums[i];
            }
            i++;
        }
        return cur;
    }
};
