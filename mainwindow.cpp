#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ///////////////////////////////////////////////////////////////////////
    sound = new QMediaPlayer(this);
    sound->setMedia(QUrl::fromLocalFile("F:/zoo/zoo_ProjetV1/music.mp3"));

    ///////////////////////////////////////////////////////////////////////
    ui->stackedWidget->insertWidget(1,&Visiteur_P);
    ui->stackedWidget->insertWidget(2,&Evenement_P);
    ui->stackedWidget->insertWidget(3,&Eva_P);
    ui->stackedWidget->insertWidget(4,&S);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Visiteur_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_7_clicked()
{
    this->close();
}

void MainWindow::on_EV_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_5_clicked()
{
    QString link="https://www.facebook.com/belvederetunis/";
    QDesktopServices::openUrl(QUrl(link));
}



void MainWindow::on_evaluation_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_evalua_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_play_clicked()
{
    sound->play();
}

void MainWindow::on_pause_clicked()
{
    sound->stop();
}

void MainWindow::on_playmusic_clicked()
{
    sound->play();
    qDebug() << sound->errorString();
}

void MainWindow::on_stat_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
