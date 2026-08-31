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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == nullptr)
            return {-1, -1};
        vector<int> point;
        ListNode* temp = head;
        int prev = temp->val;
        if (temp->next != nullptr)
            temp = temp->next;
        else
            return {-1, -1};
        int cnt = 2;
        while (true) {
            if (temp==nullptr or temp->next == nullptr)
                break;
            int curr = temp->val;
            int nextVal = temp->next->val;
            if (((prev < curr )and (curr > nextVal)) or
                ((prev > curr) and (curr < nextVal))){
                point.push_back(cnt);
            }
            prev=curr;
            temp=temp->next;
            cnt++;
        }
        if (point.size() <=1 )
            return {-1, -1};
        int n = point.size();
        cout<<n<<endl;
        int maxi = point[n - 1] - point[0];
        int mini = maxi;
        cout<<maxi<<endl;
        for (int i = 0; i < n - 1; i++) {
            mini = min(mini, point[i + 1] - point[i]);
        }
        cout<<maxi<<mini<<endl;
        return {mini, maxi};
    }
};