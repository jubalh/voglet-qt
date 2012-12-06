#ifndef vogletH
#define vogletH

#include <string>
#include <map>
#include "tinyxml2.h"
#include "entry.h"

class CVoglet
{
private:
    tinyxml2::XMLDocument doc;
    std::map<long, CEntry*> entries;
public:
    CVoglet(QString sFilename);
    long getCount(void);
    CEntry *getEntry(long nr);
    CEntry *getEntryByRandom(void);
};
#endif
