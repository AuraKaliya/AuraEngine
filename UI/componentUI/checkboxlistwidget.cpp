#include "checkboxlistwidget.h"

CheckBoxListWidget::CheckBoxListWidget(QWidget *parent)
    : QWidget{parent},m_fixHeight(30),m_hSpace(10),m_vSpace(5)
{

}

void CheckBoxListWidget::addBox(QString text)
{
    QCheckBox* box=new QCheckBox(text,this);
    box->setCheckState(Qt::Unchecked);
    m_checkBoxList.append(box);
}

void CheckBoxListWidget::updateLayout()
{
    for(int i=0;i<m_checkBoxList.size();++i)
    {
        m_checkBoxList[i]->setGeometry(m_hSpace,i*(m_fixHeight+m_vSpace)+m_vSpace,width()-2*m_hSpace,m_fixHeight);
    }
}

void CheckBoxListWidget::resizeEvent(QResizeEvent *e)
{
    QWidget::resizeEvent(e);
    updateLayout();
}
