#include <QtGui>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget w;

    QLabel *l1 = new QLabel("Greetings, Earthlings");
    QLabel *l2 = new QLabel("Take me to your leader");
    QLabel *l3 = new QLabel("ALL YOUR BASE BELONGS TO US");

    QVBoxLayout *layout = new QVBoxLayout(&w);
    layout->addWidget(l1);
    layout->addWidget(l2);
    layout->addWidget(l3);

    w.show();

    return app.exec();
}
