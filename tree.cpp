/*
* Author: Owen Miller-Fast (oray-byte)
* Date created: 09/20/2021 @ 21:06
*/

#include "tree.h"

RB_Node::RB_Node(int data, bool color, RB_Node* parent = nullptr, RB_Node* lChild = nullptr, RB_Node* rChild = nullptr)
{
	this->data = data;
	this->color = color;
	this->parent = parent;
	this->lChild = lChild;
	this->rChild = rChild;
}

void RB_Tree::insert(int data)
{
	if (!root) // nullptr === 0
	{
		root = new RB_Node(data, false);
	}
	else
	{
		insertHelper(root, data);
	}
	return;
}

bool RB_Tree::find(int data)
{
	return findHelper(root, data);
}

void RB_Tree::print()
{
	printHelper(root, 0);
}

void RB_Tree::insertHelper(RB_Node* rt, int data)
{
	if ((data < rt->data) && (!rt->lChild))
	{
		rt->lChild = new RB_Node(data, true, rt);
		balance(rt->lChild);
		return;
	}

	if ((data >= rt->data) && (!rt->rChild))
	{
		rt->rChild = new RB_Node(data, true, rt);
		balance(rt->rChild);
		return;
	}

	(data < rt->data ? insertHelper(rt->lChild, data) : insertHelper(rt->rChild, data));
}

bool RB_Tree::findHelper(RB_Node* rt, int data)
{
	if (rt->data == data)
	{
		return true;
	}
	
	if ((!rt->lChild) && (!rt->rChild))
	{
		return false;
	}

	return (data < rt->data ? findHelper(rt->lChild, data) : findHelper(rt->rChild, data));
}

void RB_Tree::balance(RB_Node* rt)
{
	RB_Node* currGrandparent = nullptr;
	RB_Node* currUncle = nullptr;
	RB_Node* sibling = nullptr;

	// Establishing node's relationships
	if (rt->parent)
	{
		currGrandparent = rt->parent->parent;
	}

	if (rt == rt->parent->rChild)
	{
		sibling = rt->parent->lChild;
	}
	else
	{
		sibling = rt->parent->rChild;
	}

	if (currGrandparent)
	{
		if (rt->parent == currGrandparent->rChild)
		{
			currUncle = currGrandparent->lChild;
		}
		else
		{
			currUncle = currGrandparent->rChild;
		}
	}

	if ((rt->parent->color) && (currUncle->color))
	{
		rt->parent->color = false;
		currUncle->color = false;
		currGrandparent->color = true;
		balance(currGrandparent);
	}
	else if ((rt->parent->color) && (!currUncle->color))
	{
		// LL rotation
		if ((rt->parent->lChild) && (rt->parent == currGrandparent->lChild))
		{
			
		}
	}
}

void RB_Tree::printHelper(RB_Node* rt, int space)
{
    int i;
    if(rt)
    {
        space = space + 10;
        printHelper(rt->rChild, space);
        cout << "\n";
        for ( i = 10; i < space; i++)
        {
            cout << " ";
        }
		cout << rt->data << endl;
        printHelper(rt->lChild, space);
    }
}
    