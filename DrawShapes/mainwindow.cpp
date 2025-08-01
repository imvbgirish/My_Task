#include "mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    qDebug() << Q_FUNC_INFO;

    drawingArea = new Shape(this);
    inputPenWidth = new QLineEdit("3", this);
    inputPenColor = new QLineEdit("White", this);
    inputBrushColor = new QLineEdit("Black", this);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);

    QVBoxLayout *shapeButtonsLayout = new QVBoxLayout();
    QList<Shape::ShapeType> availableShapes = {
        Shape::Circle,
        Shape::Rectangle,
        Shape::Square,
        Shape::Pentagon,
    };
    QStringList shapeLabels = {"Circle", "Rectangle", "Square", "Pentagon"};

    for (int i = 0; i < availableShapes.size(); ++i) {
        QPushButton *btn = new QPushButton(shapeLabels[i], this);
        shapeButtonsLayout->addWidget(btn);
        connect(btn, &QPushButton::clicked, this, [=]() {
            onShapeSelected(availableShapes[i]);
        });
    }
    shapeButtonsLayout->addStretch();

    QVBoxLayout *rightLayout = new QVBoxLayout();

    QHBoxLayout *controlsLayout = new QHBoxLayout();
    controlsLayout->addWidget(new QLabel("Pen Width:"));
    controlsLayout->addWidget(inputPenWidth);
    controlsLayout->addWidget(new QLabel("Pen Color:"));
    controlsLayout->addWidget(inputPenColor);
    controlsLayout->addWidget(new QLabel("Brush Color:"));
    controlsLayout->addWidget(inputBrushColor);

    rightLayout->addLayout(controlsLayout);
    rightLayout->addWidget(drawingArea, 1);

    mainLayout->addLayout(shapeButtonsLayout);
    mainLayout->addLayout(rightLayout, 1);

    setLayout(mainLayout);
}

MainWindow::~MainWindow() {
    qDebug() << "MainWindow Destructor";
}

void MainWindow::onShapeSelected(Shape::ShapeType shape) {
    qDebug() << Q_FUNC_INFO;

    int width = inputPenWidth->text().toInt();
    QColor penCol(inputPenColor->text());
    QColor brushCol(inputBrushColor->text());

    drawingArea->setProperties(shape, width, penCol, brushCol);
}
