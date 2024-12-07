#include "uiwidget.h"

UIWidget::UIWidget(QWidget *parent)
    : QWidget{parent},m_checkFlag(true),m_centerFlag(false)
{
    m_autoInitUIStyleFlag=false;
    m_uiDirectionFlag=AuraUI::Horizon;
}

void UIWidget::initWidget()
{

}

void UIWidget::initWidget(const QJsonObject &obj)
{

}

void UIWidget::setUIStyle(const UIStyle &style)
{
    if(m_autoInitUIStyleFlag)
    {
        for(auto it:m_widgetList)
        {
            it->setUIStyle(style);
        }
    }
    emit setUIStyleFinished();
}

void UIWidget::sourceUpdate()
{

}

bool UIWidget::autoInitUIStyleFlag() const
{
    return m_autoInitUIStyleFlag;
}

void UIWidget::setAutoInitUIStyleFlag(bool newAutoInitUIStyleFlag)
{
    m_autoInitUIStyleFlag = newAutoInitUIStyleFlag;
}

AuraUI::UIDirection UIWidget::uiDirectionFlag() const
{
    return m_uiDirectionFlag;
}

void UIWidget::setCenterWidget(QWidget *w)
{
    if(!w) return;
    w->setParent(this);
    m_centerWidget=w;
    m_centerFlag=true;
}

void UIWidget::setUiDirectionFlag(AuraUI::UIDirection newUiDirectionFlag)
{
    m_uiDirectionFlag = newUiDirectionFlag;
}

void UIWidget::paintEvent(QPaintEvent *e)
{
    QWidget::paintEvent(e);
    if(m_checkFlag)
    {
        QPainter p(this);
        p.setPen(QPen(Qt::red));
        p.drawRect(QRect(rect().x(),rect().y(),rect().width()-1,rect().height()-1));
        p.end();
    }

}

void UIWidget::resizeEvent(QResizeEvent *e)
{
    QWidget::resizeEvent(e);
    if(m_centerFlag && m_centerWidget)
    {
        m_centerWidget->setGeometry(0,0,width(),height());
    }
}

bool UIWidget::checkFlag() const
{
    return m_checkFlag;
}

void UIWidget::setCheckFlag(bool newCheckFlag)
{
    m_checkFlag = newCheckFlag;
}

QWidget *UIWidget::centerWidget() const
{
    return m_centerWidget;
}

