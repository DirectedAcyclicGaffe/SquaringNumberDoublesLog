#include "Plugin.h"

#include "NumberDataType.h"
#include "NumberDisplayIdea.h"
#include "TileLogarithmBase2Idea.h"
#include "NumberInputIdea.h"
#include "LogBase2VisualArea.h"
#include "TileSquaredIdea.h"
#include "SquaringVisualArea.h"

#include "TileLogarithmBase2SquareIdea.h"
#include "LogBase2SquareVisualArea.h"

QString Plugin::PluginName()
{
    return "Logarithm Base 2 Demo";
}

void Plugin::registerIdeas(std::shared_ptr<IdeaRegistry> ideaRegistry)
{
    ideaRegistry->registerIdea<NumberInputIdea>();
    ideaRegistry->registerIdea<TileSquaredIdea>();
    ideaRegistry->registerIdea<TileLogarithmBase2Idea>();
    ideaRegistry->registerIdea<TileLogarithmBase2SquareIdea>();
    ideaRegistry->registerIdea<NumberDisplayIdea>();

    qmlRegisterType(QUrl("qrc:/QML/OneToOneTemplate.qml"), "com.malamute.calculator", 1, 0, "OneToOneTemplate");
    qmlRegisterType<LogBase2VisualArea>("com.malamute.tileCalculator", 1, 0, "LogBase2VisualArea");
    qmlRegisterType<LogBase2SquareVisualArea>("com.malamute.tileCalculator", 1, 0, "LogBase2SquareVisualArea");
    qmlRegisterType<SquaringVisualArea>("com.malamute.tileCalculator", 1, 0, "SquaringVisualArea");

}

void Plugin::registerDataTypeAttributes(std::shared_ptr<DataTypeRegistry> dataTypeRegistry)
{
    dataTypeRegistry->registerDataTypeAttributes<NumberDataTypeAttributes>();
}

QString Plugin::defaultFile()
{
    return "qrc:/DemoFiles/InitialMutt.mutt";
}
