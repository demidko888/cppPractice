#pragma once
#include <cassert>
#include <vector>

class PlayField {
public:

    enum FieldStatus { fsInvalid, fsCrossesWin, fsNoughtsWin, fsDraw, fsNormal };

    enum CellState { csEmpty, csCross, csNought };

    class CellIdx {
    public:

        static CellIdx CreateIndex(int x, int y);

        int X() const { return x; }
        int Y() const { return y; }

    private:

        CellIdx(int iX, int iY) {
            x = iX;
            y = iY;
        }

        int x;
        int y;
    };

    CellState operator[](CellIdx index) const;
    FieldStatus checkFieldStatus() const;
    std::vector<PlayField::CellIdx> getEmptyCells() const;
    PlayField makeMove(CellIdx index) const;
    bool operator==(const PlayField& second) const;

private:
    static constexpr int DIM = 3;

    CellState matrix[DIM][DIM]{ csEmpty };    
	CellState GetNextMove() const;
    PlayField operator+(CellIdx index) const;

    bool isVertical(PlayField::CellState mark, int col) const;
    bool isHorizontal(PlayField::CellState mark, int row) const;
    bool isDiagonal(PlayField::CellState mark) const;
    bool HasWinSequence(PlayField::CellState mark) const;

    void Counts(int& crossesCount, int& noughtsCount) const;
};