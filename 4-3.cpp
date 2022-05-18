#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> min_pairs(const vector<int> &nums)
{
	assert(nums.size() % 2 == 0);
	vector<int> nums_sorted(nums);
	sort(nums_sorted.begin(), nums_sorted.end());

	vector<pair<int, int>> pairs;
	pairs.reserve(nums.size() / 2);
	for (size_t i = 0; i < nums.size() / 2; i++) {
		pairs.emplace_back(nums[i], nums[nums.size()-1-i]);
	}
	return pairs;
}

int main()
{
	vector<int> v = {1, 3, 5, 9};
	auto pairs = min_pairs(v);
	for (auto [x, y] : pairs)
		cout << '(' << x << ", " << y << ") ";
	cout << '\n';
}
