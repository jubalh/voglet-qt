#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->config = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setConfig(CConfig *config)
{
    this->config = config;
}

void MainWindow::setWord(CEntry *entry)
{
    ui->leWord->setText(entry->word);
    ui->leWord->setEnabled(false);
    ui->leTranslation->setFocus();
    ui->leTranslation->setEnabled(true);
}

void MainWindow::setTranslation(CEntry *entry)
{
    ui->leTranslation->setText(entry->translation);
    ui->leTranslation->setEnabled(false);
    ui->leWord->setFocus();
    ui->leWord->setEnabled(true);
}

void MainWindow::setEntry(CEntry *entry)
{
    if ( this->config )
    {
        VOGLET_CONFIG_DIRECTION direction = this->config->getDirection();
        if (direction == VOGLET_CONFIG_DIRECTION_BOTH)
        {
            int t = qrand() % 2;
            if (t==0)
                direction = VOGLET_CONFIG_DIRECTION_TRANSLATION;
            else
                direction = VOGLET_CONFIG_DIRECTION_WORD;
        }

        if (direction == VOGLET_CONFIG_DIRECTION_TRANSLATION)
            this->setTranslation(entry);
        else
            this->setWord(entry);
    }
    else
    {
        ui->leWord->setText(entry->word);
        ui->leTranslation->setText(entry->translation);
    }
}
