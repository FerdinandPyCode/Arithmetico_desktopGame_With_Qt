#include "mabase.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include<QDebug>

MaBase::MaBase()
{
    connexionDb();
//    id=0;
//    pbleme="";
//    solut="";
//    niv="";
//    pseuonyme="";
}

void MaBase::connexionDb(){
      QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
      db.setDatabaseName("arithmeticodb.db");
      bool ok = db.open();
      if(ok){
         // QMessageBox::information(nullptr," Création de la base de donnée","Création reussite !!!");
          QSqlQuery q;

          QString r="CREATE TABLE IF NOT EXISTS Joueurs(Id_Joueur INTEGER PRIMARY KEY AUTOINCREMENT,\
                                                        pseudo VARCHAR(50))";
            q.exec(r);

//           if(q.exec(r)){
//              QMessageBox::information(nullptr,"Création de table Joueurs","Création reussite !!!");
//          }else{
//              QMessageBox::critical(nullptr,"Création de table Joueurs","Création echouée !!!"+q.lastError().text());
//          }

          r="CREATE TABLE IF NOT EXISTS Opérations(\
                  Id_Op INTEGER PRIMARY KEY AUTOINCREMENT,\
                  Id_Joueur INTEGER,\
                  niveau VARCHAR(50),\
                  probleme VARCHAR(50),\
                  reussite INTEGER,\
                  solution VARCHAR(50),\
                  duree INTEGER)";

                  q.exec(r);

//          if(q.exec(r)){
//             QMessageBox::information(nullptr," Création de table Operation","Création reussite !!!");
//         }else{
//             QMessageBox::critical(nullptr," Création de table Operation","Création echouée !!!"+q.lastError().text());
//         }


          r="CREATE TABLE IF NOT EXISTS Partie(\
                  Id_Joueur INTEGER,\
                  niveau VARCHAR(50),\
                  score INTEGER)";
            q.exec(r);

//          if(q.exec(r)){
//             QMessageBox::information(nullptr," Création de table Partie","Création reussite !!!");
//         }else{
//             QMessageBox::critical(nullptr," Création de table Partie","Création echouée !!!"+q.lastError().text());
//         }

    }
}

void MaBase::ajout_user(QString str){
    if(verifier_user(str)){
        //QMessageBox::information(nullptr,"Ajout à la base de donnée","Le joueur <strong>"+str+"</strong> existe déjà !!!");
    }else{
    QSqlQuery q;
    q.prepare("INSERT INTO Joueurs(pseudo) VALUES(?)");
    q.addBindValue(str);
    q.addBindValue(0);
    q.exec();
//    if(q.exec()){
//        q.first();
//        //QMessageBox::information(nullptr,"Ajout à la base de donnée","Ajout de "+str+" reussit !!!\nID:"+q.value(0).toString());
//    }else{
//        QMessageBox::critical(nullptr,"Ajout à la base de donnée","Ajout échoué !!!"+q.lastError().text());
//    }
    //On crée deux champs pour le joueur dans la table partie

     QString data=recuperer_user_id(str);
     enregistrer_partie(data.toInt(),"Facile",0);
     enregistrer_partie(data.toInt(),"Dificile",0);
  }

}

bool MaBase::verifier_user(QString str){
    QString r="SELECT * FROM Joueurs WHERE pseudo='"+str+"'";
    QSqlQuery q;
    q.exec(r);
    if(q.first()){
       //QMessageBox::information(nullptr,"Vérification de"+str,"Vérification reussite !!!");
       return true;
   }else{
       //QMessageBox::critical(nullptr,"Vérification de"+str,"Vérification echouée !!!"+q.lastError().text());
       return false;
   }
}

bool MaBase::enregistrer_operation(int Id_Joueur,QString niveau,QString probleme,QString solution,int duree,int reussite){
    QString r="INSERT INTO Opérations(Id_Joueur,niveau,probleme,solution,duree,reussite) VALUES(?,?,?,?,?,?)";
    QSqlQuery q;
    q.prepare(r);
    q.addBindValue(Id_Joueur);
    q.addBindValue(niveau);
    q.addBindValue(probleme);
    q.addBindValue(solution);
    q.addBindValue(duree);
    q.addBindValue(reussite);
    if(q.exec()){
        //QMessageBox::information(nullptr,"Insertion d'operation","Insertion reussite !!!");
        return true;
    }else{
        QMessageBox::critical(nullptr,"Insertion d'operation","Insertion echouée !!!"+q.lastError().text());
        return false;
    }
}

//A la creation d'un user on lui crée les deux niveaux qui seront update à chaque fin de partie

bool MaBase::enregistrer_partie(int Id_Joueur,QString niveau,int score){
    QString r="INSERT INTO Partie(Id_Joueur,niveau,score) VALUES(?,?,?)";
    QSqlQuery q;
    q.prepare(r);
    q.addBindValue(Id_Joueur);
    q.addBindValue(niveau);
    q.addBindValue(score);
    if(q.exec()){
        //QMessageBox::information(nullptr,"Insertion de partie"+QString::number(Id_Joueur),"Insertion reussite !!!");
        return true;
    }else{
        QMessageBox::critical(nullptr,"Insertion de partie"+QString::number(Id_Joueur),"Insertion echouée !!!"+q.lastError().text());
        return false;
    }
}

//Update d'un niveau if le score est mieux

void MaBase::update_partie(int Id_Joueur,QString niveau,int score){
    QString r="UPDATE Partie SET score=? WHERE Id_Joueur=? AND niveau=? AND score<?";
    QSqlQuery q;
    q.prepare(r);
    q.addBindValue(score);
    q.addBindValue(Id_Joueur);
    q.addBindValue(niveau);
    q.addBindValue(score);
    if(q.exec()){
       // QMessageBox::information(nullptr,"Update de partie","Update reussite !!!");

    }else{
        QMessageBox::critical(nullptr,"Update de partie","Update echouée !!!"+q.lastError().text());

    }
}


QString MaBase::recuperer_user_id(QString str){
    QString r="SELECT * FROM Joueurs WHERE pseudo='"+str+"'";
    QSqlQuery q;
    //q.prepare(r);
    //q.addBindValue(str);

    QString data="-1";

    if(q.exec(r)){
        q.first();
        data=q.value(0).toString();
       //QMessageBox::information(nullptr,"Récuperation"+str,"Récuperation reussite!!!\nID:"+data);

       return data;
   }else{
       QMessageBox::critical(nullptr,"Récuperation"+str,"Récuperation  echouée !!!"+q.lastError().text());
       return data;
   }
}
