#ifndef MODEL2DHPBAR_H
#define MODEL2DHPBAR_H

#include <QObject>


#include "../BaseClass/componentobject.h"
#include "../Item/itemhpbar.h"

class Model2DHPBar : public ComponentObject
{
    Q_OBJECT
    Q_PROPERTY(int nowHP READ nowHP WRITE setNowHP NOTIFY nowHPChanged)
    Q_PROPERTY(int maxHP READ maxHP WRITE setMaxHP NOTIFY maxHPChanged)
    Q_PROPERTY(float pixWidth READ pixWidth WRITE setPixWidth NOTIFY pixWidthChanged)
    Q_PROPERTY(float pixHeight READ pixHeight WRITE setPixHeight NOTIFY pixHeightChanged)
    Q_PROPERTY(float x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(float y READ y WRITE setY NOTIFY yChanged)
    Q_PROPERTY(int z READ z WRITE setZ NOTIFY zChanged)
    Q_PROPERTY(int sceneId READ sceneId WRITE setSceneId NOTIFY sceneIdChanged)


public:
    explicit Model2DHPBar(int nowHP=100,int maxHP=100,QObject *parent = nullptr);
    explicit Model2DHPBar(Model2DHPBar& other);
    void setLinkObj(GameObject*obj)override;
    void initComponent(const QJsonObject& obj)override;
    int nowHP() const;
    void setNowHP(int newNowHP);

    int maxHP() const;
    void setMaxHP(int newMaxHP);


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

    int sceneId() const;
    void setSceneId(int newSceneId);

    void updateItemRect();
    void updateItemPos();
    void updateItemHP();

    ItemHPBar *item() const;

    void setHPColor(const QColor & color);

private:
    int m_maxHP;
    int m_nowHP;


    ItemHPBar * m_item=nullptr;
    float m_pixWidth;

    float m_pixHeight;

    float m_x;

    float m_y;

    int m_z;

    int m_sceneId;


signals:

    void nowHPChanged();
    void maxHPChanged();
    void pixWidthChanged();
    void pixHeightChanged();
    void xChanged();
    void yChanged();
    void zChanged();
    void sceneIdChanged();
};
REGISTER_CLASS( Model2DHPBar , ComponentObject )
REGISTER_COPY_CLASS( Model2DHPBar , ComponentObject )

#endif // MODEL2DHPBAR_H
