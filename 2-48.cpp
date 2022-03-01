#include <bits/stdc++.h>
using namespace std;

vector<int> create_subset(const vector<int>& s, size_t k)
{
	vector<int> result;
	result.reserve(k);
	for (size_t i=0, remaining=k; remaining>0 && i<s.size(); i++) {
		float prob = static_cast<float>(remaining) / static_cast<float>(s.size()-i);
		float r = static_cast<float>(rand()) / static_cast<int>(RAND_MAX);
		if(r < prob) {
			result.push_back(s[i]);
			remaining--;
		}
	}
	assert(result.size() == k);
	return result;
}

void print_vec(const vector<int>& v)
{
	for(auto i: v) {
		cout << i << " ";
	}
	cout << '\n';
}

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
	print_vec(v);
	print_vec(create_subset(v, 4));
}
