class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        auto graph = std::unordered_map<int, std::vector<int>>();
        for (auto const& edge : edges) {
            auto a = edge[0];
            auto b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        auto components = std::vector<std::unordered_set<int>>();
        for (int i = 0; i < n; i++) {
            auto explored = dfs(graph, i);

            auto exists = false;
            for (auto const& component : components) {
                if (explored == component) {
                    exists = true;
                    break;
                }
            }

            if (!exists) {
                components.push_back(explored);
            }
        }

        return components.size();
    }

    auto dfs(std::unordered_map<int, std::vector<int>>& graph, int start) -> std::unordered_set<int> {
        auto s = std::stack<int>();
        auto v = std::unordered_set<int>();
        s.push(start);
        while (!s.empty()) {
            auto current = s.top();
            s.pop();
            if (v.contains(current)) continue;
            v.insert(current);
            for (auto const& neighbor : graph[current]) {
                s.push(neighbor);
            }
        }
        return v;
    }
};
