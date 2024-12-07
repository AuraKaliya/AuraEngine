#include "propertytoolwidget.h"
#include "propertyeditwidget.h"
PropertyToolWidget::PropertyToolWidget(QWidget *parent)
    : UIWidget{parent}
{
    m_toolBtn=new ClickLabel(this);
}

void PropertyToolWidget::initWidget(PropertyEditWidget *linkWidget)
{
    setLinkWidget(linkWidget);
    initWidget();
}

void PropertyToolWidget::setLinkWidget(PropertyEditWidget *linkWidget)
{
    m_linkWidget=linkWidget;
}

void PropertyToolWidget::updateValue()
{
    if(!m_linkWidget || ! m_toolBtn)
    {
#ifdef QDEBUGCHECK
        qDebug()<<"PropertyToolWidget::updateValue | error : m_linkWidget or m_toolBtn not build.";
#endif
        return ;
    }

    auto & entity= m_toolBtn->entity();
    if(!entity.hasComponent("PropertyValue"))
    {
#ifdef QDEBUGCHECK
        qDebug()<<"PropertyToolWidget::updateValue | error : no have Component PropertyValue.";
#endif
        return ;
    }
    auto propertyValueComponent=entity.getComponent("PropertyValue");
    m_linkWidget->setValue(propertyValueComponent->getValue<QString>());
    m_linkWidget->submitValue();
}

void PropertyToolWidget::initWidget()
{
    auto & entity= m_toolBtn->entity();

    if(!entity.hasComponent("PropertyValue"))
    {
        entity.addComponent("PropertyValue",new Component<Entity>(entity));
    }

}

void PropertyToolWidget::initWidget(const QJsonObject &obj)
{

}

void PropertyToolWidget::resizeEvent(QResizeEvent *e)
{
    UIWidget::resizeEvent(e);
    m_toolBtn->setGeometry(0,0,width(),height());
}
