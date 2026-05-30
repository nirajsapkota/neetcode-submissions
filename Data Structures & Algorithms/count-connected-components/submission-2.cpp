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
        
        auto components = 0;
        auto visited = std::vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            if (visited[i] == 1) continue;
            dfs(graph, visited, i);
            components++;
        }

        return components;
    }

    auto dfs(
        std::unordered_map<int, std::vector<int>>& graph,
        std::vector<int>& visited,
        int start
    ) -> void {
        auto s = std::stack<int>();
        s.push(start);
        while (!s.empty()) {
            auto current = s.top();
            s.pop();

            if (visited[current] == 1) continue;
            visited[current] = 1;
            
            for (auto const& neighbor : graph[current]) {
                s.push(neighbor);
            }
        }
    }
};
