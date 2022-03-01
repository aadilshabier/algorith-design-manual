#include <bits/stdc++.h>
using namespace std;

int missing(const vector<int>& v)
{
	//sum 1 - n+1 = (n+1)(n+2)/2
	return (v.size()+1)*(v.size()+2)/2 - accumulate(v.begin(), v.end(), 0);
}

int main()
{
	cout << "Missing: " << missing({1, 7, 8, 5, 3, 4, 6}) << '\n';
}
