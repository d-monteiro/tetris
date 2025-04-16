#ifndef _PIECES_
#define _PIECES_

// ——————————————————————————–
// Pieces
// ——————————————————————————–

class Pieces
{
public:
    int GetBlockType (int pPiece, int pRotation, int pX, int pY);
    int GetXInitialPosition (int pPiece, int pRotation);
    int GetYInitialPosition (int pPiece, int pRotation);

private:
    // Moved the array definitions to pieces.cpp
    static const char mPieces[7][4][5][5];
    static const int mPiecesInitialPosition[7][4][2];
};

#endif // _PIECES_