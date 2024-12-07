#include "model2dhpbar.h"

Model2DHPBar::Model2DHPBar(int nowHP, int maxHP, QObject *parent)
    : ComponentObject{parent}
    ,m_maxHP(maxHP)
    ,m_nowHP(nowHP)
    ,m_pixWidth(50)
    ,m_pixHeight(30)
    ,m_x(0)
    ,m_y(0)
    ,m_z(0)
    ,m_sceneId(0)
{
    REGISTER_TYPEID
    setObjectName("Model2DHPBar");


    m_item=new ItemHPBar(m_nowHP,m_maxHP,QPixmap(),this);
    m_item->setLinkObj(m_linkObj);

    //item 属性关联
    connect(m_item,&ItemHPBar::nowXChanged,this,&Model2DHPBar::setX);
    connect(m_item,&ItemHPBar::nowYChanged,this,&Model2DHPBar::setY);

    updateItemRect();
}

Model2DHPBar::Model2DHPBar(Model2DHPBar &other)
{
    const QMetaObject *metaObj = other.metaObject();
    int count =metaObj -> propertyCount();
    for(int i=0;i<count;++i)
    {
        QMetaProperty metaProperty=metaObj->property(i);
        if(metaProperty.isReadable() && metaProperty.isWritable())
        {
            QVariant value =other.property(metaProperty.name());
            this->setProperty(metaProperty.name(),value);
        }
    }

    setMaxHP(other.maxHP());
    setNowHP(other.nowHP());

    m_linkObj =nullptr;

    m_item=new ItemHPBar(m_nowHP,m_maxHP,QPixmap(),this);
    m_item->setLinkObj(m_linkObj);

    //item 属性关联
    connect(m_item,&ItemHPBar::nowXChanged,this,&Model2DHPBar::setX);
    connect(m_item,&ItemHPBar::nowYChanged,this,&Model2DHPBar::setY);

    updateItemRect();
}

void Model2DHPBar::setLinkObj(GameObject *obj)
{
    ComponentObject::setLinkObj(obj);
   if(m_item)m_item->setLinkObj(m_linkObj);
}

void Model2DHPBar::initComponent(const QJsonObject &obj)
{
    ComponentObject::initComponent(obj);

    //get Value
    auto maxHP = obj.value("MaxHP").toInt();
    auto nowHP = obj.value("NowHP").toInt();
    auto pixHeight = obj.value("PixHeight").toInt();
    auto pixWidth = obj.value("PixWidth").toInt();
    auto x = obj.value("X").toInteger();
    auto y = obj.value("Y").toInteger();
    auto z = obj.value("Z").toInt();
    auto sceneId = obj.value("SceneId").toInt();

    auto hpColorArray = obj.value("HPColor").toArray();


    //set Value
    setMaxHP(maxHP);
    setNowHP(nowHP);
    setPixHeight(pixHeight);
    setPixWidth(pixWidth);
    setX(x);
    setY(y);
    setZ(z);
    setSceneId(sceneId);

    if(hpColorArray.size()>=3)
    {
        setHPColor(QColor{hpColorArray[0].toInt(),hpColorArray[1].toInt(),hpColorArray[2].toInt()});
    }

    setInitFlag(true);
}

int Model2DHPBar::nowHP() const
{
    return m_nowHP;
}

void Model2DHPBar::setNowHP(int newNowHP)
{
    if (m_nowHP == newNowHP)
        return;

    if(newNowHP<0) newNowHP=0;
    if(newNowHP>=m_maxHP )
    {
        if(m_maxHP<=0 )
        {
            m_maxHP= 1;
        }
       newNowHP=m_maxHP;
    }

    m_nowHP = newNowHP;
    updateItemHP();
    emit nowHPChanged();
}

int Model2DHPBar::maxHP() const
{
    return m_maxHP;
}

void Model2DHPBar::setMaxHP(int newMaxHP)
{
    if (m_maxHP == newMaxHP)
        return;
    if(newMaxHP<=0) newMaxHP=1;
    m_maxHP = newMaxHP;
    updateItemHP();
    emit maxHPChanged();
}

float Model2DHPBar::pixWidth() const
{
    return m_pixWidth;
}

void Model2DHPBar::setPixWidth(float newPixWidth)
{
    if (qFuzzyCompare(m_pixWidth, newPixWidth))
        return;
    m_pixWidth = newPixWidth;
    updateItemRect();
    emit pixWidthChanged();
}

float Model2DHPBar::pixHeight() const
{
    return m_pixHeight;
}

void Model2DHPBar::setPixHeight(float newPixHeight)
{
    if (qFuzzyCompare(m_pixHeight, newPixHeight))
        return;
    m_pixHeight = newPixHeight;
        updateItemRect();
    emit pixHeightChanged();
}

float Model2DHPBar::x() const
{
    return m_x;
}

void Model2DHPBar::setX(float newX)
{
    if (qFuzzyCompare(m_x, newX))
        return;
    m_x = newX;
    updateItemPos();
    emit xChanged();
}

float Model2DHPBar::y() const
{
    return m_y;
}

void Model2DHPBar::setY(float newY)
{
    if (qFuzzyCompare(m_y, newY))
        return;
    m_y = newY;
        updateItemPos();
    emit yChanged();
}

int Model2DHPBar::z() const
{
    return m_z;
}

void Model2DHPBar::setZ(int newZ)
{
    if (m_z == newZ)
        return;
    m_z = newZ;
    updateItemPos();
    emit zChanged();
}

int Model2DHPBar::sceneId() const
{
    return m_sceneId;
}

void Model2DHPBar::setSceneId(int newSceneId)
{
    if (m_sceneId == newSceneId)
        return;
    m_sceneId = newSceneId;

    if(m_item)
    {
        m_item->setSceneIdx(m_sceneId);
    }
    emit sceneIdChanged();
}

void Model2DHPBar::updateItemRect()
{
    if(!m_item)
    {
        return;
    }
    m_item->setItemRect(QRectF(0,0,m_pixWidth,m_pixHeight));
}

void Model2DHPBar::updateItemPos()
{
    if(!m_item)
    {
        return;
    }
    m_item->setX(m_x);
    m_item->setY(m_y);
    m_item->setZValue(m_z);
}

void Model2DHPBar::updateItemHP()
{
    if(!m_item) return;
    m_item->setMaxHP(m_maxHP);
    m_item->setNowHP(m_nowHP);
}

ItemHPBar *Model2DHPBar::item() const
{
    return m_item;
}

void Model2DHPBar::setHPColor(const QColor &color)
{
    if(!m_item) return;
    m_item->setHpColor(color);
}
