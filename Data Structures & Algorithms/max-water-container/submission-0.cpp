class Solution {
public:
    int maxArea(vector<int>& heights) {
        auto left = 0;
        auto right = heights.size() - 1;

        auto max = 0;
        while (left < right) {
            auto left_height = heights[left];
            auto right_height = heights[right];
            auto shortest_bar = std::min(left_height, right_height);
            auto dist_between_bars = right - left;
            auto container_size = shortest_bar * dist_between_bars;
            if (container_size > max) {
                max = container_size;
            }
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max;
    }
};
