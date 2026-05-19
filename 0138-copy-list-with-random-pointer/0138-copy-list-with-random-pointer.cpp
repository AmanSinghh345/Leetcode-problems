/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        Node* curr=head;
        while(curr!=NULL){
            Node* clone=new Node(curr->val);
            clone->next=curr->next;
            Node* next=curr->next;
            curr->next=clone;
            curr=next;
        }


        curr=head;
        while(curr!=NULL){
            if(curr->random!=NULL){
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
        Node* dummy=new Node(0);
        Node* cloneCurr=dummy;
        curr=head;
        while(curr!=NULL){
            cloneCurr->next=curr->next;
        
            curr->next=curr->next->next;
            cloneCurr=cloneCurr->next;
            curr=curr->next;
        }
        return dummy->next;
    }
};