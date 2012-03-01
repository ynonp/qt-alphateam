#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton,
                     SIGNAL(clicked()),
                     this,
                     SLOT(selectFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectFile()
{
    QString selected = QFileDialog::getOpenFileName();
    qDebug() << selected;
}

