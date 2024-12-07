#include "demophysicalsystem.h"

DemoPhysicalSystem::DemoPhysicalSystem(QObject *parent)
    : DemoSystemObject{parent}
{

}

void DemoPhysicalSystem::update(GameObject &obj)
{
    Model2DHPBar* hpBarModel=obj.getComponent<Model2DHPBar>();
    Model2DItem* characterModel=obj.getComponent<Model2DItem>();
    Model2DMove* moveModel =obj.getComponent<Model2DMove>();
    Model2DCollision * collisionModel= obj.getComponent<Model2DCollision>();
    if(!hpBarModel || !characterModel || !moveModel ||!collisionModel) return;

    QPointF objCenter((characterModel->x()+characterModel->pixWidth())/2,
                      (characterModel->y()+characterModel->pixHeight())/2);

    Model2DMove::Direction dir=Model2DMove::NoDirection;
    if(moveModel->xSpeed()>1e-6)  dir=static_cast<Model2DMove::Direction>(dir|Model2DMove::Right);
    else if (moveModel->xSpeed()<-1e-6)  dir=static_cast<Model2DMove::Direction>(dir|Model2DMove::Left);

    if(moveModel->ySpeed()>1e-6)  dir=static_cast<Model2DMove::Direction>(dir|Model2DMove::Down);
    else if(moveModel->ySpeed()<-1e-6)  dir=static_cast<Model2DMove::Direction>(dir|Model2DMove::Up);
#ifdef QDEBUGCHECK
    qDebug()<<"DemoPhysicalSystem::update | dir :"<<dir;
#endif
    //执行前 检查碰撞
    collisionModel->resetCollidingList();
//    for(auto it:collisionModel->getGetters())
//    {

//        Model2DItem* getterItemModel=it->getComponent<Model2DItem>();
//        Model2DCollision* getterCollisionModel=it->getComponent<Model2DCollision>();
//        if(!getterItemModel || !getterCollisionModel) continue;


//        if(dir & Model2DMove::Down)
//        {
//            if(rayCheck(QRect(getterItemModel->x(),getterItemModel->y(),getterItemModel->pixWidth(),getterItemModel->pixHeight()),
//                         QVector2D(objCenter.rx(),objCenter.ry()),
//                         QVector2D(0,-1),
//                         characterModel->pixHeight())/2)
//            {
//                collisionModel->addCollidingObject(it);
//                break;
//            }
//        }
//        else if(dir & Model2DMove::Up)
//        {
//            if(rayCheck(QRect(getterItemModel->x(),getterItemModel->y(),getterItemModel->pixWidth(),getterItemModel->pixHeight()),
//                         QVector2D(objCenter.rx(),objCenter.ry()),
//                         QVector2D(0,1),
//                         characterModel->pixHeight())/2)
//            {
//                collisionModel->addCollidingObject(it);
//                break;
//            }
//        }
//        if(dir & Model2DMove::Left)
//        {
//            if(rayCheck(QRect(getterItemModel->x(),getterItemModel->y(),getterItemModel->pixWidth(),getterItemModel->pixHeight()),
//                         QVector2D(objCenter.rx(),objCenter.ry()),
//                         QVector2D(-1,0),
//                         characterModel->pixWidth())/2)
//            {
//                collisionModel->addCollidingObject(it);
//                break;
//            }
//        }else if(dir & Model2DMove::Right)
//        {
//            if(rayCheck(QRect(getterItemModel->x(),getterItemModel->y(),getterItemModel->pixWidth(),getterItemModel->pixHeight()),
//                         QVector2D(objCenter.rx(),objCenter.ry()),
//                         QVector2D(1,0),
//                         characterModel->pixWidth())/2)
//            {
//                collisionModel->addCollidingObject(it);
//                break;
//            }
//        }
//    }
    QVector2D directionVector(moveModel->xSpeed(),moveModel->ySpeed());
    QRectF nextRect(characterModel->x()+directionVector.x(),characterModel->y()+directionVector.y(),characterModel->pixWidth(),characterModel->pixHeight());
    for(auto it:collisionModel->getGetters())
    {
        Model2DItem* getterItemModel=it->getComponent<Model2DItem>();
        Model2DCollision* getterCollisionModel=it->getComponent<Model2DCollision>();
        if(!getterItemModel || !getterCollisionModel) continue;

        if(rectCheck(nextRect,QRect(getterItemModel->x(),getterItemModel->y(),getterItemModel->pixWidth(),getterItemModel->pixHeight())))
        {
            collisionModel->addCollidingObject(it,dir);
        }
    }

    for(auto it:collisionModel->collidingObjectList())
    {
        it.first->getComponent<Model2DCollision>()->doGetterFunction(&obj,it.first,it.second);
    }
    directionVector=QVector2D(moveModel->xSpeed(),moveModel->ySpeed());
    //移动   -要前碰撞处理完的速度 （和方向）
    //QVector2D directionVector(moveModel->xSpeed(),moveModel->ySpeed());

    characterModel->setX(characterModel->x()+directionVector.x());
    characterModel->setY(characterModel->y()+directionVector.y());

    hpBarModel->setX(characterModel->x());
    hpBarModel->setY(characterModel->y()-5-hpBarModel->pixHeight());

    //速率更新
    if(dir & Model2DMove::Down)
    {
        directionVector.setY(qMax(directionVector.y()-moveModel->yResistance(),0.0));
    }
    if(dir & Model2DMove::Up )
    {
        directionVector.setY(qMin(directionVector.y()+moveModel->yResistance(),0.0));
    }
    if(dir & Model2DMove::Right )
    {
        directionVector.setX(qMax(directionVector.x()-moveModel->xResistance(),0.0));
    }
    if(dir & Model2DMove::Left )
    {
        directionVector.setX(qMin(directionVector.x()+moveModel->xResistance(),0.0));
    }

    if(moveModel->gravityFlag())
    {
        qDebug()<<"DemoPhysicalSystem::update |  G ";
        directionVector.setY( directionVector.y()+moveModel->gravity() );
    }

    moveModel->setXSpeed(directionVector.x());
    moveModel->setYSpeed(directionVector.y());

}

