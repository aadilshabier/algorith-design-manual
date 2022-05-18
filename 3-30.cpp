#include <bits/stdc++.h>
using namespace std;

class HotelManagement
{
public:
	// initialize hotel with n rooms
	HotelManagement(size_t n)
		: m_rooms(n)
	{
		for (size_t s = m_rooms; s > 0; s /= 2) {
			auto n_splits = m_rooms / s;
			m_occupancy.insert(m_occupancy.end(), n_splits, 0);
		}
		m_occupancy.shrink_to_fit();
	}

	// number of avaliable rooms in [l, h]
	size_t count(size_t l, size_t h)
	{
		assert(h >= l);
		// number of occupied rooms
		size_t total = 0;
		// number of avaliable rooms in [l, h] = number of rooms in [l, h] - number of occupied rooms in [l, h]
		struct position {size_t l, h;};
		// vector which keeps track of any ranges of positions left to be evaluated
		vector<position> remaining = { {l, h} };
		// ranges for the next iteration of loop
		vector<position> new_remaining;
		for (size_t i = 0, s = m_rooms; s > 0 && remaining.size() > 0; s /= 2) {
			auto n_splits = m_rooms / s; // number of splits
			for (auto [l, h] : remaining) {
				// convert to float to get the float and ceiling
				size_t l_split = ceil((float)l / (float)s),
				       h_split = floor((float)l / (float)s);
				auto begin = m_occupancy.begin()+i+l_split,
				     end = m_occupancy.begin()+i+h_split;
				total += accumulate(begin, end, 0);
				// if the range [l, h] was not fully covered, add them to the remaining ranges to be processed
				if (l < l_split * s) {
					new_remaining.push_back({l, l_split * s});
				}
				if (h > h_split * s) {
					new_remaining.push_back({h_split * s, h});
				}
			}
			remaining = new_remaining;
			new_remaining.clear();
			i += n_splits;
		}
		return h - l - total;
	}

	// return index of first empty remove, -1 if all are occupied
	ssize_t checkIn(size_t l, size_t h)
	{
		assert(h >= l);
		for (size_t i = 0, s = m_rooms; s > 0; s /= 2) {
			auto n_splits = m_rooms / s;
			// find split with unoccupied rooms
			ssize_t j_missing = -1;
			for (size_t j = 0; j < n_splits; j++) {

			}
			i += n_splits;
		}
	}
private:
	size_t m_rooms;
	vector<int> m_occupancy;
};

int main()
{

}
