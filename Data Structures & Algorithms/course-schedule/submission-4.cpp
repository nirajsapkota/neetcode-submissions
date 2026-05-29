enum class State {
    UNVISITED = 0,
    VISITING = 1,
    VISITED = 2,
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        auto graph = std::unordered_map<int, std::vector<int>>();
        for (auto const& edge : prerequisites) {
            auto a = edge[0];
            auto b = edge[1];
            graph[b].push_back(a);
        }

        auto states = std::vector<State>(numCourses, State::UNVISITED);
        for (int i = 0; i < numCourses; i++) {
            if (!canTakeCourse(graph, i, states)) {
                return false;
            }
        }

        return true;
    }

    auto canTakeCourse(
        std::unordered_map<int, std::vector<int>>& graph, 
        int course,
        std::vector<State>& states
    ) -> bool {
        auto s = std::stack<std::pair<int, bool>>();
        s.push({ course, false });
        while (!s.empty()) {
            auto [current, processed] = s.top();
            s.pop();

            if (processed) {
                states[current] = State::VISITED;
                continue;
            }

            if (states[current] == State::VISITING) {
                return false;
            }

            if (states[current] == State::VISITED) {
                continue;
            }

            states[current] = State::VISITING;
            s.push({ current, true });

            for (auto const neighbor : graph[current]) {
                s.push({ neighbor, false });
            }
        }
        return true;
    }
};
