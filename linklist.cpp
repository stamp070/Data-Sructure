#include <iostream>
#include <typeinfo>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node(int v)
    {
        value = v;
        next = NULL;
    }
};
class Linkedlist
{
public:
    Node *head;
    Linkedlist()
    {
        head = NULL;
    }

    void insertBack(int value)
    {
        Node *n = new Node(value);
        Node *check = head;

        while (check->next != NULL)
        {
            check = check->next;
        }
        check->next = n;
    }

    void insertAfter(int value, int id)
    {
        if (head == NULL)
        {
            head = new Node(value);
            print();
            return;
        }
        Node *n = new Node(value);
        Node *check = head;
        while (check != NULL && check->value != id)
        {
            if (value == check->value)
            {
                return;
            }
            check = check->next;
        }
        if (check == NULL)
        {
            insertBack(value);
            print();
            return;
        }
        else
        {
            n->next = check->next;
            check->next = n;
            print();
            return;
        }
    }
    void insertBefore(int value, int id)
    {
        if (head == NULL)
        {
            head = new Node(value);
            print();
            return;
        }
        // insert front
        Node *n = new Node(value);
        if (head->value == id)
        {
            n->next = head;
            head = n;
            print();
            return;
        }

        Node *check = head;
        Node *prev;
        while (check != NULL && check->value != id)
        {
            if (value == check->value)
            {
                return;
            }
            prev = check;
            check = check->next;
        }

        if (check == NULL)
        {
            insertBack(value);
            print();

            return;
        }
        else
        {
            n->next = prev->next;
            prev->next = n;
            print();

            return;
        }
    }
    void deleteID(int id)
    {
        Node *check = head;
        Node *prev;
        while (check != NULL && check->value != id)
        {
            prev = check;
            check = check->next;
        }
        if (check == head)
        {
            head = check->next;
            print();
            return;
        }
        else if (check != NULL)
        {
            prev->next = check->next;
            print();

            return;
        }
        else if (check == NULL)
        {
            prev->next = NULL;
        }
    }
    void print()
    {
        for (Node *n = head; n != NULL; n = n->next)
        {
            cout << n->value << " ";
        }
        cout << endl;
    }
};
int main()
{
    Linkedlist l;
    while (true)
    {
        char s;
        cin >> s;
        if (s == 'A')
        {
            int value1, id1;
            cin >> value1 >> id1;
            l.insertAfter(value1, id1);
        }
        else if (s == 'I')
        {
            int value2, id2;
            cin >> value2 >> id2;
            l.insertBefore(value2, id2);
        }
        else if (s == 'D')
        {
            int id_delete;
            cin >> id_delete;
            l.deleteID(id_delete);
        }
        else if (s == 'E')
        {
            break;
        }
    }
    return 0;
}