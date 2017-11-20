#include "tourwinerieswidget.h"
#include "ui_tourwinerieswidget.h"

tourWineriesWidget::tourWineriesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tourWineriesWidget)
{
    ui->setupUi(this);

    QImage smallLogo(":/smallCanyon2.JPG");
    QImage picture1(":/adelaidaCellars.jpg");
    QImage picture2(":/castrorCellars.jpg");
    QImage picture3(":/chumeia.jpg");
    QImage picture3_2(":/chumeia2.jpg");
    QImage picture4(":/erberle.jpg");
    QImage picture4_2(":/erberle2.jpg");
    QImage picture5(":/janKris.jpg");
    QImage picture6(":/lavent2.jpg");
    QImage picture6_2(":/lavent3.jpg");
    QImage picture7(":/norman.jpg");
    QImage picture7_2(":/norman2.jpg");
    QImage picture8(":/opolo.jpg");
    QImage picture9(":/pipestone.jpg");
    QImage picture9_2(":/pipestone2.jpg");
    QImage picture10(":/tablas.jpg");
    QImage picture10_2(":/tablas2.jpg");
    QImage picture11(":/cass.jpg");
    QImage picture11_2(":/cass2.jpg");
    QImage picture12(":/hunt.jpg");
    QImage picture12_2(":/oldbottles.jpg");

    QFont font;
    font.setPointSize(14);
    font.setBold(true);

    //All title labels
    ui->name_page_1->setFont(font);
    ui->name_page_2->setFont(font);
    ui->name_page_3->setFont(font);
    ui->name_page_4->setFont(font);
    ui->name_page_5->setFont(font);
    ui->name_page_6->setFont(font);
    ui->name_page_7->setFont(font);
    ui->name_page_8->setFont(font);
    ui->name_page_9->setFont(font);
    ui->name_page_10->setFont(font);
    ui->name_page_10->setFont(font);
    ui->name_page_11->setFont(font);
    ui->name_page_12->setFont(font);

    //All image labels
    ui->label_page1->setPixmap(QPixmap::fromImage(picture1));
    ui->picture_2->setPixmap(QPixmap::fromImage(picture2));
    ui->picture_page_3->setPixmap(QPixmap::fromImage(picture3));
    ui->picture_page_3_2->setPixmap(QPixmap::fromImage(picture3_2));
    ui->picture_page_4->setPixmap(QPixmap::fromImage(picture4));
    ui->picture_page_4_2->setPixmap(QPixmap::fromImage(picture4_2));
    ui->picture_page_5->setPixmap(QPixmap::fromImage(picture5));
    ui->picture_page_6->setPixmap(QPixmap::fromImage(picture6));
    ui->picture_page_6_2->setPixmap(QPixmap::fromImage(picture6_2));
    ui->picture_page_7->setPixmap(QPixmap::fromImage(picture7));
    ui->picture_page_7_2->setPixmap(QPixmap::fromImage(picture7_2));
    ui->picture_page_8->setPixmap(QPixmap::fromImage(picture8));
    ui->picture_page_9->setPixmap(QPixmap::fromImage(picture9));
    ui->picture_page_9_2->setPixmap(QPixmap::fromImage(picture9_2));
//    ui->picture_page_10->setPixmap(QPixmap::fromImage(picture10));
    ui->picture_page_10_2->setPixmap(QPixmap::fromImage(picture10_2));
    ui->picture_page_11->setPixmap(QPixmap::fromImage(picture11));
    ui->picture_page_11_2->setPixmap(QPixmap::fromImage(picture11_2));
    ui->picture_page_12->setPixmap(QPixmap::fromImage(picture12));
    ui->picture_page_12_2->setPixmap(QPixmap::fromImage(picture12_2));
}

tourWineriesWidget::~tourWineriesWidget()
{
    delete ui;
}

void tourWineriesWidget::setUpUi()
{

}

void tourWineriesWidget::on_next_page1_clicked()
{
    ui->page_1->hide();
    ui->page_2->show();
}

void tourWineriesWidget::on_next_page_2_clicked()
{
    ui->page_2->hide();
    ui->page_3->show();
}

void tourWineriesWidget::on_next_page_3_clicked()
{
    ui->page_3->hide();
    ui->page_4->show();
}

void tourWineriesWidget::on_nex_page_4_clicked()
{
    ui->page_4->hide();
    ui->page_5->show();
}

void tourWineriesWidget::on_next_page_5_clicked()
{
    ui->page_5->hide();
    ui->page_6->show();
}

void tourWineriesWidget::on_next_page_6_clicked()
{
    ui->page_6->hide();
    ui->page_7->show();
}

void tourWineriesWidget::on_next_page_7_clicked()
{
    ui->page_7->hide();
    ui->page_8->show();
}

void tourWineriesWidget::on_next_page_8_clicked()
{
    ui->page_8->hide();
    ui->page_9->show();
}

void tourWineriesWidget::on_next_page_9_clicked()
{
    ui->page_9->hide();
    ui->page_10->show();
}

void tourWineriesWidget::on_next_page_10_clicked()
{
    ui->page_10->hide();
    ui->page_11->show();
}

void tourWineriesWidget::on_next_page_11_clicked()
{
    ui->page_11->hide();
    ui->page_12->show();
}

void tourWineriesWidget::on_next_page_12_clicked()
{
    ui->page_12->hide();
    ui->page_1->show();
}
