#pragma once

#include <QVariant>
#include <QFuture>

#undef slots
#include <Python.h>
#define slots Q_SLOTS

#include "../AuraGlobal.h"

#include <AuraTemplate/Singleton.hpp>
namespace AuraTool {
enum class ScriptType{
    Text,
    File,
};

class AuraLibrary_DECL AuraPythonTool
{
    SINGLETON_H(AuraPythonTool)
    SINGLETON_H_CONSTRUCTOR(AuraPythonTool)
private:
    ~AuraPythonTool();
public:
    QMutex m_mutex;

    void initialize(const QString& path);
    void cleanup();
    void test();
    void runScript(const QString &str,ScriptType scriptType);

    QVariant runPythonFunction(const QString &moduleName, const QString &funcName, const QVariantList &args);
    QString getPythonVariable(const QString &moduleName, const QString &varName);

    PyObject *QVariantToPyObject(const QVariant &var);
    QVariant PyObjectToQVariant(PyObject *pyObj);
private:
    QString m_scriptDir;
};

} // namespace AuraTool

/*
QFuture<QVariant> runPythonFunctionAsync(const QString &moduleName, const QString &funcName, const QVariantList &args);
*/
