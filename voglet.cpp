#include <map>
#include <time.h>
#include <stdlib.h>
#include <QtXml>
#include "voglet.h"

CVoglet::CVoglet(QString sFilename)
{
   QDomDocument doc;
   QFile file(sFilename);
   file.open(QIODevice::ReadOnly);
   doc.setContent(&file);
   file.close();

   QDomElement docElem = doc.documentElement();
   QDomNodeList nodeList = docElem.elementsByTagName("entry");
   if (nodeList.count() > 0)
   {
       for(int i = 0;i < nodeList.count(); i++)
       {
           QString word = nodeList.at(i).toElement().elementsByTagName("word").at(0).firstChild().toText().toCharacterData().data();
           QString translation = nodeList.at(i).toElement().elementsByTagName("translation").at(0).firstChild().toText().toCharacterData().data();
           CEntry *entry = new CEntry();
           entry->word = word;
           entry->translation = translation;
           this->entries.insert(std::pair<long,CEntry*>(i,entry));
       }
   }

   qsrand( time(NULL) );
}

long CVoglet::getCount(void)
{
   return this->entries.size();
}

CEntry *CVoglet::getEntry(long nr)
{
   CEntry *e=NULL;
   for( std::map<long,CEntry*>::iterator i=entries.begin(); i!=entries.end(); ++i)
   {
      if ( (*i).first == nr )
      {
        e = (*i).second;
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
