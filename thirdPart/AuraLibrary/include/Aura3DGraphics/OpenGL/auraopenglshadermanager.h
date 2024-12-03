#pragma once

#include <QObject>
#include <QString>
#include <QMap>
#include <QOpenGLShaderProgram>


#include <AuraGlobal.h>

namespace AuraUI {

class AURAUI_LIB_DECL AuraOpenGLShaderManager : public QObject
{
    Q_OBJECT
public:
    explicit AuraOpenGLShaderManager(QObject *parent = nullptr);

    static void initShaderManager(const QString& shaderDir);

    static void initShaderLibrary();
    static QOpenGLShaderProgram* getShader(const QString & name);
    static bool initFlag();

private:
    static QMap<QString ,QOpenGLShaderProgram*> m_shaderLibrary;
    static bool m_initFlag;
    static QString m_shaderDir;

signals:

};

}//AuraUI
