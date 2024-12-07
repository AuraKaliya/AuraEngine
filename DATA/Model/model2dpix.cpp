#include "model2dpix.h"

Model2DPix::Model2DPix(QObject *parent)
    : ComponentObject{parent},m_pixPath("")
{
    REGISTER_TYPEID
    setObjectName("Model2DPix");
}

QJsonObject Model2DPix::getMetaData() const
{
    QJsonObject obj;

    return obj;
}

QString Model2DPix::pixPath() const
{
    return m_pixPath;
}

void Model2DPix::setPixPath(const QString &newPixPath)
{
    if (m_pixPath == newPixPath)
        return;

    if(!QPixmap(newPixPath).isNull())
    {
        m_pixPath=newPixPath;
        m_pixmap.load(m_pixPath);
        emit pixPathChanged();
    }
}

QPixmap Model2DPix::pixmap() const
{
    return m_pixmap;
}
