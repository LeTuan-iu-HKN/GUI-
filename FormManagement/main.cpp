#include "mainwindow.h"
#include "library.h"

#include <QApplication>

int main(int argc, char* argv[]) {
    FormManagementSystemInit Program(List);
    Program.init();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
