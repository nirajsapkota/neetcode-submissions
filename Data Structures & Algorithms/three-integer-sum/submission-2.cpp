class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        auto triplets = std::set<std::vector<int>>();
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        triplets.insert({ nums[i], nums[j], nums[k] });
                    }
                }
            }
        }
        return std::vector<std::vector<int>>(triplets.begin(), triplets.end());
    }
};
