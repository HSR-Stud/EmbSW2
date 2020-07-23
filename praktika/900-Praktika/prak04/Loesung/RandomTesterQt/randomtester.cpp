#include <QTime>

#include "randomtester.h"
#include "ui_randomtester.h"

RandomTester::RandomTester(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RandomTester),
    viewer(new RandomViewer),
    randomSrc(srcModulo),
    first(true)
{
    ui->setupUi(this);

    switch (randomSrc)
    {
    case srcSystem:
        ui->radioSystem->setChecked(true);
        ui->radioModulo->setChecked(false);
        break;
    default:
    case srcModulo:
        ui->radioSystem->setChecked(false);
        ui->radioModulo->setChecked(true);
        break;
    }
    onRadioClicked();   // invoke function to update group box enabling

    timer = new QTimer();
    timer->setInterval(10);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));

    // Initalize graphics window
    ui->centralWidget->layout()->addWidget(viewer);

    xLim = viewer->size().width();
    yLim = viewer->size().height();

    // Initialize system random
    qsrand(QDateTime::currentDateTime().toMSecsSinceEpoch());

    connect(ui->btnStartStop, SIGNAL(clicked()), this, SLOT(onStartStopClicked()));
    connect(ui->radioSystem, SIGNAL(clicked()), this, SLOT(onRadioClicked()));
    connect(ui->radioModulo, SIGNAL(clicked()), this, SLOT(onRadioClicked()));
}

RandomTester::~RandomTester()
{
    if (timer->isActive())
        timer->stop();

    delete ui;
    delete timer;
    delete viewer;
}

void RandomTester::onTimeout()
{
    x = y;
    switch (randomSrc)
    {
    case srcSystem:
        y = (1.0 * qrand() / RAND_MAX) * yLim;
        break;
    default:
    case srcModulo:
        r = (factor * r + increment) % modulus;
        y = static_cast<int>(r) * yLim / modulus;
        break;
    }
    if (!first)
        viewer->addPoint(QPoint(x, y));
    first = false;
}

void RandomTester::onStartStopClicked()
{
    if (timer->isActive())
    {
        timer->stop();
        ui->btnStartStop->setText("Start");
        if (ui->radioModulo->isChecked())
            ui->gbParameters->setEnabled(true);
        ui->gbSource->setEnabled(true);
    }
    else
    {
        if (validateParameters())
        {
            viewer->clear();
            first = true;
            timer->start();
            ui->btnStartStop->setText("Stop");
            ui->gbSource->setEnabled(false);
            ui->gbParameters->setEnabled(false);
        }
    }
}

void RandomTester::onRadioClicked()
{
    if (ui->radioSystem->isChecked())
    {
        ui->gbParameters->setEnabled(false);
        randomSrc = srcSystem;
    }
    else if (ui->radioModulo->isChecked())
    {
        ui->gbParameters->setEnabled(true);
        randomSrc = srcModulo;
    }
}

bool RandomTester::validateParameters()
{
    bool res;
    bool resAll = true;

    invalidateParameters();

    factor = ui->leFactor->text().toInt(&res);
    if (!res)
    {
        ui->leFactor->setStyleSheet("background-color: red;");
        resAll = false;
    }

    r = ui->leSeed->text().toInt(&res);
    if (!res)
    {
        ui->leSeed->setStyleSheet("background-color: red;");
        resAll = false;
    }

    increment = ui->leIncrement->text().toInt(&res);
    if (!res)
    {
        ui->leIncrement->setStyleSheet("background-color: red;");
        resAll = false;
    }

    modulus = ui->leModulus->text().toInt(&res);
    if (!res)
    {
        ui->leModulus->setStyleSheet("background-color: red;");
        resAll = false;
    }

    return resAll;
}

void RandomTester::invalidateParameters()
{
    ui->leFactor->setStyleSheet("");
    ui->leSeed->setStyleSheet("");
    ui->leIncrement->setStyleSheet("");
    ui->leModulus->setStyleSheet("");
}
