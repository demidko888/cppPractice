#include <cassert>
#include "PlayField.h"

using namespace std;

bool PlayField::operator==(const PlayField& second) const{
	for (int x = 0; x < DIM; x++)
		for (int y = 0; y < DIM; y++)
			if (matrix[x][y] != second[CellIdx::CreateIndex(x, y)])
				return false;
	return true;
}

PlayField PlayField::operator+(CellIdx index) const {
	assert(matrix[index.X()][index.Y()] == csEmpty);
	PlayField newField = PlayField(*this);
	newField.matrix[index.X()][index.Y()] = GetNextMove();
	return newField;
}

PlayField::CellState PlayField::operator[](CellIdx index) const{
	return matrix[index.X()][index.Y()];
}

PlayField::FieldStatus PlayField::checkFieldStatus() const{
	int crossesCount = 0;
	int noughtsCount = 0;
	Counts(crossesCount, noughtsCount);
	bool isCrossesWin = HasWinSequence(csCross);
	bool isNoughtsWin = HasWinSequence(csNought);
	int count = crossesCount - noughtsCount;
	bool isNormal = (count == 1 || count == 0);
	if (!isNormal)
		return fsInvalid;
	bool isMovesEnd = crossesCount+noughtsCount==9;
	assert(!(isCrossesWin && isNoughtsWin));
	if (!isCrossesWin && !isNoughtsWin && isMovesEnd)
		return fsDraw;
	FieldStatus fsWin = isCrossesWin ? fsCrossesWin : fsNoughtsWin ;
	return (isCrossesWin || isNoughtsWin) ? fsWin : fsNormal;
}

PlayField PlayField::makeMove(CellIdx index) const{
	assert(matrix[index.X()][index.Y()] == csEmpty);
	return *this + index;
}


bool PlayField::isVertical(PlayField::CellState mark, int col) const{
	for (int y = 0; y < DIM; y++)
		if (matrix[col][y] != mark)
			return false;
	return true;
}

bool PlayField::isHorizontal(PlayField::CellState mark, int row) const{
	for (int x=0;x<DIM;x++)
		if (matrix[x][row] != mark)
			return false;
	return true;
}

bool PlayField::isDiagonal(PlayField::CellState mark) const{
	return (matrix[0][0] == mark && matrix[1][1] == mark && matrix[2][2] == mark)
		|| (matrix[2][0] == mark && matrix[1][1] == mark && matrix[0][2] == mark);
}

bool PlayField::HasWinSequence(PlayField::CellState mark) const{
	bool horiz = isHorizontal(mark, 0) || isHorizontal(mark, 1) || isHorizontal(mark, 2);
	bool vert = isVertical(mark, 0) || isVertical(mark, 1) || isVertical(mark, 2);
	bool diagonal = isDiagonal(mark);
	return horiz || vert || diagonal;
}

PlayField::CellState PlayField::GetNextMove() const{
	int crossCount = 0, noughtCount = 0;
	Counts(crossCount, noughtCount);
	int count = crossCount - noughtCount;
	assert(crossCount + noughtCount < DIM * DIM);
	assert(count == 1 || count == 0);
	return (count == 1 ) ? csNought : csCross;
}

vector<PlayField::CellIdx> PlayField::getEmptyCells() const {
	vector<CellIdx> emptyCells;
	for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++)
			if (matrix[x][y] == csEmpty)
				emptyCells.push_back(PlayField::CellIdx::CreateIndex(x, y));
	return emptyCells;
}

void PlayField::Counts(int& crossesCount, int& noughtsCount) const{
	for (auto x : matrix)
		for (int y = 0; y < DIM; y++)
			switch (x[y]) {
			case csNought:
				noughtsCount++;
				break;
			case csCross:
				crossesCount++;
				break;
			}
}

PlayField::CellIdx PlayField::CellIdx::CreateIndex(int x, int y) {
	assert(x >= 0 && y >= 0 && x < DIM && y < DIM);
	return { x, y };
}
