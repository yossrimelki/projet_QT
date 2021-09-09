#include "visiteur.h"
#include<QSqlQuery>

Visiteur::Visiteur()
{
    this->Id_V = 0;
    this->Age_V = 0 ;
    this->Nom_V = "";
    this->Date_V.isNull();

}
Visiteur::Visiteur(int Id_V , int Age_V ,QString Nom_V ,QDate Date_V )
{
    this->Id_V = Id_V;
    this->Age_V = Age_V ;
    this->Nom_V = Nom_V;
    this->Date_V = Date_V;
}

//////////////////////////////////////////////////////////////////////////////
/// getter
//////////////////////////////////////////////////////////////////////////////
int Visiteur::getID_V(){return Id_V;}
int Visiteur::getAGE_V(){return Age_V;}
QString Visiteur::getNOM_V(){return Nom_V;}
QDate Visiteur::getDATE_V(){return Date_V;}
//////////////////////////////////////////////////////////////////////////////
/// setter
//////////////////////////////////////////////////////////////////////////////
void Visiteur::setID_V(int ID_V){this->Id_V=ID_V;}
void Visiteur::setAGE_V(int AGE_V){this->Age_V=AGE_V;}
void Visiteur::setNOM_V(QString NOM_V){this->Nom_V=NOM_V;}
void Visiteur::setID_V(QDate DATE_V){this->Date_V=DATE_V;}
//////////////////////////////////////////////////////////////////////////////
/// Cruds
//////////////////////////////////////////////////////////////////////////////
/////////afficher//////////
QSqlQueryModel * Visiteur::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from VISITEUR");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_V"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_V"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("AGE_V"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_V"));
    return model;

}
////////ajouter///////////
bool Visiteur::ajouter(int ID_V , int AGE_V ,QString NOM_V ,QDate DATE_V )
{
    QSqlQuery query;
    query.prepare("INSERT INTO VISITEUR(ID_V,NOM_V,AGE_V,DATE_V)"
                  "VALUES (:ID_V,:NOM_V,:AGE_V, :DATE_V)");

                        query.bindValue(":ID_V",ID_V);
                        query.bindValue(":NOM_V", NOM_V);
                        query.bindValue(":AGE_V",AGE_V);
                        query.bindValue(":DATE_V", DATE_V);


    return query.exec();
}
///////supprimer/////////
bool Visiteur::supprimer(int ID_V)
{
        QSqlQuery query;
        query.prepare("delete from VISITEUR where (ID_V=:id_v)");
        query.bindValue(":id_v",ID_V);

        return query.exec();
}
//////modifier//////////
bool Visiteur::modifier(int ID_V,int AGE_V,QString NOM_V,QDate DATE_V){
    QSqlQuery query;
    query.prepare("UPDATE VISITEUR SET NOM_V=:nom_v,AGE_V=:age_v,DATE_V=:date_v  WHERE ID_V=:id_v");
    query.bindValue(":id_v",ID_V);
    query.bindValue(":nom_v",NOM_V);
    query.bindValue(":age_v", AGE_V);
    query.bindValue(":date_v", DATE_V);

    return query.exec();
}
//////////////////////////////////////////////////////////////////////////////
/// Metier
//////////////////////////////////////////////////////////////////////////////

