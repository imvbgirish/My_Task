#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "Shape.h"

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onShapeSelected(Shape::ShapeType shape);

private:
    Shape *drawingArea;
    QLineEdit *inputPenWidth;
    QLineEdit *inputPenColor;
    QLineEdit *inputBrushColor;
};

#endif // MAINWINDOW_H
