#ifndef VISITEUR_H
#define VISITEUR_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QPrinter>
#include<QFileDialog>
#include <QTextDocument>
class Visiteur
{

public:
    Visiteur();
    Visiteur(int Id_V , int Age_V ,QString Nom_V ,QDate Date_V );
    //////////////////////////////////////////////////////////////////////////////
    /// getter
    //////////////////////////////////////////////////////////////////////////////
    int getID_V();
    int getAGE_V();
    QString getNOM_V();
    QDate getDATE_V();
    //////////////////////////////////////////////////////////////////////////////
    /// setter
    //////////////////////////////////////////////////////////////////////////////
    void setID_V(int ID_V);
    void setAGE_V(int AGE_V);
    void setNOM_V(QString NOM_V);
    void setID_V(QDate DATE_V);
    //////////////////////////////////////////////////////////////////////////////
    /// Cruds
    //////////////////////////////////////////////////////////////////////////////
    /////////afficher//////////
    QSqlQueryModel * afficher();
    ////////ajouter///////////
    bool ajouter(int ID_V , int AGE_V ,QString NOM_V ,QDate DATE_V );
    ///////supprimer/////////
    bool supprimer(int);
    //////modifier//////////
    bool modifier(int,int,QString,QDate);
    //////////////////////////////////////////////////////////////////////////////
    /// Metier
    //////////////////////////////////////////////////////////////////////////////
    //////convertir PDF//////////
    void convPDF ();
    //////rech///////////////////
    QSqlQueryModel * Rech(QString choix,int id);
    QSqlQueryModel * Rech(QString ch);
    /////TRI/////////////////////
    QSqlQueryModel * triID();
    QSqlQueryModel * triAGE();
    QSqlQueryModel * triDATE();
    //////////////////////////////////////////////////////////////////////////////
    ///////control de saisir
    /// /////////////////////////////////////////////////////////////////////////
    bool verif_nom(QString ch_nom);
    bool verif_age(int numero);
    bool checkid (int id);
private:
    int Id_V,Age_V;
    QString Nom_V ;
    QDate Date_V;
};

#endif // VISITEUR_H
