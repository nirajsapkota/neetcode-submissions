class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            if (nums[0] < nums[1]) return nums[0];
            return nums[1];
        }

        auto middle = nums.size() / 2;
        if (should_choose_left(nums)) {
            auto left = std::vector<int>(nums.begin(), nums.begin() + middle + 1);
            std::cout << "choose left";
            print_vec(left);
            return findMin(left);
        }

        auto right = std::vector<int>(nums.begin() + middle, nums.end());
        std::cout << "choose right";
        print_vec(right);
        return findMin(right);
    } 

    bool should_choose_left(vector<int> &nums) {
        auto middle = nums.size() / 2;
        auto left_extreme = nums[0];
        auto left_neighbour = nums[middle - 1];
        auto right_neighbour = nums[middle + 1];
        auto right_extreme = nums[nums.size() - 1];
        if (left_neighbour < right_neighbour && left_neighbour < right_extreme) {
            return true;
        }
        if (left_extreme < right_neighbour && left_extreme < right_extreme) {
            return true;
        }
        return false;
    }

    void print_vec(std::vector<int> const& v) {
        std::cout << "vec: ";
        for (auto const &e : v) {
            std::cout << e << ", ";
        }
        std::cout << std::endl;
    }
};
