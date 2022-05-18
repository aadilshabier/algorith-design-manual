#include <bits/stdc++.h>
using namespace std;

enum class Color {Red, Blue, Yellow};

string conv(const Color &color)
{
	switch (color) {
    case Color::Red:
		return "Red";
	case Color::Blue:
		return "Blue";
	case Color::Yellow:
		return "Yellow";
	default:
		return "NONE";
	}
}

struct Item {
	int number;
	Color color;
};

void color_sort(vector<Item> &items)
{
	vector<Item> reds, blues, yellows;
	for (auto x : items) {
		switch (x.color) {
		case Color::Red:
			reds.push_back(x);
			break;
		case Color::Blue:
			blues.push_back(x);
			break;
		case Color::Yellow:
			yellows.push_back(x);
			break;
		default:
			break;
		}
	}

	auto it = copy(reds.begin(), reds.end(), items.begin());
	it = copy(blues.begin(), blues.end(), it);
	it = copy(yellows.begin(), yellows.end(), it);
}

int main()
{
	vector<Item> v = {
		{1, Color::Blue},
		{3, Color::Red},
		{4, Color::Blue},
		{6, Color::Yellow},
		{9, Color::Red},
	};

	color_sort(v);
	for (auto [n, c] : v) {
		cout << '(' << n << ", " << conv(c) << ") ";
	}
	cout << '\n';
}
