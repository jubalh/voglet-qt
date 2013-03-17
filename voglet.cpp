#include <map>
#include <time.h>
#include <stdlib.h>
#include "voglet.h"

CVoglet::CVoglet(CConfig *config)
{
   QDomDocument doc;
   QFile file( config->getFilename() );

   if ( file.exists() )
   {
       file.open(QIODevice::ReadOnly);
       if ( doc.setContent(&file) )
       {
           file.close();

           QDomElement docElem = doc.documentElement();
           QDomNodeList nodeList = docElem.elementsByTagName("entry");
           if (nodeList.count() > 0)
           {
               for(int i = 0;i < nodeList.count(); i++)
               {
                   QString s;
                   CEntry *entry = new CEntry();

                   s = getXmlElementText(nodeList.at(i).toElement(),"word");
                   entry->word = s;
                   s = getXmlElementText(nodeList.at(i).toElement(),"translation");
                   entry->translation = s;

                   this->entries.insert(i,entry);
               }
           }
       }
   }

   this->config = config;
   qsrand( time(NULL) );
}

long CVoglet::getCount(void)
{
   return this->entries.size();
}

CEntry *CVoglet::getEntry(long nr)
{
   CEntry *e=NULL;
   for( QMap<long,CEntry*>::iterator i=entries.begin(); i!=entries.end(); ++i)
   {
      if ( i.key() == nr )
      {
          e = i.value();
          break;
      }
   }
   return e;
}

CEntry *CVoglet::getEntryByRandom(void)
{
    int count = getCount();
    CEntry *e = NULL;

    if ( count > 0 )
    {
        int t = qrand() % count;
        e = getEntry( t );
    }
    return e;
}
