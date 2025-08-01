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
    ~Shape();

    void setProperties(ShapeType shape, int width, const QColor &penCol, const QColor &brushCol);
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
