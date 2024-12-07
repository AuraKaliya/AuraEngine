#include "argumenteditwidget.h"

ArgumentEditWidget::ArgumentEditWidget(const QString &text, QWidget *parent)
    : QWidget{parent}
{
    m_mainLayout =new QHBoxLayout();
    m_label=new QLabel(text,this);
    m_editBox= new QLineEdit(this);

    m_mainLayout ->addWidget(m_label,5);
    m_mainLayout ->addWidget(m_editBox,5);

    setLayout(m_mainLayout);

}

QString ArgumentEditWidget::getTitle()
{
    return m_label->text();
}

void ArgumentEditWidget::setTitle(const QString &title)
{
    m_label->setText(title);
}

QString ArgumentEditWidget::getValue()
{
    return m_editBox->text();
}

void ArgumentEditWidget::setValue(const QString &value)
{
    m_editBox->setText(value);
}
