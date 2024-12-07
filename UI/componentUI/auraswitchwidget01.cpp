#include "auraswitchwidget01.h"
#include "clicklabel.h"

AuraSwitchWidget01::AuraSwitchWidget01(QWidget *parent)
    : UIWidget{parent}
{
    m_nowIndex=-1;
    m_preIndex=-1;
}

void AuraSwitchWidget01::initWidget()
{

}

void AuraSwitchWidget01::addLabel(AuraStateLabel01 *label)
{
    if(!label) return;
    label->setId(m_labelList.size());
    label->setParent(this);

    connect(label,&AuraStateLabel01 :: clickedId,this,[this](int id){
#ifdef QDEBUGCHECK
        qDebug()<<"AuraStateLabel01 :: clickedId | now Id:"<<id ;
#endif
        setNowIndex(id);
    });

    label->setVisible(true);
    m_labelList.append(label);
    update();
}

AuraStateLabel01 *AuraSwitchWidget01::getLabel(int index)
{
    if(index<0 || index>=m_labelList.size())
        return nullptr;
    return m_labelList[index];
}

void AuraSwitchWidget01::resizeEvent(QResizeEvent *e)
{
    UIWidget::resizeEvent(e);

    int count=m_labelList.size();
    if(count<1) return;
    int w=width()/count;
    int h=height();
    for(int i=0;i<m_labelList.count();++i)
    {
        m_labelList[i]->setGeometry(i*w,0,w,h);
    }
}

int AuraSwitchWidget01::nowIndex() const
{
    return m_nowIndex;
}

void AuraSwitchWidget01::setNowIndex(int newNowIndex)
{
    if(newNowIndex<0 || newNowIndex>=m_labelList.size()) return;
    m_preIndex = m_nowIndex;
    m_nowIndex = newNowIndex;

    updateLabelState();
}

void AuraSwitchWidget01::updateLabelState()
{
    if(m_nowIndex<0 || m_nowIndex>=m_labelList.size()) return;
    if(m_preIndex==m_nowIndex) return;
    m_labelList[m_nowIndex]->setNowState(ConstValue::StateLabelState::Current);
#ifdef QDEBUGCHECK
    qDebug()<<"AuraSwitchWidget01::updateLabelState | m_preIndex:"<<m_preIndex;
#endif
    if(m_preIndex<0 || m_preIndex>=m_labelList.size()) return;
    m_labelList[m_preIndex]->setNowState(ConstValue::StateLabelState::Normal);
#ifdef QDEBUGCHECK
    qDebug()<<"AuraSwitchWidget01::updateLabelState | end true.";
#endif
    emit nowIndexChanged(m_nowIndex);
}

void AuraSwitchWidget01::updateLayout()
{
    resizeEvent(nullptr);
}
