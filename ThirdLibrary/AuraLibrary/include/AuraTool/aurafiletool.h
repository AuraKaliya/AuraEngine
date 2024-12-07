#pragma once
#include <QPair>
#include <QVector>
#include <QString>
#include <filesystem>
#include <fstream>
namespace fs = std::filesystem;

#include "../AuraGlobal.h"
#include <AuraTemplate/Singleton.hpp>


namespace AuraTool {

class AuraLibrary_DECL AuraFileTool
{
    SINGLETON_H(AuraFileTool)
    SINGLETON_H_CONSTRUCTOR(AuraFileTool)
public:
    void loadPath(const QString& path);

    bool createFile(const QString& fileName ,bool forceFlag = false);
    bool removeFile(const QString& fileName );

    QVector<QString> filesList();
    QPair<bool,QVector<QString> > findFileByName(const QString& fileName,bool matchingFlag=true);
    bool pathValidFlag() const;

    void printFileTree();
    void printFileTree(const fs::path& path,const std::string& prefix = "");


private:
    fs::path m_path;
    bool m_pathValidFlag;
};

} // namespace AuraTool
