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
        // cout << tNode->val << " ";
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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    ListNode *resultList = NULL;

    int carry = 0;
    int value;

    // loop runs untill one of the list becomes empty
    while (l1 != NULL && l2 != NULL)
    {
        // cout<<carry<<" ";
        appendNode(((l1->val + l2->val + carry) % 10), resultList);

        carry = (l1->val + l2->val + carry) / 10;

        l1 = l1->next;
        l2 = l2->next;
    }

    if (l1 != NULL)
    {

        while (l1 != NULL)
        {

            appendNode(((l1->val + carry) % 10), resultList);

            carry = (l1->val + carry) / 10;

            l1 = l1->next;
        }
    }

    if (l2 != NULL)
    {

        while (l2 != NULL)
        {

            appendNode(((l2->val + carry) % 10), resultList);

            carry = (l2->val + carry) / 10;

            l2 = l2->next;
        }
    }

    if (carry > 0)
    {
        appendNode(carry, resultList);
    }

    return reverseList(resultList);
}

int main()
{
    ListNode *l1 = NULL;
    ListNode *l2 = NULL;

    appendNode(7, l1);
    appendNode(2, l1);
    appendNode(4, l1);
    appendNode(3, l1);

    appendNode(5, l2);
    appendNode(6, l2);
    appendNode(4, l2);

    // appendNode(l1, 1);
    // appendNode(l1, 1);
    // appendNode(l1, 1);

    // appendNode(l2, 1);
    // appendNode(l2, 1);
    // appendNode(l2, 1);

    displayList(l1);

    displayList(l2);

    displayList(addTwoNumbers(l1, l2));

    return 0;
}