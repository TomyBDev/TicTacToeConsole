#ifndef COMPUTER_INPUT_H
#define COMPUTER_INPUT_H

#include "GridEnum.h"

class ComputerInput
{
public:
    /** Empty Constructor */
    ComputerInput() = default;

    /** Returns Computers Move */
    int GetInput(gridMove* board);

private:

    int minimax(gridMove* board, int depth, bool bMaximizing);

    int evaluateBoard(gridMove* board);

    bool IsTie(gridMove* board);

    bool EqualsThree(gridMove A, gridMove B, gridMove C);
};
#endif