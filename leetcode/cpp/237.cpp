#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        // start and copy the next value
        while(node->next != nullptr) {
            ListNode * remNext = node->next;
            node->val = node->next->val;
            if (node->next->next == nullptr) {
                node->next = nullptr;
            }
            node = remNext;
        }
    }
};