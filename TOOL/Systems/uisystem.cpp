#include "uisystem.h"

UISystem*UISystem::m_instance=nullptr;
UISystem *UISystem::getInstance(QObject *parent)
{
    if(m_instance==nullptr)
    {
        m_instance=new UISystem(parent);
    }
    return  m_instance;
}

bool UISystem::systemStart()
{
#ifdef QDEBUGCHECK
    qDebug()<<"UISystem::systemStart | √ ";
#endif

    return true;
}

bool UISystem::systemInit()
{
    bool res=false;
#ifdef QDEBUGCHECK
    qDebug()<<"UISystem::systemInit | √ ";
#endif
    //初始化UI
    initUI();

    //后续处理
    // 将View传给游戏系统


    if(m_initFlag)
        res=m_initFlag;

    return res;
}

bool UISystem::systemClose()
{
#ifdef QDEBUGCHECK
    qDebug()<<"UISystem::systemClose | √ ";
#endif
    return true;
}

void UISystem::initUI()
{
    // 根页面设置
    m_rootWidget=static_cast<UIWidget*>(this->parent());

    if(!m_rootWidget)
    {
#ifdef QDEBUGCHECK
        qDebug()<<"UISystem::initUI | no have root widget.";
#endif
        return;
    }
    else
    {
        m_mainWindow =static_cast<QMainWindow*>(m_rootWidget->parent());
        m_mainWindow->setMinimumSize(1920,1080);
        m_mainWindow->move(20,20);

        //对根页面的布局/大小设置
        m_rootWidget->resize(1920,1080);

    }

    m_mainWindow->setCentralWidget(m_rootWidget);

    //m_mainWindow->adjustSize();
    //根据当前引擎的模式进行初始化页面
    /*待开发*/
    //考虑是做成json文件进行反射化读取，目前用test函数代替开发
    switch (m_engineOption) {
    case ConstValue::EngineOptions::Editor:
    {
        testLoadUI();
    }
        break;
    case ConstValue::EngineOptions::Player:
    {

    }
        break;
    default:
        break;
    }

    m_initFlag=true;
}

void UISystem::loadUI(const QJsonObject &obj)
{



}

void UISystem::uiConnections()
{

    for(auto it:m_uiDictionary.values())
    {
        connect(SourceSystem::getInstance(),&SourceSystem::sourceReflexUpdated,it,&UIWidget::sourceUpdate);
    }


}

void UISystem::testLoadUI()
{
    //  ===   获取需要进行加载的UI 及基本布局信息    （真的可以通过一个struct进行存储 这些信息都是可以从json中读取的）====
    //QVector<QString> uiNameList={   "EditGameShowWidget"    , "EditGameEditWidget"      };
    //QVector<QRect> uiRectList={     QRect(450,10,1050,800)  , QRect(1510,10,400,1050)   };
    //  =================================================================================================正式做成json后再考虑


//=============================MenuBar======================================
    QMenuBar *menuBar = new QMenuBar();
    m_mainWindow->setMenuWidget(menuBar);
    initMenu(menuBar);

//=============================MenuBar======================================
//==========================editGameShowWidget==============================

    UIWidget* editGameShowWidget=Factory<UIWidget,QWidget*>::GetInstance()->CreateClass("EditGameShowWidget",m_rootWidget);
    if(!editGameShowWidget)
    {
#ifdef QDEBUGCHECK
        qDebug()<<"UISystem::testLoadUI | editGameShowWidget is not regist!.";
#endif
        return;
    }
    editGameShowWidget->setVisible(true);
    editGameShowWidget->setGeometry(450,10,1050,800);
    editGameShowWidget->initWidget();
    m_uiDictionary.insert("EditGameShowWidget",editGameShowWidget);

    //将View传给游戏系统
    GameSystem::getInstance()->initMainView(static_cast<QGraphicsView*>(editGameShowWidget->centerWidget()));

//==========================editGameShowWidget==============================
//==========================editGameEditWidget==============================
    UIWidget* editGameEditWidget=Factory<UIWidget,QWidget*>::GetInstance()->CreateClass("EditGameEditWidget",m_rootWidget);
    if(!editGameEditWidget)
    {
#ifdef QDEBUGCHECK
        qDebug()<<"UISystem::testLoadUI | eidtGameEditWidget is not regist!.";
#endif
        return;
    }

    editGameEditWidget->setVisible(true);
    editGameEditWidget->setGeometry(1510,10,400,1050);
    editGameEditWidget->initWidget();
    m_uiDictionary.insert("EditGameEditWidget",editGameEditWidget);
//==========================editGameEditWidget==============================
//==========================editSourceEditWidget==============================
    UIWidget* editSourceEidtWidget=Factory<UIWidget,QWidget*>::GetInstance()->CreateClass("EditSourceEidtWidget",m_rootWidget);
    if(!editSourceEidtWidget)
    {
#ifdef QDEBUGCHECK
        qDebug()<<"UISystem::testLoadUI | editSourceEditWidget is not regist!.";
#endif
        return;
    }

    editSourceEidtWidget->setVisible(true);
    editSourceEidtWidget->setGeometry(10,10,430,1050);
    editSourceEidtWidget->initWidget();
    m_uiDictionary.insert("EditSourceEidtWidget",editSourceEidtWidget);
//==========================editSourceEditWidget==============================


#ifdef QDEBUGCHECK
    qDebug()<<"UISystem::testLoadUI | check: editGameShowWidget "<<editGameShowWidget->isVisible() << editGameShowWidget->geometry();
    qDebug()<<"UISystem::testLoadUI | end.";
#endif

    //connect===========================
    /*
        这部分其实可以从外部读取string  然后在标准化流程中加入到uiwidget的linkDictionary中，  具体如何进行link可在initwidget中规定  containns--->solve
    */
    connect(editGameShowWidget,SIGNAL(nowGameObjectChanged(GameObject*)),editGameEditWidget,SLOT(setNowGameObject(GameObject*)));
    uiConnections();

}

void UISystem::initMenu(QMenuBar *menuBar)
{
    if(! menuBar)
    {
        return;
    }

    QMenu *fileMenu = new QMenu("项目");

    QAction *newAction = new QAction("新建");
    QAction *openAction = new QAction("打开");
    QAction *saveAction = new QAction("保存");

    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);

    menuBar->addMenu(fileMenu);

    //connect

}


UISystem::UISystem(QObject *parent)
    : SystemObject{parent},m_engineOption(ConstValue::EngineOptions::Editor),m_uiDictionary({}),m_uiRectDictionary({}),m_initFlag(false)
{
    setObjectName("UISystem");
}
