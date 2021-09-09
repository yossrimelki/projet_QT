#include "visiteurpage.h"
#include "ui_visiteurpage.h"

VisiteurPage::VisiteurPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VisiteurPage)
{
    ui->setupUi(this);
    ui->tableViewVisiteur->setModel(Vi.afficher());
    ui->comboBox_V->addItem("ID");
    ui->comboBox_V->addItem("AGE");
    ui->comboBox_V->addItem("NOM");
}

VisiteurPage::~VisiteurPage()
{
    delete ui;
}

void VisiteurPage::on_AJOUT_V_clicked()
{
    int id=ui->ID_VISITEUR->text().toInt();
    QString nom=ui->NOM_VISITEUR->text();
    int age=ui->AGE_VISITEUR->text().toInt();
    QDate date=ui->calendarWidget->selectedDate();
    Visiteur V(id,age,nom,date);
    bool check = V.verif_nom(nom);
    if (!check){
        QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                 QObject::tr("nom est invalid! \n"
                                              "click Cancel to exit"),QMessageBox::Cancel);
        return;

    }
    check=true;
    check = V.verif_age(age);

    if (!check){
        QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                 QObject::tr("AGE est invalid! AGE <10 \n"
                                              "click Cancel to exit"),QMessageBox::Cancel);
        return;
    }
    bool test=V.ajouter(id,age,nom,date);
    if (test){
        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("ajout effectue\n""click cancel to exit."),QMessageBox::Cancel);

    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                 QObject::tr("ajout non effectuee! \n"
                                              "click Cancel to exit"),QMessageBox::Cancel);
}
}

void VisiteurPage::on_Actualiser_clicked()
{
    ui->tableViewVisiteur->setModel(Vi.afficher());
}

void VisiteurPage::on_Supprimer_V_clicked()
{
    int id=ui->zone_supp->text().toInt();
    Visiteur V;
    bool test=V.supprimer(id);
}

void VisiteurPage::on_Modifier_V_clicked()
{
    int id=ui->ID_V->text().toInt();
    QString nom=ui->NOM_V->text();
    int age=ui->AGE_V->text().toInt();
    QDate date=ui->calendarWidget_MV->selectedDate();
    Visiteur V;
    bool check = V.verif_nom(nom);
    if (!check){
        QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                 QObject::tr("nom est invalid! \n"
                                              "click Cancel to exit"),QMessageBox::Cancel);
        return;

    }
    check=true;
    check = V.verif_age(age);

    if (!check){
        QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                 QObject::tr("AGE est invalid! AGE <10 \n"
                                              "click Cancel to exit"),QMessageBox::Cancel);
        return;
    }
     bool test=V.modifier(id,age,nom,date);
        if (test){
            QMessageBox::information(nullptr,QObject::tr("OK"),
                    QObject::tr("ajout effectue\n""click cancel to exit."),QMessageBox::Cancel);

        }
        else{
            QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                     QObject::tr("ajout non effectuee! \n"
                                                  "click Cancel to exit"),QMessageBox::Cancel);
    }





}

void VisiteurPage::on_convPDF_clicked()
{
    Visiteur v;
    v.convPDF();
}

void VisiteurPage::on_Recherche_V_clicked()
{
    Visiteur v;
    QString choix = ui->comboBox_V->currentText();
    if (choix=="NOM")
    {
        QString rech=ui->zone_rech->text();
        ui->tableViewVisiteur->setModel(v.Rech(rech));

    }
    else {
        int rech=ui->zone_rech->text().toInt();
        ui->tableViewVisiteur->setModel(v.Rech(choix,rech));

    }
}

void VisiteurPage::on_Tri_V_clicked()
{
    Visiteur v;
    bool choix=ui->radioButton->isChecked();
    if (choix){
        ui->tableViewVisiteur->setModel(v.triDATE());
    }
    choix=ui->radioButton_2->isChecked();
    if (choix){
        ui->tableViewVisiteur->setModel(v.triAGE());
    }
    choix=ui->radioButton_3->isChecked();
    if (choix){
        ui->tableViewVisiteur->setModel(v.triID());
    }

}

void VisiteurPage::on_pushButton_clicked()
{
        ui->label_9->setText("Guest ID");
        ui->label_10->setText("Guest Name");
        ui->label_11->setText("Guest AGE");
        ui->label_14->setText("Guest ID");
        ui->label_15->setText("Guest Name");
        ui->label_16->setText("Guest AGE");
        ui->Supprimer_V->setText("Delete");
        ui->Actualiser->setText("refresh");
        ui->AJOUT_V->setText("ADD");
        ui->Modifier_V->setText("UPDATE");




}

void VisiteurPage::on_pushButton_2_clicked()
{
    ui->label_9->setText("ID VISITEUR");
    ui->label_10->setText("NOM VISITEUR");
    ui->label_11->setText("AGE VISITEUR");
    ui->label_14->setText("ID VISITEUR");
    ui->label_15->setText("NOM VISITEUR");
    ui->label_16->setText("AGE VISITEUR");
    ui->Supprimer_V->setText("Supprimer");
    ui->Actualiser->setText("Actualiser");
    ui->AJOUT_V->setText("Ajouter");
    ui->Modifier_V->setText("Modifier");
}
