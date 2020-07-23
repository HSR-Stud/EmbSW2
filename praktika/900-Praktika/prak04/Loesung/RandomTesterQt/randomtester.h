#ifndef RANDOMTESTER_H
#define RANDOMTESTER_H

#include <QMainWindow>
#include <QTimer>

#include <randomviewer.h>

namespace Ui {
class RandomTester;
}

class RandomTester : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief RandomTester Ctor
     * @param parent Parent
     */
    explicit RandomTester(QWidget *parent = 0);

    /**
      * @brief ~RandomTester Dtor
      */
    ~RandomTester();

public slots:
    /**
     * @brief onTimeout Draws a new random point
     */
    void onTimeout();

    /**
     * @brief onStartStopClicked Starts / stops the timer
     */
    void onStartStopClicked();

    /**
     * @brief onRadioClicked Select if the system random generator or
     * the equation r_i+1 = (a * r_i + c) mod m is used to generate the random values.
     */
    void onRadioClicked();

private:
    bool validateParameters();
    void invalidateParameters();

    enum RandomSource
    {
        srcSystem,
        srcModulo
    };

    Ui::RandomTester *ui;
    RandomViewer* viewer; /// RandomViewer to draw the random points on the pixmap
    QTimer* timer;

    RandomSource randomSrc;

    int xLim; /// x limit of the RandomViewer pixmap
    int yLim; /// y limit of the RandomViewer pixmap

    int x;
    int y;

    bool first;

    /// r = (a * r + c) mod m
    long factor; /// a
    long r; /// r
    long increment; /// c
    long modulus; /// m
};

#endif // RANDOMTESTER_H
