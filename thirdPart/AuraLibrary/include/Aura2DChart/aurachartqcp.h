
#pragma once

#include <QWidget>
#include <QPixmap>
#include <QVector>

#include <AuraGlobal.h>
#include <QCustomPlot/qcustomplot.h>

#ifndef RESOURCE_DIR
#define RESOURCE_DIR "./"
#endif


namespace AuraUI{
class AuraLibrary_DECL AuraChartQCP : public QCustomPlot
{
    Q_OBJECT
public:
    explicit AuraChartQCP(QWidget *parent = nullptr);
    QCPTextElement* getTitleElement();
    void setChartTitle(const QString & title);

    void setXTitle(const QString & title);
    void setYTitle(const QString & title);
    void setGraphTitle(const QString & title,unsigned int index = 0);
    void save();
    void setLegendVisible(bool flag);

    void transXToLog();
    void transXToNormal();

    unsigned int getLineCount();
    QCPGraph* line(unsigned int index= 0);

    void addNewLine(const QString & graphName="Default Graph",const QPen& graphPen=QPen());
    void setLineStyle(Qt::PenStyle style,unsigned int index= 0 );
    void setLineColor(QColor color,unsigned int index= 0 );


    QString filePath() const;
    void setFilePath(const QString &newFilePath);

    QString fileName() const;
    void setFileName(const QString &newFileName);

public slots:
    void OnPlotClicked(QCPAbstractPlottable * p,int dataIndex,QMouseEvent* e);
private:
    QVector<QPointer<QCPGraph>> m_graphs;
    QString m_filePath;
    QString m_fileName;
    QVector<QVector<double>> m_logX;
    QVector<QVector<double>> m_logY;
signals:
};

}//AuraUI
