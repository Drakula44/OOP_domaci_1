#ifndef _list_h
#define _list_h
#include "std.h"

template <typename list> class Iterator {
private:
    using valueType = typename list::valueType;
    using node = typename list::node;
    friend list;
    node* ptr;
    Iterator(node* a) { ptr = a; };

public:
    Iterator& operator++() {
        ptr = ptr->next;
        return *this;
    }
    Iterator& operator++(int) {
        auto tmp = *this;
        ptr = ptr->next;
        return tmp;
    }
    Iterator& operator--() {
        ptr = ptr->prev;
        return *this;
    }
    Iterator& operator--(int) {
        auto tmp = *this;
        ptr = ptr->prev;
        return tmp;
    }

    valueType& operator*() { return ptr->val; }

    bool operator!=(Iterator& other) { return other.ptr != ptr; }
    bool operator==(Iterator& other) { return other->ptr == ptr; }
};

template <typename T> class list {
private:
    using valueType = T;
    struct node {
        node* next = nullptr;
        node* prev = nullptr;
        valueType val;
        node(valueType x) : val{x} {};
        node(valueType x, node* prev, node* next = nullptr)
            : val{x}, next{next}, prev{prev} {};
    };

    using listIterator = Iterator<list>;
    friend listIterator;

    node* m_head = nullptr;
    node* m_tail = nullptr;
    int m_size = 0;

public:
    list(){};

    listIterator begin() { return listIterator(m_head); };
    listIterator end() { return listIterator(nullptr); };

    valueType front() { return *m_head; };
    valueType back() { return *m_tail; };

    bool empty() { return m_head == nullptr; };
    int size() { return size; };

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
    void print();
};

template <typename T> void list<T>::erase(listIterator pos) {
    auto tmp = pos.ptr;
    if (tmp == m_head)
        return pop_front();
    if (tmp == m_tail)
        return pop_back();
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    delete tmp;
}

template <typename T> void list<T>::insert(listIterator pos, valueType value) {
    if (pos.ptr == m_head)
        return push_front(value);
    if (pos.ptr == nullptr)
        return push_back(value);
    auto tmp = new node(value, pos.ptr->prev, pos.ptr);
    if (pos.ptr->prev != nullptr)
        pos.ptr->prev->next = tmp;
    pos.ptr->prev = tmp;
}

template <typename T> void list<T>::push_back(valueType value) {
    if (m_head == nullptr)
        m_head = m_tail = new node(value, m_tail);
    else {
        m_tail->next = new node(value, m_tail);
        m_tail = m_tail->next;
    }
}

template <typename T> void list<T>::push_front(valueType value) {
    if (m_tail == nullptr)
        m_tail = m_head = new node(value, m_tail);
    else {
        m_head->prev = new node(value, nullptr, m_head);
        m_head = m_head->prev;
    }
}

template <typename T> void list<T>::pop_back() {
    valueType tmp = m_tail->val;
    if (m_tail == m_head) {
        delete m_tail;
        m_tail = m_head = nullptr;
    } else {
        m_tail = m_tail->prev;
        delete m_tail->next;
        m_tail->next = nullptr;
    }
}

template <typename T> void list<T>::pop_front() {
    valueType tmp = m_tail->val;
    if (m_tail == m_head) {
        delete m_head;
        m_tail = m_head = nullptr;
    } else {
        m_head = m_head->next;
        delete m_head->prev;
        m_head->prev = nullptr;
    }
}

template <typename T> void list<T>::clear() {
    while (m_head != nullptr)
        pop_back();
}

template <typename T> list<T>::~list() { clear(); }

template <typename T> void list<T>::print() {
    auto tmp = m_head;
    while (tmp != nullptr) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

#endif