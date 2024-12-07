#ifndef PROPERTYTOOLWIDGET_H
#define PROPERTYTOOLWIDGET_H

#include <QWidget>

#include "../../DATA/BaseClass/uiwidget.h"

#include "clicklabel.h"

class PropertyEditWidget;
class PropertyToolWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit PropertyToolWidget(QWidget *parent = nullptr);
    virtual void initWidget(PropertyEditWidget* linkWidget);
    void setLinkWidget(PropertyEditWidget * linkWidget);


    void updateValue();

    void initWidget()override final;
    void initWidget(const QJsonObject& obj)override final;
protected:
    void resizeEvent(QResizeEvent* e)override;
protected:
    ClickLabel * m_toolBtn=nullptr;
    PropertyEditWidget * m_linkWidget=nullptr;

signals:

};

#endif // PROPERTYTOOLWIDGET_H
