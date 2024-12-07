#include "gamesystem.h"

#include <QTimer>

GameSystem* GameSystem::m_instance=nullptr;
GameSystem *GameSystem::getInstance(QObject *parent )
{
    if(m_instance==nullptr)
    {
        m_instance=new GameSystem(parent);
    }
    return m_instance;
}

bool GameSystem::systemStart()
{
#ifdef QDEBUGCHECK
    qDebug()<<"GameSystem::systemStart | √ ";
#endif
    return true;
}

bool GameSystem::systemInit()
{
#ifdef QDEBUGCHECK
    qDebug()<<"GameSystem::systemInit | √ ";
#endif

    connect(SourceSystem::getInstance(),&SourceSystem::sourceNeedUpdateView,this,[this](){
        if(m_nowDemo)
        {
            qDebug()<<"GameSystem | get (SourceSystem signal : sourceNeedUpdateView .";
            m_nowDemo->updateView(m_sceneList);

            updateRender();
        }
    });

    connect(SourceSystem::getInstance(),&SourceSystem::sourceLoadDemo,this,[this](GameDemo* demo){
        setNowDemo(demo);
    });

    return true;
}

bool GameSystem::systemClose()
{
#ifdef QDEBUGCHECK
    qDebug()<<"GameSystem::systemClose | √ ";
#endif
    return true;
}

void GameSystem::initNowDemo(const QJsonObject &obj)
{
    if(!m_nowDemo)
    {
        return;
    }

    if(m_nowDemo->initFlag())
    {
        return;
    }

    //初始化Demo
    GameDemo::setNowDemo(m_nowDemo);
    m_nowDemo->initDemo(obj);


    //注册Demo进资源系统
    //SourceSystem::registDemo(m_nowDemo);
    //注册Demo进指令系统
    InstructionSystem::registDemo(m_nowDemo);


#ifdef QDEBUGCHECK
    qDebug()<<"GameSystem::initNowDemo | check now GameObjectList in source"<<SourceSystem::gameObjectList();
    for(auto it:SourceSystem::gameObjectList())
    {
        qDebug()<<"id :"<<it->id()<<" | Class:"<<it->objClass()<<" | Name:"<<it->name();
    }
    qDebug()<<"GameSystem::initNowDemo | check now Global id :"<<SourceSystem::globalId();


    qDebug()<<"GameSystem::initNowDemo | check now GameObjectList in demo:"<<m_nowDemo->gameObjectDictionary();

#endif


    /*+++++++Demo 中有含对GO的管理模块， 尝试不用对引擎的资源系统进行注册+++++++*/
    //暂时不用
    //初始化 管理列表 为 当前Demo的所有GO
    //SourceSystem::initGameObjectList(m_nowDemo);
    /*+++++++Demo 中有含对GO的管理模块， 尝试不用对引擎的资源系统进行注册+++++++*/
}

bool GameSystem::initView()
{

    if(m_viewFlag) return m_viewFlag;

#ifdef QDEBUGCHECK
    qDebug()<<"Demo  start!";
#endif
    if(!m_nowDemo)
    {
#ifdef QDEBUGCHECK
        qDebug()<<"GameSystem::initView | no have nowDemo!";
#endif
        return m_viewFlag;
    }

    if(!m_nowDemo->initFlag())
    {
#ifdef QDEBUGCHECK
        qDebug()<<"GameSystem::initView | nowDemo no init!";
#endif
        return m_viewFlag;
    }

    //================将Demo中的数据映射到View中======================//
    //
    if(m_nowView)
    {
#ifdef QDEBUGCHECK
        qDebug()<<"GameSystem::startDemo |m_nowView EXIT. ";
#endif \
        //构建关卡----scene
        int sceneCount=m_nowDemo->sceneCount();

        if(sceneCount>=1)
        {
            //先补齐关卡
            int nowSceneCount=m_sceneList.size();
            for(int i=nowSceneCount;i<sceneCount;++i)
            {
                m_sceneList.append(new QGraphicsScene());
            }

//获取所有拥有Item函数的GameObject   --- 暂无解决办法
// 替代： 将View和Scene传给Demo，由Demo进行初始化
#ifdef QDEBUGCHECK
            qDebug()<<"GameSystem::startDemo |linkView. ";
#endif
            m_nowDemo->linkView(m_sceneList);

        }
        else
        {
            //说明该Demo不需要渲染图形实体 无关卡
        }
    }
    else
    {
#ifdef QDEBUGCHECK
        qDebug()<<"GameSystem::startDemo |m_nowView NOT EXIT. ";
#endif
    }
    //================将Demo中的数据映射到View中======================//
    m_viewFlag=true;


    return m_viewFlag;
}

