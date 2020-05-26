#pragma once
#include "TreeNode.h"
#include "PlayField.h"

class XOPlayer {
public:
    XOPlayer(TreeNode& iStepsTree, PlayField::FieldStatus myMark);
    PlayField::FieldStatus fieldStatus() const { return currentFieldState.checkFieldStatus(); };
    PlayField currentState() const { return currentFieldState; };
    void MakeMove();
    void MakeMove(PlayField::CellIdx index);
private:
    static constexpr int DIM = 3;
    TreeNode* stepsTree;
    PlayField currentFieldState;
    PlayField::FieldStatus currentPlayerWinSequence;
    void checkFieldState();
    PlayField::CellIdx GetNextMoveIndex(PlayField bestSate);
};