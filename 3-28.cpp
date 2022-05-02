#include <bits/stdc++.h>
using namespace std;

/* Solution using multiple arrays */
template <typename T>
class PartialSumA
{
public:
	PartialSumA(const vector<T>& v)
		: m_size(v.size())
	{
		cout << "Initializing data structure:\n";
		for (size_t step = v.size(); step > 0; step /= 2) {
			vector<T> v_step;
			for (auto i = v.cbegin(); i+step <= v.cend(); i += step) {
				cout << '(' << i-v.cbegin() << ' ' << i+step-v.cbegin() << ") ";
				const auto &&sum = std::accumulate(i, i+step, T{});
				v_step.push_back(sum);
			}
			cout << '\n';
			v_step.shrink_to_fit();
			m_array.push_back(std::move(v_step));
		}
		m_array.shrink_to_fit();
		cout << "Finished initializing data structure.\n";
	}

	/* Add value y to the ith element */
	void add(size_t i, const T& y)
	{
		for (auto &j : m_array) {
			// find which split the element exists in
			auto split_size = m_size / j.size();
			auto split = i / split_size;
			// check if the element is in the splits at all
			if (split < j.size()) {
				j[split] += y;
			}
		}
	}

	/* sum of first `i` elements */
	T partialSum(size_t i) const
	{
		T sum{};
		size_t start = 0;
		for (auto &j : m_array) {
			auto split_size = m_size / j.size();
			// indexes for the splits which contain the remaining elements
			size_t split_start, split_end;
			split_start = start / split_size;
			split_end = i / split_size;
			sum += std::accumulate(j.begin()+split_start, j.begin()+split_end, T{});
			start = split_end * split_size;
			if (start == i)
				break;
		}
		return sum;
	}

private:
	/* allocated workspace
	 *
	 * let s(i, j) = sum from i to j
	 * for an array with 7 elements
	 * m_array = [
	 *   [sum(0, 4)]
	 *   [sum(0, 2), sum(2, 4), sum(4, 6)],
	 *   [sum(0, 1), sum(1, 2), ...., sum(6, 7)],
	 * ]
	 */
	vector<vector<T>> m_array;
	size_t m_size;
};

int main()
{
	vector<int> v = {1, 2, 3, 4, 5, 6, 7};
	PartialSumA<int> ps(v);
	cout << "Before adding:\n";
	for (size_t i=0; i<v.size(); i++)
		cout << i << ": " << ps.partialSum(i) << endl;
	ps.add(1, 4);
	cout << "After adding:\n";
	for (size_t i=0; i<v.size(); i++)
		cout << i << ": " << ps.partialSum(i) << endl;
}
