/********************************************************************************
** Form generated from reading UI file 'helpwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPWINDOW_H
#define UI_HELPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelpWindow
{
public:
    QStackedWidget *helpStackedWidget;
    QWidget *helpMainMenu;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTextBrowser *textBrowser;
    QWidget *page_2;

    void setupUi(QWidget *HelpWindow)
    {
        if (HelpWindow->objectName().isEmpty())
            HelpWindow->setObjectName(QStringLiteral("HelpWindow"));
        HelpWindow->resize(522, 382);
        helpStackedWidget = new QStackedWidget(HelpWindow);
        helpStackedWidget->setObjectName(QStringLiteral("helpStackedWidget"));
        helpStackedWidget->setGeometry(QRect(30, 30, 471, 321));
        helpMainMenu = new QWidget();
        helpMainMenu->setObjectName(QStringLiteral("helpMainMenu"));
        pushButton = new QPushButton(helpMainMenu);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 280, 141, 23));
        label = new QLabel(helpMainMenu);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(230, 20, 81, 16));
        lineEdit = new QLineEdit(helpMainMenu);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(330, 40, 113, 20));
        pushButton_2 = new QPushButton(helpMainMenu);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 40, 75, 23));
        pushButton_3 = new QPushButton(helpMainMenu);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(250, 70, 171, 51));
        textBrowser = new QTextBrowser(helpMainMenu);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 40, 201, 141));
        textBrowser->setAutoFillBackground(true);
        helpStackedWidget->addWidget(helpMainMenu);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        helpStackedWidget->addWidget(page_2);

        retranslateUi(HelpWindow);

        helpStackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(HelpWindow);
    } // setupUi

    void retranslateUi(QWidget *HelpWindow)
    {
        HelpWindow->setWindowTitle(QApplication::translate("HelpWindow", "Form", 0));
        pushButton->setText(QApplication::translate("HelpWindow", "Return to Main Menu", 0));
        label->setText(QApplication::translate("HelpWindow", "Help", 0));
        pushButton_2->setText(QApplication::translate("HelpWindow", "Search", 0));
        pushButton_3->setText(QApplication::translate("HelpWindow", "FAQ", 0));
        textBrowser->setHtml(QApplication::translate("HelpWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Hello, you have reached the Help options page.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">You can type in your questions in the tool bar, or you can look at the FAQ section by pressing the FAQ button. </span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class HelpWindow: public Ui_HelpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPWINDOW_H
