#pragma once
#include "TreeNode.h"
#include "PlayField.h"

class XOPlayer {
public:

    XOPlayer(TreeNode& iStepsTree, PlayField::FieldStatus myMark);
    PlayField::FieldStatus fieldStatus() const { return currentState().checkFieldStatus(); }
    PlayField currentState() const { return currentTreeNode->value(); }
    void MakeMove();
    void MakeMove(PlayField::CellIdx index);
private:
    static constexpr int DIM = 3;
    TreeNode &stepsTree;
    TreeNode *currentTreeNode = nullptr;
    PlayField::FieldStatus currentPlayerWinSequence;
    PlayField::CellIdx GetNextMoveIndex(PlayField bestSate);
    void checkFieldState(PlayField state);
    
};