void GameSystem::startDemo()
{

    if(!initView()) return ;

#ifdef QDEBUGCHECK
    qDebug()<<"Demo  working!";
#endif
//===================初始化脚本=======================//
    ScriptSystem::getInstance()->initDemoScript(m_nowDemo->scriptsList());
//===================初始化脚本=======================//

    m_fps=ConstValue::EngineFPS::HighFPS;
    QTimer *timer=new QTimer;
    timer->setInterval(1000/m_fps);
    connect(timer,&QTimer::timeout,this,[this,timer](){
        if(!m_nowDemo->quitFlag())
        {
            //预处理

            // 逻辑 更新  --Demo
            m_nowDemo->updateDemo();


            // 渲染 更新  --Demo
            m_nowDemo->updateRender();
            // 渲染 更新  --Engine
            updateRender();
            updateScirpt();
            //后处理
        }
        else
        {
            timer->stop();
            timer->deleteLater();
        }
    });

    timer->start();
//    while(!m_nowDemo->exitFlag())
//    {
//        //预处理

//        // 逻辑 更新  --Demo
//        m_nowDemo->updateDemo();


//        // 渲染 更新  --Demo
//        m_nowDemo->updateRender();
//        // 渲染 更新  --Engine
//        updateRender();

//        //后处理
//    }


#ifdef QDEBUGCHECK
    qDebug()<<"Demo  exit!";
#endif

}

void GameSystem::restartDemo()
{
    //重新开始当前Demo 从初始化开始
}

GameSystem::GameSystem(QObject *parent)
    : SystemObject{parent},m_fps(ConstValue::LowFPS),m_viewFlag(false)
{
    setObjectName("GameSystem");
}

GameDemo *GameSystem::nowDemo() const
{
    return m_nowDemo;
}

void GameSystem::setNowDemo(GameDemo *newNowDemo)
{


    m_nowDemo = newNowDemo;
    SourceSystem::setNowDemo(m_nowDemo);
    ScriptSystem::setNowDemo(m_nowDemo);

    m_viewFlag=false;
}

void GameSystem::updateRender()
{
    //对View的更新
    for(auto it:m_viewList)
    {
        qDebug()<<"GameSystem::updateRender | init!";
        it->update();
        it->updateGeometry();
        it->viewport()->update();
    }

    //渲染系统的更新
    RenderSystem::getInstance()->updateRender();
}

void GameSystem::updateScirpt()
{
    ScriptSystem::getInstance()->updateScript();
}

void GameSystem::initMainView(QGraphicsView *view)
{
    if(!view)
    {
        return;
    }
    m_viewList.clear();
    m_sceneList.clear();

    //可能出现内存泄漏  直接替换view的scene
    QGraphicsScene* scene = nullptr;

    if(view->scene() == nullptr)
    {
        scene=new QGraphicsScene();
        view->setScene(scene);
#ifdef QDEBUGCHECK
        qDebug()<<"GameSystem::initMainView | view->scene() == nullptr";
#endif

    }
    else
    {
        scene=view->scene();
    }

    m_viewList.append(view);
    m_nowView=view;

    m_sceneList.append(scene);
    m_nowScene=scene;
}
