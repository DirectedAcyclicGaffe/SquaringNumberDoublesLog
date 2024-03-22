#ifndef SQUARINGVISUALAREA_H
#define SQUARINGVISUALAREA_H

#include <QQuickItem>
#include <QQmlEngine>

class SquaringVisualArea : public QQuickItem
{
    Q_OBJECT
public:
    SquaringVisualArea();

signals:

public slots:

    void setup(double n, QColor inColor, QColor outColor);
    void clear();
    void reset();
    void action();

private:
    void prepareSizeVariables(int wholeBoxes);
    int m_xBoxNum;
    double m_spacing;
    int m_borderWidth;

    QColor m_outColor;
    QColor m_inColor;
    double m_currentlyVisible;
    double m_inputNum;
    double m_fadeInTime;

    QList<QQuickItem*> m_tiles;

};

#endif // SQUARINGVISUALAREA_H
