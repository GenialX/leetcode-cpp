/**
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 */
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode* l3, *head;
            head = l3 = new ListNode(-1);
            while (!(l1 == NULL && l2 == NULL)) {
                if (l1 == NULL && l2 != NULL) {
                    l3->next = l2;
                    l3 = l3->next;
                    l2 = l2->next;
                }
                if (l1 != NULL && l2 == NULL) {
                    l3->next = l1;
                    l3 = l3->next;
                    l1 = l1->next;
                }
                if (l1 != NULL && l2 != NULL) {
                    if (l1->val == l2->val) {
                        l3->next = l1;
                        l3 = l3->next;
                        l3->next = l2;
                        l3 = l3->next;
                        l1 = l1->next;
                        l2 = l2->next;
                    } else if (l1->val < l2->val) {
                        l3->next = l1;
                        l3 = l3->next;
                        l1 = l1->next;
                    } else if (l1->val > l2->val) {
                        l3->next = l2;
                        l3 = l3->next;
                        l2 = l2->next;
                    }
                }
            }
            return head->next;
        }

};

int main(int argc, char * argv[]) {
    Solution * s = new Solution();
    ListNode *l1, *l2;
    l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    cout<<s->mergeTwoLists(l1, l2)<<endl;
}
