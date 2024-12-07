#ifndef PROPERTYTOOLLOADFILEPATHWIDGET_H
#define PROPERTYTOOLLOADFILEPATHWIDGET_H

#include <QWidget>
#include "propertytoolwidget.h"

class PropertyToolLoadFilePathWidget : public PropertyToolWidget
{
    Q_OBJECT
public:
    explicit PropertyToolLoadFilePathWidget(QWidget *parent = nullptr);
    void initWidget(PropertyEditWidget* w);
    void updateFilePath(const QString & path);
signals:

};
REGISTER_CLASS(PropertyToolLoadFilePathWidget,PropertyToolWidget,QWidget*)

#endif // PROPERTYTOOLLOADFILEPATHWIDGET_H
