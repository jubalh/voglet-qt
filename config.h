#ifndef CONFIG_H
#define CONFIG_H

#include <QtXml>
#include "xmlhelper.h"

class CConfig : public XmlHelper
{
private:
    QString file;
    QString direction;
public:
    CConfig();
    bool load();
    QString getFilename();
    QString getDirection();
};

#endif // CONFIG_H
