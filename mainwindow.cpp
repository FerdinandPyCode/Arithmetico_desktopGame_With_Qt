#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <QtCore>
#include <QTimer>
#include <QJSEngine>
#include "accueil.h"
#include "mabase.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(time_slot()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::commencer(){
    //QString pseudo="Ferdi225";
    //QString niveau="Facile";//Facile ou Dificile
    int phase=1;
    int score=0;
    int time=0;

    ui->label_niveau->setText(my_niv);
    ui->label_phase->setText(QString::number(phase));
    ui->label_pseudo->setText(pseudonyme);
    ui->label_score->setText(QString::number(score));
    ui->label_time->setText(QString::number(time));

}

void MainWindow::on_pushButton_valider_clicked()
{
    QString sphase=ui->label_phase->text();
    int phase=sphase.toInt();
    QString stime=ui->label_time->text();
    int time = stime.toInt();
    int n_score=0;
    bool reussie=false;

    if(!verifier_champs()){
        QMessageBox::critical(this,"Erreur de validation","Veuillez remplir tous les champs svp !");
    }else{
        if(!verifier_calcul()){
            QMessageBox::critical(nullptr,"Résultat de partie","Erreur de calcul !!!.\nVous avez mal faire les opérations !\nVous avez perdu !!! :)\
                                    \nRésultat donné: "+operation+"\nRésultat attendu :"+pbleme);
            n_score=0;
        }else{
            if(time<=10){
                n_score=10;
            }else if(time<20){
                n_score=5;
            }else{
                n_score=2;
            }
            reussie = true;
            QString msg="Youppiiiii vous avez reussi la partie !\nPoint Gagné :"+QString::number(n_score)+"\nTemps de jeu:"+QString::number(time);
            QMessageBox::information(this,"Résultat de partie",msg);
        }


        MaBase base;
        base.enregistrer_operation(my_id,my_niv,pbleme,operation,time,(reussie)?1:0);

        if(phase<5){
            evoluer(phase,n_score);
        }else if (phase==5) {
            finir(n_score);
        }
        clear_button();
        ui->label_time->setText("0");
    }
}

void MainWindow::on_pushButton_passer_clicked()
{
    QString sphase=ui->label_phase->text();
    int phase=sphase.toInt();

    QString stime=ui->label_time->text();
    int time=stime.toInt();

    MaBase base;
    base.enregistrer_operation(my_id,my_niv,pbleme,"",time,0);

    if(phase<5){
        evoluer(phase,0);
    }else if (phase==5) {
        finir(0);
    }
    clear_button();
    ui->label_time->setText("0");

}

void MainWindow::evoluer(int phase,int n_score){
    QString sscore=ui->label_score->text();
    int score = sscore.toInt();
    phase++;
    score+=n_score;
    ui->label_score->setText(QString::number(score));
    ui->label_phase->setText(QString::number(phase));
    generateur();
}

void MainWindow::finir(int n_score){
    QString sscore=ui->label_score->text();
    int score = sscore.toInt();
    score+=n_score;
    QString msg="Vous êtes à la fin du jeu .\nVotre score est de "+QString::number(score)+"\nVeuillez cliquez OK pour repartir au menu !";
    ui->label_score->setText(QString::number(score));


    MaBase base;
    base.update_partie(my_id,my_niv,score);

   if (QMessageBox::Yes == QMessageBox(QMessageBox::Information,"Fin de partie","Voulez-vous recommencer le jeu ?", QMessageBox::Yes|QMessageBox::No).exec())
   {
       commencer();
       generateur();
   }else{
       Accueil* myacc;
       myacc = new Accueil();
       this->hide();
       myacc->show();
   }
}



bool MainWindow::verifier_champs(){
    if(ui->pushButton_1->text().isEmpty() || \
        ui->pushButton_2->text().isEmpty()|| \
        ui->pushButton_3->text().isEmpty()|| \
        ui->pushButton_4->text().isEmpty()|| \
        ui->pushButton_5->text().isEmpty()|| \
        ui->pushButton_6->text().isEmpty()|| \
        ui->pushButton_7->text().isEmpty()|| \
        ui->pushButton_result->text().isEmpty()){

       return false;
    }else {
        return true;
    }
}

