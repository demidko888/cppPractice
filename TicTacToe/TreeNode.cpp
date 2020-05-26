#include <cassert>
#include "TreeNode.h"

using namespace std;

TreeNode::TreeNode(PlayField newState, TreeNode* newParent) : state(newState), parent(newParent){
}

bool TreeNode::isTerminal() const{
	assert(state.checkFieldStatus() != PlayField::fsInvalid);
	return state.checkFieldStatus() == PlayField::fsNoughtsWin ||
		state.checkFieldStatus() == PlayField::fsCrossesWin ||
		state.checkFieldStatus() == PlayField::fsDraw;
}

void TreeNode::addChild(TreeNode* child){
	assert(children.size() <= DIM*DIM);
	child->parent = this;
	children.push_back(child);
}

TreeNode& TreeNode::operator[](int index) const{
	return *children[index];
}

int TreeNode::childCount() const{
	return children.size();
}

const PlayField& TreeNode::value() const{
	return state;
}

int TreeNode::childQty() const{
	return (parent ? parent->childQty() - 1 : DIM*DIM);
}
