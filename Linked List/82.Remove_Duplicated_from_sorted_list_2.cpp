#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

void appendNode(int value, ListNode *&list)
{
    // creating a new node
    ListNode *newNode = new ListNode;
    newNode->val = value;
    newNode->next = NULL;

    if (list == NULL)
    {
        list = newNode;
    }
    else
    {
        ListNode *tNode = list;
        while (tNode->next != NULL)
        {
            tNode = tNode->next;
        }
        tNode->next = newNode;
    }
}

void displayList(ListNode *list)
{
    ListNode *tNode = list;
    while (tNode != NULL)
    {
        cout << tNode->val << "->";
        tNode = tNode->next;
    }
    cout << "NULL" << endl;
}

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *pNode = NULL;
    ListNode *tNode = head;

    bool shouldDelete = false;

    while (tNode != NULL)
    {
        if (tNode->next != NULL)
        {
            if (tNode->val == tNode->next->val)
            {
                shouldDelete = true;
                tNode = tNode->next;
                continue;
            }
        }

        if (shouldDelete)
        {
            // if it's head
            if (pNode == NULL)
            {
                head = tNode->next;
                tNode->next = NULL;
                pNode = NULL;
                shouldDelete = false;
                tNode = head;
                continue;
            }
            else
            {
                pNode->next = tNode->next;
                tNode = tNode->next;
                shouldDelete = false;
                continue;
            }
        }

        pNode = tNode;
        tNode = tNode->next;
    }

    return head;
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(1, l1);
    appendNode(2, l1);
    appendNode(3, l1);
    appendNode(3, l1);
    appendNode(4, l1);
    appendNode(4, l1);
    appendNode(5, l1);

    displayList(l1);

    displayList(deleteDuplicates(l1));

    return 0;
}