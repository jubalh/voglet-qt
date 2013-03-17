#include "config.h"

#define CONFIG_FILENAME "config.xml"

CConfig::CConfig()
{
}

bool CConfig::load()
{
    QDomDocument doc;
    QFile file(CONFIG_FILENAME);

    if ( file.exists() )
    {
        file.open(QIODevice::ReadOnly);
        if ( doc.setContent(&file) )
        {
            file.close();

            QDomElement docElem = doc.documentElement();

            this->file = getXmlElementText(docElem, "file");
            this->direction = getXmlElementText(docElem, "direction");
            return true;
        }
    }
    return false;
}

QString CConfig::getFilename()
{
    return this->file;
}

QString CConfig::getDirection()
{
    return this->direction;
}
