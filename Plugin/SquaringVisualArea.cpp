#include "SquaringVisualArea.h"
#include <cmath>

SquaringVisualArea::SquaringVisualArea()
{
    setFlag(ItemHasContents);
}

void SquaringVisualArea::setup(double n, QColor inColor, QColor outColor)
{
    m_currentlyVisible = n;
    m_inputNum = n;
    m_outColor = outColor;
    m_inColor = inColor;

    clear();
    int sideBoxes = std::floor(n);
    prepareSizeVariables(std::ceil(n));

    m_tiles.reserve(sideBoxes);
    for(int i = 0; i < sideBoxes; i++) // Top row whole boxes
    {
        QQmlComponent comp(qmlEngine(this), QUrl(QStringLiteral("qrc:/QML/SquaringBox.qml")));

        QVariantMap map;
        map["boxNumber"] = i;
        map["totalBoxes"] = sideBoxes;
        map["fadeInTime"] = m_fadeInTime;
        map["x"] = 0.5 + m_spacing * (i % m_xBoxNum);
        map["y"] = 0.5 + m_spacing * std::floor(i/m_xBoxNum);
        map["width"] = m_spacing - 1.0;
        map["height"] = m_spacing - 1.0;
        map["initialColor"] = inColor;
        map["midColor"] = inColor;
        map["finalColor"] = outColor;
        map["border.width"] = m_borderWidth;

        QObject* obj = comp.createWithInitialProperties(map, qmlEngine(this)->rootContext());
        QQuickItem* visibleObj = static_cast<QQuickItem*>(obj);

        m_tiles.push_back(visibleObj);
        visibleObj->setParent(this);
        visibleObj->setParentItem(this);
    }

    for(int i = 0; i < sideBoxes; i++) // Side Column whole boxes
    {
        QQmlComponent comp(qmlEngine(this), QUrl(QStringLiteral("qrc:/QML/SquaringBox.qml")));

        QVariantMap map;
        map["boxNumber"] = i;
        map["totalBoxes"] = sideBoxes;
        map["fadeInTime"] = m_fadeInTime;
        map["x"] = 0.5;
        map["y"] = 0.5 + m_spacing * (i % m_xBoxNum);
        map["width"] = m_spacing - 1.0;
        map["height"] = m_spacing - 1.0;
        map["initialColor"] = QColor("transparent");
        map["midColor"] = inColor;
        map["finalColor"] = outColor;
        map["border.width"] = m_borderWidth;

        QObject* obj = comp.createWithInitialProperties(map, qmlEngine(this)->rootContext());
        QQuickItem* visibleObj = static_cast<QQuickItem*>(obj);

        m_tiles.push_back(visibleObj);
        visibleObj->setParent(this);
        visibleObj->setParentItem(this);
    }

    int numWholeBoxesToAdd = (std::floor(n) - 1) * (std::floor(n) - 1);
    for(int i = 0; i < numWholeBoxesToAdd; i++) // Fill boxes.
    {
        QQmlComponent comp(qmlEngine(this), QUrl(QStringLiteral("qrc:/QML/SquaringBox.qml")));

        QVariantMap map;
        map["boxNumber"] = sideBoxes;
        map["totalBoxes"] = sideBoxes;
        map["fadeInTime"] = m_fadeInTime;
        map["x"] = 0.5 + m_spacing + m_spacing *(i % (sideBoxes-1));
        map["y"] = 0.5 + m_spacing + m_spacing * std::floor(i / (sideBoxes-1));
        map["width"] = m_spacing - 1.0;
        map["height"] = m_spacing - 1.0;
        map["initialColor"] = QColor("transparent");
        map["midColor"] =  QColor("transparent");
        map["finalColor"] = outColor;
        map["border.width"] = m_borderWidth;

        QObject* obj = comp.createWithInitialProperties(map, qmlEngine(this)->rootContext());
        QQuickItem* visibleObj = static_cast<QQuickItem*>(obj);

        m_tiles.push_back(visibleObj);
        visibleObj->setParent(this);
        visibleObj->setParentItem(this);
    }

    if(!qFuzzyIsNull(n - std::floor(n)))
    {
        // Partial tile at top left.
        QQmlComponent comp(qmlEngine(this), QUrl(QStringLiteral("qrc:/QML/SquaringBox.qml")));

        QVariantMap map;
        map["boxNumber"] = sideBoxes;
        map["totalBoxes"] = sideBoxes;
        map["fadeInTime"] = m_fadeInTime;
        map["x"] = 0.5 + m_spacing * (sideBoxes % m_xBoxNum);
        map["y"] = 0.5;
        map["width"] =  (n - std::floor(n)) * (m_spacing - 1.0);
        map["height"] = m_spacing - 1.0;
        map["initialColor"] = inColor;
        map["midColor"] = inColor;
        map["finalColor"] = outColor;
        map["border.width"] = m_borderWidth;

        QObject* obj = comp.createWithInitialProperties(map, qmlEngine(this)->rootContext());
        QQuickItem* visibleObj = static_cast<QQuickItem*>(obj);

        m_tiles.push_back(visibleObj);
        visibleObj->setParent(this);
        visibleObj->setParentItem(this);

        //Row on the far right.
        for(int i = 1; i < std::floor(n); i++)
        {
            QVariantMap map;
            map["boxNumber"] = sideBoxes;
            map["totalBoxes"] = sideBoxes;
            map["fadeInTime"] = m_fadeInTime;
            map["x"] = 0.5 + m_spacing * (sideBoxes % m_xBoxNum);
            map["y"] = 0.5 + m_spacing * i;
            map["width"] =  (n - std::floor(n)) * (m_spacing - 1.0);
            map["height"] = m_spacing - 1.0;
            map["initialColor"] = QColor("transparent");
            map["midColor"] = QColor("transparent");
            map["finalColor"] = outColor;
            map["border.width"] = m_borderWidth;

            QObject* obj = comp.createWithInitialProperties(map, qmlEngine(this)->rootContext());
            QQuickItem* visibleObj = static_cast<QQuickItem*>(obj);

            m_tiles.push_back(visibleObj);
            visibleObj->setParent(this);
            visibleObj->setParentItem(this);
        }
    }


    if(!qFuzzyIsNull(n - std::floor(n)))
    {
        // Partial tile at top left.
        QQmlComponent comp(qmlEngine(this), QUrl(QStringLiteral("qrc:/QML/SquaringBox.qml")));

        QVariantMap map;
        map["boxNumber"] = sideBoxes;
        map["totalBoxes"] = sideBoxes;
        map["fadeInTime"] = m_fadeInTime;
        map["x"] = 0.5;
        map["y"] = 0.5 + m_spacing * (sideBoxes % m_xBoxNum);
        map["width"] = m_spacing - 1.0;
        map["height"] =  (n - std::floor(n)) * (m_spacing - 1.0);
        map["initialColor"] = QColor("transparent");
        map["midColor"] = inColor;
        map["finalColor"] = outColor;
        map["border.width"] = m_borderWidth;

        QObject* obj = comp.createWithInitialProperties(map, qmlEngine(this)->rootContext());
        QQuickItem* visibleObj = static_cast<QQuickItem*>(obj);

        m_tiles.push_back(visibleObj);
        visibleObj->setParent(this);
        visibleObj->setParentItem(this);

        //Row on the far right.
        for(int i = 1; i < std::floor(n); i++)
        {
            QVariantMap map;
            map["boxNumber"] = sideBoxes;
            map["totalBoxes"] = sideBoxes;
            map["fadeInTime"] = m_fadeInTime;
            map["x"] = 0.5 + m_spacing * i;
            map["y"] = 0.5 + m_spacing * (sideBoxes % m_xBoxNum);
            map["width"] = m_spacing - 1.0;
            map["height"] =  (n - std::floor(n)) * (m_spacing - 1.0);
            map["initialColor"] = QColor("transparent");
            map["midColor"] = QColor("transparent");
            map["finalColor"] = outColor;
            map["border.width"] = m_borderWidth;

            QObject* obj = comp.createWithInitialProperties(map, qmlEngine(this)->rootContext());
            QQuickItem* visibleObj = static_cast<QQuickItem*>(obj);

            m_tiles.push_back(visibleObj);
            visibleObj->setParent(this);
            visibleObj->setParentItem(this);
        }
    }
    if(!qFuzzyIsNull(n - std::floor(n)))
    {
        // Partial tile at top left.
        QQmlComponent comp(qmlEngine(this), QUrl(QStringLiteral("qrc:/QML/SquaringBox.qml")));

        QVariantMap map;
        map["boxNumber"] = sideBoxes;
        map["totalBoxes"] = sideBoxes;
        map["fadeInTime"] = m_fadeInTime;
        map["x"] = 0.5 + m_spacing * (sideBoxes);
        map["y"] = 0.5 + m_spacing * (sideBoxes);
        map["width"] = (n - std::floor(n)) * (m_spacing - 1.0);
        map["height"] =  (n - std::floor(n)) * (m_spacing - 1.0);
        map["initialColor"] = QColor("transparent");
        map["midColor"] = QColor("transparent");;
        map["finalColor"] = outColor;
        map["border.width"] = m_borderWidth;

        QObject* obj = comp.createWithInitialProperties(map, qmlEngine(this)->rootContext());
        QQuickItem* visibleObj = static_cast<QQuickItem*>(obj);

        m_tiles.push_back(visibleObj);
        visibleObj->setParent(this);
        visibleObj->setParentItem(this);
    }
}

