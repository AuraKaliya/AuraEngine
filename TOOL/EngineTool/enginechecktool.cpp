#include "enginechecktool.h"

EngineCheckTool::EngineCheckTool(QObject *parent)
    : QObject{parent}
{

}

void EngineCheckTool::checkGameObject(GameObject *obj)
{
    qDebug()<<"EngineCheckTool::checkGameObject | start.";
    qDebug()<<"GameObject: "<< obj->objClass() << " | "<< obj->id() <<" | " << obj;
    qDebug()<<"Name: "<<obj->name();
    qDebug()<<"==================Component================";
    for(auto it: obj->getComponetList())
    {
        qDebug()<<"Component: "<< it->objectName();
        for(auto property :AuraPropertyTool::getProperty(it,1))
        {
            qDebug()<<property.name()<< " : "<< property.read(it);
        }
        qDebug()<<"=========";
    }
    qDebug()<<"EngineCheckTool::checkGameObject | end.";
}
