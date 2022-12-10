#include <bits/stdc++.h>
#include <cmath>

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

int power = 0;

int getDecimalValue(ListNode *head)
{
    if (head == NULL)
        return 0;

    return getDecimalValue(head->next) + (head->val * pow(2, power++));
}

int main()
{
    ListNode *l1 = NULL;

    // appendNode(1, l1);
    appendNode(0, l1);
    // appendNode(1, l1);

    displayList(l1);

    cout << getDecimalValue(l1) << endl;

    return 0;
}