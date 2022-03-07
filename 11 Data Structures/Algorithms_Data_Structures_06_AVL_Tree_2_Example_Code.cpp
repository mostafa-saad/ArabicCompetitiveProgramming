/*
 *
 *
 ******************************************** Licence *******************************************
 * 																								*
 * This File is part of Algorithms Arabic Video Series											*
 *	Made By Eng Mostafa Saad, Teaching Assistant in FCI - Cairo University						*
 * 																								*
 *	Available at My YouTube Channel: http://www.youtube.com/user/nobody123497?feature=mhee		*
 * 																								*
 * Feel free to make use of it at anytime, with indication to his owner.	*
 * 																								*
 * 																								*
 * In case of finding a mistake, kindly notify me at: mostafa.saad.fci@gmail.com				*
 * 																								*
 * Mostafa Saad Ibrahim © 2014																	*
 * 																								*
 ************************************************************************************************
 *
 *
 */

#include<iostream>
#include<cstring>
using namespace std;







struct node{

	node *left, *right;
	int value, freq, height;
	static node* sentinel;				// one NULL for all tree elements

	node(){
			memset(this, 0, sizeof *this); //initialize all member variables to zero
	}

	node(int v){
			value = v;
			freq = height = 1;
			left = right = sentinel;
	}

	void updateHeight(){
			height = 1 + max(left->height, right->height);
	}

	int balanceFactor(){
			return left->height - right->height;
	}
};

node* node::sentinel = new node();

node* rightRotation(node* Q){

	node* P = Q->left;
	Q->left = P->right;
	P->right = Q;
	Q->updateHeight();
	P->updateHeight();
	return P;
}

node* leftRotation(node* P){

	node* Q = P->right;
	P->right = Q->left;
	Q->left = P;
	P->updateHeight();
	Q->updateHeight();
	return Q;
}

node* balance(node* root){

	if(root->balanceFactor() == 2)	// Left
	{
		if(root->left->balanceFactor() == -1)	// Left Right?
				root->left = leftRotation(root->left);	// Convert to Left Left

		root = rightRotation(root);	// Balance
	}
	else if(root->balanceFactor() == -2)
	{
		if(root->right->balanceFactor() == 1)
				root->right = rightRotation(root->right);

		root = leftRotation(root);
	}
	return root;
}

node* insert(node* root, int val){

	//Normal BST Insert
	if(root == node::sentinel)
	   return new node(val);

	if(val == root->value){
		root->freq++;
		return root;
	}

	if(val < root->value)
		root->left = insert(root->left, val);
	else
		root->right = insert(root->right, val);

	//AVL Change
	root->updateHeight();
	root = balance(root);
	return root;
}


int main() {
	return 0;
}