bool MainWindow::verifier_calcul(){

 QString text1=ui->pushButton_1->text();
 QString text2=ui->pushButton_2->text();
 QString text3=ui->pushButton_3->text();
 QString text4=ui->pushButton_4->text();
 QString text5=ui->pushButton_5->text();
 QString text6=ui->pushButton_6->text();
 QString text7=ui->pushButton_7->text();

 QString x=text1+text2+text3+text4+text5+text6+text7;

 operation=x;
 //ui->label_pseudo->setText(x);
 QString textresultat=ui->pushButton_result->text();

// QJSEngine myEngine;
// QJSValue three = myEngine.evaluate("1 + 2+8*1");

// QScriptEngine myEngine;

// QScriptValue x2 = myEngine.evaluate(x);

 QJSEngine myEngine;
 QJSValue x2 = myEngine.evaluate(x);

 operation+="="+textresultat;

 if(x2.toString()==textresultat){
     return true;
 }else{
     return false;
 }

}

void MainWindow::generateur(){

    QString niveau=ui->label_niveau->text();
    int tab_valeur[4];
    int tab_opera[3];
    for(int i=0;i<4;i++){
        tab_valeur[i]= qrand() % ((20 + 1) - 0) + 0;
        if(i<3 and niveau=="Facile"){

           tab_opera[i]= qrand() % ((1 + 1) - 0) + 0;


        }else if(i<3 and niveau=="Dificile"){
            tab_opera[i]= qrand() % ((2 + 1) - 0) + 0;
        }
    }

    //Formatage de la chaine des operations sous forme de chaine de caractère

    int j=0;
    int k=0;
    QString x;
    for(int i=0;i<7;i++){
        if(i==0 || i==2 || i==4 || i==6){
            x+=QString::number(tab_valeur[j]);
            j++;
        }else{
            if(tab_opera[k]==0){
                x+="+";
            }else if(tab_opera[k]==1){
                x+="-";
            }else if(tab_opera[k]==2){
                x+="*";
            }
            k++;
        }
    }

    //Script qui prendra en paramètre une chaine de caractère avec les différents paramètres et nous permettra de recuperer le résultat;
    pbleme=x;

    // QJSEngine myEngine;
    // QJSValue three = myEngine.evaluate("1 + 2+8*1");

    QJSEngine myEngine;
    QJSValue x2 = myEngine.evaluate(x);

    pbleme+="="+x2.toString();



    //Melange des boutons générés+++++++++++++++++++++++++++++++++++++++++++++++++++

    //shuffle_tab(tab_valeur,5);




    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


    for(int i=0;i<3;i++){
            if(i==0){
                if(tab_opera[i]==0){
                    ui->pushButton_signe_3->setText("+");
                }else if(tab_opera[i]==1){
                    ui->pushButton_signe_3->setText("-");
                }else if(tab_opera[i]==2){
                    ui->pushButton_signe_3->setText("*");
                }
            }else if(i==1){
                if(tab_opera[i]==0){
                    ui->pushButton_signe_1->setText("+");
                }else if(tab_opera[i]==1){
                    ui->pushButton_signe_1->setText("-");
                }else if(tab_opera[i]==2){
                    ui->pushButton_signe_1->setText("*");
                }
            }else if(i==2){
                if(tab_opera[i]==0){
                    ui->pushButton_signe_2->setText("+");
                }else if(tab_opera[i]==1){
                    ui->pushButton_signe_2->setText("-");
                }else if(tab_opera[i]==2){
                    ui->pushButton_signe_2->setText("*");
                }
            }
    }

    ui->pushButton_op_1->setText(QString::number(x2.toInt()));

    ui->pushButton_op_2->setText(QString::number(tab_valeur[0]));
    ui->pushButton_op_3->setText(QString::number(tab_valeur[1]));
    ui->pushButton_op_4->setText(QString::number(tab_valeur[2]));
    ui->pushButton_op_5->setText(QString::number(tab_valeur[3]));
}

