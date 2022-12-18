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

bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;

    while(slow!=NULL){
        slow = slow->next;
        fast = fast->next;
        if(fast){
            fast = fast->next;
        }
        if(fast){
            fast = fast->next;
        }
        if(slow==fast)
            return true;     
    }
    return false;
}

int main()
{
    ListNode *l1 = NULL;
    appendNode(1, l1);
    appendNode(2, l1);
    appendNode(0, l1);
    appendNode(-4, l1);

    displayList(l1);

    return 0;
}