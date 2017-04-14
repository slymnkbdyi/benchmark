#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //LoadSettings();
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::SaveSettings()
{
    QSettings     setting("MyCompany","MyApp");
    setting.beginGroup("MainWindow");
    setting.setValue("position",this->geometry());
    setting.endGroup();
    qDebug() << "Saved"
}
void Dialog::LoadSettings()
{
    QSettings     setting("MyCompany","MyApp");
    setting.beginGroup("MainWindow");
    QRect myrect = setting.value("position").toRect();
    setGeometry(myrect);
    setting.endGroup();
    qDebug() << "Loaded.";

}
void Dialog::on_pushButton_clicked()
{

    SaveSettings();
}

void Dialog::on_pushButton_2_clicked()
{
    LoadSettings();
}
