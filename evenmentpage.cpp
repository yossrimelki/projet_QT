#include "evenmentpage.h"
#include "ui_evenmentpage.h"

EvenmentPage::EvenmentPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EvenmentPage)
{
    ui->setupUi(this);
    ui->tableView_E->setModel(Ev.afficher());
    ui->comboBoxrech->addItem("ID");
    ui->comboBoxrech->addItem("TYPE");
    ui->comboBoxrech->addItem("NOM");
    ui->comboBox_type->addItem("festival");
    ui->comboBox_type->addItem("competition");
    ui->comboBox_type->addItem("preparation");
}

EvenmentPage::~EvenmentPage()
{
    delete ui;
}

void EvenmentPage::on_Actualiser_E_clicked()
{
    ui->tableView_E->setModel(Ev.afficher());
}

void EvenmentPage::on_supp_E_clicked()
{
    int id=ui->supp->text().toInt();
    Evenement E;
    bool test=E.supprimer(id);
}

void EvenmentPage::on_ajout_E_clicked()
{
    QString type;
    int id=ui->id_e->text().toInt();
    QString nom=ui->nom_e->text();
    bool test=ui->radioButton->isChecked();
    if (test){
        type = "festival";

    }
    test=ui->radioButton_2->isChecked();
    if (test){
        type = "competition";
    }
    test=ui->radioButton_3->isChecked();
    if (test){
        type = "preparation";
    }
    QDate date=ui->calendarWidget_e->selectedDate();
    Evenement E(id,type,nom,date);
    bool check = E.verif_nom(nom);
    if (!check){
        QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                 QObject::tr("nom est invalid! \n"
                                              "click Cancel to exit"),QMessageBox::Cancel);
        return;

    }
    test=E.ajouter(id,type,nom,date);
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

void EvenmentPage::on_Modif_clicked()
{
    QString type;
    int id=ui->id_ev->text().toInt();
    QString nom=ui->nom_ev->text();
    bool test=ui->festival->isChecked();
    if (test){
        type = "festival";

    }
    test=ui->competition->isChecked();
    if (test){
        type = "competition";
    }
    test=ui->preparation->isChecked();
    if (test){
        type = "preparation";
    }
    QDate date=ui->calendarWidget_e->selectedDate();
    Evenement E(id,type,nom,date);
    bool check = E.verif_nom(nom);
    if (!check){
        QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                 QObject::tr("nom est invalid! \n"
                                              "click Cancel to exit"),QMessageBox::Cancel);
        return;

    }
    test=E.modifier(id,nom,type,date);
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

void EvenmentPage::on_pushButton_clicked()
{
    Evenement E;
    E.convPDF();
}

void EvenmentPage::on_rech_e_clicked()
{
    Evenement E;


    QString choix = ui->comboBoxrech->currentText();
    if (choix == "ID")
    {
        int rech=ui->rech_zon->text().toInt();
        ui->tableView_E->setModel(E.Recherche(rech));

    }
    else
    {
        QString rech=ui->rech_zon->text();
        ui->tableView_E->setModel(E.Recherche(choix,rech));

    }
}

void EvenmentPage::on_tri_E_clicked()
{
    Evenement e;
    bool choix=ui->radioButton_4->isChecked();
    if (choix)
    {
        ui->tableView_E->setModel(e.triDATE());
    }
    choix=ui->radioButton_6->isChecked();
    if (choix)
    {
        ui->tableView_E->setModel(e.triID());
    }
    choix=ui->radioButton_5->isChecked();
    if (choix)
    {
        QString ch = ui->comboBox_type->currentText();
        ui->tableView_E->setModel(e.triTYPE(ch));
    }
}

void EvenmentPage::on_pushButton_2_clicked()
{
    ui->label->setText("Event ID");
    ui->label_2->setText("Event Name");
    ui->label_3->setText("Event TYPE");
    ui->label_5->setText("Event ID");
    ui->label_6->setText("Event Name");
    ui->label_7->setText("Event TYPE");
    ui->supp_E->setText("Delete");
    ui->Actualiser_E->setText("refresh");
    ui->ajout_E->setText("ADD");
    ui->Modif->setText("UPDATE");
}

void EvenmentPage::on_pushButton_3_clicked()
{
    ui->label->setText("ID EVENEMENT");
    ui->label_2->setText("NOM EVENEMENT");
    ui->label_3->setText("TYPE EVENEMENT");
    ui->label_5->setText("ID EVENEMENT");
    ui->label_6->setText("NOM EVENEMENT");
    ui->label_7->setText("TYPE EVENEMENT");
    ui->supp_E->setText("Supprimer");
    ui->Actualiser_E->setText("Actualiser");
    ui->ajout_E->setText("Ajouter");
    ui->Modif->setText("Modifier");
}
