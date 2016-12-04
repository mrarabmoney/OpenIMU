#ifndef RESULTSTABWIDGET_H
#define RESULTSTABWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <string>
#include <QLabel>
#include <QPushButton>
#include <QInputDialog>

#include "../utilities/OpenImuButton.h"
#include "../algorithm/AlgorithmOutputInfoSerializer.h"
#include "../algorithm/AlgorithmInfoSerializer.h"
#include "../acquisition/RecordInfo.h"
#include "../core/components/blockType/DbBlock.h"
#include "../MainWindow.h"
#include "../AccDataDisplay.h"

QT_CHARTS_USE_NAMESPACE

class ResultsTabWidget: public QWidget
{
    Q_OBJECT

public:
    ResultsTabWidget();
    ResultsTabWidget(QWidget *parent, AlgorithmOutputInfo output);
    ResultsTabWidget(QWidget *parent, WimuAcquisition& accData, RecordInfo& rInfo);
     ~ResultsTabWidget();

    void init(AlgorithmOutputInfo output);
    void initFilterView(AccDataDisplay* accDataDisplay);

public slots:
    void exportToPdfSlot();
    void exportToDBSlot();
    void exportDataToDBSlot();

private:
    QWidget* m_parent;
    QGridLayout* layout;
    QWidget* container;
    QLabel* imuType;
    OpenImuButton* saveResultsToDB;


    DbBlock * m_databaseAccess;
    WimuAcquisition* m_accData;
    AlgorithmOutputInfo m_algorithmOutputInfo;
    RecordInfo m_recordInfo;
};

#endif
