//
// Created by Trung on 3/6/2017.
//

/**
 * Problem statement:
 *      A Node class is provided in the editor. A Node object has an integer data field, data, and a Node instance
 *      pointer, next, pointing to another node (i.e.: the next node in a list).
 *      A Node insert function is also declared in the editor. It has two parameters: a pointer, head, pointing to the
 *      first node of a linked list, and an integer data value that must be added to the end of the list as a new Node
 *      object.
 * Task:
 *      Complete the insert function so that it creates a new Node (pass  as the Node constructor argument) and
 *      inserts it at the tail of the linked list referenced by the head parameter. Once the new node is added,
 *      return the reference to the head node.
 * Note: If the  argument passed to the insert function is null, then the initial list is empty.
 *
 *
 */

#include <iostream>
#include <cstddef>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
class Solution{
public:

    /**
     * Traverse the list to find the last node then insert new node after that node.
     *
     * @param head
     * @param data
     * @return head of linkedlist
     */
    Node* insert(Node *head,int data)
    {
        //Complete this method
        Node *newNode = new Node(data);
        if (head != NULL) {
            Node *curr = head;
            //If next node is not NULL
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
        } else {
            head = newNode;
        }
        return head;
    }

    void display(Node *head)
    {
        Node *start=head;
        while(start)
        {
            cout<<start->data<<" ";
            start=start->next;
        }
    }
};
int main() {
    Node *head = NULL;
    Solution mylist;
    int T, data;
    cin >> T;
    while (T--> 0) {
        cin >> data;
        head = mylist.insert(head, data);
    }
    mylist.display(head);
}