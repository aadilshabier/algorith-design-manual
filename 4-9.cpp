#include <bits/stdc++.h>
using namespace std;

static bool _alg(const vector<int> &sorted_nums, size_t k, int x);

bool alg(const vector<int> &nums, size_t k, int x)
{
	auto sorted_nums{ nums };
	sort(sorted_nums.begin(), sorted_nums.end());
	return _alg(sorted_nums, k, x);
}



static bool _alg(const vector<int> &sorted_nums, size_t k, int x)
{
	assert(sorted_nums.size() >= k);
	assert(k > 0);
	if (k == 1)
		return binary_search(sorted_nums.begin(), sorted_nums.end(), x);
	return any_of(sorted_nums.begin(), sorted_nums.end(), [&](const auto &num) {
		return _alg(sorted_nums, k - 1, x - num);
	});
}

int main()
{
	vector<int> nums = {14, 0, 8, -3, 6, 21, 9, 2, -4, 6};
	cout << alg(nums, 7, 1000) << endl;
}
