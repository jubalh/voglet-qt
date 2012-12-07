#include <map>
#include <time.h>
#include <stdlib.h>
#include "voglet.h"

CVoglet::CVoglet(QString sFilename)
{
   QDomDocument doc;
   QFile file(sFilename);

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

   qsrand( time(NULL) );
}

QString CVoglet::getXmlElementText(QDomElement element, QString tag)
{
    QString r;
    QDomNode n = element.elementsByTagName(tag).at(0);
    if (!n.isNull())
    {
        QDomNode child = n.firstChild();
        if ( !child.isNull() && child.isText() )
        {
            if ( child.toText().isCharacterData() )
                r = child.toText().toCharacterData().data();
        }
    }
    return r;
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
