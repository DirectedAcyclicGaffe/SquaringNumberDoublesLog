import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtMultimedia 5.15

import com.malamute.tileCalculator 1.0
import "LogarithmHelperFunctions.js" as HelperFunctions

Item
{
    id: root
    width: 344
    height: 240

    readonly property real base : 2.0
    property real inputNumber: 0.0;
    property real outputNumber: 0.0;
    property real currentlyShownBoxes: 0.0;
    property real divisions: 0.0;

    function setupActionPicture(base){HelperFunctions.setupActionPicture(base);}
    Component.onCompleted:{setupActionPicture(base);}

    Connections
    {
        target: idea
        function onDisplay(input, output)
        {
            inputNumber = input;
            outputNumber = output;
            if(input > 32 || input < 1)
            {
                divideByBaseButton.enabled = false;
                resetButton.enabled = false;
                outputText.text = outputNumber.toPrecision(4)

                animationUnsupportedText.visible = true;
                outputText.visible = false;
                inputText.visible = false;
                visualArea.visible = false;
            }
            else
            {
                currentlyShownBoxes = input;

                divisions = 0.0;
                divideByBaseButton.enabled = true
                resetButton.enabled = true
                outputText.text = "0";
                inputText.text = parseFloat(inputNumber.toPrecision(4));
                visualArea.setup(input, idea.inPortLabelColors[0], idea.outPortLabelColors[0])

                animationUnsupportedText.visible = false;
                outputText.visible = true;
                inputText.visible = true;
                visualArea.visible = true;
            }
        }
        function onClear()
        {
            animationUnsupportedText.visible = false;
            inputText.text = "";
            outputText.text = "";
        }

        function onOutPortLabelColorsChanged()
        {
            HelperFunctions.clearActionPicture();
            HelperFunctions.setupActionPicture(base);
        }
    }

    Rectangle
    {
        id: inputArea
        anchors.left: parent.left
        height: parent.height
        width: 64
        gradient: Gradient
        {
            GradientStop{position: 0.0; color: "black"}
            GradientStop{position: 0.5; color: "#282828"}
            GradientStop{position: 1.0; color: "black"}
        }

        Rectangle
        {
            id: inputBox
            anchors.centerIn: parent
            width: 60
            height: 60
            color: idea.inPortLabelColors[0]
            border.width: 6
            border.color: Qt.darker(idea.inPortLabelColors[0]);
        }

        Text
        {
            anchors.top: inputBox.bottom
            anchors.topMargin: 4
            id: inputText
            text: "";
            color: idea.inPortLabelColors[0]
            font.pointSize: 12
            font.family: "verdana"
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    Rectangle
    {
        id: outputArea
        anchors.right: parent.right
        height: parent.height
        width: 64
        gradient: Gradient
        {
            GradientStop{position: 0.0; color: "black"}
            GradientStop{position: 0.5; color: "#282828"}
            GradientStop{position: 1.0; color: "black"}
        }

        Image
        {
            id: actionPicture
            anchors.centerIn: parent
            fillMode: Image.PreserveAspectFit
            width: 64
            source: "qrc:/Images/DownArrows.png"

            Item
            {
                id: topRectanglesContainer
                width: 64
                height: 20
                y: 14
            }

            Item
            {
                id: midRectanglesContainer
                width: 64
                height: 20
                y: 51
            }

            Item
            {
                id: botRectanglesContainer
                width: 64
                height: 20
                y: 88
            }
        }

        Text
        {
            id: outputText
            anchors.top: actionPicture.bottom
            anchors.topMargin: 4
            anchors.horizontalCenter: parent.horizontalCenter
            y: 190
            color: idea.outPortLabelColors[0]
            font.pointSize: 12
            font.family: "verdana"
            font.bold: true
            text: parseFloat(divisions.toPrecision(4));
        }
    }

    Rectangle
    {
        width: 208
        height: 208
        anchors.horizontalCenter: parent.horizontalCenter
        color: "#050512"
        radius: 4
    }

    LogBase2VisualArea
    {
        id: visualArea
        opacity:  idea.valid ? 1.0 : 0.0
        y: 4
        width: 200
        anchors.horizontalCenter: parent.horizontalCenter
        height: 200
    }

    Text
    {
        id: animationUnsupportedText;
        text: "Animation Unsupported";
        horizontalAlignment: Text.AlignHCenter
        color: "white"
        font.bold: true;
        font.pointSize: 12
        anchors.centerIn: visualArea
        visible: false
    }

    Rectangle
    {
        id: controlsRow
        width: buttonsRow.width + 10
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        height: 34
        radius: 4
        color: "#050512"

        Row
        {
            id: buttonsRow
            x: 5
            spacing: 6
            visible: idea.valid

            Button
            {
                id: divideByBaseButton
                height: 32
                enabled: idea.valid;
                anchors.verticalCenter: parent.verticalCenter;
                text: "Divide by 2"
                onClicked:
                {
                    if(currentlyShownBoxes > 1)
                    {
                        visualArea.action();
                        popSound.play();
                        currentlyShownBoxes /= base;
                        divisions += 1;
                        if(currentlyShownBoxes > 1)
                            outputText.text = parseFloat(divisions.toPrecision(4));
                        else
                            outputText.text = parseFloat(outputNumber.toPrecision(4));
                    }
                }
                font.capitalization: Font.MixedCase
                font.family: "verdana"
                font.bold: true;
                font.pointSize: 12
                Material.background: idea.outPortLabelColors[0]
                Material.foreground: "black"
            }

            Button
            {
                id: resetButton
                height: 32
                text: "Reset"
                enabled: idea.valid;
                anchors.verticalCenter: parent.verticalCenter;
                onClicked:
                {
                    visualArea.reset();
                    currentlyShownBoxes = inputNumber;
                    divisions = 0.0;
                    outputText.text = "0";
                }
                font.capitalization: Font.MixedCase
                font.family: "verdana"
                font.bold: true;
                font.pointSize: 12
                Material.background: Material.Grey
                Material.foreground:  "black"
            }
        }
    }

    SoundEffect
    {
        id: popSound
        source: "qrc:/SoundEffects/shortPop.wav"
        volume: 0.3
    }
}
