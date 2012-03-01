#include "jsrock.h"
#include <QtCore>

JSRock::JSRock(QObject *parent) :
    QObject(parent)
{
}

int JSRock::zombieApocalipse()
{
    return 666;
}

void JSRock::shout()
{
    /*
    QStringList zombies;
    zombies << "Bob" << "Mike" << "Alice" << "Carol";
    emit scream(zombies);
    */

    QVariantMap results;
    results["humans"] = 29;
    results["zombies"] = 19;
    emit fight_is_over(results);
}

