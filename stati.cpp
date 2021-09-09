#include "stati.h"
#include "ui_stati.h"
#include<iostream>
#include <QDialog>
#include <QPrinter>

stati::stati(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stati)
{
    ui->setupUi(this);
}

stati::~stati()
{
    delete ui;
}


int stati::day(int idd)
{
    QSqlQuery query;
    QString req="select * from VISITEUR where ID_V=";

    req =  req + QString::number(idd);
    QSqlQuery requete(req) ;
    QDate date=query.value(0).toDate();
    int day = date.dayOfWeek();


return day ;



}

int stati::Statistique_partie1()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select ID_V from VISITEUR ") ;
    while(requete.next())
    {    int a;
   a=day(query.value(0).toInt());
            if (a==1)
            count++ ;
    }

return count ;



}



int stati::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select ID_V from VISITEUR ") ;
    while(requete.next())
    {    int a;
   a=day(query.value(0).toInt());
            if (a==2)
            count++ ;
    }
return count ;
}
int stati::Statistique_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select ID_V from VISITEUR ") ;
    while(requete.next())
    {    int a;
   a=day(query.value(0).toInt());
            if (a==3)
            count++ ;
    }
return count ;
}
int stati::Statistique_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select ID_V from VISITEUR ") ;
    while(requete.next())
    {    int a;
   a=day(query.value(0).toInt());
            if (a==4)
            count++ ;
    }
return count ;
}
int stati::Statistique_partie5()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select ID_V from VISITEUR ") ;
    while(requete.next())
    {    int a;
   a=day(query.value(0).toInt());
            if (a==5)
            count++ ;
    }
return count ;
}
int stati::Statistique_partie6()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select ID_V from VISITEUR ") ;
    while(requete.next())
    {    int a;
   a=day(query.value(0).toInt());
            if (a==6)
            count++ ;
    }
return count ;
}
int stati::Statistique_partie7()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select ID_V from VISITEUR ") ;
    while(requete.next())
    {    int a;
   a=day(query.value(0).toInt());
            if (a==7)
            count++ ;
    }
return count ;
}





void stati::paintEvent(QPaintEvent *)
{


int b1=Statistique_partie1();
int b2=Statistique_partie2();
int b3=Statistique_partie3();
int b4=Statistique_partie4();
int b5=Statistique_partie5();
int b6=Statistique_partie6();
int b7=Statistique_partie7();




        float s1= b1*100 ;
float s2= b2*100 ;
float s3= b3*100 ;
float s4= b4*100 ;
float s5= b5*100 ;
float s6= b6*100 ;
float s7= b7*100 ;


        float nb = b1+b2+b3+b4+b5+b6+b7;
        float q1= s1/nb ;
float q2= s2/nb ;
float q3= s3/nb ;
float q4= s4/nb ;
float q5= s5/nb ;
float q6= s6/nb ;
float q7= s7/nb ;

        float y1= (q1*360)/100 ;
 float y2= (q2*360)/100 ;
 float y3= (q3*360)/100 ;
 float y4= (q4*360)/100 ;
 float y5= (q5*360)/100 ;
 float y6= (q6*360)/100 ;
 float y7= (q7*360)/100 ;



    QPainter painter(this);
    QRectF size=QRectF(150,40,this->width()-300,this->width()-300);

    painter.setBrush(Qt::blue);
    painter.drawPie(size,0,4.57142857*y1);
    ui->label_2->setText("Lundi") ;
    painter.setBrush(Qt::green);
    painter.drawPie(size,4.57142857*y1,4.57142857*y2);
    ui->label_3->setText("Mardi") ;
    painter.setBrush(Qt::red);
    painter.drawPie(size,4.57142857*y2,4.57142857*y3);
    ui->label_3->setText("Mercredi") ;
 painter.setBrush(Qt::yellow);
    painter.drawPie(size,4.57142857*y3,4.57142857*y4);
    ui->label_3->setText("jeudi") ;
 painter.setBrush(Qt::white);
    painter.drawPie(size,4.57142857*y4,4.57142857*y5);
    ui->label_3->setText("vendredi") ;
 painter.setBrush(Qt::darkYellow);
    painter.drawPie(size,4.57142857*y5,4.57142857*y6);
    ui->label_3->setText("samedi") ;
 painter.setBrush(Qt::gray);
    painter.drawPie(size,4.57142857*y6,4.57142857*y7);
    ui->label_3->setText("dimanche") ;




}

void stati::on_pushButton_clicked()
{
    hide();
}
