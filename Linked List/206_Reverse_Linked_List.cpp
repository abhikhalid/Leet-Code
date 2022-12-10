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

void reverseAList(ListNode *pNode, ListNode *tNode, ListNode *&head)
{

    if (tNode == NULL)
        return;

    if (tNode->next == NULL)
    {
        head = tNode;
    }

    pNode = tNode;
    tNode = tNode->next;

    reverseAList(pNode, tNode, head);

    if (tNode != NULL)
    {
        //cout << tNode->val << " ";
        tNode->next = pNode;
        pNode->next = NULL;
    }
}

ListNode *reverseList(ListNode *head)
{
    ListNode *pNode = NULL;
    ListNode *tNode = head;

    reverseAList(pNode, tNode, head);

    return head;
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 1);
    appendNode(l1, 2);
    appendNode(l1, 3);
    appendNode(l1, 4);
    appendNode(l1, 5);

    displayList(reverseList(l1));

    return 0;
}