#include "editgameshowwidget.h"

EditGameShowWidget::EditGameShowWidget(QWidget *parent)
    : UIWidget{parent}
{
    m_view=new GameShowView(this);

}

void EditGameShowWidget::initWidget()
{
    if(!m_view) return ;
    setCenterWidget(m_view);

    connect(m_view,&GameShowView::nowGameObjectSelected,this,[this](GameObject* obj,ComponentObject* component){
        //  暂时不做item所属的component的高亮  只做到选中GameObject的提示
        emit nowGameObjectChanged(obj);
    });


    updateLayout();
}

void EditGameShowWidget::updateLayout()
{
    resizeEvent(nullptr);
}
