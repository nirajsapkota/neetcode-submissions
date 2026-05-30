class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        auto visited = std::set<std::pair<int, int>>();
        auto islands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '0') continue;
                if (visited.contains({ i, j })) continue;
                dfs(grid, visited, i, j);
                islands++;
            }
        }
        return islands;
    }

    auto dfs(std::vector<std::vector<char>>& grid, std::set<std::pair<int, int>>& visited, int i, int j) -> void {
        auto s = std::stack<std::pair<int, int>>();
        s.push({ i, j });
        while (!s.empty()) {
            auto current = s.top();
            s.pop();

            auto r = current.first;
            auto c = current.second;

            if (visited.contains(current)) continue;
            visited.insert(current);

            if (r - 1 >= 0 && grid[r - 1][c] == '1') s.push({ r - 1, c });
            if (r + 1 < grid.size() && grid[r + 1][c] == '1') s.push({ r + 1, c });
            if (c - 1 >= 0 && grid[r][c - 1] == '1') s.push({ r, c - 1 });
            if (c + 1 < grid[r].size() && grid[r][c + 1] == '1') s.push({ r, c + 1 });
        }
    }
};
