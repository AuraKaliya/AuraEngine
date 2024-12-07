#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <QObject>





#include "../../DATA/baseClass/systemobject.h"


class RenderSystem : public SystemObject
{
    Q_OBJECT
public:
    static RenderSystem *getInstance(QObject *parent = nullptr);
    bool systemStart() override;
    bool systemInit()  override;
    bool systemClose() override;

    void updateRender();
private:
    explicit RenderSystem(QObject *parent = nullptr);
    static RenderSystem* m_instance;


signals:

};

#endif // RENDERSYSTEM_H
