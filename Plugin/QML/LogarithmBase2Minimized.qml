import QtQuick 2.0
import com.malamute.calculator 1.0

OneToOneTemplate
{
    Connections
    {
        target: idea
        function onDisplay(inputNumber, outputNumber)
        {
            inputText = "Log<sub>2</sub>(<font color=\"" + idea.inPortLabelColors[0] + "\">" +
                    parseFloat(inputNumber) + "</font>" + ")";
            outputText = "= <font color=\"" + idea.outPortLabelColors[0] + "\">"
                    + parseFloat(outputNumber.toFixed(4)) + "</font>";
        }
        function onClear()
        {
            inputText = "Log<sub>2</sub>()";
            outputText = "= ";
        }
    }
}
