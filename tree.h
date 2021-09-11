/*
* Author: Owen Miller-Fast (oray-byte)
* Date created: 09/20/2021 @ 21:06
*/

#ifndef TREE_H
#define TREE_H


struct RB_Node
{
	/*
	* This structure is the data type used in the Red-black tree.
	* int data -> Holds desired data
	* bool color -> red = true, black = false
	* RB_Node* parent -> A pointer to the RB_Node's parent. The root will not have a parent (nullptr)
	* RB_Node* lChild -> A pointer to the RB_Node's left child.
	* RB_Node* rChild -> A pointer to the RB_Node's right child.
	*/
public:
	RB_Node(int data, bool color);

	int data;
	bool color;
	RB_Node* parent;
	RB_Node* lChild;
	RB_Node* rChild;
};

class RB_Tree
{
public:
	RB_Tree();
	~RB_Tree();
	
	void insert(int data);
	void remove(int data);
	void print();
	bool find(int data);
private:
	void balance();
	RB_Node* root;
	RB_Node* currentNode;
};

#endif