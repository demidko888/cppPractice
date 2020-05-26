#pragma once
#include <vector>
#include <cassert>

using namespace std;

class PlayField {
public:
    enum FieldStatus { fsInvalid, fsCrossesWin, fsNoughtsWin, fsDraw, fsNormal };
    enum CellState { csEmpty, csCross, csNought };
    class CellIdx {
    public:
        static CellIdx CreateIndex(int x, int y) {
            assert(x >= 0 && y >= 0 && x < DIM && y < DIM);
            return { x, y };
        }

        int X() const {
            return x;
        }

        int Y() const {
            return y;
        }
    private:
        int x;
        int y;
        CellIdx(int x, int y) {
            this->x = x;
            this->y = y;
        }
    };
    CellState operator[](CellIdx index) const;
    vector<CellIdx> getEmptyCells() const;
    FieldStatus checkFieldStatus() const;
    PlayField makeMove(CellIdx index) const;
    bool operator==(const PlayField& second);
private:
    static constexpr int DIM = 3;
    CellState matrix[DIM][DIM]{ csEmpty };
    PlayField operator+(CellIdx index) const;
    bool isVertical(PlayField::CellState mark, int col) const;
    bool isHorizontal(PlayField::CellState mark, int row) const;
    bool isDiagonal(PlayField::CellState mark) const;
    bool HasWinSequence(PlayField::CellState mark) const;
    CellState GetNextMove() const;
    void Counts(int& crossesCount, int& noughtsCount) const;
};