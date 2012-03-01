#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->actionAbout,
                     SIGNAL(triggered()),
                     this,
                     SLOT(about()));

    QObject::connect(ui->actionQuit,
                     SIGNAL(triggered()),
                     this,
                     SLOT(quit()));

    QObject::connect(ui->actionOpen,
                     SIGNAL(triggered()),
                     this,
                     SLOT(openFile()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::openFile()
{
    QString filename = QFileDialog::getOpenFileName();
    QFile f(filename);

    if ( f.open(QIODevice::ReadOnly) )
    {
        QTextStream s(&f);
        QString text = s.readAll();
        ui->plainTextEdit->setPlainText(text);
    }
    else
    {
        qDebug() << "Failed to open file";
    }

}

void MainWindow::saveFile()
{
}

void MainWindow::quit()
{
    qApp->quit();
}

void MainWindow::about()
{
    QMessageBox::about(this, "About Me", "Zombie Apocallipse is here. HIDE OR ...");
}
