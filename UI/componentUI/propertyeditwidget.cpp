#include "propertyeditwidget.h"

PropertyEditWidget::PropertyEditWidget(QWidget *parent)
    : UIWidget{parent},m_hotUpdate(false),m_ratioX1(7),m_ratioX2(7),m_vSpacing(0),m_hSpacing(0)
{
    setCheckFlag(false);
    m_titleLabel=new QLabel(this);
    m_valueLabel=new QLineEdit(this);
    m_mainLayout =new QHBoxLayout();

}

void PropertyEditWidget::initWidget()
{
    setLayout(m_mainLayout);
    m_mainLayout->setContentsMargins(5,0,5,0);
    m_mainLayout->setSpacing(2);

    m_mainLayout->addWidget(m_titleLabel,m_ratioX1);
    m_mainLayout->addWidget(m_valueLabel,m_ratioX2);

    m_titleLabel->setAlignment(Qt::AlignCenter);
    m_valueLabel->setAlignment(Qt::AlignCenter);

    connect(m_valueLabel,&QLineEdit::editingFinished,this,[this](){
        if(m_hotUpdate)
        {
            submitValue();
        }
    });




}

void PropertyEditWidget::setRatio(int x1, int x2, int vSpacing, int hSpacing)
{
    m_ratioX1=x1;
    m_ratioX2=x2;
    m_vSpacing=vSpacing;
    m_hSpacing=hSpacing;
    resizeEvent(nullptr);
}

void PropertyEditWidget::setLink(QObject *obj, QMetaProperty property)
{
    m_linkProperty=property;
    m_titleLabel->setText(property.name());

    if(!obj) return;
    m_linkObject=obj;
    m_valueLabel->setText(property.read(obj).toString());

}

void PropertyEditWidget::setValue(QString value)
{
    m_valueLabel->setText(value);

}

void PropertyEditWidget::setHotUpdate(bool flag)
{
    m_hotUpdate=flag;
}

void PropertyEditWidget::addToolWidget(UIWidget *w)
{
    int valueStretch = m_mainLayout->stretch(1);
    if(valueStretch > 3)
    {
        w->setParent(this);
        valueStretch -= 1;
        m_mainLayout->setStretch(1,valueStretch);
        m_mainLayout->addWidget(w,1);
    }

}

void PropertyEditWidget::submitValue()
{
    /*待开发*/
    // 提交后需要更新相应的显示 （从GameObject处对View进行更新）
    /*待开发*/

    QVariant var=QVariant::fromValue(m_valueLabel->text());
    if(m_linkObject!=nullptr)
    {
        if(!m_linkProperty.write(m_linkObject,var))
        {
#ifdef QDEBUGCHECK
            qDebug()<<"PropertyEditWidget::submitValue | failed to submit"<<m_linkProperty.name();
#endif
        }
    }
}

void PropertyEditWidget::updateValue()
{
    if(!m_linkObject)return;

    m_valueLabel->setText(m_linkProperty.read(m_linkObject).toString());
    update();
}

void PropertyEditWidget::resizeEvent(QResizeEvent *e)
{
    UIWidget::resizeEvent(e);
//    int width=this->width()-3*m_hSpacing;
//    int height=this->height();
//    //可能出现负数情况 ---
//    m_titleLabel->setGeometry(m_hSpacing,m_vSpacing,width*(m_ratioX1/(m_ratioX1+m_ratioX2)),height-2*m_vSpacing);
//    m_valueLabel->setGeometry(m_hSpacing*2+m_titleLabel->width(),m_vSpacing,width*(m_ratioX2/(m_ratioX1+m_ratioX2)),height-2*m_vSpacing);
    update();
}
