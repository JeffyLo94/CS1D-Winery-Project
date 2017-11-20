/********************************************************************************
** Form generated from reading UI file 'wineshoppingcart.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINESHOPPINGCART_H
#define UI_WINESHOPPINGCART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wineShoppingCart
{
public:
    QLineEdit *currentTotal;
    QLabel *label;
    QStackedWidget *stackedWidget;
    QWidget *mainMenu;
    QWidget *page_2;
    QTabWidget *wineryTab;
    QWidget *tab_2;
    QWidget *tab;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QFrame *frame;
    QWidget *widget;
    QLabel *label_4;
    QPushButton *pushButton_updateCart;
    QPushButton *pushButton_checkout;

    void setupUi(QWidget *wineShoppingCart)
    {
        if (wineShoppingCart->objectName().isEmpty())
            wineShoppingCart->setObjectName(QStringLiteral("wineShoppingCart"));
        wineShoppingCart->resize(634, 451);
        currentTotal = new QLineEdit(wineShoppingCart);
        currentTotal->setObjectName(QStringLiteral("currentTotal"));
        currentTotal->setGeometry(QRect(470, 30, 113, 20));
        currentTotal->setReadOnly(true);
        label = new QLabel(wineShoppingCart);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(310, 30, 161, 20));
        stackedWidget = new QStackedWidget(wineShoppingCart);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(70, 70, 741, 301));
        mainMenu = new QWidget();
        mainMenu->setObjectName(QStringLiteral("mainMenu"));
        stackedWidget->addWidget(mainMenu);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        wineryTab = new QTabWidget(wineShoppingCart);
        wineryTab->setObjectName(QStringLiteral("wineryTab"));
        wineryTab->setGeometry(QRect(30, 70, 551, 291));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        wineryTab->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(370, 70, 113, 20));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(370, 40, 46, 13));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(370, 120, 46, 13));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(370, 150, 113, 20));
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(250, 50, 101, 21));
        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(240, 20, 121, 221));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 119, 219));
        scrollArea->setWidget(scrollAreaWidgetContents);
        frame = new QFrame(tab);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 20, 341, 221));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        widget = new QWidget(frame);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 331, 221));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(190, 30, 31, 20));
        wineryTab->addTab(tab, QString());
        frame->raise();
        scrollArea->raise();
        lineEdit->raise();
        label_2->raise();
        label_3->raise();
        lineEdit_2->raise();
        lineEdit_3->raise();
        pushButton_updateCart = new QPushButton(wineShoppingCart);
        pushButton_updateCart->setObjectName(QStringLiteral("pushButton_updateCart"));
        pushButton_updateCart->setGeometry(QRect(30, 390, 151, 41));
        pushButton_checkout = new QPushButton(wineShoppingCart);
        pushButton_checkout->setObjectName(QStringLiteral("pushButton_checkout"));
        pushButton_checkout->setGeometry(QRect(450, 390, 151, 41));

        retranslateUi(wineShoppingCart);

        wineryTab->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(wineShoppingCart);
    } // setupUi

    void retranslateUi(QWidget *wineShoppingCart)
    {
        wineShoppingCart->setWindowTitle(QApplication::translate("wineShoppingCart", "Form", 0));
        label->setText(QApplication::translate("wineShoppingCart", "Current Total (Tax not included):", 0));
        wineryTab->setTabText(wineryTab->indexOf(tab_2), QApplication::translate("wineShoppingCart", "Tab 2", 0));
        label_2->setText(QApplication::translate("wineShoppingCart", "TextLabel", 0));
        label_3->setText(QApplication::translate("wineShoppingCart", "TextLabel", 0));
        label_4->setText(QApplication::translate("wineShoppingCart", "TextLabel", 0));
        wineryTab->setTabText(wineryTab->indexOf(tab), QApplication::translate("wineShoppingCart", "Tab 1", 0));
        pushButton_updateCart->setText(QApplication::translate("wineShoppingCart", "Update Cart", 0));
        pushButton_checkout->setText(QApplication::translate("wineShoppingCart", "Checkout", 0));
    } // retranslateUi

};

namespace Ui {
    class wineShoppingCart: public Ui_wineShoppingCart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINESHOPPINGCART_H
