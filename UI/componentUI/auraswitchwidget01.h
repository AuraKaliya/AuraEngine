#ifndef AURASWITCHWIDGET01_H
#define AURASWITCHWIDGET01_H

#include <QWidget>

#include "../../DATA/BaseClass/uiwidget.h"


#include "aurastatelabel01.h"

class AuraSwitchWidget01 : public UIWidget
{
    Q_OBJECT
public:
    explicit AuraSwitchWidget01(QWidget *parent = nullptr);
    void initWidget()override;


    void addLabel(AuraStateLabel01* label);
    AuraStateLabel01* getLabel(int index);
    int nowIndex() const;
    void setNowIndex(int newNowIndex);
    void updateLabelState();
    void updateLayout();
protected:
    void resizeEvent(QResizeEvent* e)override;
private:
    QVector<AuraStateLabel01*> m_labelList;
    int m_nowIndex;
    int m_preIndex;

signals:
    void nowIndexChanged(int);
};

#endif // AURASWITCHWIDGET01_H
