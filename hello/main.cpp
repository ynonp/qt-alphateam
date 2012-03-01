#include <QtGui>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QPushButton btn("Hello");
    btn.show();

    return app.exec();
}
