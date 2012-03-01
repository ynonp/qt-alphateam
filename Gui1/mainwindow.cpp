#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QColor color = QColorDialog::getColor();
    ui->label->setText(color.name());
    QString style("background-color: %1");

    ui->label->setStyleSheet(style.arg(color.name()));

}






