#include "Shape.h"
#include <QPainter>

Shape::Shape(QWidget *parent) : QWidget(parent), penWidth(1), penColor(Qt::black), brushColor(Qt::yellow) {
    setMinimumSize(500, 500);
}

void Shape::setShape(Shape::ShapeType shape) {
    currentShape = shape;
    update();
}

void Shape::setPenWidth(int width) {
    penWidth = width;
    update();
}

void Shape::setPenColor(const QColor &color) {
    penColor = color;
    update();
}

void Shape::setBrushColor(const QColor &color) {
    brushColor = color;
    update();
}

Shape::ShapeType Shape::currentShapeType() const
{
    return currentShape;
}

void Shape::paintEvent(QPaintEvent *)
{
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

