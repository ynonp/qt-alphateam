#include <QtGui>

#include <QtGui/QPushButton>
#include <QtGui/QApplication>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget w;
    QLabel *l = new QLabel("Hello World", &w);

       w.show();

    return app.exec();
}
