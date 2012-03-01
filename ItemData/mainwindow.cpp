#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->horizontalLayout->addStrut(200);
    /*
    initComboBoxData();

    QObject::connect(ui->comboBox, SIGNAL(activated(int)),
                     this, SLOT(paintLabel(int)));
                     */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initComboBoxData()
{
    /*
    ui->comboBox->addItem("Happy", Qt::red);
    ui->comboBox->addItem("Excited", Qt::green);
    ui->comboBox->addItem("Cheerful", Qt::blue);
    */
}

void MainWindow::paintLabel(int colorIndex)
{
    /*
    QVariant color = ui->comboBox->itemData(colorIndex);
    ui->label->setStyleSheet(
                QString("background-color: %1").arg(color.toString()));
                */
}

