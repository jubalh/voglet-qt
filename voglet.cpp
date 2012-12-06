#include <map>
#include <time.h>
#include <stdlib.h>
#include "voglet.h"

CVoglet::CVoglet(std::string sFilename)
{
   tinyxml2::XMLNode *node;
   std::string s;

   int i=doc.LoadFile(sFilename.c_str());
   if (i==0)
   {
      tinyxml2::XMLElement *el = doc.FirstChildElement("voglet")->FirstChildElement("entry");
      while (el)
      {
         CEntry *entry = new CEntry();

         node = el->FirstChildElement("word")->FirstChild();
         entry->word = node->Value();
         node = el->FirstChildElement("translation")->FirstChild();
         entry->translation = node->Value();

         this->entries.insert(std::pair<long,CEntry*>(count++,entry));

         el = el->NextSiblingElement("entry");
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
