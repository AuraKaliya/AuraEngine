#ifndef GAMESHOWVIEW_H
#define GAMESHOWVIEW_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QVector>
#include <QVector2D>

#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include <QTimer>
#include <QOpenGLTexture>

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsScene>


#include "../../DATA/BaseClass/baseclass.h"
#include "../../TOOL/EngineTool/enginedragtool.h"
class GameShowView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GameShowView(QWidget *parent = nullptr);
protected:
    //
    void focusInEvent(QFocusEvent *event) override;
    void focusOutEvent(QFocusEvent *event) override;
    void mousePressEvent(QMouseEvent* e)override;
    void mouseMoveEvent(QMouseEvent*e)override;
    void mouseReleaseEvent(QMouseEvent* e)override;
    void paintEvent(QPaintEvent* e)override;

    void dragEnterEvent(QDragEnterEvent* e)override;
    void dropEvent(QDropEvent*e)override;
    void dragMoveEvent(QDragMoveEvent*e)override;
private:
    QRect m_selectRect;
    bool m_dragFlag;

signals:
    void getFocus();
    void loseFocus();

    void nowGameObjectSelected(GameObject*,ComponentObject*);

};

#endif // GAMESHOWVIEW_H
