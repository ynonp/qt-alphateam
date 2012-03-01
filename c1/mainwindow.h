#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class MyJS;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void initWebview();
private:
    Ui::MainWindow *ui;
    MyJS *my_js;
};

#endif // MAINWINDOW_H
