#pragma once

#include <QObject>
#include <QOffscreenSurface>
#include <QOpenGLFunctions_3_3_Core>

#include <AuraGlobal.h>
#include "auraopenglwidget.h"
#include "AuraTemplate/Singleton.hpp"

namespace AuraUI {
class AuraUIPath;

class AURAUI_LIB_DECL AuraOpenGLManager : public QObject,public QOpenGLFunctions_3_3_Core
{
    Q_OBJECT
    QOBJ_SINGLETON_H(AuraOpenGLManager)
    //QOBJ_SINGLETON_H_CONSTRUCTOR(AuraOpenGLManager)
    explicit AuraOpenGLManager(QObject *parent = nullptr);
public:
    void initManager(AuraUIPath& path);

    AuraOpenGLWidget* createOpenGLWidget(const QString & projectName,QWidget* parent = nullptr);
    AuraOpenGLWidget* createReferenceOpenGLWidget(AuraOpenGLWidget* w);
    AuraOpenGLWidget* createCopyOpenGLWidget(AuraOpenGLWidget* w);

    void createNewProject(const QString & projectName);

public:
    //test
    void loadTestUnitData(AuraOpenGLWidget* w);
    void loadTestUnitData2(AuraOpenGLWidget* w);
protected:
    void syncMainContext(AuraOpenGLWidget* w);
private:
    QString m_shaderDir;
    QString m_moduleDir;
    QString m_textureDir;

    bool m_initFlag{false};

    std::unordered_map<QString,std::shared_ptr<AuraOpenGLUnitManager>> m_projectDictionary;
    //std::unordered_map<>

    QSurfaceFormat* m_format;


    bool m_shareContextFlag{false};
    QOpenGLContext* m_globalContext{nullptr};
    QOffscreenSurface* m_offscreenSurface{nullptr};


signals:
};

} // namespace AuraUI
