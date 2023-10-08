#pragma once

#include <QMainWindow>

void initIcons();

enum Direction {
    NW, NE, SW, SE
};

class QPushButton;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();

    void moveIcon();
    void setDirection(Direction direction);

private:
    Direction direction;
    int x, y;
    int iconIndex;
    QPushButton *iconButton;
};
