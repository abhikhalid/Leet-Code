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

    while (tNode != NULL)
    {
        // duplicate found, now delete it
        if (tNode->next != NULL)
        {
            if (tNode->val == tNode->next->val)
            {
                ListNode *tNodeNext = tNode->next;
                tNode->next = tNode->next->next;
                delete tNodeNext;
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
    appendNode(1, l1);
    appendNode(1, l1);
    appendNode(1, l1);

    displayList(l1);

    cout << "After removing duplicates..." << endl;

    displayList(deleteDuplicates(l1));

    return 0;
}