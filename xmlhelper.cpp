#include "xmlhelper.h"

XmlHelper::XmlHelper()
{
}

QString XmlHelper::getXmlElementText(QDomElement element, QString tag)
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
