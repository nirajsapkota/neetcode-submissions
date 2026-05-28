class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        auto islands = 0;
        auto visited = std::set<std::tuple<int, int>>();

        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                auto cell = grid[row][col];
                if (cell == '0') continue;
                if (visited.contains({ row, col })) continue;
                explore_island(row, col, grid, visited);
                islands++;
            }
        }

        return islands;
    }

    auto explore_island(
        int row,
        int col,
        std::vector<std::vector<char>> const& grid,
        std::set<std::tuple<int, int>>& visited
    ) -> void {
        auto q = std::queue<std::tuple<int, int>>();
        q.push({ row, col });
        for (; !q.empty(); q.pop()) {
            auto [row, col] = q.front();
            if (visited.contains({ row, col })) continue;
            visited.insert({ row, col });
            if (row + 1 < grid.size() && grid[row + 1][col] == '1') q.push({ row + 1, col });
            if (row - 1 >= 0 && grid[row - 1][col] == '1') q.push({ row - 1, col });
            if (col + 1 < grid[row].size() && grid[row][col + 1] == '1') q.push({ row, col + 1 });
            if (col - 1 >= 0 && grid[row][col - 1] == '1') q.push({ row, col - 1 });
        }
    }
};
