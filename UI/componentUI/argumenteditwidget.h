#ifndef ARGUMENTEDITWIDGET_H
#define ARGUMENTEDITWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>


class ArgumentEditWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ArgumentEditWidget(const QString& text,QWidget *parent = nullptr);
    QString getTitle();
    void setTitle(const QString & title);
    QString getValue();
    void setValue(const QString &  value);
private:
    QHBoxLayout* m_mainLayout=nullptr;
    QLabel * m_label =nullptr;
    QLineEdit * m_editBox= nullptr;

signals:
};

#endif // ARGUMENTEDITWIDGET_H
