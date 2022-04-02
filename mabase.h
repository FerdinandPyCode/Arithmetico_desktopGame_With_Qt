#ifndef MABASE_H
#define MABASE_H
#include <QSqlDatabase>
#include <QString>
#include <QVector>

class MaBase
{
public:
    void connexionDb();
    void ajout_user(QString pseudo);
    QString recuperer_user_id(QString str);
    bool verifier_user(QString q);
    bool enregistrer_operation(int Id_Joueur,QString niveau,QString probleme,QString solution,int duree,int reussite);
    bool enregistrer_partie(int Id_Joueur,QString niveau,int score);
    void update_partie(int Id_Joueur,QString niveau,int score);

    MaBase();
};

#endif // MABASE_H

