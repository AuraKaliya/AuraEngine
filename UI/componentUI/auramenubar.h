#ifndef AURAMENUBAR_H
#define AURAMENUBAR_H

#include <QWidget>
#include <QMenuBar>
#include <QScopedPointer>

#include "../../DATA/BaseClass/baseclass.h"

//不妥 废弃

class AuraMenuBar : public UIWidget
{
    Q_OBJECT
public:
    explicit AuraMenuBar(QWidget *parent = nullptr);
    void initWidget()override;
    QMenuBar *bar() const;

private:
    QMenuBar * m_bar;
signals:
};

REGISTER_CLASS(AuraMenuBar,UIWidget,QWidget*)
#endif // AURAMENUBAR_H
