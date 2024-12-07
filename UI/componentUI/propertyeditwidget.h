#ifndef PROPERTYEDITWIDGET_H
#define PROPERTYEDITWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QMetaProperty>
#include <QHBoxLayout>
#include "../../DATA/BaseClass/uiwidget.h"




class PropertyEditWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit PropertyEditWidget(QWidget *parent = nullptr);
    void initWidget()override;
    void setRatio(int x1=4,int x2= 6.0,int vSpacing=0,int hSpacing=0);
    void setLink(QObject* obj,QMetaProperty property);
    void setValue(QString value);
    void setHotUpdate(bool flag);
    void addToolWidget(UIWidget * w);

    void submitValue();
    void updateValue();
protected:
    void resizeEvent(QResizeEvent* e)override;
private:

    QLabel* m_titleLabel=nullptr;
    QLineEdit* m_valueLabel=nullptr;

    QHBoxLayout * m_mainLayout=nullptr;

    QMetaProperty m_linkProperty;
    QObject* m_linkObject=nullptr;

    bool m_hotUpdate;

    int m_ratioX1;
    int m_ratioX2;
    int m_vSpacing;
    int m_hSpacing;


signals:

};

#endif // PROPERTYEDITWIDGET_H
