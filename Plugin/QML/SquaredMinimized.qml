import QtQuick 2.0
import com.malamute.calculator 1.0

OneToOneTemplate
{
    Connections
    {
        target: idea
        function onDisplay(inputNumber, outputNumber)
        {
            if(inputNumber > 0.0)
            {
            inputText = "<font color=\"" + idea.inPortLabelColors[0] + "\">" +
                    parseFloat(inputNumber.toPrecision(4)) + "</font>" + "^2";
            }
            else
            {
                inputText = "(<font color=\"" + idea.inPortLabelColors[0] + "\">" +
                        parseFloat(inputNumber.toPrecision(4)) + "</font>" + ")^2";
            }
            outputText = "= <font color=\"" + idea.outPortLabelColors[0] + "\">"
                    + parseFloat(outputNumber.toPrecision(4)) + "</font>";
        }
        function onClear()
        {
            inputText = "^2";
            outputText = "= ";
        }
    }
}
