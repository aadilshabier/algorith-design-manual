#include <bits/stdc++.h>
using namespace std;

struct BST
{
	int value;
	BST *left, *right;
};

static int heightTree(BST* root)
{
	if(root==nullptr)
		return 0;
	return 1+max(heightTree(root->left), heightTree(root->right));
}

bool isBalanced(BST* root)
{
	return (abs(heightTree(root->left)-heightTree(root->right)) <= 1);
	   
}

int main()
{}
