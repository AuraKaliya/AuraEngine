#include "model2ditem.h"

Model2DItem::Model2DItem(QString pixPath, QObject *parent)
    : ComponentObject{parent}
    ,m_pixPath(pixPath)
    ,m_pixWidth(50)
    ,m_pixHeight(50)
    ,m_x(0)
    ,m_y(0)
    ,m_z(0)
    ,m_sceneId(0)
{
    REGISTER_TYPEID
    setObjectName("Model2DItem");
    m_pixmap.load(m_pixPath);

    //====item的父对象是model   model的父对象是object
    m_item=new ObjectItem(m_pixmap,this);
    m_item->setLinkObj(m_linkObj);

    //item 属性关联
    connect(m_item,&ObjectItem::nowXChanged,this,&Model2DItem::setX);
    connect(m_item,&ObjectItem::nowYChanged,this,&Model2DItem::setY);

    if(!m_pixmap.isNull())
    {
        setPixWidth(m_pixmap.width());
        setPixHeight(m_pixmap.height());
    }

    //对item 的rect进行初始化
    updateItemRect();
}

Model2DItem::Model2DItem(Model2DItem &other)
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
    m_linkObj =nullptr;

    m_pixmap.load(m_pixPath);
    m_item=new ObjectItem(m_pixmap,this);
    m_item->setLinkObj(m_linkObj);

    //item 属性关联
    connect(m_item,&ObjectItem::nowXChanged,this,&Model2DItem::setX);
    connect(m_item,&ObjectItem::nowYChanged,this,&Model2DItem::setY);

    updateItemRect();
}

QJsonObject Model2DItem::getMetaData() const
{
    return QJsonObject();
}

void Model2DItem::setLinkObj(GameObject *obj)
{
    ComponentObject::setLinkObj(obj);
    if(m_item)m_item->setLinkObj(m_linkObj);
}

void Model2DItem::initComponent(const QJsonObject &obj)
{
    ComponentObject::initComponent(obj);

    //get Value
    QString path = obj.value("PixPath").toString();
    //ConstValue::SourceDir().path()
    int pixHeight =obj.value("PixHeight").toInt();
    int pixWidth = obj.value("PixWidth").toInt();
    auto x = obj.value("X").toInteger();
    auto y = obj.value("Y").toInteger();
    int z = obj.value("Z").toInt();
    unsigned int sceneId =obj.value("SceneId").toInt();

    //set Value
    setPixPath(ConstValue::SourceDir().path()+path);
    setPixHeight(pixHeight);
    setPixWidth(pixWidth);
    setX(x);
    setY(y);
    setZ(z);
    setSceneId(sceneId);

    //other
    setInitFlag(true);
}

QString Model2DItem::pixPath() const
{
    return m_pixPath;
}

void Model2DItem::setPixPath(const QString &newPixPath)
{

    if (m_pixPath == newPixPath)
        return;

    if(!QPixmap(newPixPath).isNull())
    {
#ifdef QDEBUGCHECK
        qDebug()<<"Model2DItem::setPixPath | path load :"<<newPixPath;
#endif
        m_pixPath=newPixPath;
        m_pixmap.load(m_pixPath);

        if(m_item)
        m_item->setPix(m_pixmap);

        emit pixPathChanged();
    }else
    {

#ifdef QDEBUGCHECK
        qDebug()<<"Model2DItem::setPixPath | path null :"<<newPixPath;
#endif

    }
}

QPixmap Model2DItem::pixmap()
{
    return m_pixmap;
}

ObjectItem *Model2DItem::item() const
{
    return m_item;
}

float Model2DItem::pixWidth() const
{
    return m_pixWidth;
}

void Model2DItem::setPixWidth(float newPixWidth)
{
    if (qFuzzyCompare(m_pixWidth, newPixWidth))
        return;

    m_pixWidth = newPixWidth;
    updateItemRect();
    emit pixWidthChanged();
#ifdef QDEBUGCHECK
    if(m_item)
    qDebug()<<"Model2DItem::setPixWidth | now PixWidth:"<<m_pixWidth<<"item :"<<dynamic_cast<QGraphicsItem*>(m_item)<<" | rect:"<<dynamic_cast<QGraphicsItem*>(m_item)->boundingRect();
#endif

}

float Model2DItem::pixHeight() const
{
    return m_pixHeight;
}

void Model2DItem::setPixHeight(float newPixHeight)
{
    if (qFuzzyCompare(m_pixHeight, newPixHeight))
        return;

    m_pixHeight = newPixHeight;
    updateItemRect();
    emit pixHeightChanged();
}

float Model2DItem::x() const
{
    return m_x;
}

void Model2DItem::setX(float newX)
{
    if (qFuzzyCompare(m_x, newX))
        return;

    m_x = newX;
    updateItemPos();
    emit xChanged();

}

float Model2DItem::y() const
{
    return m_y;
}

void Model2DItem::setY(float newY)
{
    if (qFuzzyCompare(m_y, newY))
        return;
    m_y = newY;
    updateItemPos();
    emit yChanged();
}

int Model2DItem::z() const
{
    return m_z;
}

void Model2DItem::setZ(int newZ)
{
    if (m_z == newZ)
        return;
    m_z = newZ;

    updateItemPos();

    emit zChanged();
}

void Model2DItem::updateItemRect()
{
    if(!m_item)
    {
        return;
    }
    m_item->setItemRect(QRectF(0,0,m_pixWidth,m_pixHeight));
}

void Model2DItem::updateItemPos()
{
    if(!m_item)
    {
        return;
    }
    m_item->setX(m_x);
    m_item->setY(m_y);
    m_item->setZValue(m_z);
}

int Model2DItem::sceneId() const
{
    return m_sceneId;
}

void Model2DItem::setSceneId(int newSceneId)
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


