#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct LinkedList
{
	T item;
	LinkedList<T>* next;
};

/* push element to back of list.
 * if `front` == nullptr, create a new list
 */
template <typename T>
LinkedList<T>* pushBack(LinkedList<T>* front, T item)
{
	LinkedList<T>* newElem = new LinkedList<T>;
	newElem->item = item;
	newElem->next = nullptr;
	if (front == nullptr) {
		front = newElem;
	} else {
		auto i = front;
		while(i->next != nullptr)
			i = i->next;
		i->next = newElem;
	}
	return front;
}

/* reverse list and return new front element */
template <typename T>
LinkedList<T>* reverseList(LinkedList<T>* front)
{
	LinkedList<T>* a = front, *b = front->next, *c;
	a->next = nullptr;
	while (b != nullptr) {
		c = b->next;
		b->next = a;
		a = b;
		b = c;
	}
	return a;
}

template <typename T>
void print_list(LinkedList<T>* l)
{
	auto it = l;
	cout << it->item;
	it = it->next;
	for(; it != nullptr; it = it->next)
		cout << " -> " << it->item;
	cout << endl;
}

int main()
{
	LinkedList<int> *l = nullptr;
	l = pushBack(l, 1);
	l = pushBack(l, 2);
	l = pushBack(l, 3);
	l = pushBack(l, 4);
	l = pushBack(l, 5);
	cout << "Before:\n  ";
	print_list(l);
	auto rev = reverseList(l);
	cout << "After:\n  ";
	print_list(rev);
}
