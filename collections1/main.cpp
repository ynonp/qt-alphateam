#include <QtCore/QCoreApplication>
#include <QtCore>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> list;
    list << "a" << "B" << "c";

    qDebug() << list.at(2);
    qDebug() << list[1];

    return a.exec();
}
