#include "accueil.h"
#include "ui_accueil.h"
#include "aide.h"
#include "meilleurscore.h"
#include "mainwindow.h"
#include "mabase.h"
#include <QMessageBox>

Accueil::Accueil(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Accueil)
{
    ui->setupUi(this);
}

Accueil::~Accueil()
{
    delete ui;
}

void Accueil::on_pushButton_3_clicked()
{
    QString pseudo=ui->lineEdit_pseudo->text();
    QString myniv=ui->comboBox_niveau->currentText();
    if(pseudo.isEmpty()){
        ui->label_infos->setText("Veuillez remplir le champs pseudo :)");
    }else{
        MaBase base;
        bool verifier=false;

        if(base.verifier_user(pseudo)){
            if(ui->comboBox_status->currentText()=="Nouveau"){
                ui->label_infos->setText("Ce pseudo existe dejà ::\nVeuillez changer de pseudo ou \nchoisir ancien pour continuer avec l'ancien compte");
            }else{
                verifier=true;
            }
        }else{
            if(ui->comboBox_status->currentText()=="Ancien"){
                ui->label_infos->setText("Ce pseudo n'existe pas dans notre base :)\nVeuillez changer de pseudo ou \nchoisir nouveau pour creer un new compte");
            }else{
                base.ajout_user(pseudo);
                verifier=true;
            }
        }
        if(verifier){
            QMessageBox::information(this,"Démarrage du jeu Arithmético","<br>Votre jeu demarrera dès que vous cliquez OK<br>Veuillez cliquer sur les nombres pour les déplacer dans les deux sens bas vers haut et haut vers bas! ");

            MainWindow* w;
            w = new MainWindow();
            QString myId=base.recuperer_user_id(pseudo);
            w->recuper_infos_jeu(myId.toInt(),pseudo,myniv);
            w->commencer();
            w->generateur();
            this->hide();
            w->show();
        }
    }

}

void Accueil::on_pushButton_5_clicked()
{
    Aide* myaide;
    myaide = new Aide();
    this->hide();
    myaide->show();
}

void Accueil::on_pushButton_4_clicked()
{
    MeilleurScore* m;
    m = new MeilleurScore();
    this->hide();
    m->show();
}
