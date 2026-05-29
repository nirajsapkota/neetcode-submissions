class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        auto graph = std::unordered_map<int, std::vector<int>>();
        for (auto const& edge : edges) {
            auto a = edge[0];
            auto b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        auto s = std::stack<std::pair<int, int>>();
        auto v = std::unordered_set<int>();
        s.push({0, - 1});

        while (!s.empty()) {
            auto [current, parent] = s.top();
            s.pop();

            if (v.contains(current)) return false;
            v.insert(current);

            for (auto const& neighbor : graph[current]) {
                if (neighbor == parent) continue;
                s.push({ neighbor, current });
            }
        }

        return n == v.size();
    }
};
