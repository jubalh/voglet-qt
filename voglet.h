#ifndef vogletH
#define vogletH

#include <string>
#include <map>
#include <QtXml>
#include "entry.h"

class CVoglet
{
private:
    std::map<long, CEntry*> entries;
    QString getXmlElementText(QDomElement element, QString tag);
public:
    CVoglet(QString sFilename);
    long getCount(void);
    CEntry *getEntry(long nr);
    CEntry *getEntryByRandom(void);
};
#endif
