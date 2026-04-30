class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto seen = std::unordered_map<int, int>();
        for (int i = 0; i < nums.size(); i++) {
            auto complement = target - nums[i];
            if (seen.contains(complement)) {
                return std::vector<int>{seen.at(complement), i};
            }
            seen.insert({ nums[i], i }); 
        }
        return std::vector<int>();
    }
};
