#ifndef TILELOGARITHMBASE2SQUAREIDEA_H
#define TILELOGARITHMBASE2SQUAREIDEA_H

#include "LogarithmBase2Idea.h"

struct TileLogarithmBase2SquareAttributes : public IdeaAttributes
{
    TileLogarithmBase2SquareAttributes();
};

class TileLogarithmBase2SquareIdea : public LogarithmBase2Idea
{
    Q_OBJECT

public:
    explicit TileLogarithmBase2SquareIdea();
    const IdeaAttributes attributes() override;

    void resetDisplay() override;
};

#endif // TILELOGARITHMBASE2SQUAREIDEA_H
