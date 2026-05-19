/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> umap;
        while(headB!=NULL){
            umap.insert(headB);
            headB=headB->next;
        }
        while(headA!=NULL){
            if(umap.find(headA)!=umap.end()) return headA;
            headA=headA->next;
        }
        return NULL;
    }
};