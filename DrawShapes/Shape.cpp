#include "Shape.h"
#include <QPainter>

Shape::Shape(QWidget *parent) : QWidget(parent), penWidth(1), penColor(Qt::white), brushColor(Qt::black) {
    setMinimumSize(500, 500);
    qDebug() << Q_FUNC_INFO;
}

Shape::~Shape()
{
    qDebug() << "Shape Destructor";
}


void Shape::setProperties(Shape::ShapeType shape, int width, const QColor &penCol, const QColor &brushCol) {
    qDebug() << Q_FUNC_INFO;

    currentShape = shape;
    penWidth = width;
    penColor = penCol;
    brushColor = brushCol;
    update();
}


Shape::ShapeType Shape::currentShapeType() const
{
    qDebug() << Q_FUNC_INFO;
    return currentShape;
}

void Shape::paintEvent(QPaintEvent *)
{

    qDebug() << Q_FUNC_INFO;

    QPainter painter(this);
    painter.setPen(QPen(penColor, penWidth));
    painter.setBrush(QBrush(brushColor));

    switch (currentShape)
    {
    case Circle:
        painter.drawEllipse(100, 100, 200, 200);
        break;

    case Rectangle:
        painter.drawRect(100, 100, 300, 150);
        break;

    case Square:
        painter.drawRect(100, 100, 200, 200);
        break;

    case Pentagon:
    {
        QPolygon polygon;
        polygon << QPoint(200, 100) << QPoint(300, 160) << QPoint(260, 260)
                << QPoint(140, 260) << QPoint(100, 160);
        painter.drawPolygon(polygon);
        break;
    }
    }
}

