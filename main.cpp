#include <QApplication>
#include "mainwindow.h"
#include "voglet.h"
#include "entry.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CVoglet *v = new CVoglet(QString("file.xml"));

    CEntry *entry;
    entry = v->getEntryByRandom();

    MainWindow w;
    w.setEntry(entry);
    w.show();
    return a.exec();
}
