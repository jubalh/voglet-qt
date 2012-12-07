#ifndef vogletH
#define vogletH

#include <QtXml>
#include <QMap>
#include "entry.h"

class CVoglet
{
private:
    QMap<long, CEntry*> entries;
    QString getXmlElementText(QDomElement element, QString tag);
public:
    CVoglet(QString sFilename);
    long getCount(void);
    CEntry *getEntry(long nr);
    CEntry *getEntryByRandom(void);
};
#endif
