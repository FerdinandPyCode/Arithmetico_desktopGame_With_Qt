#include "meilleurscore.h"
#include "ui_meilleurscore.h"
#include "accueil.h"
#include <QTableView>
#include "mabase.h"
#include <QSqlQuery>
#include <QSqlQueryModel>

MeilleurScore::MeilleurScore(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MeilleurScore)
{
    ui->setupUi(this);
    afficher_d();
    afficher_f();
}

MeilleurScore::~MeilleurScore()
{
    delete ui;
}

void MeilleurScore::on_pushButton_clicked()
{
    Accueil* accueil;
    accueil = new Accueil();
    this->hide();
    accueil->show();
}

void MeilleurScore::afficher_d(){
    MaBase base;
    QSqlQueryModel* model = new QSqlQueryModel();

    QString r="SELECT pseudo,score FROM Partie INNER JOIN Joueurs on Partie.Id_Joueur=Joueurs.Id_Joueur WHERE niveau=? ORDER BY score DESC LIMIT 10";
    QSqlQuery q;

    q.prepare(r);
    q.addBindValue("Dificile");
    q.exec();

    model->setQuery(q);
    ui->tableView_dificile->setModel(model);
}

void MeilleurScore::afficher_f(){
    MaBase base;
    QSqlQueryModel* model = new QSqlQueryModel();

    QString r="SELECT pseudo,score FROM Partie INNER JOIN Joueurs on Partie.Id_Joueur=Joueurs.Id_Joueur WHERE niveau=? ORDER BY score DESC LIMIT 10";
    QSqlQuery q;

    q.prepare(r);
    q.addBindValue("Facile");
    q.exec();

    model->setQuery(q);
    ui->tableView_facile->columnWidth(800);
    ui->tableView_facile->rowHeight(200);
    ui->tableView_facile->setModel(model);
}
