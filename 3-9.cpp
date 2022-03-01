#include <bits/stdc++.h>
using namespace std;

#define METHOD 3

const char* DICT_FILE_PATH = "3-9-dictionary.txt";

static int letterToKeypadNum(char c);
static int wordToKeypadNum(const string& s);

//Naive search
class Method1
{
public:
	Method1(ifstream& ifile)
	{
		for (string s; ifile >> s; ) {
			mWords.push_back(s);
		}
		mWords.shrink_to_fit();
	}
	vector<const string*> find(int n) const
	{
		vector<const string*> result;
		for(const auto& s: mWords) {
			if(wordToKeypadNum(s) == n)
				result.push_back(&s);
		}
		return result;
	}
private:
	vector<string> mWords;	
};

//Precompute and save keypad nums
class Method2
{
	struct Word
	{
		string s;
		int n;
	};
public:
	Method2(ifstream& ifile)
	{
		for (string s; ifile >> s; ) {
			mWords.push_back({s, wordToKeypadNum(s)});
		}
		mWords.shrink_to_fit();
	}
	vector<const string*> find(int n) const
	{
		vector<const string*> result;
		for(const auto& w: mWords) {
			if(w.n == n)
				result.push_back(&w.s);
		}
		return result;
	}
private:
	vector<Word> mWords;
};

//Precompute all results
class Method3
{
public:
	Method3(ifstream& ifile)
	{
		for (string s; ifile >> s; ) {
			mWords[wordToKeypadNum(s)].push_back(s);
		}
		for(auto &[_, x]: mWords)
			x.shrink_to_fit();
	}
	vector<const string*> find(int n) const
	{
		vector<const string*> result;
		if(mWords.count(n) != 0) {
			const auto& v = mWords.at(n);
			result.reserve(v.size());
			for(size_t i=0; i<v.size(); i++)
				result.push_back(&v[i]);
		}
		
		return result;
	}
private:
	unordered_map<int, vector<string>> mWords;
};

int main() {
	ifstream ifile(DICT_FILE_PATH);
#if (METHOD == 1)
	Method1 method(ifile);
#elif (METHOD == 2)
	Method2 method(ifile);
#elif (METHOD == 3)
	Method3 method(ifile);
#endif

	for(int n;;) {
		cout << "Enter number: ";
		if(!(cin >> n))
			break;
		auto results = method.find(n);
		if(results.size() == 0) {
			cout << "Not found\n";
		} else {
			cout << n << ":\n";
			for(size_t i=0; i<results.size(); i++)
				cout << i+1 << ". " << *results[i] << "\n";
		}
	}
	
	return 0;
}

static int letterToKeypadNum(char c)
{
	if     (c >= 'a' && c <= 'c')
		return 2;
	else if(c >= 'd' && c <= 'f')
		return 3;
	else if(c >= 'g' && c <= 'i')
		return 4;
	else if(c >= 'j' && c <= 'l')
		return 5;
	else if(c >= 'm' && c <= 'o')
		return 6;
	else if(c >= 'p' && c <= 's')
		return 7;
	else if(c >= 't' && c <= 'v')
		return 8;
	else if(c >= 'w' && c <= 'z')
		return 9;
	else
		assert(!"Invalid character");
}

static int wordToKeypadNum(const string& s)
{
	int n = 0;
	for(auto c: s) {
		n += letterToKeypadNum(c);
		n *= 10;
	}
	n /= 10;
	return n;
}
