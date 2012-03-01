#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jsrock.h"

#include <QtWebKit>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->webView->setUrl(QUrl("file:///Users/ynonperek/tmp/qt/alphateam/Webby1/app.html"));

    m_rock = new JSRock(this);

    QObject::connect(ui->webView,
                     SIGNAL(loadFinished(bool)),
                     this,
                     SLOT(addCoolQtClassToJS(bool)));

    QObject::connect(ui->pushButton,
                     SIGNAL(clicked()),
                     m_rock,
                     SLOT(shout()));

    ui->webView->page()->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addCoolQtClassToJS(bool success)
{
    ui->webView->page()->mainFrame()->addToJavaScriptWindowObject("qt", m_rock);
    ui->webView->page()->mainFrame()->evaluateJavaScript("init();");

    QWebInspector *inspector = new QWebInspector();
    inspector->setPage(ui->webView->page());
    inspector->show();
}

