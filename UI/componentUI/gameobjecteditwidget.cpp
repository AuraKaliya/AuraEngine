#include "gameobjecteditwidget.h"

#include <QLabel>

GameObjectEditWidget::GameObjectEditWidget(QWidget *parent)
    : UIWidget{parent}
{
    m_centerWidget=new WheelSlideWidget(this);
    m_centerWidget->setWheelDirection(WheelSlideWidget::VDirection);
    setCenterWidget(m_centerWidget);
}

void GameObjectEditWidget::initWidget()
{
    updateWidget();
#ifdef QDEBUGCHECK
    qDebug()<<"GameObjectEditWidget::initWidget |  init start.";
#endif


    // 1. 获取GameObject的自定义属性
    GameObject obj;
    QVector<QMetaProperty> propertyList=AuraPropertyTool::getProperty(&obj,1);

#ifdef QDEBUGCHECK
    qDebug()<<"GameObjectEditWidget::initWidget |  check: propertyList size:"<<propertyList.size();
#endif
    // 2. 初始化GameObject的基本信息栏
    int labelH=30;
    for(int i=0;i<propertyList.size();++i)
    {
        PropertyEditWidget *w=new  PropertyEditWidget();
        w->initWidget();
        w->setLink(nullptr,propertyList[i]);
        w->resize(width(),labelH);
        m_centerWidget->addWidgetInArea(w,0,i*labelH);
        w->setVisible(true);
        m_gameObjectPropertyWidgetList.append(w);
    }
    // 3. 添加分割栏窗体
    QLabel  * splitLabel=new QLabel("====================");
    splitLabel->setAlignment(Qt::AlignCenter);
    splitLabel->resize(width(),labelH);
    m_centerWidget->addWidgetInArea(splitLabel,0,propertyList.size()*labelH);

#ifdef QDEBUGCHECK
    qDebug()<<"GameObjectEditWidget::initWidget |  init end.";
#endif
}

void GameObjectEditWidget::setNowGameObject(GameObject *obj)
{
    if( m_nowGameObject==obj)
    {
#ifdef QDEBUGCHECK
        qDebug()<<"GameObjectEditWidget::setNowGameObject | obj =obj .";
#endif

        updateValue();
        return;
    }
    m_nowGameObject=obj;
    updateWidget();
}

void GameObjectEditWidget::updateWidget()
{
    if(!m_nowGameObject ) return;

    m_centerWidget->clearWidgetList();
    m_gameObjectPropertyWidgetList.clear();
    m_componentWidgetList.clear();
    // 1. 获取GameObject的自定义属性
    QVector<QMetaProperty> propertyList=AuraPropertyTool::getProperty(m_nowGameObject,1);
    // 2. 更新GameObject的基本信息栏
    int labelH=30;
    for(int i=0;i<propertyList.size();++i)
    {
        PropertyEditWidget *w=new  PropertyEditWidget();
        w->initWidget();
        w->setLink(m_nowGameObject,propertyList[i]);
        w->resize(width(),labelH);
        m_centerWidget->addWidgetInArea(w,0,i*labelH);
        w->setVisible(true);
        m_gameObjectPropertyWidgetList.append(w);
    }

    // 3. 添加分割栏窗体
    QLabel  * splitLabel=new QLabel("====================");
    splitLabel->setAlignment(Qt::AlignCenter);
    splitLabel->resize(width(),labelH);
    m_centerWidget->addWidgetInArea(splitLabel,0,propertyList.size()*labelH);
    splitLabel->setVisible(true);
    // 3. 获取GameObject的组件信息
    auto componentList= m_nowGameObject->getComponetList();
    // 4. 更新CenterWidget中的组件栏 （ remove  + add ）
    int nextY=(propertyList.size()+1)*labelH;
    for(int i=0;i<componentList.size();++i)
    {
        ComponentEditWidget* w=new ComponentEditWidget();
        w->resize(width(),1);
        w->setComponentObj(componentList[i]);
        m_centerWidget->addWidgetInArea(w,0,nextY);
        nextY=nextY+w->height();
        qDebug()<<"GameObjectEditWidget::updateWidget | heigh:"<<w->height();
        qDebug()<<"GameObjectEditWidget::updateWidget | y:"<<(propertyList.size()+1)*labelH+i*w->height();
        w->setVisible(true);
        m_componentWidgetList.append(w);
    }


}

void GameObjectEditWidget::updateValue()
{
    for(auto it: m_gameObjectPropertyWidgetList)
    {
        it->updateValue();
    }
    for(auto it:m_componentWidgetList)
    {
        it->updateValue();
    }
}

void GameObjectEditWidget::updateLayout()
{
    resizeEvent(nullptr);
}

