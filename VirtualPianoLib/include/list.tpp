#ifndef _list_tpp
#define _list_tpp

template <typename T> void list<T>::erase(listIterator pos) {
    auto tmp = pos.ptr;
    if (tmp == m_head)
        return pop_front();
    if (tmp == m_tail)
        return pop_back();
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    m_size--;
    delete tmp;
}

template <typename T> void list<T>::insert(listIterator pos, valueType value) {
    if (pos.ptr == m_head)
        return push_front(value);
    if (pos.ptr == nullptr)
        return push_back(value);
    m_size++;
    auto tmp = new node(value, pos.ptr->prev, pos.ptr);
    if (pos.ptr->prev != nullptr)
        pos.ptr->prev->next = tmp;
    pos.ptr->prev = tmp;
}

template <typename T> void list<T>::push_back(valueType value) {
    m_size++;
    if (m_head == nullptr)
        m_head = m_tail = new node(value, nullptr);
    else {
        m_tail->next = new node(value, m_tail);
        m_tail = m_tail->next;
    }
}

template <typename T> void list<T>::push_front(valueType value) {
    m_size++;
    if (m_tail == nullptr)
        m_tail = m_head = new node(value, m_tail);
    else {
        m_head->prev = new node(value, nullptr, m_head);
        m_head = m_head->prev;
    }
}

template <typename T> void list<T>::pop_back() {
    m_size--;
    if (m_tail == m_head) {
        delete m_tail;
        m_tail = m_head = nullptr;
    }
    else {
        m_tail = m_tail->prev;
        delete m_tail->next;
        m_tail->next = nullptr;
    }
}

template <typename T> void list<T>::pop_front() {
    m_size--;
    if (m_tail == m_head) {
        delete m_head;
        m_tail = m_head = nullptr;
    }
    else {
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

template <typename T> void list<T>::print() const {
    auto tmp = m_head;
    while (tmp != nullptr) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

template <typename T> Iterator<T>& Iterator<T>::operator++() {
    ptr = ptr->next;
    return *this;
}

template <typename T> Iterator<T>& Iterator<T>::operator++(int) {
    ptr = ptr->next;
    return Iterator(ptr->prev);
}

template <typename T> Iterator<T>& Iterator<T>::operator--() {
    ptr = ptr->prev;
    return *this;
}

template <typename T> Iterator<T>& Iterator<T>::operator--(int) {
    ptr = ptr->prev;
    return Iterator(ptr->next);
}
#endif