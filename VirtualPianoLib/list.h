
template <typename T>
class Node {
private:
	Node* next;
	Node* prev;
	T val;
public:

};

template <typename T>
class list
{
private:
	Node<T>* head;
public:
	list();
	list(T* start, T* end);
	list(T head);
	~list();

	Node<T>* front();
	Node<T>* back();

	bool empty();
	int size();
	
	void clear();
	void insert(T value);
	void erase(T value);
	
	void push_back(T value);
	void push_front(T value);
	void pop_back(T value);
	void pop_front(T value);

	void sort();
	void unique();

};