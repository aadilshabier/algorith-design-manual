#include <bits/stdc++.h>
using namespace std;

bool alg(const vector<int> &v1, const vector<int> &v2, int x)
{
	assert(v1.size() == v2.size());
	auto sorted_v1{v1}, sorted_v2{v2};
	sort(sorted_v1.begin(), sorted_v1.end());
	sort(sorted_v2.begin(), sorted_v2.end());

	for (const auto &x1 : sorted_v1) {
		if (binary_search(sorted_v2.begin(), sorted_v2.end(), x - x1))
			return true;
	}
	return false;
}

int main()
{
	vector<int> v1 = {1, 5, 8, 3};
	vector<int> v2 = {6, -3, 2, 1};
	int x = 11;
	if (alg(v1, v2, x))
		cout << "FOUND\n";
	else
		cout << "NOT FOUND\n";
}
