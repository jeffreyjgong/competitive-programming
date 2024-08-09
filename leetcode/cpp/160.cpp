#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == headB) {
            return headA;
        }
        unordered_set<ListNode*> seen;

        ListNode* aT = headA;
        ListNode* bT = headB;

        while(aT || bT) {
            if (aT == bT) return aT;
            if (seen.find(aT) != seen.end()) return aT;
            if (aT) seen.insert(aT);
            if (seen.find(bT) != seen.end()) return bT;
            if (bT) seen.insert(bT);

            if (aT) aT = aT->next;
            if (bT) bT = bT->next;
        }

        return nullptr;
    }
};