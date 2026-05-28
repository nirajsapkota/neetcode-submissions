class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        auto cells = std::vector<std::vector<int>>();
        for (int r = 0; r < heights.size(); r++) {
            for (int c = 0; c < heights[r].size(); c++) {
                if (can_flow(heights, r, c)) {
                    cells.push_back(std::vector<int>{{r, c}});
                }
            }
        }
        return cells;
    }

    auto can_flow(
        std::vector<std::vector<int>> const& heights,
        int start_r,
        int start_c
    ) -> bool {
        auto borders_pacific = false;
        auto borders_atlantic = false;

        auto q = std::queue<std::pair<int, int>>();
        auto v = std::set<std::pair<int, int>>();
        q.push({ start_r, start_c });
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (v.contains({ r, c })) continue;
            v.insert({ r, c });

            if (r == 0 || c == 0) {
                borders_pacific = true;
            }
            if (r == heights.size() - 1 || c == heights[r].size() - 1) {
                borders_atlantic = true;
            }

            if (r - 1 >= 0 && heights[r - 1][c] <= heights[r][c]) {
                q.push({ r - 1, c });
            }
            if (r + 1 < heights.size() && heights[r + 1][c] <= heights[r][c]) {
                q.push({ r + 1, c });
            }
            if (c - 1 >= 0 && heights[r][c - 1] <= heights[r][c]) {
                q.push({ r, c - 1 });
            }
            if (c + 1 < heights[r].size() && heights[r][c + 1] <= heights[r][c]) {
                q.push({ r, c + 1 });
            }
        }

        return borders_pacific && borders_atlantic;
    }
};
