#include <iostream>
#include "PlayField.h"
#include "XOPlayer.h"
#include "TreeNode.h"

using namespace std;

void BuildSubTree(TreeNode& root);
void PrintField(PlayField field);
void PrintCell(PlayField::CellState cell);
void CountResults(TreeNode& root, int(&results)[3]);

int main()
{
    PlayField pf0;
    TreeNode node0(pf0,nullptr);
    BuildSubTree(node0);
    cout << "0 - watch game results, 1 - play game" << endl;
    int select;
    cin >> select;
    if (select == 0) {
        for (int i = 0; i < 9; i++) {
            PrintField(node0[i].value());
            int results[3] = { 0, 0, 0 };
            CountResults(node0[i], results);
            cout << "Crosses win count : " << results[0] << endl;
            cout << "Noughts win count : " << results[1] << endl;
            cout << "Draws count : " << results[2] << endl;
        }
    }
    if (select == 1) {
        cout << "Select player (0 - Xs, 1 - Os)" << endl;
        cin >> select;
        XOPlayer player(node0, (select == 0 ? PlayField::fsNoughtsWin : PlayField::fsCrossesWin));
        int x, y;
        do {
            PrintField(player.currentState());
            if (select == 0) {
                cout << "Enter index of cell [x,y]" << endl;
                cin >> x >> y;
                player.MakeMove(PlayField::CellIdx::CreateIndex(x, y));
                PrintField(player.currentState());
                player.MakeMove();
            }
            else {
                player.MakeMove();
                PrintField(player.currentState());
                cout << "Enter index of cell [x,y]" << endl;
                cin >> x >> y;
                player.MakeMove(PlayField::CellIdx::CreateIndex(x, y));
            }
        } while (player.fieldStatus() == PlayField::fsNormal);
        PrintField(player.currentState());
        if (player.fieldStatus() == PlayField::fsCrossesWin)
            cout << "Crosses are win" << endl;
        if (player.fieldStatus() == PlayField::fsNoughtsWin)
            cout << "Noughts are win" << endl;
        if (player.fieldStatus() == PlayField::fsDraw)
            cout << "Draw" << endl;
    }
}

#pragma region Functions

void BuildSubTree(TreeNode& root) {
    if (root.isTerminal())
        return;
    auto emptyCells = root.value().getEmptyCells();
    for (int i = 0; i < emptyCells.size(); i++) {
        root.addChild(new TreeNode(root.value().makeMove(emptyCells[i]), nullptr));
        BuildSubTree(root[i]);
    }
}

void PrintField(PlayField field) {
    cout << "-------" << endl;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++)
            PrintCell(field[PlayField::CellIdx::CreateIndex(x, y)]);
        cout << "|" << endl;
    }
    cout << "-------" << endl;
}

void PrintCell(PlayField::CellState cell) {
    string writing = "| ";
    switch (cell) {
    case PlayField::csCross:
        writing = "|X";
        break;
    case PlayField::csNought:
        writing = "|O";
        break;
    }
    cout << writing;
}

void CountResults(TreeNode& root, int(&results)[3]) {
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
    auto emptyCells = root.value().getEmptyCells();
    for (int i = 0; i < root.childCount(); i++) {
        CountResults(root[i], results);
    }
}
#pragma endregion



