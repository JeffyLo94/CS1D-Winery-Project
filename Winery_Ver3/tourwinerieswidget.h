#ifndef TOURWINERIESWIDGET_H
#define TOURWINERIESWIDGET_H
#include "Winery.h"
#include <vector>

#include <QWidget>
#include <QPixmap>
#include <QImage>
#include <QFont>

namespace Ui {
class tourWineriesWidget;
}

class tourWineriesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit tourWineriesWidget(QWidget *parent = 0);
    ~tourWineriesWidget();

    tourWineriesWidget(vector<Winery> wineries);

    void setUpUi();


private slots:
    void on_next_page1_clicked();

    void on_next_page_2_clicked();

    void on_next_page_3_clicked();

    void on_nex_page_4_clicked();

    void on_next_page_5_clicked();

    void on_next_page_6_clicked();

    void on_next_page_7_clicked();

    void on_next_page_8_clicked();

    void on_next_page_9_clicked();

    void on_next_page_10_clicked();

    void on_next_page_11_clicked();

    void on_next_page_12_clicked();

private:

    Ui::tourWineriesWidget *ui;

    vector<Winery> wineryList;
};

#endif // TOURWINERIESWIDGET_H
