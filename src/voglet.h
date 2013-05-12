#ifndef vogletH
#define vogletH

#include <QtXml>
#include <QMap>
#include "entry.h"
#include "xmlhelper.h"
#include "config.h"

class CVoglet : XmlHelper
{
private:
    QMap<long, CEntry*> entries;
    CConfig *config;
public:
    CVoglet(CConfig *config);
    long getCount(void);
    CEntry *getEntry(long nr);
    CEntry *getEntryByRandom(void);
};
#endif
