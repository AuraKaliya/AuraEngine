#ifndef MODEL2DITEM_H
#define MODEL2DITEM_H

#include <QObject>
#include <QString>
#include <QPixmap>
#include <QGraphicsItem>
#include <QGraphicsScene>

#include "../BaseClass/componentobject.h"

#include "../BaseClass/objectitem.h"


class Model2DItem : public ComponentObject
{
    Q_OBJECT
    Q_PROPERTY(QString pixPath READ pixPath WRITE setPixPath NOTIFY pixPathChanged)
    Q_PROPERTY(float pixWidth READ pixWidth WRITE setPixWidth NOTIFY pixWidthChanged)
    Q_PROPERTY(float pixHeight READ pixHeight WRITE setPixHeight NOTIFY pixHeightChanged)
    Q_PROPERTY(float x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(float y READ y WRITE setY NOTIFY yChanged)
    Q_PROPERTY(int z READ z WRITE setZ NOTIFY zChanged)
    Q_PROPERTY(int sceneId READ sceneId WRITE setSceneId NOTIFY sceneIdChanged)

public:
    explicit Model2DItem(QString pixPath="",QObject *parent = nullptr);
    explicit Model2DItem(Model2DItem & other);
    QJsonObject getMetaData()const override;
    void setLinkObj(GameObject*obj)override;
    void initComponent(const QJsonObject & obj)override ;

    QString pixPath() const;
    void setPixPath(const QString &newPixPath);

    QPixmap pixmap();

    ObjectItem *item() const;

    float pixWidth() const;
    void setPixWidth(float newPixWidth);

    float pixHeight() const;
    void setPixHeight(float newPixHeight);

    float x() const;
    void setX(float newX);

    float y() const;
    void setY(float newY);

    int z() const;
    void setZ(int newZ);

    void updateItemRect();
    void updateItemPos();
    int sceneId() const;
    void setSceneId(int newSceneId);


protected:

protected:
    QString m_pixPath;
    QPixmap m_pixmap;

    ObjectItem * m_item=nullptr;

    float m_pixWidth;
    float m_pixHeight;
    float m_x;
    float m_y;
    int m_z;
    int m_sceneId;
signals:

    void pixPathChanged();
    void pixWidthChanged();
    void pixHeightChanged();
    void xChanged();
    void yChanged();
    void zChanged();
    void sceneIdChanged();
private:

};

REGISTER_CLASS(Model2DItem,ComponentObject)
REGISTER_COPY_CLASS(Model2DItem,ComponentObject)

#endif // MODEL2DITEM_H
