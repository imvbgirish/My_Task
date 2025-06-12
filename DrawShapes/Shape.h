#ifndef SHAPE_H
#define SHAPE_H

#include <QWidget>
#include <QPen>
#include <QBrush>

class Shape : public QWidget {
    Q_OBJECT
public:
    enum ShapeType {
        Circle,
        Rectangle,
        Square,
        Pentagon,
    };

    explicit Shape(QWidget *parent = nullptr);

    void setShape(ShapeType shape);
    void setPenWidth(int width);
    void setPenColor(const QColor &color);
    void setBrushColor(const QColor &color);

    ShapeType currentShapeType() const;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    ShapeType currentShape;
    int penWidth;
    QColor penColor;
    QColor brushColor;
};

#endif // SHAPE_H
