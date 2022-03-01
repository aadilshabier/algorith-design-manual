#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack
{
public:
	Stack();
	Stack(vector<T> vec);
	Stack(const vector<T>&& vec);
	void push(T x);
	T pop();
	T* findMin();
private:
private:
	vector<T> mVec;
	size_t mMin;
};

template <typename T>
Stack<T>::Stack()
	: mMin(0)
{}

template <typename T>
Stack<T>::Stack(vector<T> vec)
	: mVec(vec)
{
	mMin = min_element(mVec) - mVec.begin();
}

template <typename T>
Stack<T>::Stack(const vector<T>&& vec)
	: mVec(vec)
{
	mMin = min_element(mVec) - mVec.begin();
}

template <typename T>
void Stack<T>::push(T x)
{
	mVec.push_back(x);
	if (x < mVec[mMin])
		mMin = mVec.size() - 1;
}

template <typename T>
T Stack<T>::pop()
{
	auto x = mVec.back();
	mVec.pop_back();
	//if smallest element was deleted
	if (mVec.size() == mMin)
		mMin = min_element(mVec.begin(), mVec.end()) - mVec.begin();

	return x;
}

template <typename T>
T* Stack<T>::findMin()
{
	return mVec.data() + mMin;
}

int main()
{
	Stack<int> stack;
	stack.push(4);
	stack.push(9);
	stack.push(12);
	stack.push(1);
	stack.push(9);

	cout << "Minimum element: " << *stack.findMin() << endl;
	cout << "Removed: " << stack.pop() << endl;
	cout << "Removed: " << stack.pop() << endl;
	cout << "Minimum element: "<< *stack.findMin() << endl;
}
