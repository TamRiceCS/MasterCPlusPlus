// Made a templated class really early, this is in section 6!

#include <iostream>
#include <vector>

template <typename T>
class SuperSimpleLL
{
private:
    class Node
    {
    public:
        T m_data;
        Node *prior = nullptr;
        Node *next = nullptr;
    };

    int size = 0;
    Node *head = nullptr;
    Node *tail = nullptr;

public:
    SuperSimple();
    SuperSimpleLL(T firstData)
    {
        this->head = new Node{firstData, nullptr, nullptr};
        this->tail = head;
        this->size = 1;
        std::cout << "Built" << std::endl;
    }

    void insertEnd(T nextData)
    {
        this->size++;
        Node *temp = new Node{nextData, tail, nullptr};
        tail->next = temp;
        tail = temp;
    }
    void insertStart(T nextData)
    {
        this->size++;
        Node *temp = new Node{nextData, nullptr, head};
        head->prior = temp;
        head = temp;
    }

    void report()
    {
        Node *iter = head;
        while (iter != nullptr)
        {
            std::cout << "\t" << iter->m_data;
            iter = iter->next;
        }
    }

    ~SuperSimpleLL()
    {
        Node *iter = tail;
        Node *temp = nullptr;

        std::cout << "Destructed" << std::endl;

        while (iter != nullptr)
        {
            temp = iter;

            std::cout << "\t" << iter->m_data;

            iter = iter->prior;
            delete temp;
        }

        std::cout << "\n";

        head = nullptr;
        tail = nullptr;
    }
};