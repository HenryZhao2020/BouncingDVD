#include "MainWindow.h"
#include <QApplication>
#include <QDir>
#include <QTimer>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QDir::setCurrent(QApplication::applicationDirPath());
    QDir::setCurrent("Res");

    initIcons();

    MainWindow window;
    window.showFullScreen();

    QTimer iconTimer;
    QObject::connect(&iconTimer, &QTimer::timeout, &app, [&window] {
        window.moveIcon();
    });
    iconTimer.start(10);

    QTimer winTimer;
    QObject::connect(&iconTimer, &QTimer::timeout, &app, [&window] {
        window.showFullScreen();
    });
    winTimer.start(1000);

    return app.exec();
}