////////covertir PDF/////////
void Visiteur::convPDF (){
    QString str;
               str.append("<!DOCTYPE html><html lang='en'><head><style>#ipi-table > thead > tr, #ipi-table > thead > tr > td {font-size: .9em;font-weight: 400;background: #51596a;text-transform: uppercase;color: #ffffff;}#ipi-table > tbody > tr > td {max-height: 200px;vertical-align: middle!important;}</style></head><body><div class='container'><div class='row'><div class='col-md-12'><p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  &nbsp; &nbsp; &nbsp; TABLEAU GESTION VISITEUR  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;</p></div></div></div><div class='container'><div class='card' id='TableSorterCard'><div class='row'><div class='col-12'><div><table class='table table tablesorter' id='ipi-table'><thead class='thead-dark'><tr><th>ID_VISITEUR &nbsp; &nbsp;</th><th class='filter-false'>NOM_VISITEUR &nbsp; &nbsp;</th><th class='filter-false sorter-false'>AGE_VISITEUR &nbsp; &nbsp;</th><th class='filter-false sorter-false'>DATE_VISITEUR &nbsp; &nbsp;</th></tr></thead><tbody>");




               QSqlQuery* query=new QSqlQuery();
               query->exec("SELECT * FROM VISITEUR");

               while(query->next())
               {
               str.append("<tr><td>");
               str.append(query->value(0).toString()) ;
               str.append("</td><td>") ;
               str.append(query->value(1).toString());
               str.append("</td><td>") ;
               str.append(query->value(2).toString());
               str.append("</td><td>") ;
               str.append(query->value(3).toString());
               str.append("</td><td>") ;



               }
            str.append("</tbody></table></div></div></div></div></body></html>") ;

            QPrinter printer ;
            printer.setOrientation(QPrinter::Portrait);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPaperSize(QPrinter::A4) ;

            QString path=QFileDialog::getSaveFileName(NULL,"Convertir a PDF","..","PDF(*.pdf)");

            if (path.isEmpty()) return ;
            printer.setOutputFileName(path) ;

            QTextDocument doc;
            doc.setHtml(str) ;
            doc.print(&printer);
}
/////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
/// rech ///////
QSqlQueryModel * Visiteur::Rech(QString choix,int id)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    if (choix == "ID"){
    QString id_string=QString::number(id);
    model->setQuery("select * from VISITEUR where ID_V like '"+id_string+"%'");
    }
    else if (choix =="AGE")
    {
        QString id_string=QString::number(id);
        model->setQuery("select * from VISITEUR where AGE_V like '"+id_string+"%'");
    }
    return model;
}
QSqlQueryModel * Visiteur::Rech(QString ch)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from VISITEUR where NOM_V like '"+ch+"%'");
    return model;
}
///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
/// TRI///////////
QSqlQueryModel * Visiteur::triID()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from VISITEUR order by ID_V");
    return model;
}
/////////////////////////////////////
QSqlQueryModel * Visiteur::triAGE()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from VISITEUR order by AGE_V");
    return model;
}
/////////////////////////////////////
QSqlQueryModel * Visiteur::triDATE()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from VISITEUR order by DATE_V");
    return model;
}

//////////////////////////////////////////////////////////////////////////////
/// control de saisir
//////////////////////////////////////////////////////////////////////////////
bool Visiteur::verif_nom(QString ch_nom){
    bool test=true;
    int i;
    if(true)
    {
        for(i=0;i<ch_nom.length();i++){
            if(!(ch_nom[i]=='A')&&!(ch_nom[i]=='B')&&!(ch_nom[i]=='C')&&!(ch_nom[i]=='D')&&!(ch_nom[i]=='E')&&!(ch_nom[i]=='F')&&!(ch_nom[i]=='G')&&!(ch_nom[i]=='H')&&!(ch_nom[i]=='I')&&!(ch_nom[i]=='J')&&!(ch_nom[i]=='K')&&!(ch_nom[i]=='L')&&!(ch_nom[i]=='M')&&!(ch_nom[i]=='N')&&!(ch_nom[i]=='O')&&!(ch_nom[i]=='P')&&!(ch_nom[i]=='Q')&&!(ch_nom[i]=='R')&&!(ch_nom[i]=='S')&&!(ch_nom[i]=='T')&&!(ch_nom[i]=='U')&&!(ch_nom[i]=='V')&&!(ch_nom[i]=='W')&&!(ch_nom[i]=='Y')&&!(ch_nom[i]=='Z')&&!(ch_nom[i]=='a')&&!(ch_nom[i]=='b')&&!(ch_nom[i]=='c')&&!(ch_nom[i]=='d')&&!(ch_nom[i]=='e')&&!(ch_nom[i]=='f')&&!(ch_nom[i]=='g')&&!(ch_nom[i]=='h')&&!(ch_nom[i]=='i')&&!(ch_nom[i]=='j')&&!(ch_nom[i]=='k')&&!(ch_nom[i]=='l')&&!(ch_nom[i]=='m')&&!(ch_nom[i]=='n')&&!(ch_nom[i]=='o')&&!(ch_nom[i]=='p')&&!(ch_nom[i]=='q')&&!(ch_nom[i]=='r')&&!(ch_nom[i]=='s')&&!(ch_nom[i]=='t')&&!(ch_nom[i]=='u')&&!(ch_nom[i]=='v')&&!(ch_nom[i]=='w')&&!(ch_nom[i]=='y')&&!(ch_nom[i]=='z')){
                test=false;
                return  test;
        }
    }
    }
    return  test;
}
bool Visiteur::verif_age(int numero)
{
    bool test=true;
    if(numero < 10){
       test=false;
    }
 return test;
}
bool Visiteur::checkid (int id)
{
   QString id_string=QString::number(id);
   QSqlQuery q;
   q.prepare("select TOP 1 * from VISITEUR WHERE ID_V like '%"+id_string+"%' ");

   return q.exec();
}
