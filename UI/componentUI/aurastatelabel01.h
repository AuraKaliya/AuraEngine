#ifndef AURASTATELABEL01_H
#define AURASTATELABEL01_H

#include <QWidget>

#include "clicklabel.h"

#include "../../DATA/constvalue.h"

class AuraStateLabel01 : public ClickLabel
{
    Q_OBJECT
public:
    static void setStateStyle(ConstValue::StateLabelState state,QColor color);
    static QColor stateStyle(ConstValue::StateLabelState state);
public:
    explicit AuraStateLabel01(QWidget *parent = nullptr);
    explicit AuraStateLabel01(const QString &text, QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());


    int id() const;
    void setId(int newId);

    ConstValue::StateLabelState nowState() const;
    void setNowState(ConstValue::StateLabelState newNowState);

protected:
    void mouseReleaseEvent(QMouseEvent* e)override;
    void paintEvent(QPaintEvent* e)override;
private:
    void initLabel();
private:
    static QMap<ConstValue::StateLabelState,QColor> m_stateToStyleDictionary;


private:
    int m_id;
    ConstValue::StateLabelState m_nowState;

signals:
    void clickedId(int);
};

#endif // AURASTATELABEL01_H
