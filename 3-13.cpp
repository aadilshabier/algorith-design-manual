#include <bits/stdc++.h>
using namespace std;

struct BST
{
	int value;
	BST *left, *right;
};

static BST* find_incorrect(BST* root)
{
	if((root->left!=nullptr) && !(root->left->value < root->value))
		return root->left;
	else if((root->right!=nullptr) && !(root->right->value > root->value))
		return root->right;
	else
		return nullptr;
}

//Find parent of given node
static  BST* parent( BST* root,  BST* node)
{
	if(root->left == node || root->right == node)
		return root;

	if(root->left!=nullptr) {
		auto n = parent(root->left, node);
		if (n!=nullptr)
			return n;
	}
	if(root->right!=nullptr) {
		auto n = parent(root->right, node);
		if (n!=nullptr)
			return n;
	}
	return nullptr;
}

//Finds incorrect positions found and writes the nodes to nodes[2] and the amoutn found to n
static void _incorrect_positions( BST* root, BST* nodes[2], int *n)
{
	if(*n == 2)
		return;

	if (root->left!=nullptr) {
		if (!(root->left->value<root->value))
			nodes[(*n)++] = root->left;
		_incorrect_positions(root->left, nodes, n);
	}
	if (root->right!=nullptr) {
		if (!(root->right->value>root->value))
			nodes[(*n)++] = root->right;
		_incorrect_positions(root->right, nodes, n);
	}
}

//assumes there is always a swapped element
pair<BST*, BST*> find_swapped( BST* root)
{
	int n = 0;
	BST* nodes[2];
	_incorrect_positions(root, nodes, &n);
	if(n==2) {
		return make_pair(nodes[0], nodes[1]);
	} else if(n==1) {
		//exchanged nodes is the found node and its parent
		return make_pair(nodes[0], parent(root, nodes[0]));
	} else {
		assert(0 && "Something went wrong");
	}
}

int main()
{
	BST a, b, c;
	//CORRECT
	//       a
	//     /   \
	//    b     c
	//INCORRECT
	//       a
	//     /   \
	//    c     b
	// b and c are swapped
	b = {3, nullptr, nullptr};
	c = {9, nullptr, nullptr};
	swap(b, c);
	a = {6, &b, &c};
	auto [s1, s2] = find_swapped(&a);
	cout << s1->value << endl;
	cout << s2->value << endl;

	BST p, q, r;
	//CORRECT
	//       p
	//     /
	//    q
	//   /
	//  r
	//INCORRECT
	//       p
	//     /
	//    r
	//   /
	//  q
	// q and r are swapped
	q = {6, nullptr, nullptr};
	r = {3, &q, nullptr};
	p = {9, &r, nullptr};
	auto [s3, s4] = find_swapped(&p);
	cout << s3->value << endl;
	cout << s4->value << endl;
}