bool DemoPhysicalSystem::rayCheck(QRectF rect, QVector2D startPos, QVector2D direction, double length, int zValueRange)
{
    return false;
}

bool DemoPhysicalSystem::rayCheck(QRectF rect, QVector2D startPos, QVector2D direction, double length)
{
    // 计算射线的结束点   --未直接使用
    QVector2D endPos = startPos + direction * length;

    // 计算矩形的四个边界
    double left = rect.left();
    double right = rect.right();
    double top = rect.top();
    double bottom = rect.bottom();

    // 检查射线是否与矩形的四条边相交
    for (int i = 0; i < 4; i++) {
        QVector2D edgeStart, edgeEnd;

        switch (i) {
        case 0:  // 左边界
            edgeStart = QVector2D(left, top);
            edgeEnd = QVector2D(left, bottom);
            break;
        case 1:  // 右边界
            edgeStart = QVector2D(right, top);
            edgeEnd = QVector2D(right, bottom);
            break;
        case 2:  // 上边界
            edgeStart = QVector2D(left, top);
            edgeEnd = QVector2D(right, top);
            break;
        case 3:  // 下边界
            edgeStart = QVector2D(left, bottom);
            edgeEnd = QVector2D(right, bottom);
            break;
        }

        // 计算两个向量：一个从射线的起点到边界的起点，另一个从射线的起点到边界的终点
        QVector2D v1 = edgeStart - startPos;
        QVector2D v2 = edgeEnd - startPos;

        // 计算两个向量的叉积，如果结果的z分量为0，那么射线与边界在同一直线上
        double crossZ = v1.x() * v2.y() - v1.y() * v2.x();

        // 如果射线与边界在同一直线上，那么检查射线是否在边界的两个端点之间
        if (crossZ == 0) {
            double dot1 = QVector2D::dotProduct(v1, direction);
            double dot2 = QVector2D::dotProduct(v2, direction);
            if ((dot1 > 0 && dot2 < 0) || (dot1 < 0 && dot2 > 0)) {
                return true;
            }
        }
    }

    // 如果射线没有与任何边界相交，那么返回false
    return false;
}

bool DemoPhysicalSystem::rectCheck(QRectF rect1, QRectF rect2)
{
    return rect1.intersects(rect2);
}
