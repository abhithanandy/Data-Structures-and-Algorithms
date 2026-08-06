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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr)
            return head;
            
        int n=0;
        ListNode* temp=head;

        while(temp!=nullptr){
            n++;
            temp=temp->next;
        }
        
        k=k%n;
        if(k==0){
            return head;
        }
        temp=head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        
        temp->next=head; //circular

        ListNode* end=head;

        for(int i=1;i<n-k;i++){
            end=end->next;                        
        }
        ListNode* newHead = end->next;

        end->next=nullptr; //break loop

        return newHead;
        
    }
};