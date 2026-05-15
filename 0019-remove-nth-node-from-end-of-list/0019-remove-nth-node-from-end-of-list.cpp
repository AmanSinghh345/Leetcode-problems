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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* it=head;
        int cnt=0;
        while(it){
            cnt++;
            it=it->next;
        }
            
        int pos=cnt-n+1;
if(pos==1) {
            return head->next;
        }
        it=head;
        cnt=1;
    
        while(it!=NULL && it->next!=NULL){
        
            if(cnt==pos-1){
                it->next=it->next->next;
                break;
            }
            cnt++;
            it=it->next;
        }
    return head;
    }
};