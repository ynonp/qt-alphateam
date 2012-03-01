#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label->setText(tr("Hello"));

    QSignalMapper *mapper = new QSignalMapper(this);

    mapper->setMapping(ui->pushButton, "Darth is the best evil master in the galaxy");
    mapper->setMapping(ui->pushButton_2, "Luke");
    mapper->setMapping(ui->pushButton_3, "Lia");

    QObject::connect(ui->pushButton, SIGNAL(clicked()),
                     mapper, SLOT(map()));

    QObject::connect(ui->pushButton_2, SIGNAL(clicked()),
                     mapper, SLOT(map()));

    QObject::connect(ui->pushButton_3, SIGNAL(clicked()),
                     mapper, SLOT(map()));

    QObject::connect(mapper, SIGNAL(mapped(QString)),
                     this, SLOT(addNameToTextbox(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addNameToTextbox(QString text)
{
    ui->textEdit->append(text);
}