void MainWindow::remplir_case(QString str){

    QString text1=ui->pushButton_1->text();
    QString text2=ui->pushButton_2->text();
    QString text3=ui->pushButton_3->text();
    QString text4=ui->pushButton_4->text();
    QString text5=ui->pushButton_5->text();
    QString text6=ui->pushButton_6->text();
    QString text7=ui->pushButton_7->text();
    QString text8=ui->pushButton_result->text();
    if(text1==""){
        ui->pushButton_1->setText(str);
        ui->pushButton_1->setStyleSheet("background-color:rgb(53, 132, 228);color:rgb(255, 255, 255);border-radius:15;");
    }else if(text2==""){
        ui->pushButton_2->setText(str);
        ui->pushButton_2->setStyleSheet("background-color:rgb(53, 132, 228);color:rgb(255, 255, 255);border-radius:15;");
    }else if(text3==""){
        ui->pushButton_3->setText(str);
        ui->pushButton_3->setStyleSheet("background-color:rgb(53, 132, 228);color:rgb(255, 255, 255);border-radius:15;");
    }else if(text4==""){
        ui->pushButton_4->setText(str);
        ui->pushButton_4->setStyleSheet("background-color:rgb(53, 132, 228);color:rgb(255, 255, 255);border-radius:15;");
    }else if(text5==""){
        ui->pushButton_5->setText(str);
        ui->pushButton_5->setStyleSheet("background-color:rgb(53, 132, 228);color:rgb(255, 255, 255);border-radius:15;");
    }else if(text6==""){
        ui->pushButton_6->setText(str);
        ui->pushButton_6->setStyleSheet("background-color:rgb(53, 132, 228);color:rgb(255, 255, 255);border-radius:15;");
    }else if(text7==""){
        ui->pushButton_7->setText(str);
        ui->pushButton_7->setStyleSheet("background-color:rgb(53, 132, 228);color:rgb(255, 255, 255);border-radius:15;");
    }else if(text8==""){
        ui->pushButton_result->setText(str);
        ui->pushButton_result->setStyleSheet("background-color:rgb(53, 132, 228);color:rgb(255, 255, 255);border-radius:15;");
    }
}

void MainWindow::on_pushButton_op_1_clicked()
{
    QString text1=ui->pushButton_op_1->text();
    ui->pushButton_op_1->hide();
    remplir_case(text1);
}

void MainWindow::on_pushButton_op_2_clicked()
{
    QString text1=ui->pushButton_op_2->text();
    ui->pushButton_op_2->hide();
    remplir_case(text1);
}

void MainWindow::on_pushButton_op_3_clicked()
{
    QString text1=ui->pushButton_op_3->text();
    ui->pushButton_op_3->hide();
    remplir_case(text1);
}

void MainWindow::on_pushButton_op_4_clicked()
{
    QString text1=ui->pushButton_op_4->text();
    ui->pushButton_op_4->hide();
    remplir_case(text1);
}

void MainWindow::on_pushButton_signe_1_clicked()
{
    QString text1=ui->pushButton_signe_1->text();
    ui->pushButton_signe_1->hide();
    remplir_case(text1);
}

void MainWindow::on_pushButton_op_5_clicked()
{
    QString text1=ui->pushButton_op_5->text();
    ui->pushButton_op_5->hide();
    remplir_case(text1);
}


void MainWindow::on_pushButton_signe_2_clicked()
{
    QString text1=ui->pushButton_signe_2->text();
    ui->pushButton_signe_2->hide();
    remplir_case(text1);
}

void MainWindow::on_pushButton_signe_3_clicked()
{
    QString text1=ui->pushButton_signe_3->text();
    ui->pushButton_signe_3->hide();
    remplir_case(text1);
}

void MainWindow::clear_button(){
    ui->pushButton_1->setText("");
    ui->pushButton_1->setStyleSheet("border:2px solid rgb(98, 160, 234);border-radius:15;");
    ui->pushButton_2->setText("");
    ui->pushButton_2->setStyleSheet("border:2px solid rgb(98, 160, 234);border-radius:15;");
    ui->pushButton_3->setText("");
    ui->pushButton_3->setStyleSheet("border:2px solid rgb(98, 160, 234);border-radius:15;");
    ui->pushButton_4->setText("");
    ui->pushButton_4->setStyleSheet("border:2px solid rgb(98, 160, 234);border-radius:15;");
    ui->pushButton_5->setText("");
    ui->pushButton_5->setStyleSheet("border:2px solid rgb(98, 160, 234);border-radius:15;");
    ui->pushButton_6->setText("");
    ui->pushButton_6->setStyleSheet("border:2px solid rgb(98, 160, 234);border-radius:15;");
    ui->pushButton_7->setText("");
    ui->pushButton_7->setStyleSheet("border:2px solid rgb(98, 160, 234);border-radius:15;");
    ui->pushButton_result->setText("");
    ui->pushButton_result->setStyleSheet("border:2px solid rgb(98, 160, 234);border-radius:15;");

    ui->pushButton_op_1->show();
    ui->pushButton_op_2->show();
    ui->pushButton_op_3->show();
    ui->pushButton_op_4->show();
    ui->pushButton_op_5->show();
    ui->pushButton_signe_1->show();
    ui->pushButton_signe_2->show();
    ui->pushButton_signe_3->show();
}
void MainWindow::clear_button_high(QString str){
    if(ui->pushButton_op_1->isHidden() && ui->pushButton_op_1->text()==str){
        ui->pushButton_op_1->show();
    }else if(ui->pushButton_op_2->isHidden() && ui->pushButton_op_2->text()==str){
        ui->pushButton_op_2->show();
    }else if(ui->pushButton_op_3->isHidden() && ui->pushButton_op_3->text()==str){
        ui->pushButton_op_3->show();
    }else if(ui->pushButton_op_4->isHidden() && ui->pushButton_op_4->text()==str){
        ui->pushButton_op_4->show();
    }else if(ui->pushButton_op_5->isHidden() && ui->pushButton_op_5->text()==str){
        ui->pushButton_op_5->show();
    }else if(ui->pushButton_signe_1->isHidden() && ui->pushButton_signe_1->text()==str){
        ui->pushButton_signe_1->show();
    }else if(ui->pushButton_signe_2->isHidden() && ui->pushButton_signe_2->text()==str){
        ui->pushButton_signe_2->show();
    }else if(ui->pushButton_signe_3->isHidden() && ui->pushButton_signe_3->text()==str){
        ui->pushButton_signe_3->show();
    }
}

