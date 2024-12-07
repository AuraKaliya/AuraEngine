#include "aurapropertytool.h"

QVector<QMetaProperty> AuraPropertyTool::getProperty(QObject *obj, int start, int num)
{

    QVector<QMetaProperty> vector;
    const QMetaObject * metaObj=obj->metaObject();
    if(num==0) num=99;
    int end=num+start;
    for(int i=start;i<end;++i)
    {
        QMetaProperty property=metaObj->property(i);
#ifdef QDEBUGCHECK
        qDebug()<<"AuraPropertyTool::getProperty | check:"<<property.name();
#endif
        if(!property.isValid()) break;
        vector.append(property);
    }
    return vector;
}

AuraPropertyTool::AuraPropertyTool()
{

}
