#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "helpwindow.h"
#include "wine.h"
#include "Winery.h"

#include <QMainWindow>
#include <QListWidget>
#include <QFont>
#include <QObject>
#include <QWindow>
#include <QString>
#include <QMessageBox>
#include <QModelIndexList>
#include <sstream>
#include <ostream>
#include <QPixmap>
#include <QGraphicsScene>
#include <QImage>
#include <QDebug>
#include <QGridLayout>
#include <QTableWidget>
#include <QPushButton>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QDate>
#include "wineshoppingcart.h"
#include "tourwinerieswidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void FileToWinery();
    void PropagateWineryList();
    QString returnAllData(int elementNumber);

    QString getWineList(int vectorElement);

    void WriteToFile(vector<Winery>& wineryListPtr);

    void CreateDistanceVector();
    void CreateDistanceVectorTrip(vector < vector<double> > & someVec);

    double shortest(vector< vector<double> > &v,
                   vector<int> &path);
    vector<Winery> CreateSelectedWineryList(const vector<int>& IDList);

    double shortestTripAlgorithm(vector< vector<double> > &v,
                    vector<int> &path,
                    int startingWinery,
                    int numberOfWineries);

public slots:
    bool AddWinery();

private slots:
    void on_push_button_viewListOfWineries_clicked();

    void on_pushButton_back_viewList_clicked();

    void on_pushButton_backPlanTrip_clicked();

    void on_pushButton_planTrip_clicked();

    void on_pushButton_backTourAndPurchase_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_Admin_clicked();

    void on_pushButton_adminLogin_clicked();

    void on_pushButton_adminLogout_clicked();

    void on_pushButton_tourAndPurchase_clicked();

    void on_pushButton_viewCurrentList_clicked();

    void on_pushButton_backInListView_clicked();

    void on_pushButton_backAboutVilla_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_backViewCurrentLists_clicked();

    void on_pushButton_viewWines_clicked();

    void on_pushButton_backViewWines_clicked();

    void on_pushButton_Quit_clicked();

    void on_pushButton_backAddWinery_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_viewCurrentLists_addWinery_clicked();

    void on_pushButton_backInAdminList_clicked();

    void on_pushButton_11_clicked();

    void on_addWineryOK_clicked();

    void on_addWineryCancel_clicked();

    void on_pushButton_viewDistanceList_clicked();

    void on_pushButton_addWine_wineOptions_clicked();

    void on_pushButton_modifyWine_clicked();

    void on_pushButton_back_wineOptions_clicked();

    void on_backButtonViewDistance_clicked();

    void on_pushButton_customTrip_back_clicked();

    void on_pushButton__clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_shortestTrip_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_shortestTripPage2_back_clicked();

    void on_pushButton_shortestTrip_next_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_editWine_wineOptions_clicked();

    void on_pushButton__back_editWine_clicked();

    void on_comboBox_selectWinery_editWine_currentIndexChanged(int index);

    void on_pushButton_apply_editWine_clicked();

    void on_pushButton_confirmAdd_addWine_clicked();

    void on_comboBox_selectWinery_addWine_currentIndexChanged(int index);

    void on_pushButton_back_addWine_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_shopForWines_clicked();

    void on_push_button_customTrip_Done_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_visitAll_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_clicked();

    void on_pushButton_website_clicked();

private:
    Ui::MainWindow *ui;

    QString currentPassword;
    QString currentUsername;
    QListWidget * viewWineryList;
    bool adminAccessGranted;
    QFont font;
    QFont font2;
    QFont font3;
    vector<Winery> wineryList;
    vector<QLineEdit*> newWineryInfo;
    vector<QLabel*>     labelList;
    vector<vector <double> > distanceList;
    wineShoppingCart shoppingCart;
    int beginningWinery;
    int amountToVisit;
    tourWineriesWidget tourWineries;

};

#endif // MAINWINDOW_H
