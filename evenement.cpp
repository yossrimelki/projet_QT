#include "evenement.h"
#include<QSqlQuery>
Evenement::Evenement()
{
    this->Id_E =0;
    this->Type_E ="";
    this->Nom_E ="";
    this->Date_E.isNull();

}
Evenement::Evenement(int Id_E , QString Type_E ,QString Nom_E ,QDate Date_E ){
    this->Id_E = Id_E;
    this->Type_E = Type_E;
    this->Nom_E = Nom_E;
    this->Date_E = Date_E;


}
//////////////////////////////////////////////////////////////////////////////
/// getter
//////////////////////////////////////////////////////////////////////////////
int Evenement::getID_E(){return Id_E;}
QString Evenement::getTYPE_E(){return Type_E;}
QString Evenement::getNOM_E(){return Nom_E;}
QDate Evenement::getDATE_E(){return Date_E;}
//////////////////////////////////////////////////////////////////////////////
/// setter
//////////////////////////////////////////////////////////////////////////////
void Evenement::setID_E(int ID_E){this->Id_E=ID_E;}
void Evenement::setTYPE_E(QString TYPE_E){this->Type_E=TYPE_E;}
void Evenement::setNOM_E(QString NOM_E){this->Nom_E=NOM_E;}
void Evenement::setID_E(QDate DATE_E){this->Date_E=DATE_E;}
//////////////////////////////////////////////////////////////////////////////
/// Cruds
//////////////////////////////////////////////////////////////////////////////
/////////afficher//////////
QSqlQueryModel * Evenement::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from EVENEMENT");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_E"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_E"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE_E"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_E"));
    return model;
}
////////ajouter///////////
bool Evenement::ajouter(int ID_E , QString TYPE_E ,QString NOM_E ,QDate DATE_E )
{
    QSqlQuery query;
    query.prepare("INSERT INTO EVENEMENT(ID_E,NOM_E,TYPE_E,DATE_E)"
                  "VALUES (:ID_E,:NOM_E,:TYPE_E, :DATE_E)");

                        query.bindValue(":ID_E",ID_E);
                        query.bindValue(":NOM_E", NOM_E );
                        query.bindValue(":TYPE_E",TYPE_E);
                        query.bindValue(":DATE_E", DATE_E);


    return query.exec();
}
///////supprimer/////////
bool Evenement::supprimer(int ID_E)
{
    QSqlQuery query;
    query.prepare("delete from EVENEMENT where (ID_E=:id_e)");
    query.bindValue(":id_e",ID_E);

    return query.exec();
}
//////modifier//////////
bool Evenement::modifier(int ID_E,QString NOM_E ,QString TYPE_E,QDate DATE_E)
{
    QSqlQuery query;
    query.prepare("UPDATE EVENEMENT SET NOM_E=:nom_e,TYPE_E=:type_e,DATE_E=:date_e  WHERE ID_E=:id_e");
    query.bindValue(":id_e",ID_E);
    query.bindValue(":nom_e",NOM_E);
    query.bindValue(":type_e", TYPE_E);
    query.bindValue(":date_e", DATE_E);

    return query.exec();

}
//////////////////////////////////////////////////////////////////////////////
/// Metier
//////////////////////////////////////////////////////////////////////////////
////////covertir PDF/////////
void Evenement::convPDF (){
    QString str;
               str.append("<!DOCTYPE html><html lang='en'><head><style>#ipi-table > thead > tr, #ipi-table > thead > tr > td {font-size: .9em;font-weight: 400;background: #51596a;text-transform: uppercase;color: #ffffff;}#ipi-table > tbody > tr > td {max-height: 200px;vertical-align: middle!important;}</style></head><body><div class='container'><div class='row'><div class='col-md-12'><p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  &nbsp; &nbsp; &nbsp; TABLEAU GESTION EVENEMENT  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;</p></div></div></div><div class='container'><div class='card' id='TableSorterCard'><div class='row'><div class='col-12'><div><table class='table table tablesorter' id='ipi-table'><thead class='thead-dark'><tr><th>ID_EVENEMENT &nbsp; &nbsp;</th><th class='filter-false'>NOM_EVENEMENT &nbsp; &nbsp;</th><th class='filter-false sorter-false'>TYPE_EVENEMENT &nbsp; &nbsp;</th><th class='filter-false sorter-false'>DATE_EVENEMENT &nbsp; &nbsp;</th></tr></thead><tbody>");




               QSqlQuery* query=new QSqlQuery();
               query->exec("SELECT * FROM EVENEMENT");

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
QSqlQueryModel * Evenement::Recherche(int id)
{
    QString id_string=QString::number(id);
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from EVENEMENT where ID_E like '"+id_string+"%'");
    return model;
}
QSqlQueryModel * Evenement::Recherche(QString choix,QString ch)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    if (choix == "TYPE"){
    model->setQuery("select * from EVENEMENT where TYPE_E like '"+ch+"%'");
    }
    else if (choix == "NOM")
    {
    model->setQuery("select * from EVENEMENT where NOM_E like '"+ch+"%'");
    }
    return model;
}
///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
/// TRI///////////
QSqlQueryModel * Evenement::triID()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from EVENEMENT order by ID_E");
    return model;
}
/////////////////////////////////////
QSqlQueryModel * Evenement::triTYPE(QString ch)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from EVENEMENT WHERE TYPE_E like '"+ch+"%' order by DATE_E ");
    return model;
}
/////////////////////////////////////
QSqlQueryModel * Evenement::triDATE()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from EVENEMENT order by DATE_E");
    return model;
}
//////////////////////////////////////////////////////////////////////////////
/// control de saisir
//////////////////////////////////////////////////////////////////////////////
bool Evenement::verif_nom(QString ch_nom){
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

