class Solution {
public:
    bool canJump(vector<int>& nums) {
        auto positions = std::queue<int>();
        positions.push(0);
        
        for (; !positions.empty(); positions.pop()) {
            auto position = positions.front();
            if (position >= nums.size() - 1) return true;
            auto maxJumpFromPosition = nums[position];
            while (maxJumpFromPosition > 0) {
                positions.push(position + maxJumpFromPosition);
                maxJumpFromPosition--;
            }
        }

        return false;
    }
};
