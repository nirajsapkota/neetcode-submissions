class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        auto triplets = std::vector<std::vector<int>>();
        auto seen_triplets = std::set<std::vector<int>>();
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (i == j || i == k || j == k) {
                        continue;
                    }
                    if (nums[i] + nums[j] + nums[k] != 0) {
                        continue;
                    }
                    auto triplet = std::vector<int>{nums[i], nums[j], nums[k]};
                    std::sort(triplet.begin(), triplet.end());
                    if (!seen_triplets.contains(triplet)) {
                        triplets.push_back(triplet);
                        seen_triplets.insert(triplet);
                    }
                }
            }
        }

        return triplets;
    }
};
