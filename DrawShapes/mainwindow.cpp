#include "mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    shapeArea = new Shape(this);
    penWidthEdit = new QLineEdit("2", this);
    penColorEdit = new QLineEdit("black", this);
    brushColorEdit = new QLineEdit("yellow", this);


    QHBoxLayout *mainLayout = new QHBoxLayout(this);


    QVBoxLayout *shapeButtonsLayout = new QVBoxLayout();
    QList<Shape::ShapeType> shapeTypes = {
        Shape::Circle,
        Shape::Rectangle,
        Shape::Square,
        Shape::Pentagon,
    };
    QStringList shapeNames = {"Circle", "Rectangle", "Square", "Pentagon"};

    for (int i = 0; i < shapeTypes.size(); ++i) {
        QPushButton *button = new QPushButton(shapeNames[i], this);
        shapeButtonsLayout->addWidget(button);
        connect(button, &QPushButton::clicked, this, [=]() {
            onShapeButtonClicked(shapeTypes[i]);
        });
    }
    shapeButtonsLayout->addStretch();

    QVBoxLayout *rightLayout = new QVBoxLayout();


    QHBoxLayout *controlsLayout = new QHBoxLayout();
    controlsLayout->addWidget(new QLabel("Pen Width:"));
    controlsLayout->addWidget(penWidthEdit);
    controlsLayout->addWidget(new QLabel("Pen Color:"));
    controlsLayout->addWidget(penColorEdit);
    controlsLayout->addWidget(new QLabel("Brush Color:"));
    controlsLayout->addWidget(brushColorEdit);

    rightLayout->addLayout(controlsLayout);
    rightLayout->addWidget(shapeArea, 1);

    mainLayout->addLayout(shapeButtonsLayout);
    mainLayout->addLayout(rightLayout, 1);

    setLayout(mainLayout);
}

void MainWindow::onShapeButtonClicked(Shape::ShapeType shape) {
    shapeArea->setShape(shape);
    shapeArea->setPenWidth(penWidthEdit->text().toInt());
    shapeArea->setPenColor(QColor(penColorEdit->text()));
    shapeArea->setBrushColor(QColor(brushColorEdit->text()));
    shapeArea->update();
}
