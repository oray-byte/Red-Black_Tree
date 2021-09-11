/*
* Author: Owen Miller-Fast (oray-byte)
* Date created: 09/20/2021 @ 21:06
*/

#include "tree.h"

RB_Node::RB_Node(int data, bool color)
{
	this->data = data;
	this->color = color;
	this->parent = nullptr;
	this->lChild = nullptr;
	this->rChild = nullptr;
}