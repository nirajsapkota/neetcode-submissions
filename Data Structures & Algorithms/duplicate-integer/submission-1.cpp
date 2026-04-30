class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        auto seen = std::unordered_set<int>();
        for (auto const& num : nums) {
            if (seen.contains(num)) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};