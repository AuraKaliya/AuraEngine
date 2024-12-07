#include "componenteditwidget.h"

ComponentEditWidget::ComponentEditWidget(QWidget *parent)
    : UIWidget{parent},m_nameRectH(30),m_propertyRectH(30)
{

}

void ComponentEditWidget::initWidget()
{
    if(!m_componentObj) return;
    //获取组件的所有属性
    auto propertyList=AuraPropertyTool::getProperty(m_componentObj,1);
    //

    for(auto it:propertyList)
    {
        //qDebug()<<"Property Name :" << it.name()<<" 对比： "<<(QString(it.name()) == "pixPath");
        PropertyEditWidget * w=new PropertyEditWidget(this);
        w->setLink(m_componentObj,it);
        w->initWidget();
        w->setHotUpdate(true);
        w->setVisible(true);
        loadPropertyToolWidget(w,it);
        m_propertyEditWidgetList.append(w);
    }

    updateLayout();
}

void ComponentEditWidget::updateLayout()
{
    for(int i=0 ;i< m_propertyEditWidgetList.size();++i)
    {
        m_propertyEditWidgetList[i]->setGeometry(0,m_nameRectH+i*m_propertyRectH,
                                                 width(),m_propertyRectH);
    }
    resize(width(),1+m_nameRectH+m_propertyEditWidgetList.size()*m_propertyRectH);
}

void ComponentEditWidget::updateValue()
{
    for(auto it:m_propertyEditWidgetList)
    {
        it->updateValue();
    }
}

void ComponentEditWidget::setComponentObj(ComponentObject *cobj)
{
    m_componentObj=cobj;
    initWidget();
}

ComponentObject *ComponentEditWidget::componentObj()
{
    return m_componentObj;
}

void ComponentEditWidget::loadPropertyToolWidget(PropertyEditWidget *w, const QMetaProperty &property)
{
    if(QString(property.name()) == "pixPath")
    {
        PropertyToolWidget * toolWidget =Factory<PropertyToolWidget,QWidget*>::GetInstance()->CreateClass("PropertyToolLoadFilePathWidget",nullptr);
        toolWidget->initWidget(w);
        w->addToolWidget(toolWidget);
    }

}

void ComponentEditWidget::resizeEvent(QResizeEvent *e)
{
    UIWidget::resizeEvent(e);
    m_nameRect=QRect(1,1,width()/2,m_nameRectH);
    update();
}

void ComponentEditWidget::paintEvent(QPaintEvent *e)
{
    if(!m_componentObj) return ;
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkRed));
    painter.drawText(m_nameRect,m_componentObj->objectName(),QTextOption(Qt::AlignCenter));
    painter.end();
}
