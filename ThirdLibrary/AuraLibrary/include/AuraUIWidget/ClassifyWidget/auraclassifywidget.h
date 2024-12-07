#pragma once

#include <QWidget>

#include "../UIHeader.h"
#include "../uiwidget.h"

namespace AuraUI {

enum class ClassifyWidgetStyle:int{
    Default,
    Classify,
    FixedView,
    Circle

};

class AuraLibrary_DECL AuraClassifyWidget : public UIWidget
{
    Q_OBJECT
    friend class UIFunction;
public:
    explicit AuraClassifyWidget(QWidget *parent = nullptr);
    ~AuraClassifyWidget();
    void initWidget()override;
    void initWidgetStyle()override;
    void applyWidgetStyle()override;

    void initWidget(ClassifyWidgetStyle style);

    void addCategory(const QString& name);

    QList<QString> getCategoryList();
    QList<QWidget*>getCategoryWidgetList();
protected:
    void paintEvent(QPaintEvent* e)override;
    void resizeEvent(QResizeEvent* e)override;

private:
    class AuraClassifyWidgetPrivate;
    friend class AuraClassifyWidgetPrivate;
    QScopedPointer<AuraClassifyWidgetPrivate> m_d;

signals:
    void nowCategoryChangedSig(const QString& nowCategory);
};

} // namespace AuraUI
