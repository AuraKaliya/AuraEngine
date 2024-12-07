#include "editinstructioneditwidget.h"
#include "../../TOOL/Systems/instructionsystem.h"
#include "../../TOOL/Systems/sourcesystem.h"

EditInstructionEditWidget::EditInstructionEditWidget(QWidget *parent)
    : UIWidget{parent}
    ,m_linkFlag(false)
{
    m_mainLayout =new QVBoxLayout();
    m_insLinkObjLayout =new  QHBoxLayout();
    m_insBaseInfoLayout=new QHBoxLayout();
    m_toolBtnLayout =new QHBoxLayout();

    m_idWidget=new ArgumentEditWidget("ObjId",this);
    m_linkBtn =new QPushButton("Link",this);
    m_linkStateWidget =new ArgumentEditWidget("State",this);

    m_insTypeWidget =new QComboBox(this);
    m_insNameWidget =new QComboBox(this);

    m_valueWidget =new WheelSlideWidget(this);

    m_addArgToolBtn =new QPushButton("Add",this);
    m_delArgToolBtn =new QPushButton("Del",this);
    m_saveInsToolBtn =new QPushButton("Save",this);
    m_createInsToolBtn =new QPushButton("Create",this);
    m_createAndRunInsToolBtn =new QPushButton("Run",this);
}

void EditInstructionEditWidget::initWidget()
{
    setLayout(m_mainLayout);

    m_mainLayout->addLayout(m_insLinkObjLayout,1);
    m_mainLayout->addLayout(m_insBaseInfoLayout,1);
    m_mainLayout->addWidget(m_valueWidget,5);
    m_mainLayout->addLayout(m_toolBtnLayout,1);

    m_insLinkObjLayout->addWidget(m_idWidget,4);
    m_insLinkObjLayout->addWidget(m_linkBtn,1);
    m_insLinkObjLayout->addWidget(m_linkStateWidget,4);

    m_insBaseInfoLayout->addWidget(m_insTypeWidget,5);
    m_insBaseInfoLayout->addWidget(m_insNameWidget,5);

    m_toolBtnLayout->addWidget(m_addArgToolBtn,1);
    m_toolBtnLayout->addWidget(m_delArgToolBtn,1);
    m_toolBtnLayout->addWidget(m_saveInsToolBtn,1);
    m_toolBtnLayout->addWidget(m_createInsToolBtn,1);
    m_toolBtnLayout->addWidget(m_createAndRunInsToolBtn,1);

    //============================================
    //init Info
    m_insTypeWidget->addItem("Function");

    m_insNameWidget->addItems(InstructionSystem::getInstance()->getInsFunctionList());


    QString insName =m_insNameWidget->currentText();
    auto insFunctionInfo = InstructionSystem::getInstance()->getInsFunctionInfo(insName);
    initValueList(insFunctionInfo);

    //============================================
    //connect
    connect(m_linkBtn,&QPushButton::clicked,this,[this](){
        //Link
        setLinkObj(SourceSystem::getInstance()->getGameObjectById(m_idWidget->getValue().toUInt()));
    });
    connect(m_insNameWidget,&QComboBox::currentTextChanged,this,[this](const QString& nowInsName){
        //Ins changed
        auto insFunctionInfo = InstructionSystem::getInstance()->getInsFunctionInfo(nowInsName);
        initValueList(insFunctionInfo);
    });
    connect(m_addArgToolBtn,&QPushButton::clicked,this,[this](){
        //Add
        unsigned int count =m_valueWidgetList.size();
        int height = 40;
        int width =m_valueWidget->width();
        ArgumentEditWidget* w =new ArgumentEditWidget("NewValue");
        w->resize(width,height);
        m_valueWidget->addWidgetInArea(w,0,count*height);
        m_valueWidgetList.append(w);
        w->setVisible(true);
    });

    connect(m_createAndRunInsToolBtn,&QPushButton::clicked,this,[this](){
        //Run

        // 0. check
        if(!m_linkObj || m_linkStateWidget->getValue()!="Linked" )
        {
#ifdef QDEBUGCHECK
            qDebug()<<"EditInstructionEditWidget :Run Function | no have GameObject.";
#endif
            return;
        }

        // 1. 生成指令
        QString insName = m_insNameWidget->currentText();
        QString insType = m_insTypeWidget->currentText();
        QVector<QVariant> paramlist;
        for(auto it:m_valueWidgetList)
        {
            paramlist.append(QVariant(it->getValue()));
        }
        InstructionContext context(m_linkObj,insName,insType,QVariant(paramlist));

        // 2. 调用指令
        InstructionSystem::soluteInsContext(context);
    });

    //=====================================================
#ifdef QDEBUGCHECK
    qDebug()<<"EditInstructionEditWidget::initWidget | check InsFunctionList():"<<InstructionSystem::getInstance()->getInsFunctionList();
#endif


}

void EditInstructionEditWidget::setLinkObj(GameObject *obj)
{
    m_linkObj =obj;
    if(m_linkObj)
    {
        m_linkStateWidget->setValue("Linked");
    }
    else
    {
        m_linkStateWidget->setValue("Unlinked");
    }
}

void EditInstructionEditWidget::initValueList(const InstructionFunctionInfomation &insFunctionInfo)
{
    m_valueWidget->clearWidgetList();
    m_valueWidgetList.clear();
    int height = 40;
    int width =m_valueWidget->width();

    auto tips= insFunctionInfo.tips();

    for(int i=0;i<tips.size();++i)
    {
        ArgumentEditWidget* w =new ArgumentEditWidget(tips[i]);
        w->resize(width,height);
        m_valueWidget->addWidgetInArea(w,0,i*height);
        m_valueWidgetList.append(w);
        w->setVisible(true);
    }

}

void EditInstructionEditWidget::resizeEvent(QResizeEvent *e)
{
    UIWidget::resizeEvent(e);
    int height = 40;
    int width =m_valueWidget->width();
    for(auto it:m_valueWidgetList)
    {
        it->resize(width,height);
    }
}


