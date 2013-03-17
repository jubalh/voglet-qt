#ifndef XMLHELPER_H
#define XMLHELPER_H

#include <QtXml>

class XmlHelper
{
public:
    XmlHelper();
    QString getXmlElementText(QDomElement element, QString tag);
};

#endif // XMLHELPER_H
