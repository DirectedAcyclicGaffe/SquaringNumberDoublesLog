import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtMultimedia 5.15
import com.malamute.tileCalculator 1.0

import "MultiplicationHelperFunctions.js" as HelperFunctions

Item
{
    id: root
    width: 344
    height: 240

    property real inputNumber1: 0.0;
    property real outputNumber: 0.0;

    Connections
    {
        target: idea
        function onDisplay(inputNumber1, outputNumber)
        {
            visualArea.clear();

            input1Text.text = parseFloat(inputNumber1.toPrecision(4));
            outputText.text = parseFloat(outputNumber.toPrecision(4));

            if(inputNumber1 < 1 || inputNumber1 > 32)
            {
                animationUnsupportedText.visible = true;
                multiplicationButton.enabled = false;
                resetButton.enabled = false;
                visualArea.visible = false;
            }
            else
            {
                visualArea.visible = true;
                visualArea.setup(inputNumber1, idea.inPortLabelColors[0], idea.outPortLabelColors[0]);
                animationUnsupportedText.visible = false;
                multiplicationButton.enabled = true;
                resetButton.enabled = true;
            }
        }
        function onClear()
        {
            input1Text.text = "";
            outputText.text = "";

            multiplicationButton.enabled = false;
            resetButton.enabled = false;
            animationUnsupportedText.visible = false;
            visualArea.clear();
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
            id: input1Box
            anchors.centerIn: parent

            width: 60
            height: 60
            color: idea.inPortLabelColors[0]
            border.width: 6
            border.color: Qt.darker(idea.inPortLabelColors[0]);
        }

        Text
        {
            id: input1Text
            anchors.top: input1Box.bottom
            anchors.topMargin: 4
            anchors.horizontalCenter: parent.horizontalCenter

            text: "";
            font.family: "verdana"
            font.bold: true
            color: idea.inPortLabelColors[0]
            font.pointSize: 12
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
        Rectangle
        {
            id: outputBox
            anchors.centerIn: parent
            width: 60
            height: 60
            color: idea.outPortLabelColors[0]
            border.width: 6
            border.color: Qt.darker(idea.outPortLabelColors[0]);
        }

        Text
        {
            anchors.top: outputBox.bottom
            anchors.topMargin: 4
            id: outputText
            text: "";
            font.family: "verdana"
            font.bold: true;
            color: idea.outPortLabelColors[0]
            font.pointSize: 12
            anchors.horizontalCenter: parent.horizontalCenter
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

    SquaringVisualArea
    {
        id: visualArea
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

            Button
            {
                id: multiplicationButton
                height: 32
                anchors.verticalCenter: parent.verticalCenter;
                onClicked:
                {
                    visualArea.action();
                    soundEffect.play();
                }
                font.family: "verdana"
                font.pointSize: 12
                font.bold: true;
                font.capitalization: Font.MixedCase
                Material.background: idea.outPortLabelColors[0]
                Material.foreground: "#1a1a1a"
                text: "Square"
            }
            Button
            {
                id: resetButton
                height: 32
                text: "Reset"
                anchors.verticalCenter: parent.verticalCenter;
                onClicked:
                {
                    visualArea.reset();
                }
                font.family: "verdana"
                font.pointSize: 12
                font.bold: true;
                font.capitalization: Font.MixedCase
                Material.background: Material.Grey
                Material.foreground:  "#1a1a1a"
            }
        }
    }

    MediaPlayer
    {
        id: soundEffect
        source: "qrc:/SoundEffects/riffle.wav"
        volume: 0.5
    }
}
