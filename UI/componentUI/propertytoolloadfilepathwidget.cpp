#include "propertytoolloadfilepathwidget.h"

#include <QMessageBox>
#include <QFileDialog>

PropertyToolLoadFilePathWidget::PropertyToolLoadFilePathWidget(QWidget *parent)
    : PropertyToolWidget{parent}
{

}

void PropertyToolLoadFilePathWidget::initWidget(PropertyEditWidget *w)
{
    PropertyToolWidget::initWidget(w);

    connect(m_toolBtn,&ClickLabel::clicked,this,[this](){
        QString path = QFileDialog::getOpenFileName();
        if(path.isEmpty())
        {
            QMessageBox::warning(this,"打开文件","选择文件路径不能为空");
            return;
        }
#ifdef QDEBUGCHECK
        qDebug()<<"PropertyToolLoadFilePathWidget::initWidget | check path:"<<path;
#endif
        updateFilePath(path);
    });
}

void PropertyToolLoadFilePathWidget::updateFilePath(const QString &path)
{
    //在此处需要做一次绝对路径转相对路径的存储  -->指定文件必须存放至某个文件夹 -->资源文件夹内
    auto & entity= m_toolBtn->entity();
    if(!entity.hasComponent("PropertyValue"))
    {
#ifdef QDEBUGCHECK
        qDebug()<<"PropertyToolLoadFilePathWidget::updateFilePath | error : no have Component PropertyValue.";
#endif
        return ;
    }
    auto propertyValueComponent=entity.getComponent("PropertyValue");
    //QVariant::fromValue(path)
    propertyValueComponent->setValue(path);
#ifdef QDEBUGCHECK
    qDebug()<<"PropertyToolLoadFilePathWidget::updateFilePath | this.";
#endif
    updateValue();
}
