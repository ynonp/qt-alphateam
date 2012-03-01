#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class JSRock;

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
    void addCoolQtClassToJS(bool success);


private:
    Ui::MainWindow *ui;
    JSRock *m_rock;
};

#endif // MAINWINDOW_H
