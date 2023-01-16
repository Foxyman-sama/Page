#include <QApplication>
#include "mainwindow.hpp"

int main(int   _argc,
         char *_p_argv[]) {
    setlocale(0, ".UTF8");

    QApplication a(_argc, _p_argv);
    MainWindow w;
    w.show();
    return a.exec();
}
