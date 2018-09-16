/**
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if (lists.size() == 0) return NULL;
            return mergeSort(lists, 0, lists.size() - 1);
        }
        ListNode* mergeSort(vector<ListNode*>& lists, int start_index, int end_index) {
            int mid_index = 0;
            ListNode* l1;
            ListNode* l2;
            if (start_index < end_index) {
                mid_index = floor((start_index + end_index) / 2);
                l1 = mergeSort(lists, start_index, mid_index);
                l2 = mergeSort(lists, mid_index + 1, end_index);
                return mergeTwoLists(l1, l2);
            }
            return lists[start_index];
        }

        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode* l3, *head;
            head = l3 = new ListNode(-1);
            while (!(l1 == NULL && l2 == NULL)) {
                if (l1 == NULL && l2 != NULL) {
                    l3->next = new ListNode(l2->val);
                    l3 = l3->next;
                    l2 = l2->next;
                } else if (l1 != NULL && l2 == NULL) {
                    l3->next = new ListNode(l1->val);
                    l3 = l3->next;
                    l1 = l1->next;
                } else if (l1 != NULL && l2 != NULL) {
                    if (l1->val == l2->val) {
                        l3->next = new ListNode(l1->val);
                        l3 = l3->next;
                        l3->next = new ListNode(l2->val);
                        l3 = l3->next;
                        l1 = l1->next;
                        l2 = l2->next;
                    } else if (l1->val < l2->val) {
                        l3->next = new ListNode(l1->val);
                        l3 = l3->next;
                        l1 = l1->next;
                    } else if (l1->val > l2->val) {
                        l3->next = new ListNode(l2->val);
                        l3 = l3->next;
                        l2 = l2->next;
                    }
                }
            }
            return head->next;
        }
};

int main(int arvc, char *argv[]) {
    Solution *s = new Solution();
    ListNode *l1, *l2;
    l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    l2->next->next->next = new ListNode(9);
    vector<ListNode*> l3;
    l3.push_back(l1);
    l3.push_back(l2);
    l3.push_back(l2);
    l3.push_back(l2);
    ListNode* r = s->mergeKLists(l3);
    while (r != NULL) {
        cout<<r->val<<endl;
        r = r->next;
    }
}

