#ifndef WINESHOPPINGCART_H
#define WINESHOPPINGCART_H

#include <QWidget>
#include <vector>
#include <Winery.h>
#include "wine.h"
#include <QTabWidget>
#include <QListWidget>
#include <QDesktopServices>
#include <QUrl>
#include <QTextBrowser>
#include <QScrollArea>
#include <QScrollBar>

namespace Ui {
class wineShoppingCart;
}

class wineShoppingCart : public QWidget
{
    Q_OBJECT

public:
    explicit wineShoppingCart(QWidget *parent = 0);
    ~wineShoppingCart();
    wineShoppingCart(const vector<Winery> & List);
    void fillAllLists();
    void setList(const vector<Winery>& list);


private slots:
    void on_pushButton_checkout_clicked();

    void on_pushButton_updateCart_clicked();

private:
    vector<Winery>              wineryList;
    vector<QTextBrowser*>      totalBottleEachWinery;
    vector<QTextBrowser*>      totalEachWinery;
    Ui::wineShoppingCart*       ui;
//    vector<QListWidget*>        wineListVector;
    vector<vector <QLineEdit*> > bottleList;
    double  grandTotal;
};

#endif // WINESHOPPINGCART_H
