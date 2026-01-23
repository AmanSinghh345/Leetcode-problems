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
        vector<int> a;
        for(auto list : lists)
        {
            while(list!=NULL)
            {
                a.push_back(list->val);
                list=list->next;
            }
        }
        sort(a.begin(),a.end());

        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        for(int i=0;i<a.size();i++)
        {
            curr->next=new ListNode(a[i]);
            curr=curr->next;
        }
        return dummy->next;
    }
};