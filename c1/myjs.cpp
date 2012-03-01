#include "myjs.h"
#include <QPixmap>
#include <QFileDialog>
#include <QDebug>

MyJS::MyJS(QObject *parent) :
    QObject(parent)
{
}

QPixmap MyJS::loadImage()
{
    QString fname = QFileDialog::getOpenFileName(0, "Select Image", QString(), "*.png");
    qDebug() << "Selected: " << fname;

    return QPixmap(fname);
}
