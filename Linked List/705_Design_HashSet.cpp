#include <bits/stdc++.h>

using namespace std;

class MyHashSet
{
    struct ListNode
    {
        int val;
        ListNode *next;
    };

    ListNode *head = NULL;

    int totalSize = 0;

public:
    MyHashSet()
    {
    }

    // void add(key) Inserts the value key into the HashSet.

    void add(int key)
    {
        // creating a node
        ListNode *newNode = new ListNode;
        newNode->val = key;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            ListNode *tNode = head;
            if (tNode != NULL)
            {
                while (tNode->next != NULL)
                {
                    tNode = tNode->next;
                }
                tNode->next = newNode;
            }
        }
    }

    // void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.

    void remove(int key)
    {
        ListNode *pNode = NULL;
        ListNode *tNode = head;

        while (tNode != NULL)
        {
            // we have found the key, let's remove it
            if (tNode->val == key)
            {
                if (pNode == NULL)
                {
                    head = head->next;
                    delete tNode;
                    tNode = head;
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
    }

    // bool contains(key) Returns whether the value key exists in the HashSet or not.

    bool contains(int key)
    {
        ListNode *tNode = head;
        while (tNode != NULL)
        {
            if (tNode->val == key)
                return true;
            tNode = tNode->next;
        }
        return false;
    }

    void displayList()
    {
        ListNode *tNode = head;
        while (tNode != NULL)
        {
            cout << tNode->val << "->";
            tNode = tNode->next;
        }
        cout << "NULL" << endl;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main()
{
    MyHashSet *obj = new MyHashSet();
    obj->add(1);
    obj->add(2);

    // cout << obj->contains(1) << endl;
    // cout << obj->contains(3) << endl;
    obj->add(2);
    // cout << obj->contains(2) << endl;
    obj->remove(2);
    cout << obj->contains(2) << endl;
    obj->displayList();

    return 0;
}