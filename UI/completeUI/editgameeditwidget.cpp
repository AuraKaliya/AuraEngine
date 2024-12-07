#include "editgameeditwidget.h"

EditGameEditWidget::EditGameEditWidget(QWidget *parent)
    : UIWidget{parent}
{
    m_switchWidget=new AuraSwitchWidget01(this);
    m_mainEditWidget=new QStackedWidget(this);

    m_demoEditWidget=new DemoEditWidget(m_mainEditWidget);
    m_gameObjectEditWidget=new GameObjectEditWidget(m_mainEditWidget);
    m_itemEditWidget=new ItemEditWidget(m_mainEditWidget);

}

void EditGameEditWidget::initWidget()
{

#ifdef QDEBUGCHECK
    qDebug()<<"EditGameEditWidget::initWidget | initWidget.";
#endif
//====================后续可改为通过配置数据进行初始化========================
    //=============  编辑栏菜单 ================
    AuraStateLabel01* label1 =new AuraStateLabel01("Demo");
    m_switchWidget->addLabel(label1);

    AuraStateLabel01* label2 =new AuraStateLabel01("Object");
    m_switchWidget->addLabel(label2);

    AuraStateLabel01* label3 =new AuraStateLabel01("Item");
    m_switchWidget->addLabel(label3);

    m_switchWidget->setNowIndex(0);
    //=============  编辑栏菜单 ================


    //=============  编辑栏主体 ================
    m_mainEditWidget->addWidget(m_demoEditWidget);
    m_mainEditWidget->addWidget(m_gameObjectEditWidget);
    m_mainEditWidget->addWidget(m_itemEditWidget);

    m_editWidgetList.append(m_demoEditWidget);
    m_editWidgetList.append(m_gameObjectEditWidget);
    m_editWidgetList.append(m_itemEditWidget);

    updateLayout();
    m_gameObjectEditWidget->initWidget();

    m_mainEditWidget->setCurrentIndex(0);
    //=============  编辑栏主体 ================



    //connect
    connect(m_switchWidget,&AuraSwitchWidget01::nowIndexChanged,m_mainEditWidget,&QStackedWidget::setCurrentIndex);
    connect(m_mainEditWidget,&QStackedWidget::currentChanged,this,[](int i){
        qDebug()<<"QStackedWidget::currentChanged | now Idx:"<<i;
    });


//====================后续可改为通过配置数据进行初始化========================
#ifdef QDEBUGCHECK
    qDebug()<<"EditGameEditWidget::initWidget | initWidget end.";
#endif

    //==================test=====================
    //m_gameObjectEditWidget->setNowGameObject(new TestCharacter);
    //==================test=====================


    updateLayout();
}

void EditGameEditWidget::updateLayout()
{
    resizeEvent(nullptr);
    m_switchWidget->updateLayout();
}


void EditGameEditWidget::setNowGameObject(GameObject *obj)
{
    m_gameObjectEditWidget->setNowGameObject(obj);
}

void EditGameEditWidget::resizeEvent(QResizeEvent *e)
{
    UIWidget::resizeEvent(e);

    int switchWidgetHeight=height()/10;
    int mainEditWidetHeight=(height()*7)/10;
    m_switchWidget->setGeometry(0,0,width(),switchWidgetHeight);

    m_mainEditWidget->setGeometry(0,switchWidgetHeight,width(),mainEditWidetHeight);
    for(auto it:m_editWidgetList)
    {
        it->setGeometry(0,0,m_mainEditWidget->width(),m_mainEditWidget->height());
    }

}
