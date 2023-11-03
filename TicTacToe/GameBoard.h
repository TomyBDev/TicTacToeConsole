#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "GridEnum.h"

#include <map>
#include <string>

class GameBoard
{
public:
    GameBoard();

    void DisplayGameBoard();

    bool PlayMove(int gridNum, gridMove type = Player);

    gameStatus GetGameState() const { return gameState; }

    gridMove* getBoard() { return board; }

private:

    void CheckWin();

    bool Equals3(gridMove A, gridMove B, gridMove C);

    void DisplayWinningInfo(std::string winType);

    void DisplayDrawInfo();
    
    void PrintLine();

    void PrintNumbers(int x, int y, int z);
    
    gridMove board[9];

    gameStatus gameState = Playing;

    int numMoves = 1;

    std::map<int,char> translator = {{0, ' '}, {1, 'X'}, {2, 'O'}};

    std::map<int,std::string> winningTranslator = {{0, ""}, {1, "Player"}, {2, "Computer"}};
};
#endif
