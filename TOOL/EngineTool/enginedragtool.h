#ifndef ENGINEDRAGTOOL_H
#define ENGINEDRAGTOOL_H

#include <QObject>
#include <QMimeData>
#include <QString>

using dragFunction = void(*)(const QMimeData*);
class EngineDragTool : public QObject
{
    Q_OBJECT
public:
    explicit EngineDragTool(QObject *parent = nullptr);
    void solveDragData(QString dragStratagy,const QMimeData* data);


    static void initTool();
    static void cardLabelDragFunction(const QMimeData* data);
    static void defaultDragFunction(const QMimeData* data);
private:
    inline static QMap<QString ,dragFunction > m_dragFunctionDictionary{};
    inline static bool m_initFlag=false;
signals:

};

#endif // ENGINEDRAGTOOL_H
