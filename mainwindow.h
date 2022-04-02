#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QTimer>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);

    void shuffle_tab(int* tab,int taille);

    void commencer();
    void evoluer(int phase,int score);
    void finir(int score);
    void definir_temps();
    void generateur();
    void remplir_case(QString str);
    void clear_button();
    void clear_button_high(QString str);
    bool verifier_partie();
    bool verifier_champs();
    bool verifier_calcul();
    void recuper_infos_jeu(int id,QString pseud,QString niv);
    //void shuffle_tab(int* tab,int taille);


    //Accueil* myacc;

    ~MainWindow();

private slots:
    void on_pushButton_valider_clicked();

    void on_pushButton_passer_clicked();

    void on_pushButton_op_1_clicked();

    void on_pushButton_op_2_clicked();

    void on_pushButton_op_3_clicked();

    void on_pushButton_op_4_clicked();

    void on_pushButton_signe_1_clicked();

    void on_pushButton_op_5_clicked();

    void on_pushButton_signe_2_clicked();

    void on_pushButton_signe_3_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_result_clicked();

    void on_pushButton_retour_menu_clicked();

public slots:

    void time_slot();

private:
    Ui::MainWindow *ui;
};
static QString operation;
static int my_id=0;
static QString pseudonyme;
static QString pbleme;
static QString solut;
static QString my_niv;
#endif // MAINWINDOW_H
