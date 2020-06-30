#pragma once
#include <vector>
#include "PlayField.h"

class TreeNode {
public:
    TreeNode(PlayField newState, TreeNode* parent = nullptr);
    bool isTerminal() const;
    void addChild(TreeNode* child);
    TreeNode& operator[](int index) const;
    int childCount() const;
    const PlayField& value() const;
private:
	static constexpr int DIM = 3;
    const int childQty() const;
    const PlayField state;
    std::vector<TreeNode*> children;
    const TreeNode* parent = nullptr;
};