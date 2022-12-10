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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *resultList = NULL;

    while (list1 != NULL && list2 != NULL)
    {

        if (list1->val == list2->val)
        {
            appendNode(list1->val, resultList);
            appendNode(list1->val, resultList);
            list1 = list1->next;
            list2 = list2->next;
        }
        else if (list1->val < list2->val)
        {
            appendNode(list1->val, resultList);
            list1 = list1->next;
        }
        else
        {
            appendNode(list2->val, resultList);
            list2 = list2->next;
        }
    }

    if (list1 != NULL)
    {
        while (list1 != NULL)
        {
            appendNode(list1->val, resultList);
            list1 = list1->next;
        }
    }
    if (list2 != NULL)
    {
        while (list2 != NULL)
        {
            appendNode(list2->val, resultList);
            list2 = list2->next;
        }
    }

    return resultList;
}

int main()
{
    ListNode *l1 = NULL;
    ListNode *l2 = NULL;

    appendNode(1, l1);
    appendNode(2, l1);
    appendNode(4, l1);

    displayList(l1);

    appendNode(1, l2);
    appendNode(3, l2);
    appendNode(4, l2);

    displayList(l2);

    displayList(mergeTwoLists(l1, l2));

    return 0;
}