#ifndef RANDOMVIEWER_H
#define RANDOMVIEWER_H

#include <QFrame>
#include <QPixmap>
#include <QSize>
#include <QPen>

class RandomViewer : public QFrame
{
    Q_OBJECT
public:
    /**
     * @brief RandomViewer Ctor
     * @param s Size of the pixmap
     * @param parent Parent
     */
    explicit RandomViewer(QSize s = QSize(600, 600), QWidget *parent = 0);

    /**
     * @brief addPoint Draws the point in the pixmap
     * @param p Point to draw
     */
    void addPoint(QPoint p);

    /**
     * @brief clear Clears the pixmap
     */
    void clear();

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *);

private:
    QPen pen;
    QPixmap pixmap;
};

#endif // RANDOMVIEWER_H
