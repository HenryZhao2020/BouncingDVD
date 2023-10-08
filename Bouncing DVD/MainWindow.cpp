#include "MainWindow.h"
#include <QPushButton>

#define ICON_W 360
#define ICON_H 160

QIcon ICONS[7];

void initIcons() {
    for (int i = 0; i < 7; i++) {
        ICONS[i] = QIcon("dvdlogo-0" + QString::number(i + 1) + ".svg");
    }
}

MainWindow::MainWindow() {
    setAttribute(Qt::WA_DeleteOnClose);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::Tool |
                   Qt::FramelessWindowHint |
                   Qt::WindowStaysOnTopHint);

    direction = Direction::SE;
    x = 0;
    y = 0;
    iconIndex = 0;

    iconButton = new QPushButton(this);
    iconButton->setIcon(ICONS[iconIndex]);
    iconButton->setStyleSheet("border: 0");
    iconButton->setFixedSize(ICON_W, ICON_H);
    iconButton->setIconSize(QSize(ICON_W, ICON_H));
}

void MainWindow::moveIcon() {
    switch (direction) {
    case NW:
        if (--x == 0) setDirection(NE);
        else if (--y == 0) setDirection(SW);
        break;

    case NE:
        if (++x == width() - ICON_W) setDirection(NW);
        else if (--y == 0) setDirection(SE);
        break;

    case SW:
        if (--x == 0) setDirection(SE);
        else if (++y == height() - ICON_H) setDirection(NW);
        break;

    case SE:
        if (++x == width() - ICON_W) setDirection(SW);
        else if (++y == height() - ICON_H) setDirection(NE);
        break;
    }

    if ((x == 0 && y == 0) ||
        (x == width() - ICON_W && y == 0) ||
        (x == 0 && y == height() - ICON_H) ||
        (x == width() - ICON_W && y == height() - ICON_H)) {
        close();
    }

    iconButton->move(x, y);
}

void MainWindow::setDirection(Direction direction) {
    this->direction = direction;

    if (++iconIndex == 7) {
        iconIndex = 0;
    }
    iconButton->setIcon(ICONS[iconIndex]);
}
