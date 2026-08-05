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
        ListNode* temp=head;
        int x=0;

        while(temp!=nullptr){
            x++;
            temp=temp->next;
        }

        if(x==n){
            return head->next;
        }
        
        int position=x-n;
        temp=head;
        for(int i=1;i<position;i++){
            temp=temp->next; //temp stops at position-1
        }
        temp->next=temp->next->next;

        return head;
        
    }
};