#ifndef GAMEBRIDGE_H
#define GAMEBRIDGE_H

#include <QObject>
#include <QtGui>
#include <QList>
#include <QVariantMap>
#include <QVariantList>

class GameBridge : public QObject
{
    Q_OBJECT
public:
    explicit GameBridge(QObject *parent = 0);

signals:
    void show_card(int, int, QPixmap);
    void hide_cards_array(QVariantList cards);

public slots:
    void card_selected(int row, int col);

public:
    void hideCard(int x, int y);

};

#endif // GAMEBRIDGE_H
