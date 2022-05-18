#include <bits/stdc++.h>
using namespace std;

size_t h_index(const vector<size_t> &citation_counts)
{
	auto sorted_counts{ citation_counts };
	sort(sorted_counts.begin(), sorted_counts.end()); // sort in descending order

	auto h = sorted_counts.size();
	for (auto x : sorted_counts) {
		if (x >= h)
			break;
		--h;
	}
	return h;
}

int main()
{
	vector<size_t> citations = {12, 21, 16, 1, 3, 7, 15, 17};
	cout << "h-index of author is: " << h_index(citations) << endl;
}
