class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        auto islands = std::vector<std::vector<std::tuple<int, int>>>();
        auto visited = std::set<std::tuple<int, int>>();

        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                auto cell = grid[row][col];
                if (cell == '0') continue;
                if (visited.contains({ row, col })) continue;
                islands.push_back(explore_island(row, col, grid, visited));
            }
        }

        return islands.size();
    }

    auto explore_island(
        int row,
        int col,
        std::vector<std::vector<char>> const& grid,
        std::set<std::tuple<int, int>>& visited
    ) -> std::vector<std::tuple<int, int>> {
        auto island = std::vector<std::tuple<int, int>>();
        auto q = std::queue<std::tuple<int, int>>();
        q.push({ row, col });
        for (; !q.empty(); q.pop()) {
            auto [row, col] = q.front();
            if (visited.contains({ row, col })) continue;
            visited.insert({ row, col });
            island.push_back({ row, col });

            if (row + 1 < grid.size() && grid[row + 1][col] == '1') {
                q.push({ row + 1, col });
            }
            if (row - 1 >= 0 && grid[row - 1][col] == '1') {
                q.push({ row - 1, col });
            }
            if (col + 1 < grid[row].size() && grid[row][col + 1] == '1') {
                q.push({ row, col + 1 });
            }
            if (col - 1 >= 0 && grid[row][col - 1] == '1') {
                q.push({ row, col - 1 });
            }
        }
        return island;
    }
};
