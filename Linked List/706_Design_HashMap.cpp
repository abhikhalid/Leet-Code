#include <bits/stdc++.h>

using namespace std;

class MyHashMap
{
    struct ListNode
    {
        int key;
        int value;
        ListNode *next;
    };

    ListNode *head = NULL;

public:
    MyHashMap()
    {
    }
    void put(int key, int value)
    {
        // append a new node
        ListNode *newNode = new ListNode;
        newNode->key = key;
        newNode->value = value;
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
                    if (tNode->key == key)
                    {

                        tNode->value = value;
                        // delete newNode;
                        return;
                    }
                    tNode = tNode->next;
                }
                if (tNode->key == key)
                {

                    tNode->value = value;
                    // delete newNode;
                    return;
                }
                tNode->next = newNode;
            }
        }
    }

    int get(int key)
    {
        if (head == NULL)
            return -1;

        ListNode *tNode = head;
        while (tNode != NULL)
        {
            if (tNode->key == key)
            {
                return tNode->value;
            }
            tNode = tNode->next;
        }
        return -1;
    }

    void remove(int key)
    {
        ListNode *pNode = NULL;
        ListNode *tNode = head;

        while (tNode != NULL)
        {
            // remove the node
            if (tNode->key == key)
            {
                if (pNode == NULL)
                {
                    head = head->next;
                    delete tNode;
                }
                else
                {
                    pNode->next = tNode->next;
                    delete tNode;
                    return;
                }
            }

            pNode = tNode;
            tNode = tNode->next;
        }
    }

    void displayList()
    {
        ListNode *tNode = head;
        while (tNode != NULL)
        {
            cout << tNode->value << "->";
            tNode = tNode->next;
        }
        cout << "NULL" << endl;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main()
{
    MyHashMap *obj = new MyHashMap();
    obj->put(1, 1);
    obj->put(2, 2);
    // obj->get(1);
    // cout <<
    // obj->get(3);
    obj->put(2, 1);
    //  obj->get(2);
    //  obj->remove(2);
    //   obj->get(2);

    obj->displayList();

    return 0;
}