#include "aide.h"
#include "ui_aide.h"
#include "accueil.h"

Aide::Aide(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Aide)
{
    ui->setupUi(this);
}

Aide::~Aide()
{
    delete ui;
}

void Aide::on_pushButton_clicked()
{
    Accueil* myac;
    myac = new Accueil();
    this->hide();
    myac->show();

}

