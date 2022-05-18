#include <bits/stdc++.h>
using namespace std;

template<typename T>
T mode(const vector<T> &vec)
{
	vector<T> sorted_vec(vec);
	sort(sorted_vec.begin(), sorted_vec.end());

	T curr_elem = sorted_vec[0], max_elem = sorted_vec[0];
	size_t curr_count = 0, max_count = 0;

	for (const auto &x : sorted_vec) {
		if (x == curr_elem) {
			curr_count++;
			if (curr_count > max_count) {
				max_elem = curr_elem;
				max_count = curr_count;
			}
		} else {
			curr_elem = x;
			curr_count = 1;
		}

	}

	return max_elem;
}

int main()
{
	vector<int> v = {4, 6, 2, 4, 3, 1};
	cout << mode(v) << endl;
}
