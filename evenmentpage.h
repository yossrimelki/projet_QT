#ifndef EVENMENTPAGE_H
#define EVENMENTPAGE_H

#include <QWidget>
#include <evenement.h>
#include <QMessageBox>
namespace Ui {
class EvenmentPage;
}

class EvenmentPage : public QWidget
{
    Q_OBJECT

public:
    explicit EvenmentPage(QWidget *parent = nullptr);
    ~EvenmentPage();

private slots:
    void on_Actualiser_E_clicked();

    void on_supp_E_clicked();

    void on_ajout_E_clicked();

    void on_Modif_clicked();

    void on_pushButton_clicked();

    void on_rech_e_clicked();

    void on_tri_E_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::EvenmentPage *ui;
    Evenement Ev;
};

#endif // EVENMENTPAGE_H
