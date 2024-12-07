#ifndef MODEL2DPIX_H
#define MODEL2DPIX_H

#include <QObject>
#include <QString>
#include <QPixmap>
#include "../BaseClass/componentobject.h"

class Model2DPix : public ComponentObject
{
    Q_OBJECT
    Q_PROPERTY(QString pixPath READ pixPath WRITE setPixPath NOTIFY pixPathChanged)

public:
    explicit Model2DPix(QObject *parent = nullptr);
    QJsonObject getMetaData()const override;
    QString pixPath() const;
    void setPixPath(const QString &newPixPath);

    QPixmap pixmap() const;

signals:
    void pixPathChanged();
private:
    QString m_pixPath;
    QPixmap m_pixmap;
};


#endif // MODEL2DPIX_H