void SquaringVisualArea::clear()
{
    for(int i = 0; i < m_tiles.length(); i++)
        m_tiles[i]->deleteLater();
    m_tiles.clear();
}

void SquaringVisualArea::reset()
{
    for(int i = 0; i < m_tiles.length(); i++)
    {
        QMetaObject::invokeMethod(m_tiles[i], "reset");
    }
}

void SquaringVisualArea::action()
{
    for(int i = 0; i < m_tiles.length(); i++)
    {
        QMetaObject::invokeMethod(m_tiles[i], "animate");
    }
}

void SquaringVisualArea::prepareSizeVariables(int wholeBoxes)
{
    m_fadeInTime = 300 * std::floor(std::log2(wholeBoxes + 1));

    if(wholeBoxes <= 4)
    {
        m_borderWidth = 5;
        m_spacing = 50;
        m_xBoxNum = 4;
    }
    else if(wholeBoxes <= 8)
    {
        m_borderWidth = 2;
        m_spacing = 25;
        m_xBoxNum = 8;
    }
    else if(wholeBoxes <= 16)
    {
        m_borderWidth = 1;
        m_spacing = 12.5;
        m_xBoxNum = 16;
    }
    else if(wholeBoxes <= 32)
    {
        m_borderWidth = 1;
        m_spacing = 6.25;
        m_xBoxNum = 32;
    }
    else if(wholeBoxes <= 200)
    {
        m_borderWidth = 0;
        m_spacing = 1;
        m_xBoxNum = 200;
    }
}
