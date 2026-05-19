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
    bool check(ListNode* curr,int k){
        while(curr!=NULL && k>0){
            curr=curr->next;
            k--;
        }
        return k==0;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1) return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prevGroupTail = dummy;

        ListNode* curr=head;
        while(check(curr,k)) {
                ListNode* groupStart=curr;
                ListNode* prev=NULL;
                for(int i=0;i<k;i++){
                    ListNode* next=curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=next;
            }
            prevGroupTail->next=prev;
            groupStart->next=curr;
            prevGroupTail=groupStart;
            
        }
        return dummy->next;
    }
};