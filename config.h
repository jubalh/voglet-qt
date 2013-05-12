#ifndef CONFIG_H
#define CONFIG_H

#include <QtXml>
#include "xmlhelper.h"

typedef enum
{
    VOGLET_CONFIG_DIRECTION_BOTH,
    VOGLET_CONFIG_DIRECTION_WORD,
    VOGLET_CONFIG_DIRECTION_TRANSLATION
} VOGLET_CONFIG_DIRECTION;

class CConfig : public XmlHelper
{
private:
    QString file;
    VOGLET_CONFIG_DIRECTION direction;
public:
    CConfig();
    bool load();
    QString getFilename();
    VOGLET_CONFIG_DIRECTION getDirection();
};

#endif // CONFIG_H
