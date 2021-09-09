#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QMainWindow>
#include <visiteurpage.h>
#include <evenmentpage.h>
#include <evaluation.h>
#include <stati.h>
#include <QDesktopServices>
#include <QUrl>
#include <QMultimedia>
#include <QSound>
#include <QMediaPlayer>
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Visiteur_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_Evenement_clicked();

    void on_event_clicked();

    void on_evenemen_clicked();

    void on_EV_clicked();

    void on_pushButton_5_clicked();

    void on_evaluation_clicked();

    void on_pushButton_21_clicked();

    void on_evalua_clicked();

    void on_play_clicked();

    void on_pause_clicked();

    void on_playmusic_clicked();

    void on_stat_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    VisiteurPage Visiteur_P;
    Visiteur  Vi;
    EvenmentPage Evenement_P;
    Evenement Ev;
    stati S;
    Evaluation Eva_P;

    QMediaPlayer  *sound;
};
#endif // MAINWINDOW_H
