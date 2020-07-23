#include <QPainter>
#include <QPoint>

#include "randomviewer.h"

RandomViewer::RandomViewer(QSize s, QWidget *parent) :
    QFrame(parent)
{
    setFixedSize(s);
    setFrameStyle(QFrame::Box);
    pen.setColor(Qt::white);

    pixmap = QPixmap(size());
    pixmap.fill(Qt::black);
}

void RandomViewer::addPoint(QPoint p)
{
    QPainter painter(&pixmap);
    painter.setPen(pen);
    painter.drawPoint(p);
    update();
}

void RandomViewer::clear()
{
    pixmap.fill(Qt::black);
}

void RandomViewer::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(0, 0, pixmap);
    QFrame::paintEvent(event);
}
