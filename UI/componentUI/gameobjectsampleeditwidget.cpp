#include "gameobjectsampleeditwidget.h"
#include "../../TOOL/QtTool/aurapixtool.h"
GameObjectSampleEditWidget::GameObjectSampleEditWidget(GameObject *obj, QWidget *parent)
    : QWidget{parent},m_linkObject(obj),m_initFlag(false)
{
    preInit();
}

void GameObjectSampleEditWidget::preInit()
{
    if(!m_linkObject ) return ;

    resize(400,800);
    m_mainLayout =new QVBoxLayout (this);
    m_mainLayout->setSpacing(5);
    m_mainLayout->setContentsMargins(5,10,5,10);
    m_objPropertyLayout=new QVBoxLayout(this);
    m_objPropertyLayout->setSpacing(10);
    m_objPropertyLayout->setContentsMargins(0,0,0,0);
    m_headLayout=new QHBoxLayout(this);
    m_headLayout->setSpacing(10);
    m_headLayout->setContentsMargins(0,0,0,0);
    m_bottomLayout=new QHBoxLayout(this);
    m_bottomLayout->setSpacing(10);
    m_bottomLayout->setContentsMargins(0,0,0,0);

    QVector<QMetaProperty> propertyList= AuraPropertyTool::getProperty(m_linkObject,1);

    // obj property
    int labelH= 30;
    for(int i=0;i<propertyList.size();++i)
    {
        PropertyEditWidget * w=new PropertyEditWidget(this);
        w->initWidget();
        w->setLink(m_linkObject,propertyList[i]);
        w->setMinimumHeight(labelH);
        m_objPropertyLayout->addWidget(w,1);
    }

    //Pix
    CardLabel * pixLabel =new CardLabel();
    pixLabel->setMinimumSize(90,90);
    pixLabel->setPix(ConstValue::SourceDir().path()+"/Engine/DefaultSource/DefaultCardPix.png");
    pixLabel->setPaintFunction(std::bind(GameObjectSampleEditWidget::paintPix,
                                         std::placeholders::_1,
                                         std::placeholders::_2));

    m_headLayout->addWidget(pixLabel,1);
    m_headLayout->addLayout(m_objPropertyLayout,1);

    //component
    WheelSlideWidget * slideWidget=new WheelSlideWidget(this);
    slideWidget->setWheelDirection(WheelSlideWidget::VDirection);

    auto componentList=m_linkObject->getComponetList();
    int vSpace=10;
    int nextY = vSpace;
    for(int i=0;i<componentList.size();++i)
    {
        ComponentEditWidget * w=new ComponentEditWidget();
        w->resize(width()-20,1);
        w->setComponentObj(componentList[i]);
        slideWidget->addWidgetInArea(w,5,nextY);
        nextY=nextY+w->height();
        w->setVisible(true);
    }

    //btn
    QPushButton * btn1=new QPushButton("确定");
    QPushButton * btn2=new QPushButton("另存为");
    QPushButton * btn3=new QPushButton("返回");

    m_bottomLayout->addWidget(btn1,1);
    m_bottomLayout->addWidget(btn2,1);
    m_bottomLayout->addWidget(btn3,1);

    m_mainLayout->addLayout(m_headLayout,3);
    m_mainLayout->addWidget(slideWidget,8);
    m_mainLayout->addLayout(m_bottomLayout,1);

    setLayout(m_mainLayout);
    m_initFlag=true;
}

bool GameObjectSampleEditWidget::initFlag() const
{
    return m_initFlag;
}

void GameObjectSampleEditWidget::paintPix(QPainter *p, CardLabel *w)
{
    qreal radius=w->radius();
    int a = qMin(w->width(),w->height());
    QRect pixRect((w->width()-a)/2,(w->height()-a)/2,a,a);
    p->setPen(Qt::NoPen);
    p->setBrush(Qt::NoBrush);
    p->drawPixmap(pixRect,AuraPixTool::getRoundRectPixmap(w->pixmap(),pixRect.size(),radius));
}

