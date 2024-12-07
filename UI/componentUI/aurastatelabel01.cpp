#include "aurastatelabel01.h"

QMap<ConstValue::StateLabelState,QColor> AuraStateLabel01::m_stateToStyleDictionary
{
    {ConstValue::StateLabelState::Normal,QColor(Qt::darkGray)},
    {ConstValue::StateLabelState::Current,QColor(Qt::gray)}
};
AuraStateLabel01::AuraStateLabel01(QWidget *parent)
    : ClickLabel{parent}
{
    initLabel();
}

AuraStateLabel01::AuraStateLabel01(const QString &text, QWidget *parent, Qt::WindowFlags f)
:ClickLabel{text,parent,f}
{
    initLabel();
}

int AuraStateLabel01::id() const
{
    return m_id;
}

void AuraStateLabel01::setId(int newId)
{
    m_id = newId;
}

void AuraStateLabel01::paintEvent(QPaintEvent *e)
{
#ifdef QDEBUGCHECK
    //qDebug()<<"AuraStateLabel01::paintEvent | check rect:"<<width()<< height();
    //qDebug()<<"AuraStateLabel01::paintEvent | check color:" <<stateStyle(m_nowState);
#endif
    QPainter p(this);
    p.setBrush(QBrush(stateStyle(m_nowState)));
    p.setPen(QPen(stateStyle(m_nowState)));
    p.drawRect(0,0,width(),height());

    ClickLabel::paintEvent(e);
}

void AuraStateLabel01::initLabel()
{
    m_id=-1;
    m_nowState=ConstValue::StateLabelState::Normal;
    setAlignment(Qt::AlignCenter);

    //=================后面采用Style进行设置=================
    QFont font;
    font.setPointSize(20);
    setFont(font);
    //=================后面采用Style进行设置=================
}

ConstValue::StateLabelState AuraStateLabel01::nowState() const
{
    return m_nowState;
}

void AuraStateLabel01::setNowState(ConstValue::StateLabelState newNowState)
{
    m_nowState = newNowState;
    update();
}

void AuraStateLabel01::mouseReleaseEvent(QMouseEvent *e)
{
    ClickLabel::mouseReleaseEvent(e);
    emit clickedId(m_id);
}

void AuraStateLabel01::setStateStyle(ConstValue::StateLabelState state, QColor color)
{
    m_stateToStyleDictionary[state]=color;
}

QColor AuraStateLabel01::stateStyle(ConstValue::StateLabelState state)
{
    return m_stateToStyleDictionary[state];
}
