#include <QApplication>
#include "accueil.h"

#include "mainwindow.h"
#include <QDebug>

int main(int argc,char *argv[])
{
    QApplication a(argc,argv);

       MainWindow w;
//       int tab[] = {5,7,1,8,0};
//       w.shuffle_tab(tab,5);
    Accueil aa;
    aa.show();


    return a.exec();
}
