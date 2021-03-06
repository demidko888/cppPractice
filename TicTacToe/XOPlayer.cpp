#include "XOPlayer.h"
#include "PlayField.h"

XOPlayer::XOPlayer(TreeNode& iStepsTree, PlayField::FieldStatus myMark) : stepsTree(iStepsTree) {
	currentTreeNode = &stepsTree;
	currentPlayerWinSequence = myMark;
}

void CountMyWins(TreeNode& root, int(&results)[3]) {
    if (root.isTerminal()) {
        switch (root.value().checkFieldStatus()) {
        case PlayField::fsCrossesWin:
            results[0]++;
            break;
        case PlayField::fsNoughtsWin:
            results[1]++;
            break;
        case PlayField::fsDraw:
            results[2]++;
            break;
        }
        return;
    }
    for (int i = 0; i < root.childCount(); i++)
        CountMyWins(root[i], results);
}

void XOPlayer::MakeMove(PlayField::CellIdx index){
    PlayField currentField = currentTreeNode->value().makeMove(index);
    checkFieldState(currentField);
}

void XOPlayer::MakeMove() {
    PlayField currentField;
    if (currentTreeNode[0].isTerminal())
        return;
    int maxCount = 0, maxIndex = 0, markIndex;
    if (currentPlayerWinSequence == PlayField::fsCrossesWin)
        markIndex = 0;
    else
        markIndex = 1;

    for (int i = 0; i < currentTreeNode->childCount(); ++i) {
        int results[3] = { 0,0,0 };
        CountMyWins(currentTreeNode[0][i], results);
        if (results[markIndex] + results[2] > maxCount) {
            maxCount = results[markIndex] + results[2];
            maxIndex = i;
        }
    }
    auto temp = currentTreeNode[0][maxIndex].value();
    currentField = currentTreeNode->value().makeMove(GetNextMoveIndex(temp));
    checkFieldState(currentField);
}

void XOPlayer::checkFieldState(PlayField currentState) {
    for (int i = 0; i < currentTreeNode->childCount(); ++i) {
        TreeNode& temp = currentTreeNode[0][i];
        if ((PlayField)temp.value() == currentState) {
            currentTreeNode = &currentTreeNode[0][i];
            break;
        }
    }
}

PlayField::CellIdx XOPlayer::GetNextMoveIndex(PlayField bestState){
    PlayField::CellIdx tempIndex = PlayField::CellIdx::CreateIndex(0, 0);
    for (int x = 0 ;x < DIM; ++x)
        for (int y = 0;y < DIM; ++y) {
            tempIndex = PlayField::CellIdx::CreateIndex(x, y);
            if (currentTreeNode->value()[tempIndex] != bestState[tempIndex])
                return tempIndex;
        }
    return tempIndex;
}