#ifndef EDITGAMESHOWWIDGET_H
#define EDITGAMESHOWWIDGET_H

#include <QWidget>
#include "../../DATA/BaseClass/uiwidget.h"

#include "../componentUI/gameshowview.h"


class EditGameShowWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit EditGameShowWidget(QWidget *parent = nullptr);
    void initWidget()override;
    void updateLayout();
private:

    GameShowView * m_view=nullptr;

signals:

};
REGISTER_CLASS(EditGameShowWidget,UIWidget,QWidget*)
#endif // EDITGAMESHOWWIDGET_H
