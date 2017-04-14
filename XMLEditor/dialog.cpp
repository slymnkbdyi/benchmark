#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    Filename = "C:/Users/dtsis/Desktop/a.xml";
    model = new QStandardItemModel(0,1,this);
    ReadFile();
    ui->treeView->setModel(model);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::ReadFile()
{
    QStandardItem *root = new QStandardItem("AFC");
    model->appendRow(root);
    QDomDocument document;


    //LOAD FILE

    QFile file(Filename);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        document.setContent(&file);
        file.close();
    }



    QDomElement xmlroot = document.firstChildElement();
    QDomNodeList books = xmlroot.elementsByTagName("Info");
    for(int i =0 ;i<books.count();i++)
    {
        QDomElement book = books.at(i).toElement();
        QStandardItem *bookitem = new QStandardItem(book.attribute("prodGroupId"));



    // Read the Chapters of the book

     QDomNodeList chapters  = book.elementsByTagName("prodDetailId");
     for(int h=0;h<chapters.count();h++)
     {
            QDomElement chapter = chapters.at(h).toElement();
            QStandardItem *chapteritem = new QStandardItem(chapter.attribute("passProdNm"));
            bookitem->appendRow(chapteritem);
     }
     root->appendRow(bookitem);





    }










}

void Dialog::WriteFile()
{

}

void Dialog::on_pushButton_clicked()
{
    // save document
}
