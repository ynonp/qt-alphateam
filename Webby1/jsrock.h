#ifndef JSROCK_H
#define JSROCK_H

#include <QObject>
#include <QtCore>

class JSRock : public QObject
{
    Q_OBJECT
public:
    explicit JSRock(QObject *parent = 0);

    Q_INVOKABLE int zombieApocalipse();


signals:
    void scream(QStringList zombieNames);
    void fight_is_over(QVariantMap result);

public slots:
    void shout();

};

#endif // JSROCK_H
