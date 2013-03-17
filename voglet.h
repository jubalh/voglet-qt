#ifndef vogletH
#define vogletH

#include <QtXml>
#include <QMap>
#include "entry.h"
#include "xmlhelper.h"

class CVoglet : XmlHelper
{
private:
    QMap<long, CEntry*> entries;
public:
    CVoglet(QString sFilename);
    long getCount(void);
    CEntry *getEntry(long nr);
    CEntry *getEntryByRandom(void);
};
#endif
