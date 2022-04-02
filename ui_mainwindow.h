/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_pseudo;
    QLabel *label_2;
    QLabel *label_niveau;
    QLabel *label_score;
    QLabel *label_4;
    QLabel *label_phase;
    QLabel *label_6;
    QLabel *label_3;
    QFrame *frame;
    QPushButton *pushButton_op_1;
    QPushButton *pushButton_op_2;
    QPushButton *pushButton_op_3;
    QPushButton *pushButton_op_4;
    QPushButton *pushButton_op_5;
    QPushButton *pushButton_signe_1;
    QPushButton *pushButton_signe_2;
    QPushButton *pushButton_signe_3;
    QPushButton *pushButton_retour_menu;
    QPushButton *pushButton_valider;
    QPushButton *pushButton_passer;
    QLabel *label_14;
    QLabel *label_time;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_result;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1246, 746);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(15, -2, 71, 41));
        label->setStyleSheet(QString::fromUtf8("font-size:20px;\n"
""));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_pseudo = new QLabel(centralWidget);
        label_pseudo->setObjectName(QString::fromUtf8("label_pseudo"));
        label_pseudo->setGeometry(QRect(100, 0, 281, 41));
        label_pseudo->setStyleSheet(QString::fromUtf8("font-size:20px;\n"
"color:rgb(46, 194, 126);"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1030, 0, 81, 41));
        label_2->setStyleSheet(QString::fromUtf8("font-size:20px"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_niveau = new QLabel(centralWidget);
        label_niveau->setObjectName(QString::fromUtf8("label_niveau"));
        label_niveau->setGeometry(QRect(1130, 10, 101, 31));
        label_niveau->setStyleSheet(QString::fromUtf8("font-size:20px;\n"
"color:rgb(224, 27, 36)"));
        label_score = new QLabel(centralWidget);
        label_score->setObjectName(QString::fromUtf8("label_score"));
        label_score->setGeometry(QRect(930, 110, 66, 19));
        label_score->setStyleSheet(QString::fromUtf8("font-size:25px;\n"
"color:rgb(46, 194, 126);"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(810, 100, 131, 41));
        label_4->setStyleSheet(QString::fromUtf8("font-size:22px\n"
""));
        label_4->setAlignment(Qt::AlignCenter);
        label_phase = new QLabel(centralWidget);
        label_phase->setObjectName(QString::fromUtf8("label_phase"));
        label_phase->setGeometry(QRect(350, 110, 66, 19));
        label_phase->setStyleSheet(QString::fromUtf8("font-size:25px;\n"
"color:rgb(53, 132, 228);"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(230, 100, 131, 41));
        label_6->setStyleSheet(QString::fromUtf8("font-size:22px\n"
""));
        label_6->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(940, 290, 66, 51));
        label_3->setStyleSheet(QString::fromUtf8("font-size:30px;"));
        label_3->setAlignment(Qt::AlignCenter);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(180, 400, 791, 151));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_op_1 = new QPushButton(frame);
        pushButton_op_1->setObjectName(QString::fromUtf8("pushButton_op_1"));
        pushButton_op_1->setEnabled(true);
        pushButton_op_1->setGeometry(QRect(10, 30, 121, 31));
        pushButton_op_1->setStyleSheet(QString::fromUtf8("background-color:rgb(53, 132, 228);\n"
"color:rgb(255, 255, 255);"));
        pushButton_op_2 = new QPushButton(frame);
        pushButton_op_2->setObjectName(QString::fromUtf8("pushButton_op_2"));
        pushButton_op_2->setGeometry(QRect(160, 30, 121, 31));
        pushButton_op_2->setStyleSheet(QString::fromUtf8("background-color:rgb(53, 132, 228);\n"
"color:rgb(255, 255, 255)"));
        pushButton_op_3 = new QPushButton(frame);
        pushButton_op_3->setObjectName(QString::fromUtf8("pushButton_op_3"));
        pushButton_op_3->setGeometry(QRect(320, 30, 121, 31));
        pushButton_op_3->setStyleSheet(QString::fromUtf8("background-color:rgb(53, 132, 228);\n"
"color:rgb(255, 255, 255)"));
        pushButton_op_4 = new QPushButton(frame);
        pushButton_op_4->setObjectName(QString::fromUtf8("pushButton_op_4"));
        pushButton_op_4->setEnabled(true);
        pushButton_op_4->setGeometry(QRect(480, 30, 121, 31));
        pushButton_op_4->setStyleSheet(QString::fromUtf8("background-color:rgb(53, 132, 228);\n"
"color:rgb(255, 255, 255)"));
        pushButton_op_5 = new QPushButton(frame);
        pushButton_op_5->setObjectName(QString::fromUtf8("pushButton_op_5"));
        pushButton_op_5->setEnabled(true);
        pushButton_op_5->setGeometry(QRect(650, 30, 121, 31));
        pushButton_op_5->setStyleSheet(QString::fromUtf8("background-color:rgb(53, 132, 228);\n"
"color:rgb(255, 255, 255)"));
        pushButton_signe_1 = new QPushButton(frame);
        pushButton_signe_1->setObjectName(QString::fromUtf8("pushButton_signe_1"));
        pushButton_signe_1->setGeometry(QRect(100, 100, 121, 31));
        pushButton_signe_1->setStyleSheet(QString::fromUtf8("background-color:rgb(53, 132, 228);\n"
"color:rgb(255, 255, 255)"));
        pushButton_signe_2 = new QPushButton(frame);
        pushButton_signe_2->setObjectName(QString::fromUtf8("pushButton_signe_2"));
        pushButton_signe_2->setGeometry(QRect(330, 100, 121, 31));
        pushButton_signe_2->setStyleSheet(QString::fromUtf8("background-color:rgb(53, 132, 228);\n"
"color:rgb(255, 255, 255)"));
        pushButton_signe_3 = new QPushButton(frame);
        pushButton_signe_3->setObjectName(QString::fromUtf8("pushButton_signe_3"));
        pushButton_signe_3->setEnabled(true);
        pushButton_signe_3->setGeometry(QRect(560, 100, 121, 31));
        pushButton_signe_3->setStyleSheet(QString::fromUtf8("background-color:rgb(53, 132, 228);\n"
"color:rgb(255, 255, 255)"));
        pushButton_retour_menu = new QPushButton(centralWidget);
        pushButton_retour_menu->setObjectName(QString::fromUtf8("pushButton_retour_menu"));
        pushButton_retour_menu->setGeometry(QRect(90, 590, 191, 51));
        pushButton_retour_menu->setStyleSheet(QString::fromUtf8("background-color:rgb(246, 97, 81);\n"
"color:rgb(255, 255, 255)"));
        pushButton_valider = new QPushButton(centralWidget);
        pushButton_valider->setObjectName(QString::fromUtf8("pushButton_valider"));
        pushButton_valider->setGeometry(QRect(550, 590, 201, 51));
        pushButton_valider->setStyleSheet(QString::fromUtf8("background-color:rgb(51, 209, 122);\n"
"color:rgb(255, 255, 255)"));
        pushButton_passer = new QPushButton(centralWidget);
        pushButton_passer->setObjectName(QString::fromUtf8("pushButton_passer"));
        pushButton_passer->setGeometry(QRect(990, 590, 231, 51));
        pushButton_passer->setStyleSheet(QString::fromUtf8("background-color:rgb(98, 160, 234);\n"
"color:rgb(255, 255, 255)"));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(540, 100, 131, 41));
        label_14->setStyleSheet(QString::fromUtf8("font-size:22px\n"
""));
        label_14->setAlignment(Qt::AlignCenter);
        label_time = new QLabel(centralWidget);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setGeometry(QRect(535, 178, 141, 41));
        label_time->setStyleSheet(QString::fromUtf8("font-size:30px;\n"
"color:rgb(192, 28, 40)"));
        label_time->setAlignment(Qt::AlignCenter);
        pushButton_1 = new QPushButton(centralWidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(40, 290, 101, 51));
        pushButton_1->setStyleSheet(QString::fromUtf8("border:2px solid rgb(98, 160, 234);\n"
"border-radius:15;"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 290, 101, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("border:2px solid rgb(98, 160, 234);\n"
"border-radius:15;"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(300, 290, 101, 51));
        pushButton_3->setStyleSheet(QString::fromUtf8("border:2px solid rgb(98, 160, 234);\n"
"border-radius:15;"));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(430, 290, 101, 51));
        pushButton_4->setStyleSheet(QString::fromUtf8("border:2px solid rgb(98, 160, 234);\n"
"border-radius:15;"));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(560, 290, 101, 51));
        pushButton_5->setStyleSheet(QString::fromUtf8("border:2px solid rgb(98, 160, 234);\n"
"border-radius:15;"));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(690, 290, 101, 51));
        pushButton_6->setStyleSheet(QString::fromUtf8("border:2px solid rgb(98, 160, 234);\n"
"border-radius:15;"));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(820, 290, 101, 51));
        pushButton_7->setStyleSheet(QString::fromUtf8("border:2px solid rgb(98, 160, 234);\n"
"border-radius:15;"));
        pushButton_result = new QPushButton(centralWidget);
        pushButton_result->setObjectName(QString::fromUtf8("pushButton_result"));
        pushButton_result->setGeometry(QRect(1010, 290, 101, 51));
        pushButton_result->setStyleSheet(QString::fromUtf8("border:2px solid rgb(98, 160, 234);\n"
"border-radius:15;"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1246, 24));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "Pseudo:", nullptr));
        label_pseudo->setText(QApplication::translate("MainWindow", "Ferdi229", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Niveau:", nullptr));
        label_niveau->setText(QApplication::translate("MainWindow", "Difficile", nullptr));
        label_score->setText(QApplication::translate("MainWindow", "10", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "SCORE:", nullptr));
        label_phase->setText(QApplication::translate("MainWindow", "5", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "PHASE:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "=", nullptr));
        pushButton_op_1->setText(QApplication::translate("MainWindow", "1", nullptr));
        pushButton_op_2->setText(QApplication::translate("MainWindow", "2", nullptr));
        pushButton_op_3->setText(QApplication::translate("MainWindow", "3", nullptr));
        pushButton_op_4->setText(QApplication::translate("MainWindow", "4", nullptr));
        pushButton_op_5->setText(QApplication::translate("MainWindow", "10", nullptr));
        pushButton_signe_1->setText(QApplication::translate("MainWindow", "+", nullptr));
        pushButton_signe_2->setText(QApplication::translate("MainWindow", "-", nullptr));
        pushButton_signe_3->setText(QApplication::translate("MainWindow", "*", nullptr));
        pushButton_retour_menu->setText(QApplication::translate("MainWindow", "RETOUR AU MENU", nullptr));
        pushButton_valider->setText(QApplication::translate("MainWindow", "VALIDER", nullptr));
        pushButton_passer->setText(QApplication::translate("MainWindow", "PASSER", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "TIME", nullptr));
        label_time->setText(QApplication::translate("MainWindow", "10", nullptr));
        pushButton_1->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        pushButton_result->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
