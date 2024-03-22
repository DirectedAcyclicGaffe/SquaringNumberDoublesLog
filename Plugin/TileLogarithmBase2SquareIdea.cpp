#include "TileLogarithmBase2SquareIdea.h"
#include <cmath>

TileLogarithmBase2SquareAttributes::TileLogarithmBase2SquareAttributes()
{
    m_listName = "Logarithm Base 2 (Tiles in square)";
    m_displayName = "Logarithm Base 2";
    m_iconPath = "qrc:/Icons/LogarithmBase2.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_embeddedQMLPath = ":/QML/TileLogarithmBase2SquareIdea.qml";
    m_minimizedQMLPath = ":/QML/LogarithmBase2Minimized.qml";
    m_minimizedName = "";
    m_startMinimized = false;

    m_gear = true;
}

TileLogarithmBase2SquareIdea::TileLogarithmBase2SquareIdea()
{

}

const IdeaAttributes TileLogarithmBase2SquareIdea::attributes()
{
    return Magic<TileLogarithmBase2SquareAttributes>::cast();
}

void TileLogarithmBase2SquareIdea::resetDisplay()
{
    if(valid())
    {
        double n = m_input.lock()->number();
        double log = std::log2(n);
        emit display(n, log);
    }
}
