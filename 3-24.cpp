#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool isKUnique(T* a, size_t n, size_t k)
{
	assert(k <= n);
	//Initialize
	unordered_set<T> frame(k+1);
	for(size_t i=0; i<=k; i++) {
		if (frame.count(a[i]))
			return false;
		frame.insert(a[i]);
	}
	//move frame to the right
	for(size_t i=1; i+k<n; i++) {
		frame.erase(a[i-1]);
		if (frame.count(a[i+k]))
			return false;
		frame.insert(a[i+k]);
	}
	return true;
}

int main()
{
	int a[] = {1, 2, 3, 4, 1, 2, 3};
	assert(isKUnique(a, sizeof(a)/sizeof(a[0]), 3));
	assert(!isKUnique(a, sizeof(a)/sizeof(a[0]), 4));

	return 0;
}
