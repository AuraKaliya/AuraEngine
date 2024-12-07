#ifndef CHECKBOXLISTWIDGET_H
#define CHECKBOXLISTWIDGET_H

#include <QWidget>
#include <QCheckBox>
#include <QVector>
#include <QMap>
class CheckBoxListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CheckBoxListWidget(QWidget *parent = nullptr);
    void addBox(QString text);
    void updateLayout();
protected:
    void resizeEvent(QResizeEvent*e)override;
private:
    QVector<QCheckBox*> m_checkBoxList;

    int m_fixHeight;
    int m_hSpace;
    int m_vSpace;
signals:

};

#endif // CHECKBOXLISTWIDGET_H
