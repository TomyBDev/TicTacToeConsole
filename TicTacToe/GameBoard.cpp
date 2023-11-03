#include "GameBoard.h"

#include <iostream>

GameBoard::GameBoard()
{
    for (auto& i : board)
    {
        i = Empty;
    }
}

void GameBoard::DisplayGameBoard()
{
    std::cout << "-+TicTacToe+-" << "\n\n";
    PrintNumbers(board[0], board[1], board[2]);
    PrintLine();
    PrintNumbers(board[3], board[4], board[5]);
    PrintLine();
    PrintNumbers(board[6], board[7], board[8]);
}

bool GameBoard::PlayMove(int gridNum, gridMove type)
{
    bool bValidMove = false;
    
    switch (board[gridNum]) {
    case Empty:
        board[gridNum] = type;
        CheckWin();
        bValidMove = true;
        if (numMoves++ >= 9 && gameState == Playing)
        {
            gameState = Draw;
            DisplayDrawInfo();
        }  
        break;
    case Player:
        std::cout << "Player already has placed here.\n";
        break;
    case Computer:
        std::cout << "Player already has placed here.\n";
        break;
    default:
        std::cout << "Invalid grid type.\n";
        break;
    }

    return bValidMove;
}

void GameBoard::CheckWin()
{
    // Horizontal Check

    for (int j = 0; j < 3; ++j)
    {
        if (Equals3(board[j*3+0], board[j*3+1], board[j*3+2]))
        {
            gameState = static_cast<gameStatus>(board[j*3+0]);
            DisplayWinningInfo("Horizontal");
        }
    }
    
    // Vertical Check

    for (int i = 0; i < 3; ++i)
    {
        if (Equals3(board[0*3+i], board[1*3+i], board[2*3+i]))
        {
            gameState = static_cast<gameStatus>(board[0*3+i]);
            DisplayWinningInfo("Vertical");
        }
    }

    
    // Diagonal Check
    
    if (Equals3(board[0], board[4], board[8]))
    {
        gameState = static_cast<gameStatus>(board[4]);
        DisplayWinningInfo("Diagonal");
    }
    else if (Equals3(board[2], board[4], board[6]))
    {
        gameState = static_cast<gameStatus>(board[4]);
        DisplayWinningInfo("Diagonal");
    }
    
}

bool GameBoard::Equals3(gridMove A, gridMove B, gridMove C)
{
    return (A == B && B == C && A != Empty);
}

void GameBoard::DisplayWinningInfo(std::string winType)
{
    system("CLS");
    DisplayGameBoard();
    std::cout << "\n" << winningTranslator[gameState] << " won with a " << winType << " match.";
    
}

void GameBoard::DisplayDrawInfo()
{
    system("CLS");
    DisplayGameBoard();
    std::cout << "\n" <<  "Game was a draw.";
 
}

void GameBoard::PrintLine()
{
    std::cout << "    -+-+-" << "\n";
}

void GameBoard::PrintNumbers(int x, int y, int z)
{
    std::cout << "    " << translator[x] << "|" << translator[y] << "|" << translator[z] << "\n";
}