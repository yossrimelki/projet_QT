#ifndef  STATI_H
#define STATI_H

#include <QPainter>
#include <QSqlQuery>
#include <QDialog>
#include <QDate>
using namespace std;

namespace Ui {
class stati;
}

class stati : public QDialog
{
    Q_OBJECT

public:
    explicit stati(QWidget *parent = nullptr);
       int Statistique_partie1() ;
       int Statistique_partie2() ;
 int Statistique_partie3() ;
       int Statistique_partie4() ;
 int Statistique_partie5() ;
       int Statistique_partie6() ;
 int Statistique_partie7() ;
int day(int);



     void paintEvent(QPaintEvent *) ;
    ~stati();
private slots:
    void on_pushButton_clicked();

private:
    Ui::stati *ui;
};

#endif // STATI_H
