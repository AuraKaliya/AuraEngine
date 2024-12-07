#include "editsourceeidtwidget.h"

#include <QPushButton>

EditSourceEidtWidget::EditSourceEidtWidget(QWidget *parent)
    : UIWidget{parent}
{
    m_switchWidget=new AuraSwitchWidget01(this);
    m_mainEditWidget=new QStackedWidget(this);
}

void EditSourceEidtWidget::initWidget()
{

    //=============  编辑栏菜单 ================
    AuraStateLabel01* label1 =new AuraStateLabel01("资产区");
    m_switchWidget->addLabel(label1);

    AuraStateLabel01* label2 =new AuraStateLabel01("样板区");
    m_switchWidget->addLabel(label2);

    AuraStateLabel01* label3 =new AuraStateLabel01("GO区");
    m_switchWidget->addLabel(label3);

    AuraStateLabel01* label4 =new AuraStateLabel01("插件区");
    m_switchWidget->addLabel(label4);

    m_switchWidget->setNowIndex(0);
    //=============  编辑栏菜单 ================

    //================测试用   各区页面====================
    //=======资产区
    QWidget* w1 =new QWidget();
    QVBoxLayout * layout1=new QVBoxLayout(w1);
    AuraSwitchWidget01* switchWidget1 =new AuraSwitchWidget01(w1);
    QWidget* w11 =new QWidget(w1);
    UIWidget* w12 =new UIWidget(w1);

    layout1->addWidget(switchWidget1,1);
    layout1->addWidget(w11,13);
    layout1->addWidget(w12,1);
    w1->setLayout(layout1);

    AuraStateLabel01* l11 =new AuraStateLabel01("图片");
    AuraStateLabel01* l12 =new AuraStateLabel01("音频");
    AuraStateLabel01* l13 =new AuraStateLabel01("模型");
    switchWidget1->addLabel(l11);
    switchWidget1->addLabel(l12);
    switchWidget1->addLabel(l13);
    switchWidget1->setNowIndex(0);

    m_mainEditWidget->addWidget(w1);
    m_editWidgetList.append(w1);


    //=====================操作区 （按钮）==================
    FlowLayout* fLayout1=new FlowLayout(w12);

    QPushButton * btn11=new QPushButton("导入资产",w12);
    btn11->setFixedHeight(30);
    btn11->adjustSize();
    fLayout1->addWidget(btn11);

    QPushButton * btn12=new QPushButton("导入配置",w12);
    btn12->setFixedHeight(30);
    btn12->adjustSize();
    fLayout1->addWidget(btn12);

    w12->setLayout(fLayout1);

    //=====================操作区 （按钮）==================

    //=======资产区

    //=======样板区
    QWidget* w2 =new QWidget();
    QVBoxLayout * layout2=new QVBoxLayout(w2);
    AuraSwitchWidget01* switchWidget2 =new AuraSwitchWidget01(w2);
    QWidget* w21 =new QWidget(w2);
    UIWidget* w22 =new UIWidget(w2);

    layout2->addWidget(switchWidget2,1);
    layout2->addWidget(w21,13);
    layout2->addWidget(w22,1);
    w2->setLayout(layout2);

    AuraStateLabel01* l21 =new AuraStateLabel01("默认");
    AuraStateLabel01* l22 =new AuraStateLabel01("自定义1");
    AuraStateLabel01* l23 =new AuraStateLabel01("自定义2");
    switchWidget2->addLabel(l21);
    switchWidget2->addLabel(l22);
    switchWidget2->addLabel(l23);
    switchWidget2->setNowIndex(0);

    m_mainEditWidget->addWidget(w2);
    m_editWidgetList.append(w2);


    //=====================操作区 （按钮）==================
    FlowLayout* fLayout2=new FlowLayout(w22);

    QPushButton * btn21=new QPushButton("导入样板",w22);
    btn21->setFixedHeight(30);
    btn21->adjustSize();
    fLayout2->addWidget(btn21);

    QPushButton * btn22=new QPushButton("导出样板",w22);
    btn22->setFixedHeight(30);
    btn22->adjustSize();
    fLayout2->addWidget(btn22);

    w22->setLayout(fLayout2);

    //=====================操作区 （按钮）==================



    //=======样板区
    //=======GO区
    QWidget* w3 =new QWidget();
    QVBoxLayout * layout3=new QVBoxLayout(w3);
    AuraSwitchWidget01* switchWidget3 =new AuraSwitchWidget01(w3);
    QWidget* w31 =new UIWidget(w3);
    UIWidget* w32 =new UIWidget(w3);

    layout3->addWidget(switchWidget3,1);
    layout3->addWidget(w31,13);
    layout3->addWidget(w32,1);
    w3->setLayout(layout3);

    AuraStateLabel01* l31 =new AuraStateLabel01("默认");
    AuraStateLabel01* l32 =new AuraStateLabel01("自定义1");
    AuraStateLabel01* l33 =new AuraStateLabel01("自定义2");
    switchWidget3->addLabel(l31);
    switchWidget3->addLabel(l32);
    switchWidget3->addLabel(l33);
    switchWidget3->setNowIndex(0);

    m_mainEditWidget->addWidget(w3);
    m_editWidgetList.append(w3);

    //=====================操作区 （按钮）==================
    FlowLayout* fLayout3=new FlowLayout(w32);

    QPushButton * btn31=new QPushButton("重新载GO数据",w32);
    btn31->setFixedHeight(30);
    btn31->adjustSize();
    fLayout3->addWidget(btn31);

    QPushButton * btn32=new QPushButton("统计GO信息",w32);
    btn32->setFixedHeight(30);
    btn32->adjustSize();
    fLayout3->addWidget(btn32);

    w32->setLayout(fLayout3);





   //=================添加响应=====================

    FlowLayout * fLayout31=new FlowLayout(w31);
    w31->setLayout(fLayout31);

    //点击重新加载GO 响应
    connect(btn31,&QPushButton::clicked,this,[w31,fLayout31](){

        for(auto it:fLayout31->widgetList())
        {
            fLayout31->removeWidget(it);
            it->close();
        }

        for(auto it:SourceSystem::gameObjectClassSet())
        {
            CardLabel * cardLabel=new CardLabel(w31);

            cardLabel->setMinimumSize(90,160);
            cardLabel->setPix(ConstValue::SourceDir().path()+"/Engine/DefaultSource/DefaultCardPix.png");
            cardLabel->setText(it);
            fLayout31->setSpacing(10);
            fLayout31->addWdiget(cardLabel);
            cardLabel->setVisible(true);


            //双击card响应
            connect(cardLabel,&CardLabel::doubleClicked,cardLabel,[cardLabel](){

                GameObjectSampleEditWidget * w =new GameObjectSampleEditWidget(SourceSystem::getGameObjectSample(cardLabel->text()));
                if(w->initFlag())
                {
                    w->show();
                }
                else
                {

                }


            });



        }
#ifdef QDEBUGCHECK
//        qDebug()<<"&QPushButton::clicked | get | check: Set: "<<SourceSystem::gameObjectClassSet();
//        qDebug()<<"&QPushButton::clicked | get | check: list: "<<fLayout31->widgetList();
//        for(auto it:fLayout31->widgetList())
//        {
//            qDebug()<<it -> geometry() << " | " << it->isVisible();
//        }
//        qDebug()<<"&QPushButton::clicked | get | check: w: "<<w31->geometry() << w31->isVisible();
#endif
    });










   //=================添加响应=====================


    //=====================操作区 （按钮）==================



    //=======GO区
    //=======插件区
    CheckBoxListWidget* w4 =new CheckBoxListWidget();

    w4->addBox("TestPlugin1");
    w4->addBox("TestPlugin2");
    w4->addBox("TestPlugin3");
    w4->addBox("TestPlugin4");

    m_mainEditWidget->addWidget(w4);
    m_editWidgetList.append(w4);
    //=======插件区


    connect(m_switchWidget,&AuraSwitchWidget01::nowIndexChanged,m_mainEditWidget,&QStackedWidget::setCurrentIndex);
    connect(m_mainEditWidget,&QStackedWidget::currentChanged,this,[](int i){
        qDebug()<<"QStackedWidget::currentChanged | now Idx:"<<i;
    });

    //================测试用   各区页面====================





    updateLayout();
}

void EditSourceEidtWidget::sourceUpdate()
{

#ifdef QDEBUGCHECK
    qDebug()<<"EditSourceEidtWidget::sourceUpdate | now Object Class:"<<SourceSystem::getInstance()->gameObjectClassSet();
    qDebug()<<"EditSourceEidtWidget::sourceUpdate | now Component Class:"<<SourceSystem::getInstance()->componentClassSet();
#endif


}

void EditSourceEidtWidget::updateLayout()
{
    resizeEvent(nullptr);
    m_switchWidget->updateLayout();
}

void EditSourceEidtWidget::resizeEvent(QResizeEvent *e)
{
    UIWidget::resizeEvent(e);
    int switchWidgetHeight=height()/15;
    int mainEditWidetHeight=(height()*14)/15;
    m_switchWidget->setGeometry(0,0,width(),switchWidgetHeight);

    m_mainEditWidget->setGeometry(0,switchWidgetHeight,width(),mainEditWidetHeight);
    for(auto it:m_editWidgetList)
    {
        it->setGeometry(0,0,m_mainEditWidget->width(),m_mainEditWidget->height());
    }
}
