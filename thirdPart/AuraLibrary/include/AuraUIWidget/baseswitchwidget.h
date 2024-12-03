#pragma once
#include <QWidget>

#include "UIHeader.h"
#include "uiwidget.h"
#include "componentclicklabel.h"


namespace AuraUI {

class AURAUI_LIB_DECL BaseSwitchWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit BaseSwitchWidget(QWidget *parent = nullptr);
    void initWidget()override;
    virtual void addLabel(ComponentClickLabel* label);

    ComponentClickLabel* getLabel(int index);
    int nowIndex()const;
    int labelCount()const;
protected:
    void resizeEvent(QResizeEvent* e)override;
protected:
    QVector<ComponentClickLabel*> m_labelList;
    int m_nowIndex;
    int m_preIndex;
signals:
    void nowIndexChanged(int);
public slots:
    void setNowIndex(int newNowIndex);
    virtual void updateLabelState();
};

}// namespace AuraUI
