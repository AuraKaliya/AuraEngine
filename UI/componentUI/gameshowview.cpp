#include "gameshowview.h"
#include "qmimedata.h"

#include <QDragEnterEvent>
#include <QDropEvent>


GameShowView::GameShowView(QWidget *parent)
    : QGraphicsView(parent)
    ,m_dragFlag(false)
{
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setDragMode(QGraphicsView::RubberBandDrag);
    setAcceptDrops(true);

    //setViewportUpdateMode(QGraphicsView::ViewportUpdateMode::FullViewportUpdate);
}

void GameShowView::focusInEvent(QFocusEvent *event)
{
    emit getFocus();
}

void GameShowView::focusOutEvent(QFocusEvent *event)
{
    emit loseFocus();
}

void GameShowView::mousePressEvent(QMouseEvent *e)
{
    QGraphicsView::mousePressEvent(e);
    setMouseTracking(true);
    m_selectRect=QRect();
    viewport()->update();
}

void GameShowView::mouseMoveEvent(QMouseEvent *e)
{
    QGraphicsView::mouseMoveEvent(e);
    viewport()->update();
}

void GameShowView::mouseReleaseEvent(QMouseEvent *e)
{

    QGraphicsView::mouseReleaseEvent(e);
    if(!this->scene()->selectedItems().empty())
    {
        QRect rect;
        rect.setRect(this->mapFromScene(this->scene()->selectedItems()[0]->pos()).x(),
                     this->mapFromScene(this->scene()->selectedItems()[0]->pos()).y(),
                     0,0);

        if(this->scene()->selectedItems().size()==1)
        {
            //======只有一个选中的情况下，可进行定位======
            //获取GameObject
            ObjectItem* item=static_cast<ObjectItem*>(this->scene()->selectedItems()[0]);
            emit nowGameObjectSelected(item->linkObj(),static_cast<ComponentObject*>(item->parent()));
        }

        for(auto it:this->scene()->selectedItems())
        {
            rect.setX(qMin((int)rect.x(),(int)(this->mapFromScene(it->pos()).x())));
            rect.setY(qMin((int)rect.y(),(int)(this->mapFromScene(it->pos()).y())));
            rect.setWidth(qMax((int)rect.width(),(int)(it->x()+it->boundingRect().width()-rect.x()+((width()-scene()->width())/2))));
            rect.setHeight(qMax((int)rect.height(),(int)(it->y()+it->boundingRect().height()-rect.y()+((height()-scene()->height())/2))));
        }

        m_selectRect=rect;

    }

    viewport()->update();
}

void GameShowView::paintEvent(QPaintEvent *e)
{
    QGraphicsView::paintEvent(e);
    QPainter painterSelect(this->viewport());
    if(!this->scene()->selectedItems().empty())
    {
        QPen pen(Qt::red,2,Qt::DashDotDotLine,Qt::RoundCap,Qt::RoundJoin);
        painterSelect.setPen(pen);
        painterSelect.drawRect(m_selectRect);
    }
    painterSelect.end();
}

void GameShowView::dragEnterEvent(QDragEnterEvent *e)
{

    const QMimeData *data =e->mimeData();
#ifdef QDEBUGCHECK
    qDebug()<<"GameShowView::dragEnterEvent | in.";
    qDebug()<<"GameShowView::dragEnterEvent | data:"<<data<< " ; hasText:"<<data->hasText();
#endif

    if(data->hasText())
    {
#ifdef QDEBUGCHECK
        qDebug()<<"GameShowView::dragEnterEvent | text:"<<data->text();
#endif
        setMouseTracking(true);
        e->accept();
        //e->acceptProposedAction();
    }
    else
    {
        QGraphicsView::dragEnterEvent(e);
    }

}

void GameShowView::dropEvent(QDropEvent *e)
{
#ifdef QDEBUGCHECK
    qDebug()<<"GameShowView::dropEvent | in.";
    qDebug()<<"GameShowView::dropEvent | pos:"<<e->position();
#endif
    e->dropAction();
    const QMimeData * data =e->mimeData() ;

    QString dragClassText =data->text();
#ifdef QDEBUGCHECK
    qDebug()<<"GameShowView::dropEvent | text:"<<dragClassText;
#endif
    EngineDragTool dragTool;
    dragTool.solveDragData(dragClassText,data);
    QGraphicsView::dropEvent(e);
}

void GameShowView::dragMoveEvent(QDragMoveEvent *e)
{
    const QMimeData * data =e->mimeData();
#ifdef QDEBUGCHECK
    //qDebug()<<"GameShowView::dragMoveEvent | data:"<<data<< " text:"<<data->text();
#endif
    if(data->text() == "CardLabel")
    {
        e->accept();
    }
    else
    {
       QGraphicsView::dragMoveEvent(e);
    }

}
