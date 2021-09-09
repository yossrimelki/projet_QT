#ifndef EVALUATION_H
#define EVALUATION_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QPrinter>
#include<QFileDialog>
#include <QTextDocument>
#include <QWidget>

namespace Ui {
class Evaluation;
}
class Evaluation : public QWidget
{
    Q_OBJECT

public:
    explicit Evaluation(QWidget *parent = nullptr);
    ~Evaluation();
    Evaluation(int Id_V , int Etoil ,QDate Date_EV );
    //////////////////////////////////////////////////////////////////////////////
    /// getter
    //////////////////////////////////////////////////////////////////////////////
    int getID_V();
    int getETOIL();
    QDate getDATE_EV();
    //////////////////////////////////////////////////////////////////////////////
    /// setter
    //////////////////////////////////////////////////////////////////////////////
    void setID_V(int ID_E);
    void setETOIL(int ETOIL);
    void setDATE_EV(QDate DATE_EV);
    //////////////////////////////////////////////////////////////////////////////
    /// Cruds
    //////////////////////////////////////////////////////////////////////////////
    /////////afficher//////////
    QSqlQueryModel * afficher();
    ////////ajouter///////////
    bool ajouter(int ID_V , int ETOIL ,QDate DATE_EV );
    ///////supprimer/////////
    bool supprimer(int);
    //////modifier//////////
    bool modifier(int,int,QDate);
    //////////////////////////////////////////////////////////////////////////////
    /// Metier
    /////////////////////// ///////////////////////////////////////////////////////
    //////convertir PDF//////////
    void convPDF ();
    //////rech///////////////////
    QSqlQueryModel * Recherche(QString choix,int id);
    /////TRI/////////////////////
    QSqlQueryModel * triID();
    QSqlQueryModel * triAVIS();
    QSqlQueryModel * triDATE();
private slots:
    void on_pushButton_6_clicked();

    void on_tri_eva_clicked();

    void on_Actualiser_eva_clicked();

    void on_supp_eva_clicked();

    void on_conv_pdf_clicked();

    void on_ajout_ev_clicked();

    void on_search_clicked();

    void on_modifier_clicked();

private:
    Ui::Evaluation *ui;
    int Id_V,Etoil;
    QDate Date_EV;
};

#endif // EVALUATION_H
