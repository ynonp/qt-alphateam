#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mainToolBar->addAction(ui->actionOpen);
    ui->centralWidget->addAction(ui->actionOpen);
    ui->centralWidget->setContextMenuPolicy(Qt::ActionsContextMenu);

    ui->actionOpen->setEnabled(false);
    QObject::connect(ui->actionOpen, SIGNAL(triggered()),
                     this, SLOT(opeFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    QFileDialog::getOpenFileName();
}

