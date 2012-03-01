#ifndef MYJS_H
#define MYJS_H

#include <QObject>
#include <QPixmap>

class MyJS : public QObject
{
    Q_OBJECT
public:
    explicit MyJS(QObject *parent = 0);

Q_INVOKABLE QPixmap loadImage();

signals:

public slots:

};

#endif // MYJS_H
