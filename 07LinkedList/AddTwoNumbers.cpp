#include <bits/stdc++.h>
using namespace std;

class ListNode{
  public:
  int val;
  ListNode* next;

  ListNode(int val){
    this->val = val;
    this->next = NULL;
  }
};

void printList(ListNode* head){
    ListNode* temp = head;
    while(temp!=NULL){
      cout<<temp->val;
      if(temp->next) cout<<"->";
      else cout<<endl;
      temp = temp->next;
    }
  }

//Approach - 1 Reverse LL and add 

//Approach - 2 Take DummyNode add using a carry; TC- O(N) , SC- O(1)
class Solution{
  public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode* dummyNode = new ListNode(-1);
    ListNode* curr = dummyNode;
    int carry = 0;
    while(l1!=NULL || l2!=NULL || carry !=0){
      int val1 = (l1!=NULL) ? l1->val : 0;
      int val2 = (l2!=NULL) ? l2->val : 0;
      int sum = val1 + val2 + carry;
      carry = sum/10;
      sum = sum%10;
      curr->next = new ListNode(sum);
      curr = curr->next;
      
      if(l1) l1 = l1->next;
      if(l2) l2 = l2->next;
    }
     return dummyNode->next;
  }
 
};

int main() {
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(9);

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);

    // Add two numbers represented as linked lists
    Solution sol;
    ListNode* sum = sol.addTwoNumbers(head1, head2);

    // Print the resulting sum list
    printList(sum);

    return 0;
}
