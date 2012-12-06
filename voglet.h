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
    long count=0;
public:
    CVoglet(std::string sFilename);
    long getCount(void);
    CEntry *getEntry(long nr);
    CEntry *getEntryByRandom(void);
};
#endif

