import QtQuick 2.12

Rectangle
{
    id: tile;

    property color fadeColor: "black"
    property real shrinkWidth: 0.0;
    function fadeOut(color)
    {
        fadeColor = color;
        fadeOutAnimation.start();
    }

    function resetColor(color)
    {
        fadeOutAnimation.stop();
        tile.color = color;
        tile.opacity = 1.0;
    }
    function shrink(width)
    {
        shrinkWidth = width;
        shrinkAnimation.start();
    }

    SequentialAnimation
    {
        id: fadeOutAnimation

        PropertyAnimation
        {
            target: tile
            property: "color"
            to: fadeColor
            duration: 200
        }
        ParallelAnimation
        {
            NumberAnimation
            {
                target: tile
                properties: "width,height,opacity"
                to: 0.0;
                duration: 1000
                easing.type: Easing.OutQuad
            }
            NumberAnimation
            {
                target: tile
                property: "x"
                to: tile.x + tile.width;
                duration: 1000
                easing.type: Easing.OutQuad
            }
        }
    }
    SequentialAnimation
    {
        id: shrinkAnimation
        PauseAnimation
        {
            duration: 200
        }
        NumberAnimation
        {
            target: tile
            property: "width"
            to: shrinkWidth;
            duration: 1000
            easing.type: Easing.OutQuad
        }
    }
}
