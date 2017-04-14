#include "dialog.h"
#include <QApplication>
#include<QMediaPlayer>
#include<QVideoWidget>
#include<QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Dialog w;
    // w.show();
   QMediaPlayer* player = new QMediaPlayer;
   QVideoWidget* vw = new QVideoWidget;
   player->setVideoOutput(vw);
   player->setMedia(QUrl::fromLocalFile("//C://Users//dtsis//Desktop//vi.mpg"));
   vw->setGeometry(100,100,300,400);
   vw->show();
   player->play();
   qDebug() << player->state();

    return a.exec();
}
