#include "evaluation.h"
#include "ui_evaluation.h"
#include<QSqlQuery>
Evaluation::Evaluation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Evaluation)
{
    ui->setupUi(this);
    ui->tableView->setModel(this->afficher());
    ui->comboBox->addItem("ID");
    ui->comboBox->addItem("ETOIL");
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->progressBar,SLOT(setValue(int)));
    connect(ui->horizontalSlider_2,SIGNAL(valueChanged(int)),ui->progressBar_2,SLOT(setValue(int)));
}

Evaluation::~Evaluation()
{
    this->Id_V =0;
    this->Etoil =0;
    this->Date_EV.isNull();
    delete ui;
}
Evaluation::Evaluation(int Id_V , int Etoil ,QDate Date_EV )
{
    this->Id_V = Id_V;
    this->Etoil= Etoil;
    this->Date_EV = Date_EV;

}
//////////////////////////////////////////////////////////////////////////////
/// getter
//////////////////////////////////////////////////////////////////////////////
int Evaluation::getID_V(){return Id_V;}
int Evaluation::getETOIL(){return Etoil;}
QDate Evaluation::getDATE_EV(){return Date_EV;}
//////////////////////////////////////////////////////////////////////////////
/// setter
//////////////////////////////////////////////////////////////////////////////
void Evaluation::setID_V(int ID_V){this->Id_V=ID_V;}
void Evaluation::setETOIL(int ETOIL){this->Etoil=ETOIL;}
void Evaluation::setDATE_EV(QDate DATE_EV){this->Date_EV=DATE_EV;}
//////////////////////////////////////////////////////////////////////////////
/// Cruds
//////////////////////////////////////////////////////////////////////////////
/////////afficher//////////
QSqlQueryModel * Evaluation::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from EVALUATION");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_V"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_AVIS"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ETOIL"));
    return model;
}
////////ajouter///////////
bool Evaluation::ajouter(int ID_V , int ETOIL ,QDate DATE_EV )
{
    QSqlQuery query;
    query.prepare("INSERT INTO EVALUATION(ID_V,DATE_AVIS,ETOIL)"
                  "VALUES (:ID_V, :DATE_EV,:ETOIL)");

                        query.bindValue(":ID_V",ID_V);
                        query.bindValue(":DATE_EV", DATE_EV);
                        query.bindValue(":ETOIL", ETOIL );


    return query.exec();
}
///////supprimer/////////
bool Evaluation::supprimer(int ID_V)
{
    QSqlQuery query;
    query.prepare("delete from EVALUATION where (ID_V=:id_v)");
    query.bindValue(":id_v",ID_V);

    return query.exec();
}
//////modifier//////////
bool Evaluation::modifier(int ID_V,int ETOIL ,QDate DATE_EV)
{
    QSqlQuery query;
    query.prepare("UPDATE EVALUATION SET ETOIL=:etoil,DATE_AVIS=:date_ev  WHERE ID_V=:id_v");
    query.bindValue(":id_v",ID_V);
    query.bindValue(":etoil",ETOIL);
    query.bindValue(":date_ev", DATE_EV);

    return query.exec();

}
//////////////////////////////////////////////////////////////////////////////
/// Metier
//////////////////////////////////////////////////////////////////////////////
////////covertir PDF/////////
void Evaluation::convPDF (){
    QString str;
               str.append("<!DOCTYPE html><html lang='en'><head><style>#ipi-table > thead > tr, #ipi-table > thead > tr > td {font-size: .9em;font-weight: 400;background: #51596a;text-transform: uppercase;color: #ffffff;}#ipi-table > tbody > tr > td {max-height: 200px;vertical-align: middle!important;}</style></head><body><div class='container'><div class='row'><div class='col-md-12'><p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  &nbsp; &nbsp; &nbsp; TABLEAU GESTION EVALUATION  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;</p></div></div></div><div class='container'><div class='card' id='TableSorterCard'><div class='row'><div class='col-12'><div><table class='table table tablesorter' id='ipi-table'><thead class='thead-dark'><tr><th>ID_VISITEUR &nbsp; &nbsp;</th><th class='filter-false'>ETOIL &nbsp; &nbsp;</th><th class='filter-false sorter-false'>DATE &nbsp; &nbsp;</th></tr></thead><tbody>");




               QSqlQuery* query=new QSqlQuery();
               query->exec("SELECT * FROM EVALUATION");

               while(query->next())
               {
               str.append("<tr><td>");
               str.append(query->value(0).toString()) ;
               str.append("</td><td>") ;
               str.append(query->value(1).toString());
               str.append("</td><td>") ;
               str.append(query->value(2).toString());
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
QSqlQueryModel * Evaluation::Recherche(QString choix,int id)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    if (choix == "ID"){
    QString id_string=QString::number(id);
    model->setQuery("select * from EVALUATION where ID_V like '"+id_string+"%'");
    }
    else if (choix =="ETOIL")
    {
        QString id_string=QString::number(id);
        model->setQuery("select * from EVALUATION where ETOIL like '"+id_string+"%'");
    }
    return model;
}
///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
/// TRI///////////
QSqlQueryModel * Evaluation::triID()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from EVALUATION order by ID_V");
    return model;
}
/////////////////////////////////////
QSqlQueryModel * Evaluation::triAVIS()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from EVALUATION order by ETOIL");
    return model;
}
//////////////////////////////////////
QSqlQueryModel * Evaluation::triDATE()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from EVALUATION order by DATE_AVIS");
    return model;
}
///////////////////////////////////////////////////////////////////////////////
/// pushButton////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
void Evaluation::on_pushButton_6_clicked()
{
    QString choix = ui->comboBox->currentText();
    int id=ui->rech_eva->text().toInt();
    this->Recherche(choix,id);
}


void Evaluation::on_tri_eva_clicked()
{
    bool choix=ui->radioButton->isChecked();
    if (choix)
    {
        ui->tableView->setModel(this->triID());
    }
    choix=ui->radioButton_2->isChecked();
    if (choix)
    {
        ui->tableView->setModel(this->triDATE());
    }
    choix=ui->radioButton_3->isChecked();
    if (choix)
    {
        ui->tableView->setModel(this->triAVIS());
    }
}

void Evaluation::on_Actualiser_eva_clicked()
{
    ui->tableView->setModel(this->afficher());
}

void Evaluation::on_supp_eva_clicked()
{
    int id=ui->suppp->text().toInt();
    this->supprimer(id);
}


void Evaluation::on_conv_pdf_clicked()
{
    this->convPDF();
}

void Evaluation::on_ajout_ev_clicked()
{
    int id=ui->id_v->text().toInt();
    QDate date=ui->calendarWidget->selectedDate();
    int valuee = ui->progressBar->value();
    this->ajouter(id,valuee,date);

}

void Evaluation::on_search_clicked()
{
    QString choix = ui->comboBox->currentText();
    int id=ui->rech_eva->text().toInt();
    ui->tableView->setModel(this->Recherche(choix,id));

}

void Evaluation::on_modifier_clicked()
{
    int id=ui->id_eva2->text().toInt();
    QDate date=ui->calendarWidget_2->selectedDate();
    int valuee = ui->progressBar_2->value();
    this->modifier(id,valuee,date);
}
