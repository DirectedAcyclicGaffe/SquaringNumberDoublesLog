function createBoxesSquared(inputNumber1, outputNumber)
{
    let inputNumber2 = inputNumber1;
    let borderWidth
    let spacing;
    let xBoxNum;

    let boxComponent;
    let boxObject;

    let totalBoxes = Math.ceil(inputNumber1);

    let col0 = idea.inPortLabelColors[0];
    let col2 = Qt.rgba(1,1,1,0.0)

    if(inputNumber1 <= 4)
    {
        borderWidth = 5;
        spacing = 50;
        xBoxNum = 4;
    }
    else if(inputNumber1 <= 8)
    {
        borderWidth = 2;
        spacing = 25;
        xBoxNum = 8;
    }
    else if(inputNumber1 <= 16)
    {
        borderWidth = 1;
        spacing = 12.5;
        xBoxNum = 16;
    }
    else if(inputNumber1 <= 32)
    {
        borderWidth = 1;
        spacing = 6.25;
        xBoxNum = 32;
    }
    else if(inputNumber1 <= 200)
    {
        borderWidth = 0;
        spacing = 1;
        xBoxNum = 200;
    }

    let fadeInTime = 800 * Math.floor(Math.log2(totalBoxes + 1))

    let i = 0;
    for(i = 0; i < Math.floor(inputNumber1); i++)
    {
        boxComponent = Qt.createComponent("SquaringBox.qml");
        boxObject = boxComponent.createObject(animationArea, {borderWidth: borderWidth,
                                                  boxNumber: i, totalBoxes: totalBoxes, fadeInTime: fadeInTime,
                                                  initialRect: Qt.rect(spacing*i + 0.5,
                                                                         0.5, spacing - 1.0, spacing - 1.0),
                                                  initialColor: col0,
                                                  midColor: col0,
                                                  finalColor: idea.outPortLabelColors[0]})
    }


    for(i = 1; i < Math.floor(inputNumber2); i++)
    {
        boxComponent = Qt.createComponent("SquaringBox.qml");
        boxObject = boxComponent.createObject(animationArea, {borderWidth: borderWidth,
                                                  boxNumber: i - 1, totalBoxes: totalBoxes, fadeInTime: fadeInTime,
                                                  initialRect: Qt.rect(0.5,
                                                                         spacing*i + 0.5, spacing - 1.0, spacing - 1.0),
                                                  initialColor: col2,
                                                  midColor: col0,
                                                  finalColor: idea.outPortLabelColors[0]})
    }

    let numBoxesToAdd = ((Math.floor(inputNumber1)*Math.floor(inputNumber2)) - Math.floor(inputNumber1) - Math.floor(inputNumber2)) + 1;
    for(i = 0; i < numBoxesToAdd; i++)
    {
        boxComponent = Qt.createComponent("SquaringBox.qml");
        boxObject = boxComponent.createObject(animationArea, {borderWidth: borderWidth,
                                                  boxNumber: totalBoxes, totalBoxes: totalBoxes, fadeInTime: fadeInTime,
                                                  initialRect: Qt.rect((i%(Math.floor(inputNumber1) - 1)) * spacing + spacing + 0.5,
                                                                        Math.floor(i/(Math.floor(inputNumber1) - 1)) * spacing + spacing + 0.5,
                                                                       spacing - 1.0, spacing - 1.0),
                                                  initialColor: col2,
                                                  midColor: col2,
                                                  finalColor: idea.outPortLabelColors[0]})
    }
    if((inputNumber1 % 1.0) !== 0) // Fraction input1.
    {
        boxComponent = Qt.createComponent("SquaringBox.qml");
        boxObject = boxComponent.createObject(animationArea, {borderWidth: borderWidth,
                                                  boxNumber: Math.floor(inputNumber1) + 1, totalBoxes: totalBoxes, fadeInTime: fadeInTime,
                                                  initialRect: Qt.rect(spacing*Math.floor(inputNumber1) + 0.5,
                                                                         0.5, (spacing - 1.0) * (inputNumber1 % 1.0), spacing - 1.0),
                                                  initialColor: col0,
                                                  midColor: col0,
                                                  finalColor: idea.outPortLabelColors[0]})

        for(i = 1; i < Math.floor(inputNumber2); i++)
        {
            boxComponent = Qt.createComponent("SquaringBox.qml");
            boxObject = boxComponent.createObject(animationArea, {borderWidth: borderWidth,
                                                      boxNumber: totalBoxes, totalBoxes: totalBoxes, fadeInTime: fadeInTime,
                                                      initialRect: Qt.rect(spacing*Math.floor(inputNumber1) + 0.5,
                                                                             0.5 + spacing*i, (spacing - 1.0) * (inputNumber1 % 1.0), spacing - 1.0),
                                                      initialColor: col2,
                                                      midColor: col2,
                                                      finalColor: idea.outPortLabelColors[0]})
        }

    }
    if((inputNumber2 % 1.0) !== 0) // Need a fraction box for input 2.
    {
        boxComponent = Qt.createComponent("SquaringBox.qml");
        boxObject = boxComponent.createObject(animationArea, {borderWidth: borderWidth,
                                                  boxNumber: totalBoxes - 1, totalBoxes: totalBoxes, fadeInTime: fadeInTime,
                                                  initialRect: Qt.rect(0.5,
                                                                         spacing*Math.floor(inputNumber2) + 0.5, spacing - 1.0, (spacing - 1.0) * (inputNumber2 % 1.0)),
                                                  initialColor: col2,
                                                  midColor: col0,
                                                  finalColor: idea.outPortLabelColors[0]})

        for(i = 1; i < Math.floor(inputNumber1); i++)
        {
            boxComponent = Qt.createComponent("SquaringBox.qml");
            boxObject = boxComponent.createObject(animationArea, {borderWidth: borderWidth,
                                                      boxNumber: totalBoxes, totalBoxes: totalBoxes, fadeInTime: fadeInTime,
                                                      initialRect: Qt.rect(0.5 + spacing*i, spacing*Math.floor(inputNumber2) + 0.5,
                                                                           spacing - 1.0, (spacing - 1.0) * (inputNumber2 % 1.0)),
                                                      initialColor: col2,
                                                      midColor: col2,
                                                      finalColor: idea.outPortLabelColors[0]})
        }
    }
    if((inputNumber1 % 1.0) !== 0 && (inputNumber2 % 1.0) !== 0)
    {
        boxComponent = Qt.createComponent("SquaringBox.qml");
        boxObject = boxComponent.createObject(animationArea, {borderWidth: borderWidth,
                                                  boxNumber: totalBoxes, totalBoxes: totalBoxes, fadeInTime: fadeInTime,
                                                  initialRect: Qt.rect(spacing*Math.floor(inputNumber1) + 0.5, spacing*Math.floor(inputNumber2) + 0.5,
                                                                       (spacing - 1.0) * (inputNumber1 % 1.0), (spacing - 1.0) * (inputNumber2 % 1.0)),
                                                  initialColor: col2,
                                                  midColor: col2,
                                                  finalColor: idea.outPortLabelColors[0]})
    }
}

function multiply()
{
    for(let i = 0; i < animationArea.children.length; i++)
    {
        animationArea.children[i].animate();
    }
}

function reset()
{
    for(let i = 0; i < animationArea.children.length; i++)
    {
        animationArea.children[i].reset();
    }
}

function clearBoxes()
{
    for(let i = 0; i < animationArea.children.length; i++)
    {
        animationArea.children[i].destroy();
    }
}
