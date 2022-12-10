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

void removeNthNode(ListNode *pNode, ListNode *tNode, ListNode *&head, int &count)
{
    
    if (tNode == NULL)
        return;    

    pNode = tNode;
    tNode = tNode->next;

    removeNthNode(pNode, tNode, head,count);
    
    if (count == 0)
    {
        pNode->next = tNode->next;
        delete tNode;
    }

    count--;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *pNode = NULL;
    ListNode *tNode = head;

    if(head->next==NULL && n == 1) return NULL;

    removeNthNode(pNode, tNode, head, n);

    return head;
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 1);
    appendNode(l1, 2);

    displayList(l1);

    displayList(removeNthFromEnd(l1, 2));

    return 0;
}