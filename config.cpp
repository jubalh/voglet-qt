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
            QString sDirection;
            file.close();

            QDomElement docElem = doc.documentElement();

            this->file = getXmlElementText(docElem, "file");

            sDirection = getXmlElementText(docElem, "direction");
            if (sDirection.compare("both", Qt::CaseInsensitive))
                this->direction = VOGLET_CONFIG_DIRECTION_BOTH;
            else if (sDirection.compare("translation", Qt::CaseInsensitive))
                this->direction = VOGLET_CONFIG_DIRECTION_TRANSLATION;
            else if (sDirection.compare("word", Qt::CaseInsensitive))
                this->direction == VOGLET_CONFIG_DIRECTION_WORD;

            return true;
        }
    }
    return false;
}

QString CConfig::getFilename()
{
    return this->file;
}

VOGLET_CONFIG_DIRECTION CConfig::getDirection()
{
    return this->direction;
}