void MainWindow::on_pushButton_1_clicked()
{
    if(ui->pushButton_1->text()!=""){

        ui->pushButton_1->setStyleSheet("border:2px solid rgb(98, 160, 234);border-radius:15;");
        clear_button_high(ui->pushButton_1->text());
        ui->pushButton_1->setText("");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->pushButton_2->text()!=""){

        ui->pushButton_2->setStyleSheet("border:2px solid rgb(98, 160, 234);border-radius:15;");
        clear_button_high(ui->pushButton_2->text());
        ui->pushButton_2->setText("");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(ui->pushButton_3->text()!=""){

        ui->pushButton_3->setStyleSheet("border:2px solid rgb(98, 160, 234);border-radius:15;");
        clear_button_high(ui->pushButton_3->text());
        ui->pushButton_3->setText("");
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(ui->pushButton_4->text()!=""){

        ui->pushButton_4->setStyleSheet("border:2px solid rgb(98, 160, 234);border-radius:15;");
        clear_button_high(ui->pushButton_4->text());
        ui->pushButton_4->setText("");
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if(ui->pushButton_5->text()!=""){

        ui->pushButton_5->setStyleSheet("border:2px solid rgb(98, 160, 234);border-radius:15;");
        clear_button_high(ui->pushButton_5->text());
        ui->pushButton_5->setText("");
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    if(ui->pushButton_6->text()!=""){

        ui->pushButton_6->setStyleSheet("border:2px solid rgb(98, 160, 234);border-radius:15;");
        clear_button_high(ui->pushButton_6->text());
        ui->pushButton_6->setText("");
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    if(ui->pushButton_7->text()!=""){

        ui->pushButton_7->setStyleSheet("border:2px solid rgb(98, 160, 234);border-radius:15;");
        clear_button_high(ui->pushButton_7->text());
        ui->pushButton_7->setText("");
    }
}

void MainWindow::on_pushButton_result_clicked()
{
    if(ui->pushButton_result->text()!=""){

        ui->pushButton_result->setStyleSheet("border:2px solid rgb(98, 160, 234);border-radius:15;");
        clear_button_high(ui->pushButton_result->text());
        ui->pushButton_result->setText("");
    }
}

void MainWindow::time_slot(){

    QString stime = ui->label_time->text();
    int time=stime.toInt();
    time++;
    ui->label_time->setText(QString::number(time));
}

void MainWindow::on_pushButton_retour_menu_clicked()
{
    Accueil* myacc;
    myacc = new Accueil();
    this->hide();
    myacc->show();
}

void MainWindow::recuper_infos_jeu(int id,QString pseud,QString niv){
    my_id=id;
    pseudonyme=pseud;
    my_niv=niv;
}

void MainWindow::shuffle_tab(int* tab,int taille){

    int tab1[taille];
    QVector<int> index;

    for(int i=0;i<taille;i++){
        tab1[i]= *(tab+i);
    }

    for(int i=0;i<taille;i++){

        bool verifier=false;

        while(verifier==false){
            int a= qrand() % (((taille-1) + 1) - 0) + 0;
            qDebug()<<a;

            if(index.length()==0){
                verifier=true;
                index.push_back(a);
            }else{
                bool yes=false;
                for(int j=0;j<index.length();j++){
                    if(index[j]==a){
                        yes=true;
                    }
                }

                if(yes==true){
                    verifier=false;
                }else{
                    verifier=true;
                    index.push_back(a);
                }
            }
      }
    }

    for(int i=0;i<taille;i++){
        *(tab+i) = tab1[index[i]];
    }

}
