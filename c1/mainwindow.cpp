#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myjs.h"
#include <QWebFrame>
#include <QWebPage>
#include <QtWebKit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    my_js = new MyJS(this);

    QString url("file://%1/html/index.html");
    ui->webView->setUrl(QUrl(url.arg(QApplication::applicationDirPath())));
    QObject::connect(this->ui->webView, SIGNAL(loadFinished(bool)),
                     this, SLOT(initWebview()));

    ui->webView->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initWebview()
{
    ui->webView->page()->mainFrame()->addToJavaScriptWindowObject("qt", my_js);
    QWebInspector *inspector = new QWebInspector();
    inspector->setPage(ui->webView->page());
    inspector->show();
}

