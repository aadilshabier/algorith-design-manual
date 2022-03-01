#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Solver
{
 public:
	virtual T getMin(size_t start, size_t end) const = 0;
};

/*
 * 0,  1; ... ;0, n
 * 1,  2; ... ;1, n
 * 2,  3; ... ;2, n
 * n-1,n
 */
template <typename T>
class AllSolutionsSolver : public Solver<T> {   
public:
	AllSolutionsSolver(const vector<T>& nums)
		: mSize(nums.size())
		, mCalculatedMins(mSize*(mSize+1))
	{
		for(size_t x1=0; x1<mSize; x1++) {
			for(size_t x2=x1+1; x2<=mSize; x2++) {
				mCalculatedMins[x1*mSize+x2] = *min_element(nums.begin()+x1,
															nums.begin()+x2);
			}
		}
	}
	T getMin(size_t x1, size_t x2) const override
	{
		assert(x1 < mSize && x2 <= mSize && x1 < x2);
		return mCalculatedMins[x1*mSize+x2];
	}
private:
	size_t mSize;
	vector<int> mCalculatedMins;
};


/* s is the size
 * [min(0, s/2), min(s/2, s)]
 * [min(0,s/4), ... , min(3s/4, s)]
 * ...
 */
template <typename T>
class MinSegmentTree : public Solver<T>
{
	struct Node
	{
		size_t start, end;
		T item;
		Node *left, *right;
	};
public:
	MinSegmentTree(const vector<int>& nums)
		: m_size(nums.size())
	{
		m_root = makeTree(nums, 0, nums.size());
	}
	~MinSegmentTree()
	{
		
	}
	T getMin(size_t start, size_t end) const override
	{
		assert(end > start);
		return minOfSubTree(m_root, start, end);
	}
private:
	static Node* makeTree(const vector<int>& nums, size_t start, size_t end)
	{
		if(end == start) {
			return nullptr;
		}

		Node* n = new Node;
		n->start = start;
		n->end = end;
		n->item = * min_element(nums.begin()+start,
								nums.begin()+end);
		// for single elements
		if(end - start == 1) {
			n->left = nullptr;
			n->right = nullptr;
		} else {
			size_t mid = (start + end) / 2;
			n->left = makeTree(nums, start, mid);
			n->right = makeTree(nums, mid, end);
		}

		return n;
	}
	static T minOfSubTree(Node* root, size_t start, size_t end)
	{
		assert(root->start <= start && root->end >= end);
		/* if r.s = s and r.e = e:
		 *     return r.item
		 * elif e <= r.left.e
		 *     return minOfSubTree(r.left, s, e)
		 * elif s >= r.right.s
		 *     return minOfSubTree(r.right, s, e)
		 * else
		 *     part = r.left.e
		 *     return min(minOfSubTree(r.left, s, part), minOfSubTree(r.right, part, e))
		 */
		if (root->start == start && root->end == end) {
			return root->item;
		} else if (end <= root->left->end) {
			return minOfSubTree(root->left, start, end);
		} else if (start >= root->right->start) {
			return minOfSubTree(root->right, start, end);
		} else {
			size_t sep = root->left->end; //same as root->right->start
			return min(minOfSubTree(root->left, start, sep),
					   minOfSubTree(root->right, sep, end));
		}
	}
private:
	Node* m_root;
	size_t m_size;
};

int main()
{
	vector<int> nums = {1, 5, 1, 7, 2, 7, 2, 4, 6};
	AllSolutionsSolver ass(nums);
	MinSegmentTree<int> msb(nums);

	cout << "Using AllSolutionsSolver: " << ass.getMin(7, 9) << endl;
	cout << "Using MinSegmentTree: " << msb.getMin(7, 9) << endl;

	cout << "Using AllSolutionsSolver: " << ass.getMin(1, 4) << endl;
	cout << "Using MinSegmentTree: " << msb.getMin(1, 4) << endl;
}
