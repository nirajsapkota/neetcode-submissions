/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto head = select_next_node(lists);

        auto it = head;
        while (!lists.empty()) {
            it->next = select_next_node(lists);
            it = it->next;
        }

        return head;
    }

    auto select_next_node(vector<ListNode*>& lists) -> ListNode* {
        sanitize_list(lists);
        sort_nodes(lists);
        return get_min_node(lists);
    }

    auto sanitize_list(vector<ListNode*>& lists) -> void {
        auto eraser = [](ListNode* n) { return n == nullptr; };
        std::erase_if(lists, eraser);
    }

    auto sort_nodes(vector<ListNode*>& lists) -> void {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val < b->val; };
        std::sort(lists.begin(), lists.end(), cmp);
    }

    auto get_min_node(vector<ListNode*>& lists) -> ListNode* {
        if (lists.size() == 0) {
            return nullptr;
        }

        auto head = lists[0];
        auto next = head->next;
        head->next = nullptr;
        lists[0] = next;
        return head;
    }

    auto print(vector<ListNode*>& lists) -> void {
        std::cout << "lists=[";
        for (auto const& head : lists) {
            std::cout << "[";
            auto it = head;
            while (it != nullptr) {
                std::cout << it->val << ",";
                it = it->next;
            }
            std::cout << "]";
        }
        std::cout << "]\n";
    }
};
