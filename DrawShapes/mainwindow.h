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

private slots:
    void onShapeButtonClicked(Shape::ShapeType shape);

private:
    Shape *shapeArea;
    QLineEdit *penWidthEdit;
    QLineEdit *penColorEdit;
    QLineEdit *brushColorEdit;
};

#endif // MAINWINDOW_H
