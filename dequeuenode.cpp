
#include <iostream>

struct Node
{
    int value;
    Node *next;
    Node *prev;

    Node(int v) : value(v),
                  next(nullptr),
                  prev(nullptr)
    {
    }
};

class Deque
{
    Node *head;
    Node *tail;
public:

    Deque() : head(nullptr), tail(nullptr) {}

    void push_front(int value)
    {
        if (empty())
        {
            head = new Node(value);
            tail = head;
        }
        else
        {
            Node *tmp = new Node(value);
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
        }
    }
    void push_back(int value)
    {
        if (empty())
        {
            head = new Node(value);
            tail = head;
        }
        else
        {
            Node *tmp = new Node(value);
            tmp->prev = tail;
            tail->next = tmp;
            tail = tmp;
        }
    }
    void pop_front()
    {
        if (empty())
        {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back()
    {
        if (empty())
        {
            std::cout << "Deque is empty" << std::endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }

    bool empty()
    {
        return head == nullptr;
    }
    ~Deque()
    {
        while (!empty())
        {
            pop_front();
        }
    }
    Deque(const Deque &original) : head(nullptr), tail(nullptr)
    {
        Node *temp = original.head;
        while (temp != nullptr)
        {
            push_back(temp->value);
            temp = temp->next;
        }
    }
    Deque &operator=(const Deque &original)
    {
        if (this == &original)
        {
            return *this;
        }
        while (!empty())
        {
            pop_front();
        }
        Node *temp = original.head;
        while (temp != nullptr)
        {
            push_back(temp->value);
            temp = temp->next;
        }
        return *this;
    }
    int front()
    {
        if (empty())
        {
            std::cout << "Deque is empty" << std::endl;
            return 0;
        }
        return head->value;
    }
    int back()
    {
        if (empty())
        {
            std::cout << "Deque is empty" << std::endl;
            return 0;
        }
        return tail->value;
    }
    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    Deque d;
    d.push_front(1);
    d.push_front(2);
    d.push_front(3);
    d.push_front(4);
    d.push_back(5);
    d.push_back(6);
    d.push_back(7);
    d.print();
    Deque d2;
    d2 = d;
    d2.print();




}