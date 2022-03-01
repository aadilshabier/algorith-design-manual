#include <bits/stdc++.h>
using namespace std;

struct Coord {
	float x, y;
};

float dist(const Coord& a, const Coord& b) {
	return sqrt(pow((a.x-b.x), 2) + pow((a.y-b.y), 2));
}

float tsp1(const vector<Coord>& coords)
{
	vector<bool> visited(coords.size(), false);

	if (coords.size() == 0) {
		return 0.f;
	}

	//choose i=0 as staring
	size_t i_current = 0;
	visited[i_current] = false;
	float distance = 0.f;
	ssize_t i_shortest;

	while (any_of(visited.cbegin(), visited.cend(), [](auto b){ return !b;})) {
		i_shortest = -1;
		float d_shortest = 0.f;
		for(size_t i=0; i<coords.size(); i++) {
			if (visited[i])
				continue;
			if((i_shortest == -1) ||
			   (dist(coords[i_current], coords[i]) < d_shortest)) {
				d_shortest = dist(coords[i_current], coords[i]);
				i_shortest = i;
			}
		}
		distance += d_shortest;
		visited[i_shortest] = true;
		i_current = i_shortest;
	}
	//return back to starting position
	distance += dist(coords[0], coords[i_shortest]);
	return distance;
}

int main()
{
	vector<Coord> coords = {{0.f, 0.f},
							{0.f, -21.f},
							{0.f, -5.f},
							{0.f, -1.f},
							{0.f, 1.f},
							{0.f, 3.f},
							{0.f, 11.f},
	};
	float d = tsp1(coords);
	cout << "Distance with tsp1: " << d << '\n';
	return 0;
}
