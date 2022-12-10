#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

void appendNode(ListNode *&list, int value)
{
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

ListNode *removeElements(ListNode *head, int val)
{

    ListNode *pNode = NULL;
    ListNode *tNode = head;

    while (tNode != NULL)
    {
        if (tNode->val == val)
        {
            // now, delete this node

            // delete the head node
            if (pNode == NULL)
            {
                head = head->next;
                delete tNode;
                tNode = head;
                pNode = NULL;
                continue;
            }
            else
            {
                pNode->next = tNode->next;
                delete tNode;
                tNode = pNode->next;
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

    appendNode(l1, 1);
    appendNode(l1, 2);
    appendNode(l1, 6);
    appendNode(l1, 3);
    appendNode(l1, 4);
    appendNode(l1, 5);
    appendNode(l1, 6);

    // displayList(l1);

    displayList(removeElements(l1, 6));

    return 0;
}