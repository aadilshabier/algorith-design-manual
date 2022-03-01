#include <bits/stdc++.h>
using namespace std;

constexpr float BIN_MAX_WEIGHT = 1.0f;

size_t bestFit(const float* wx, size_t n)
{
	multiset<float, greater<float>> bins;
	for (size_t i=0; i<n; i++) {
		float required_space = BIN_MAX_WEIGHT - wx[i];
		auto it = bins.lower_bound(required_space);
	    if(it == bins.end()) {
			bins.insert(wx[i]);
		} else {
			auto node = bins.extract(it);
			node.value() += wx[i];
			bins.insert(move(node));
		}
	}
	cout << "Bins using best-fit: ";
	for(auto x: bins)
		cout << x << ' ';
	cout << endl;
	return bins.size();
}

size_t worstFit(const float* wx, size_t n)
{
	multiset<float> bins;
	for (size_t i=0; i<n; i++) {
		float required_space = BIN_MAX_WEIGHT - wx[i];
		auto smallest_it = bins.begin();
		if (smallest_it == bins.end() || required_space <= *smallest_it) {
			bins.insert(wx[i]);
		} else {
			auto node = bins.extract(smallest_it);
			node.value() += wx[i];
			bins.insert(move(node));
		}
	}
	cout << "Bins using worst-fit: ";
	for(auto x: bins)
		cout << x << ' ';
	cout << endl;
	return bins.size();
}

int main()
{
	vector<float> wx = {0.5, 0.5, 0.2, 0.5, 0.4, 0.2, 0.4, 0.6, 0.2, 0.4};
	auto x = bestFit(wx.data(), wx.size());
	cout << "Number of bins: " << x << endl;
	x = worstFit(wx.data(), wx.size());
	cout << "Number of bins: " << x << endl;
}
