#include "ComputerInput.h"

#include <algorithm>
#include <climits>
#include <fenv.h>

int ComputerInput::GetInput(gridMove* board)
{
    int bestVal = -1000;
    int bestMove = -1;

    for (int i = 0; i < 9; ++i)
    {
        if (board[i] != Empty)
            continue;

        board[i] = Computer;

        int evaluation = minimax(board, 0, false);

        board[i] = Empty;

        if (evaluation > bestVal)
        {
            bestVal = evaluation;
            bestMove = i;
        }
    }
    
    return bestMove;
}

int ComputerInput::minimax(gridMove* board, int depth, bool bMaximizing)
{
    int evaluation = evaluateBoard(board);
    
    if (evaluation != 0)
        return evaluation;

    if (IsTie(board))
        return 0;

    if (bMaximizing)
    {
        int bestVal = INT_MIN;
        
        for (int i = 0; i < 9; ++i)
        {
            if (board[i] != Empty)
                continue;

            board[i] = Computer;
        
            bestVal = std::max(bestVal, minimax(board, depth+1, false));

            board[i] = Empty;
        }
        return bestVal;
    }

    int bestVal = INT_MAX;

    for (int i = 0; i < 9; ++i)
    {
        if (board[i] != Empty)
            continue;

        board[i] = Player;
        
        bestVal = std::min(bestVal, minimax(board, depth+1, true));

        board[i] = Empty;
    }

    return bestVal;
}

int ComputerInput::evaluateBoard(gridMove* board)
{

    // Horizontal Check

    for (int j = 0; j < 3; ++j)
    {
        if (EqualsThree(board[j*3+0], board[j*3+1], board[j*3+2]))
        {
            if (board[j*3+0] == Player)
                return -10;
            return 10;
        }
    }

    // Vertical Check

    for (int i = 0; i < 3; ++i)
    {
        if (EqualsThree(board[0*3+i], board[1*3+i], board[2*3+i]))
        {
            if (board[0*3+i] == Player)
                return -10;
            return 10;
        }
    }


    // Diagonal Check

    if (EqualsThree(board[0], board[4], board[8]))
    {
        if (board[4] == Player)
            return -10;
        return 10;
    }
    else if (EqualsThree(board[2], board[4], board[6]))
    {
        if (board[4] == Player)
            return -10;
        return 10;
    }

    return 0;
}

bool ComputerInput::IsTie(gridMove* board)
{
    bool bIsTie = true;
    
    for (int i = 0; i < 9; ++i)
    {
        if (board[i] == Empty)
            bIsTie = false;
    }

    return  bIsTie;
}

bool ComputerInput::EqualsThree(gridMove A, gridMove B, gridMove C)
{
    return (A == B && B == C && A != Empty);
}
