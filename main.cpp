#include <QApplication>
#include "mainwindow.h"
#include "config.h"
#include "voglet.h"
#include "entry.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CConfig *conf = new CConfig();
    if ( !conf->load() )
        return -1;

    CVoglet *v = new CVoglet( conf->getFilename() );

    CEntry *entry;
    entry = v->getEntryByRandom();

    MainWindow w;
    w.setEntry(entry);
    w.show();
    return a.exec();
}
