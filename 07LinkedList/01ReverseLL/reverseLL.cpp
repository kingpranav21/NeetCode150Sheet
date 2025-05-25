#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// Definition of a Node
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Linked List class
class LinkedList
{
public:
    // Function to reverse the linked list using array
    Node *reverseLL(Node *head)
    {
        vector<int> arr;
        Node *temp = head;

        while (temp != nullptr)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }

        int i = arr.size() - 1;
        temp = head;

        while (temp != nullptr)
        {
            temp->data = arr[i--];
            temp = temp->next;
        }

        return head;
    }

    // Function to print the linked list
    void printList(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    LinkedList ll;

    cout << "Original List: ";
    ll.printList(head);

    // Reverse the list
    head = ll.reverseLL(head);

    cout << "Reversed List: ";
    ll.printList(head);

    return 0;
}
