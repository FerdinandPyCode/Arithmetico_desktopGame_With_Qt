#ifndef MEILLEURSCORE_H
#define MEILLEURSCORE_H

#include <QMainWindow>

namespace Ui {
class MeilleurScore;
}

class MeilleurScore : public QMainWindow
{
    Q_OBJECT

public:
    explicit MeilleurScore(QWidget *parent = 0);
    void afficher_f();
    void afficher_d();
    ~MeilleurScore();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MeilleurScore *ui;
};

#endif // MEILLEURSCORE_H
