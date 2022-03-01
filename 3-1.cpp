#include <bits/stdc++.h>
using namespace std;

bool balanced(const string& s)
{
	vector<char> stack;
	for(size_t i=0; i<s.size(); i++) {
		switch(s[i]) {
		case '(':
			stack.push_back('(');
			break;
		case ')':
			if(stack.size()>0)
				stack.pop_back();
			else
				return false;
			break;
		}
	}
	return true;
}

int main()
{
	string s1 = "(())()((()()))";
	string s2 = "(()))((()()))";
	cout << "balanced(\"" << s1 << "\") = " << balanced(s1) << endl;
	cout << "balanced(\"" << s2 << "\") = " << balanced(s2) << endl;
}
