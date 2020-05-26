#pragma once
#include <vector>
#include "PlayField.h"

using namespace std;

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
    int childQty() const;
    const PlayField state;
    vector<TreeNode*> children;
    const TreeNode* parent = nullptr;
};