#ifndef TOURWINERIES_H
#define TOURWINERIES_H

#include <QWidget>

namespace Ui {
class tourWineries;
}

class tourWineries : public QWidget
{
    Q_OBJECT

public:
    explicit tourWineries(QWidget *parent = 0);
    ~tourWineries();

private:
    Ui::tourWineries *ui;
};

#endif // TOURWINERIES_H
