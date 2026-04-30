class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        auto triplets = std::vector<std::vector<int>>();

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (i == j || i == k || j == k) {
                        continue;
                    }
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        auto triplet = std::vector<int>{nums[i], nums[j], nums[k]};
                        std::sort(triplet.begin(), triplet.end());
                        if (!is_duplicate_triplet(triplets, triplet)) {
                            triplets.push_back(triplet);
                        }
                    }
                }
            }
        }

        return triplets;
    }

    bool is_duplicate_triplet(vector<vector<int>> const& triplets, vector<int> const& triplet) {
        for (auto const& existing_triplet : triplets) {
            if (triplet == existing_triplet) {
                return true;
            }
        }
        return false;
    }
};
