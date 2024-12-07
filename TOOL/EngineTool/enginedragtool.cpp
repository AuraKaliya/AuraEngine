#include "enginedragtool.h"
#include "../Systems/sourcesystem.h"

EngineDragTool::EngineDragTool(QObject *parent)
    : QObject{parent}
{
    if(!m_initFlag)
    {
        initTool();
    }
}

void EngineDragTool::solveDragData(QString dragStratagy, const QMimeData *data)
{
    auto it =m_dragFunctionDictionary.find(dragStratagy);
    if(it != m_dragFunctionDictionary.end())
    {
        it.value()(data);
    }
    else
    {
        m_dragFunctionDictionary.find("Default").value()(data);
    }
}

void EngineDragTool::initTool()
{
    m_dragFunctionDictionary.insert("CardLabel",cardLabelDragFunction);
    m_dragFunctionDictionary.insert("Default",cardLabelDragFunction);
    m_initFlag =true;
}

void EngineDragTool::cardLabelDragFunction(const QMimeData *data)
{
#ifdef QDEBUGCHECK
    qDebug()<<"EngineDragTool::cardLabelDragFunction | data:"<<data;
    if(data->hasFormat("GameObjectClass"))
    {
        QString objClass = QString::fromLocal8Bit(data->data("GameObjectClass"));
        qDebug()<<"EngineDragTool::cardLabelDragFunction | GameObjectClass:"<<objClass;
    }
#endif
    if(data->hasFormat("GameObjectClass"))
    {
        QString objClass = QString::fromLocal8Bit(data->data("GameObjectClass"));
        SourceSystem::getInstance()->addGameObjectFromSample(objClass);
    }
}

void EngineDragTool::defaultDragFunction(const QMimeData *data)
{
#ifdef QDEBUGCHECK
    qDebug()<<"EngineDragTool::defaultDragFunction | error:no find dataStratagy:"<<data->text();
#endif
}
