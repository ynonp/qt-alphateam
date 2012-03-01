#include "gamebridge.h"
#include <QDebug>

GameBridge::GameBridge(QObject *parent) :
    QObject(parent)
{
}

void GameBridge::card_selected(int row, int col)
{
    qDebug() << "User clicked";
}

void GameBridge::hideCard(int x, int y)
{
    QVariantMap cardDetails;
    cardDetails["row"] = x;
    cardDetails["col"] = y;

    QVariantList cards;
    cards << cardDetails;

    emit hide_cards_array(cards);
}
