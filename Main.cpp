#include "MainWindow.h"
#include <QApplication>
#include <QDir>
#include <QTimer>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QDir::setCurrent(QApplication::applicationDirPath());
    QDir::setCurrent("BouncingDVD_Files");
    initIcons();

    MainWindow window;
    window.showFullScreen();

    QTimer timer;
    timer.setInterval(10);
    QObject::connect(&timer, &QTimer::timeout, &app, [&window] {
        window.moveIcon();
    });
    timer.start();

    return app.exec();
}
