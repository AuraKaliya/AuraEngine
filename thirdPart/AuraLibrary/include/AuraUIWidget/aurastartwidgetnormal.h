#pragma once

#include <QWidget>


#include "UIHeader.h"
#include "uiwidget.h"



//Qt 前置声明
class QStackedWidget;
class QHBoxLayout;
class QScrollArea;

namespace AuraUI {

class AuraHeadBarNormal;
class ParagraphShowWidget;

class AuraLibrary_DECL AuraStartWidgetNormal : public UIWidget
{
    Q_OBJECT
public:
    explicit AuraStartWidgetNormal(QWidget *parent = nullptr);

    void initWidget()override;
    void initWidgetStyle()override;
    void applyWidgetStyle()override;


    AuraCardLabel* addToolBtn(const QString& text,const QPixmap& pix);
    AuraCardLabel* addCard(const QString & toolBarText,const QString& text,const QPixmap& pix);


    void check();

    AuraCardLabel *nowToolBar() const;
    void setNowToolBar(AuraCardLabel *newNowToolBar);

    AuraCardLabel *nowCard() const;
    void setNowCard(AuraCardLabel *newNowCard);

protected:
    void paintEvent(QPaintEvent*e)override;
    void resizeEvent(QResizeEvent* e)override;
    void showEvent(QShowEvent* e)override;
    void leftWidgetRelayout();
    void updateInfoWidget(AuraCardLabel* cl);

    //可提出去
    QPainterPath getRoundRectPath(int width, int height, int leftTop, int rightTop, int leftBottom, int rightBottom);
private:
    AuraHeadBarNormal*  m_headBar    =   nullptr;
    UIWidget*           m_centralWidget = nullptr;

    //布局
    QHBoxLayout *       m_mainLayout            =   nullptr ;
    //QVBoxLayout *       m_leftLayout            =   nullptr ;
    QWidget *          m_leftToolBarWidget     = nullptr;
    QScrollArea*        m_leftToolBar           =   nullptr ;
    QStackedWidget*     m_middleToolWidget      =   nullptr ;
    ParagraphShowWidget*           m_rightInfoWidget       =   nullptr ;

    //管理的组件
    AuraCardLabel* m_nowToolBar = nullptr;
    AuraCardLabel* m_nowCard = nullptr;
    QVector<AuraCardLabel* > m_toolBarList;
    QVector<AuraCardLabel* > m_cardList;
    QMap<QString,AuraCardLabel*> m_cardDictionary;

    QColor m_backgroundColor;
    QColor m_borderColor;
    unsigned int m_radius;

signals:
    void nowToolBarChanged();
    void nowCardChanged();
};
}// namespace AuraUI
