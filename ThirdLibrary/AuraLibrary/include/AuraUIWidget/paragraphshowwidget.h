#pragma once

#include <QWidget>
#include <QLabel>
#include <QString>
#include <QScrollArea>
#include <QVBoxLayout>

#include "UIHeader.h"
#include "uiwidget.h"

namespace AuraUI {

class ParagraphShowWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit ParagraphShowWidget(QWidget *parent = nullptr);
    void initWidget()override;
    void initWidgetStyle()override;
    void applyWidgetStyle()override;

    void setHead(const QString & headText);
    void addParagraph(const QString & text);
    void addTitle(const QString & text);
    void setHTML(const QString & htmlText);
    void clear();
    bool removeParagraph(unsigned int index);
    bool removeHead(unsigned int index);
protected:
    void updateShowArea();
    void resizeEvent(QResizeEvent*e)override;
    //void
private:
    QVector<QLabel*> m_titleList;
    QVector<QLabel*> m_paragraphList;

    QLabel * m_headLabel=nullptr;
    QWidget * m_splitWidget = nullptr;
    QWidget * m_introductionShowWidget=nullptr;
    QScrollArea * m_introductionShowArea=nullptr;

    QVBoxLayout * m_mainLayout = nullptr;
    QVBoxLayout * m_areaLayout = nullptr;

    QColor m_backgroundColor;

    QColor m_labelBackgroundColor;
    QColor m_labelTextColor;
    QColor m_slipLineColor;


    unsigned int splitLineHeight;

signals:

};

} // namespace AuraUI

