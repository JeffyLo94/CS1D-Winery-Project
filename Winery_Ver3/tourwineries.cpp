#include "tourwineries.h"
#include "ui_tourwineries.h"

tourWineries::tourWineries(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tourWineries)
{
    ui->setupUi(this);
}

tourWineries::~tourWineries()
{
    delete ui;
}
