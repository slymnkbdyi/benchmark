#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);


    connect(player,&QMediaPlayer::positionChanged,this,&Dialog::on_positionChanged);
    connect(player,&QMediaPlayer::durationChanged,this,&Dialog::on_durationChanged);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_sliderProgress_sliderMoved(int position)
{
  player->setPosition(position);
}

void Dialog::on_sliderVolume_sliderMoved(int position)
{
    player->setVolume(position);
}

void Dialog::on_pushButton_clicked()
{


    // Load File

    player->setMedia(QUrl::fromLocalFile("//C://Users/dtsis//Desktop//se.mp3"));
    player->play();
    qDebug() << player->errorString();




}

void Dialog::on_pushButton_2_clicked()
{
   player->stop();
}

void Dialog::on_durationChanged(quint64 position)
{
   ui->sliderProgress->setMaximum(position);
}

void Dialog::on_positionChanged(quint64 position)
{

    ui->sliderProgress->setValue(position);
}
