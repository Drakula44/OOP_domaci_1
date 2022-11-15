#ifndef _list_h
#define _list_h
#include "MusicSymbol.h"
#include "Note.h"
#include "std.h"

class Note;
template <typename list> class Iterator {
private:
    using valueType = typename list::valueType;
    using node = typename list::node;

    friend list;
    node* ptr;

    Iterator(node* a) { ptr = a; };

public:
    Iterator(Iterator& a) { ptr = a.ptr; };
    Iterator operator=(Iterator& a) { ptr = a.ptr; };
    Iterator& operator++();
    Iterator& operator++(int);
    Iterator& operator--();
    Iterator& operator--(int);
    valueType& operator*() { return ptr->val; }

    bool operator!=(const Iterator& other) const { return other.ptr != ptr; }
    bool operator==(const Iterator& other) const { return other->ptr == ptr; }
};

template <typename T> class list {
private:
    using valueType = T;
    using listIterator = Iterator<list>;
    friend listIterator;

    struct node {
        valueType val;
        node* prev = nullptr;
        node* next = nullptr;
        node(valueType x) : val{x} {};
        node(valueType x, node* prev, node* next = nullptr)
            : val{x}, prev{prev}, next{next} {};
    };

    node* m_head = nullptr;
    node* m_tail = nullptr;
    int m_size = 0;

public:
    list(){};

    listIterator begin() const { return listIterator(m_head); };
    listIterator end() const { return listIterator(nullptr); };

    valueType front() const { return *m_head; };
    valueType back() const { return *m_tail; };

    bool empty() const { return m_head == nullptr; };
    int size() const { return m_size; };

    ~list();

    void clear();
    void insert(listIterator pos, valueType value);
    void erase(listIterator pos);

    void insert(int pos, valueType value);
    void erase(valueType value);

    void push_back(valueType value);
    void push_front(valueType value);
    void pop_back();
    void pop_front();

    void sort();
    void unique();
    void print() const;
};
#include "list.tpp"
#endif