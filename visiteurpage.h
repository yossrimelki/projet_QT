#ifndef VISITEURPAGE_H
#define VISITEURPAGE_H

#include <QWidget>
#include <visiteur.h>
#include <QString>
#include <QMessageBox>
#include <iostream>

namespace Ui {
class VisiteurPage;
}

class VisiteurPage : public QWidget
{
    Q_OBJECT

public:
    explicit VisiteurPage(QWidget *parent = nullptr);
    ~VisiteurPage();

private slots:

    void on_AJOUT_V_clicked();

    void on_Actualiser_clicked();

    void on_Supprimer_V_clicked();

    void on_Modifier_V_clicked();

    void on_convPDF_clicked();

    void on_Recherche_V_clicked();

    void on_Tri_V_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::VisiteurPage *ui;
    Visiteur  Vi;
};

#endif // VISITEURPAGE_H
