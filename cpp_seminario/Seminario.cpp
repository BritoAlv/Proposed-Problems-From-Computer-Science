#include <iostream>
namespace Seminario
{
using std::cout;
template <typename T> class DLL
{
  public:
    DLL()
    {
        head = nullptr;
        tail = nullptr;
    }
    void watch()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->val << ' ';
            current = current->next;
        }
        cout << '\n';
    }
    void watchDebug()
    {
        cout << "START" << '\n';
        Node *current = head;
        while (current != nullptr)
        {
            current->watch();
            current = current->next;
        }
        cout << "END" << '\n';
    }
    void pb(T val)
    {
        Node *A = new Node();
        A->val = val;
        A->next = nullptr;
        if (head == nullptr)
        {
            A->prev = nullptr;
            head = A;
            tail = A;
        }
        else
        {
            Node *current = tail;
            current->next = A;
            A->prev = current;
            tail = A;
        }
    }
    void rm(T val)
    {
        Node *current = head;
        while (current != nullptr && current->val != val)
        {
            current = current->next;
        }
        if (current != nullptr)
        {
            Node *before = current->prev;
            Node *next = current->next;
            if (before == nullptr)
            {
                head = next;
                if (next != nullptr)
                {
                    next->prev = nullptr;
                }
                else
                {
                    // linked list with only one element
                    // and have to delete precisely it.
                    tail = nullptr;
                }
            }
            else
            {
                before->next = next;
                if (next != nullptr)
                {
                    next->prev = before;
                }
                else
                {
                    tail = before;
                }
            }
        }
    }

  private:
    class Node
    {
      public:
        Node(){

        };
        void watchDebug()
        {
            cout << "Val is: " << ' ' << val << '\n';
            cout << "Prev is: " << ' ';
            if (prev == nullptr)
            {
                cout << "NULL";
            }
            else
            {
                cout << prev->val;
            }
            cout << '\n';
            cout << "Next is: " << ' ';
            if (next == nullptr)
            {
                cout << "NULL";
            }
            else
            {
                cout << next->val;
            }
            cout << '\n';
        }
        T val;
        Node *next;
        Node *prev;
    };

  private:
    Node *head;
    Node *tail;
};
} // namespace Seminario