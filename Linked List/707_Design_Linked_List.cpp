#include <bits/stdc++.h>

using namespace std;

class MyLinkedList
{

    struct ListNode
    {
        int val;
        ListNode *next;
    };

    ListNode *head = NULL;
    int totalSize = 0; // empty elements

public:
    // Initializes the MyLinkedList object.
    MyLinkedList()
    {
    }

    // Get the value of the indexth node in the linked list. If the index is invalid, return -1.
    int get(int index)
    {
        if (index >= totalSize)
            return -1;

        ListNode *tNode = head;

        int i = 0;

        while (i != index)
        {
            i++;
            tNode = tNode->next;
        }

        return tNode->val;
    }

    // Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked lis
    void addAtHead(int val)
    {
        // creating e node
        ListNode *newNode = new ListNode;
        newNode->val = val;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        totalSize++;
    }

    // Append a node of value val as the last element of the linked list.
    void addAtTail(int val)
    {
        // creating e node
        ListNode *newNode = new ListNode;
        newNode->val = val;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            totalSize++;
            return;
        }

        ListNode *tNode = head;
        if (tNode != NULL)
        {
            while (tNode->next != NULL)
            {
                tNode = tNode->next;
            }

            tNode->next = newNode;
            totalSize++;
        }
    }

    // Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
    void addAtIndex(int index, int val)
    {
        if (index > totalSize)
            return;

        // creating e node
        ListNode *newNode = new ListNode;
        newNode->val = val;
        newNode->next = NULL;

        // check if head is not or not
        if (head == NULL)
        {
            head = newNode;
            totalSize++;
            return;
        }

        // insert node at the end
        if (index == totalSize)
        {
            ListNode *tNode = head;
            if (tNode != NULL)
            {
                while (tNode->next != NULL)
                {
                    tNode = tNode->next;
                }
                tNode->next = newNode;

                totalSize++;
            }
        }
        else if (index < totalSize)
        {

            int i = 0;
            ListNode *pNode = NULL;
            ListNode *tNode = head;

            while (i != index)
            {
                pNode = tNode;
                tNode = tNode->next;
                i++;
            }
            // insert at head position
            if (pNode == NULL)
            {
                newNode->next = head;
                head = newNode;
            }
            else
            {
                // pNode = tNode;
                // tNode = tNode->next;
                pNode->next = newNode;
                newNode->next = tNode;
            }

            totalSize++;
        }
    }
    // Delete the indexth node in the linked list, if the index is valid.
    void deleteAtIndex(int index)
    {
        if (index >= totalSize)
            return;

        ListNode *pNode = NULL;
        ListNode *tNode = head;

        int i = 0;

        while (i != index)
        {
            pNode = tNode;
            tNode = tNode->next;
            i++;
        }
        // delete the first node
        if (pNode == NULL)
        {
            head = head->next;
            delete tNode;
            totalSize--;
        }
        else
        {
            pNode->next = tNode->next;
            delete tNode;
            totalSize--;
        }
    }

    void displayList()
    {
        ListNode *tNode = head;
        while (tNode != NULL)
        {
            cout << tNode->val << "->";
            tNode = tNode->next;
        }
        cout << endl;
    }
};

int main()
{
    MyLinkedList *obj = new MyLinkedList();

    obj->addAtTail(1);

    obj->displayList();
    cout << endl;
    // cout << obj->get(1) << endl;

    return 0;
}