/********************************************************************************
** Form generated from reading ui file 'ds_gen.ui'
**
** Created: Sun Jan 13 20:18:06 2008
**      by: Qt User Interface Compiler version 4.3.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DS_GEN_H
#define UI_DS_GEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_ds_genClass
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QWidget *centralwidget;
    QVBoxLayout *vboxLayout;
    QTabWidget *mainTabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout1;
    QComboBox *methodCBox;
    QLabel *label_17;
    QDoubleSpinBox *intstepSBox;
    QLabel *label_24;
    QDoubleSpinBox *noise_lvlSBox;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout2;
    QCheckBox *conststartvaluesBox;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout3;
    QLabel *label_26;
    QSpinBox *eqnsSBox;
    QTextEdit *dssummaryTEdit;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout4;
    QComboBox *timeseriestypeCBox;
    QLabel *label_27;
    QLabel *label_28;
    QSpinBox *serieslengthsSBox;
    QSpinBox *serieslengtheSBox;
    QSpinBox *serieslengthstepSBox;
    QLabel *label_19;
    QLabel *label_18;
    QLabel *label_25;
    QSpinBox *seriesstepsSBox;
    QSpinBox *seriesstepeSBox;
    QSpinBox *seriesstepstepSBox;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout5;
    QLabel *label_12;
    QLabel *label_22;
    QLabel *label_23;
    QDoubleSpinBox *forcecouplbSBox;
    QDoubleSpinBox *forcecoupleSBox;
    QDoubleSpinBox *forcecouplstepSBox;
    QLabel *label_13;
    QComboBox *responseCBox;
    QLabel *label_14;
    QComboBox *driverCBox;
    QLabel *label_15;
    QComboBox *coupltypeCBox;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout6;
    QLabel *label_20;
    QPushButton *folderchooseButt;
    QLabel *label_21;
    QComboBox *datatypeCBox;
    QPushButton *generateButt;
    QProgressBar *progressBar;
    QLabel *elapsedTime;
    QWidget *tab_2;
    QGridLayout *gridLayout7;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout8;
    QPushButton *drawGraphButt;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *ds_genClass)
    {
    if (ds_genClass->objectName().isEmpty())
        ds_genClass->setObjectName(QString::fromUtf8("ds_genClass"));
    ds_genClass->resize(793, 639);
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(ds_genClass->sizePolicy().hasHeightForWidth());
    ds_genClass->setSizePolicy(sizePolicy);
    ds_genClass->setBaseSize(QSize(400, 300));
    action = new QAction(ds_genClass);
    action->setObjectName(QString::fromUtf8("action"));
    action_2 = new QAction(ds_genClass);
    action_2->setObjectName(QString::fromUtf8("action_2"));
    action_3 = new QAction(ds_genClass);
    action_3->setObjectName(QString::fromUtf8("action_3"));
    centralwidget = new QWidget(ds_genClass);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    vboxLayout = new QVBoxLayout(centralwidget);
    vboxLayout->setSpacing(1);
    vboxLayout->setMargin(1);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    vboxLayout->setContentsMargins(1, 1, 1, 1);
    mainTabWidget = new QTabWidget(centralwidget);
    mainTabWidget->setObjectName(QString::fromUtf8("mainTabWidget"));
    mainTabWidget->setTabShape(QTabWidget::Rounded);
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    gridLayout = new QGridLayout(tab);
    gridLayout->setSpacing(1);
    gridLayout->setMargin(1);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    groupBox_5 = new QGroupBox(tab);
    groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
    gridLayout1 = new QGridLayout(groupBox_5);
    gridLayout1->setSpacing(1);
    gridLayout1->setMargin(1);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    gridLayout1->setContentsMargins(1, 1, 1, 1);
    methodCBox = new QComboBox(groupBox_5);
    methodCBox->setObjectName(QString::fromUtf8("methodCBox"));

    gridLayout1->addWidget(methodCBox, 0, 0, 1, 2);

    label_17 = new QLabel(groupBox_5);
    label_17->setObjectName(QString::fromUtf8("label_17"));
    label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    gridLayout1->addWidget(label_17, 1, 0, 1, 1);

    intstepSBox = new QDoubleSpinBox(groupBox_5);
    intstepSBox->setObjectName(QString::fromUtf8("intstepSBox"));
    intstepSBox->setDecimals(4);

    gridLayout1->addWidget(intstepSBox, 1, 1, 1, 1);

    label_24 = new QLabel(groupBox_5);
    label_24->setObjectName(QString::fromUtf8("label_24"));
    label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    gridLayout1->addWidget(label_24, 2, 0, 1, 1);

    noise_lvlSBox = new QDoubleSpinBox(groupBox_5);
    noise_lvlSBox->setObjectName(QString::fromUtf8("noise_lvlSBox"));
    noise_lvlSBox->setDecimals(3);

    gridLayout1->addWidget(noise_lvlSBox, 2, 1, 1, 1);


    gridLayout->addWidget(groupBox_5, 0, 0, 2, 1);

    groupBox_3 = new QGroupBox(tab);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    gridLayout2 = new QGridLayout(groupBox_3);
    gridLayout2->setSpacing(1);
    gridLayout2->setMargin(1);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    gridLayout2->setContentsMargins(1, 1, 1, 1);
    conststartvaluesBox = new QCheckBox(groupBox_3);
    conststartvaluesBox->setObjectName(QString::fromUtf8("conststartvaluesBox"));

    gridLayout2->addWidget(conststartvaluesBox, 0, 0, 1, 1);


    gridLayout->addWidget(groupBox_3, 0, 1, 5, 1);

    groupBox_9 = new QGroupBox(tab);
    groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
    gridLayout3 = new QGridLayout(groupBox_9);
    gridLayout3->setSpacing(1);
    gridLayout3->setMargin(1);
    gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
    gridLayout3->setContentsMargins(1, 1, 1, 1);
    label_26 = new QLabel(groupBox_9);
    label_26->setObjectName(QString::fromUtf8("label_26"));

    gridLayout3->addWidget(label_26, 0, 0, 1, 1);

    eqnsSBox = new QSpinBox(groupBox_9);
    eqnsSBox->setObjectName(QString::fromUtf8("eqnsSBox"));

    gridLayout3->addWidget(eqnsSBox, 0, 1, 1, 1);


    gridLayout->addWidget(groupBox_9, 0, 2, 1, 1);

    dssummaryTEdit = new QTextEdit(tab);
    dssummaryTEdit->setObjectName(QString::fromUtf8("dssummaryTEdit"));
    dssummaryTEdit->setReadOnly(false);

    gridLayout->addWidget(dssummaryTEdit, 1, 2, 4, 1);

    groupBox_6 = new QGroupBox(tab);
    groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
    gridLayout4 = new QGridLayout(groupBox_6);
    gridLayout4->setSpacing(1);
    gridLayout4->setMargin(1);
    gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
    gridLayout4->setContentsMargins(1, 1, 1, 1);
    timeseriestypeCBox = new QComboBox(groupBox_6);
    timeseriestypeCBox->setObjectName(QString::fromUtf8("timeseriestypeCBox"));

    gridLayout4->addWidget(timeseriestypeCBox, 0, 0, 1, 1);

    label_27 = new QLabel(groupBox_6);
    label_27->setObjectName(QString::fromUtf8("label_27"));
    label_27->setAlignment(Qt::AlignCenter);

    gridLayout4->addWidget(label_27, 0, 1, 1, 1);

    label_28 = new QLabel(groupBox_6);
    label_28->setObjectName(QString::fromUtf8("label_28"));
    label_28->setAlignment(Qt::AlignCenter);

    gridLayout4->addWidget(label_28, 0, 2, 1, 1);

    serieslengthsSBox = new QSpinBox(groupBox_6);
    serieslengthsSBox->setObjectName(QString::fromUtf8("serieslengthsSBox"));
    serieslengthsSBox->setMaximum(100000000);

    gridLayout4->addWidget(serieslengthsSBox, 1, 0, 1, 1);

    serieslengtheSBox = new QSpinBox(groupBox_6);
    serieslengtheSBox->setObjectName(QString::fromUtf8("serieslengtheSBox"));
    serieslengtheSBox->setMaximum(100000000);

    gridLayout4->addWidget(serieslengtheSBox, 1, 1, 1, 1);

    serieslengthstepSBox = new QSpinBox(groupBox_6);
    serieslengthstepSBox->setObjectName(QString::fromUtf8("serieslengthstepSBox"));
    serieslengthstepSBox->setMaximum(100000000);
    serieslengthstepSBox->setSingleStep(1000);

    gridLayout4->addWidget(serieslengthstepSBox, 1, 2, 1, 1);

    label_19 = new QLabel(groupBox_6);
    label_19->setObjectName(QString::fromUtf8("label_19"));
    label_19->setAlignment(Qt::AlignCenter);

    gridLayout4->addWidget(label_19, 2, 0, 1, 1);

    label_18 = new QLabel(groupBox_6);
    label_18->setObjectName(QString::fromUtf8("label_18"));
    label_18->setAlignment(Qt::AlignCenter);

    gridLayout4->addWidget(label_18, 2, 1, 1, 1);

    label_25 = new QLabel(groupBox_6);
    label_25->setObjectName(QString::fromUtf8("label_25"));
    label_25->setAlignment(Qt::AlignCenter);

    gridLayout4->addWidget(label_25, 2, 2, 1, 1);

    seriesstepsSBox = new QSpinBox(groupBox_6);
    seriesstepsSBox->setObjectName(QString::fromUtf8("seriesstepsSBox"));
    seriesstepsSBox->setMaximum(200);

    gridLayout4->addWidget(seriesstepsSBox, 3, 0, 1, 1);

    seriesstepeSBox = new QSpinBox(groupBox_6);
    seriesstepeSBox->setObjectName(QString::fromUtf8("seriesstepeSBox"));

    gridLayout4->addWidget(seriesstepeSBox, 3, 1, 1, 1);

    seriesstepstepSBox = new QSpinBox(groupBox_6);
    seriesstepstepSBox->setObjectName(QString::fromUtf8("seriesstepstepSBox"));

    gridLayout4->addWidget(seriesstepstepSBox, 3, 2, 1, 1);


    gridLayout->addWidget(groupBox_6, 2, 0, 1, 1);

    groupBox_4 = new QGroupBox(tab);
    groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
    gridLayout5 = new QGridLayout(groupBox_4);
    gridLayout5->setSpacing(1);
    gridLayout5->setMargin(1);
    gridLayout5->setObjectName(QString::fromUtf8("gridLayout5"));
    gridLayout5->setContentsMargins(1, 1, 1, 1);
    label_12 = new QLabel(groupBox_4);
    label_12->setObjectName(QString::fromUtf8("label_12"));
    label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    gridLayout5->addWidget(label_12, 0, 0, 1, 1);

    label_22 = new QLabel(groupBox_4);
    label_22->setObjectName(QString::fromUtf8("label_22"));
    label_22->setAlignment(Qt::AlignCenter);

    gridLayout5->addWidget(label_22, 0, 1, 1, 1);

    label_23 = new QLabel(groupBox_4);
    label_23->setObjectName(QString::fromUtf8("label_23"));
    label_23->setAlignment(Qt::AlignCenter);

    gridLayout5->addWidget(label_23, 0, 2, 1, 1);

    forcecouplbSBox = new QDoubleSpinBox(groupBox_4);
    forcecouplbSBox->setObjectName(QString::fromUtf8("forcecouplbSBox"));
    forcecouplbSBox->setDecimals(3);
    forcecouplbSBox->setMinimum(-99.99);

    gridLayout5->addWidget(forcecouplbSBox, 1, 0, 1, 1);

    forcecoupleSBox = new QDoubleSpinBox(groupBox_4);
    forcecoupleSBox->setObjectName(QString::fromUtf8("forcecoupleSBox"));
    forcecoupleSBox->setDecimals(3);
    forcecoupleSBox->setMinimum(-99.99);

    gridLayout5->addWidget(forcecoupleSBox, 1, 1, 1, 1);

    forcecouplstepSBox = new QDoubleSpinBox(groupBox_4);
    forcecouplstepSBox->setObjectName(QString::fromUtf8("forcecouplstepSBox"));
    forcecouplstepSBox->setDecimals(4);

    gridLayout5->addWidget(forcecouplstepSBox, 1, 2, 1, 1);

    label_13 = new QLabel(groupBox_4);
    label_13->setObjectName(QString::fromUtf8("label_13"));
    label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    gridLayout5->addWidget(label_13, 2, 0, 1, 1);

    responseCBox = new QComboBox(groupBox_4);
    responseCBox->setObjectName(QString::fromUtf8("responseCBox"));

    gridLayout5->addWidget(responseCBox, 2, 1, 1, 2);

    label_14 = new QLabel(groupBox_4);
    label_14->setObjectName(QString::fromUtf8("label_14"));
    label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    gridLayout5->addWidget(label_14, 3, 0, 1, 1);

    driverCBox = new QComboBox(groupBox_4);
    driverCBox->setObjectName(QString::fromUtf8("driverCBox"));

    gridLayout5->addWidget(driverCBox, 3, 1, 1, 2);

    label_15 = new QLabel(groupBox_4);
    label_15->setObjectName(QString::fromUtf8("label_15"));
    label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    gridLayout5->addWidget(label_15, 4, 0, 1, 1);

    coupltypeCBox = new QComboBox(groupBox_4);
    coupltypeCBox->setObjectName(QString::fromUtf8("coupltypeCBox"));

    gridLayout5->addWidget(coupltypeCBox, 4, 1, 1, 2);


    gridLayout->addWidget(groupBox_4, 3, 0, 1, 1);

    groupBox_7 = new QGroupBox(tab);
    groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
    gridLayout6 = new QGridLayout(groupBox_7);
    gridLayout6->setSpacing(1);
    gridLayout6->setMargin(1);
    gridLayout6->setObjectName(QString::fromUtf8("gridLayout6"));
    gridLayout6->setContentsMargins(1, 1, 1, 1);
    label_20 = new QLabel(groupBox_7);
    label_20->setObjectName(QString::fromUtf8("label_20"));
    label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    gridLayout6->addWidget(label_20, 0, 0, 1, 1);

    folderchooseButt = new QPushButton(groupBox_7);
    folderchooseButt->setObjectName(QString::fromUtf8("folderchooseButt"));

    gridLayout6->addWidget(folderchooseButt, 0, 1, 1, 1);

    label_21 = new QLabel(groupBox_7);
    label_21->setObjectName(QString::fromUtf8("label_21"));
    label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    gridLayout6->addWidget(label_21, 1, 0, 1, 1);

    datatypeCBox = new QComboBox(groupBox_7);
    datatypeCBox->setObjectName(QString::fromUtf8("datatypeCBox"));

    gridLayout6->addWidget(datatypeCBox, 1, 1, 1, 1);


    gridLayout->addWidget(groupBox_7, 4, 0, 1, 1);

    generateButt = new QPushButton(tab);
    generateButt->setObjectName(QString::fromUtf8("generateButt"));
    QFont font;
    font.setBold(true);
    font.setWeight(75);
    generateButt->setFont(font);
    generateButt->setAutoDefault(true);
    generateButt->setDefault(true);

    gridLayout->addWidget(generateButt, 5, 0, 1, 3);

    progressBar = new QProgressBar(tab);
    progressBar->setObjectName(QString::fromUtf8("progressBar"));
    progressBar->setValue(24);

    gridLayout->addWidget(progressBar, 6, 0, 1, 2);

    elapsedTime = new QLabel(tab);
    elapsedTime->setObjectName(QString::fromUtf8("elapsedTime"));

    gridLayout->addWidget(elapsedTime, 6, 2, 1, 1);

    mainTabWidget->addTab(tab, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    gridLayout7 = new QGridLayout(tab_2);
    gridLayout7->setSpacing(1);
    gridLayout7->setMargin(1);
    gridLayout7->setObjectName(QString::fromUtf8("gridLayout7"));
    groupBox_8 = new QGroupBox(tab_2);
    groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
    gridLayout8 = new QGridLayout(groupBox_8);
    gridLayout8->setSpacing(1);
    gridLayout8->setMargin(1);
    gridLayout8->setObjectName(QString::fromUtf8("gridLayout8"));
    gridLayout8->setContentsMargins(1, 1, 1, 1);

    gridLayout7->addWidget(groupBox_8, 0, 0, 1, 1);

    drawGraphButt = new QPushButton(tab_2);
    drawGraphButt->setObjectName(QString::fromUtf8("drawGraphButt"));

    gridLayout7->addWidget(drawGraphButt, 0, 1, 1, 1);

    mainTabWidget->addTab(tab_2, QString());

    vboxLayout->addWidget(mainTabWidget);

    ds_genClass->setCentralWidget(centralwidget);
    menubar = new QMenuBar(ds_genClass);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 793, 25));
    menu = new QMenu(menubar);
    menu->setObjectName(QString::fromUtf8("menu"));
    ds_genClass->setMenuBar(menubar);

    menubar->addAction(menu->menuAction());
    menu->addAction(action);
    menu->addAction(action_2);
    menu->addAction(action_3);

    retranslateUi(ds_genClass);

    mainTabWidget->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(ds_genClass);
    } // setupUi

    void retranslateUi(QMainWindow *ds_genClass)
    {
    ds_genClass->setWindowTitle(QApplication::translate("ds_genClass", "MainWindow", 0, QApplication::UnicodeUTF8));
    action->setText(QApplication::translate("ds_genClass", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\277\321\200\320\276\321\204\320\270\320\273\321\214...", 0, QApplication::UnicodeUTF8));
    action->setShortcut(QApplication::translate("ds_genClass", "Ctrl+O", 0, QApplication::UnicodeUTF8));
    action_2->setText(QApplication::translate("ds_genClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\277\321\200\320\276\321\204\320\270\320\273\321\214...", 0, QApplication::UnicodeUTF8));
    action_2->setShortcut(QApplication::translate("ds_genClass", "Ctrl+S", 0, QApplication::UnicodeUTF8));
    action_3->setText(QApplication::translate("ds_genClass", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", 0, QApplication::UnicodeUTF8));
    action_3->setShortcut(QApplication::translate("ds_genClass", "Ctrl+N", 0, QApplication::UnicodeUTF8));
    groupBox_5->setTitle(QApplication::translate("ds_genClass", "\320\240\320\265\321\210\320\265\320\275\320\270\320\265 \320\224\320\243", 0, QApplication::UnicodeUTF8));
    methodCBox->clear();
    methodCBox->insertItems(0, QStringList()
     << QApplication::translate("ds_genClass", "\320\234\320\265\321\202\320\276\320\264 \320\255\320\271\320\273\320\265\321\200\320\260", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("ds_genClass", "\320\234\320\265\321\202\320\276\320\264 \320\240\321\203\320\275\320\263\320\265-\320\232\321\203\321\202\321\202\321\213", 0, QApplication::UnicodeUTF8)
    );
    label_17->setText(QApplication::translate("ds_genClass", "\320\250\320\260\320\263 \320\270\320\275\321\202\320\265\320\263\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
    label_24->setText(QApplication::translate("ds_genClass", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \321\210\321\203\320\274\320\260", 0, QApplication::UnicodeUTF8));
    groupBox_3->setTitle(QApplication::translate("ds_genClass", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\321\213\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
    conststartvaluesBox->setText(QApplication::translate("ds_genClass", "\320\243\320\264\320\265\321\200\320\266. \320\277\320\276\321\201\321\202. \320\275\320\260 \320\272\320\260\320\266\320\264\320\276\320\274 \321\210\320\260\320\263\320\265", 0, QApplication::UnicodeUTF8));
    groupBox_9->setTitle(QString());
    label_26->setText(QApplication::translate("ds_genClass", "\320\232\320\276\320\273-\320\262\320\276 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\271", 0, QApplication::UnicodeUTF8));
    groupBox_6->setTitle(QApplication::translate("ds_genClass", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\262\321\200\320\265\320\274\320\265\320\275\320\275\320\276\320\263\320\276 \321\200\321\217\320\264\320\260", 0, QApplication::UnicodeUTF8));
    timeseriestypeCBox->clear();
    timeseriestypeCBox->insertItems(0, QStringList()
     << QApplication::translate("ds_genClass", "\320\224\320\273\320\270\320\275\320\260 \321\200\321\217\320\264\320\260", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("ds_genClass", "\320\232\320\276\320\273-\320\262\320\276 \321\202\320\276\321\207\320\265\320\272", 0, QApplication::UnicodeUTF8)
    );
    label_27->setText(QApplication::translate("ds_genClass", "\320\264\320\276", 0, QApplication::UnicodeUTF8));
    label_28->setText(QApplication::translate("ds_genClass", "\321\210\320\260\320\263", 0, QApplication::UnicodeUTF8));
    label_19->setText(QApplication::translate("ds_genClass", "\320\250\320\260\320\263 \320\262\321\213\320\261\320\276\321\200\320\272\320\270 \320\276\321\202", 0, QApplication::UnicodeUTF8));
    label_18->setText(QApplication::translate("ds_genClass", "\320\264\320\276", 0, QApplication::UnicodeUTF8));
    label_25->setText(QApplication::translate("ds_genClass", "\321\210\320\260\320\263", 0, QApplication::UnicodeUTF8));
    groupBox_4->setTitle(QApplication::translate("ds_genClass", "\320\241\320\262\321\217\320\267\321\214", 0, QApplication::UnicodeUTF8));
    label_12->setText(QApplication::translate("ds_genClass", "\320\241\320\270\320\273\320\260 \321\201\320\262\321\217\320\267\320\270 \320\276\321\202", 0, QApplication::UnicodeUTF8));
    label_22->setText(QApplication::translate("ds_genClass", "\320\264\320\276", 0, QApplication::UnicodeUTF8));
    label_23->setText(QApplication::translate("ds_genClass", "\321\210\320\260\320\263", 0, QApplication::UnicodeUTF8));
    label_13->setText(QApplication::translate("ds_genClass", "\320\222\320\265\320\264\320\276\320\274\320\276\320\265", 0, QApplication::UnicodeUTF8));
    responseCBox->clear();
    responseCBox->insertItems(0, QStringList()
     << QApplication::translate("ds_genClass", "x1", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("ds_genClass", "x2", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("ds_genClass", "x3", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("ds_genClass", "x4", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("ds_genClass", "x5", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("ds_genClass", "x6", 0, QApplication::UnicodeUTF8)
    );
    label_14->setText(QApplication::translate("ds_genClass", "\320\222\320\265\320\264\321\203\321\211\320\265\320\265", 0, QApplication::UnicodeUTF8));
    driverCBox->clear();
    driverCBox->insertItems(0, QStringList()
     << QApplication::translate("ds_genClass", "x1", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("ds_genClass", "x2", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("ds_genClass", "x3", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("ds_genClass", "x4", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("ds_genClass", "x5", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("ds_genClass", "x6", 0, QApplication::UnicodeUTF8)
    );
    label_15->setText(QApplication::translate("ds_genClass", "\320\242\320\270\320\277 \321\201\320\262\321\217\320\267\320\270", 0, QApplication::UnicodeUTF8));
    coupltypeCBox->clear();
    coupltypeCBox->insertItems(0, QStringList()
     << QApplication::translate("ds_genClass", "\320\237\321\200\320\276\320\277\320\276\321\200\321\206\320\270\320\276\320\275\320\260\320\273\321\214\320\275\320\260\321\217", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("ds_genClass", "\320\240\320\260\320\267\320\275\320\276\321\201\321\202\320\275\320\260\321\217", 0, QApplication::UnicodeUTF8)
    );
    groupBox_7->setTitle(QApplication::translate("ds_genClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\265 \320\264\320\260\320\275\320\275\321\213\321\205", 0, QApplication::UnicodeUTF8));
    label_20->setText(QApplication::translate("ds_genClass", "\320\237\320\260\320\277\320\272\320\260", 0, QApplication::UnicodeUTF8));
    folderchooseButt->setText(QApplication::translate("ds_genClass", "\320\222\321\213\320\261\320\276\321\200...", 0, QApplication::UnicodeUTF8));
    label_21->setText(QApplication::translate("ds_genClass", "\320\242\320\270\320\277 \320\264\320\260\320\275\320\275\321\213\321\205", 0, QApplication::UnicodeUTF8));
    datatypeCBox->clear();
    datatypeCBox->insertItems(0, QStringList()
     << QApplication::translate("ds_genClass", "\320\241\320\266\320\260\321\202\321\213\320\265 Qt", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("ds_genClass", "\320\242\320\265\320\272\321\201\321\202", 0, QApplication::UnicodeUTF8)
    );
    generateButt->setText(QApplication::translate("ds_genClass", "\320\223\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214!", 0, QApplication::UnicodeUTF8));
    elapsedTime->setText(QApplication::translate("ds_genClass", "\320\222\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\276 \320\267\320\260: ", 0, QApplication::UnicodeUTF8));
    mainTabWidget->setTabText(mainTabWidget->indexOf(tab), QApplication::translate("ds_genClass", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 \320\264\320\270\320\275\320\260\320\274\320\270\321\207\320\265\321\201\320\272\320\276\320\271 \321\201\320\270\321\201\321\202\320\265\320\274\321\213", 0, QApplication::UnicodeUTF8));
    groupBox_8->setTitle(QApplication::translate("ds_genClass", "\320\272\320\260\320\272\320\270\320\265 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\213\320\265 \321\201\321\202\321\200\320\276\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
    drawGraphButt->setText(QApplication::translate("ds_genClass", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", 0, QApplication::UnicodeUTF8));
    mainTabWidget->setTabText(mainTabWidget->indexOf(tab_2), QApplication::translate("ds_genClass", "\320\222\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217", 0, QApplication::UnicodeUTF8));
    menu->setTitle(QApplication::translate("ds_genClass", "\320\244\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ds_genClass: public Ui_ds_genClass {};
} // namespace Ui

#endif // UI_DS_GEN_H
