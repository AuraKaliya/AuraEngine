#pragma once

#include <QWidget>
#include <QMap>
#include <QString>
#include <QImage>
#include <QPixmap>
#include <QColor>
#include <QLabel>
#include <QHBoxLayout>


#include "UIHeader.h"
#include "uiwidget.h"
namespace AuraUI {

class AURAUI_LIB_DECL AuraTitleBar : public UIWidget
{
    Q_OBJECT
public:
    explicit AuraTitleBar(const QString& title,QWidget *parent = nullptr);

    QPixmap titleIcon() const;
    void setTitleIcon(const QPixmap &newTitleIcon);
    void initWidget()override;
protected:
    void resizeEvent(QResizeEvent *e)override;
    //void paintEvent(QPaintEvent *e)override;
    void reLayoutToolBar();


private:
    unsigned int m_minHeight;
    unsigned int m_maxHeight;

    float m_horizonMargin;
    float m_verticalMargin;

    bool m_dragControlFlag;
    bool m_iconFlag;

    QLabel* m_iconLabel  = nullptr;
    QLabel* m_titleLabel = nullptr;
    QWidget* m_toolWidget =nullptr;
    QHBoxLayout * m_layout;


    QString m_title;
    QPixmap m_titleIcon;
    QColor m_titleColor;
    QColor m_backgroundColor;


    QMap<QString,QWidget*> m_toolBarDictionary;
signals:

};

}// namespace AuraUI
