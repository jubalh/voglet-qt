#include <QLabel>
#include <QRect>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->leWord->installEventFilter(this);
    ui->leTranslation->installEventFilter(this);
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
    this->entry = entry;
    if ( this->config )
    {
        this->lastDirection = this->config->getDirection();
        if (this->lastDirection== VOGLET_CONFIG_DIRECTION_BOTH)
        {
            int t = qrand() % 2;
            if (t==0)
                this->lastDirection = VOGLET_CONFIG_DIRECTION_TRANSLATION;
            else
               this->lastDirection = VOGLET_CONFIG_DIRECTION_WORD;
        }

        if (this->lastDirection == VOGLET_CONFIG_DIRECTION_TRANSLATION)
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

void MainWindow::compareInput(QLineEdit *edit, QString &text)
{
    if (edit->text().compare(text,Qt::CaseSensitive))
    {
        QRect rect;
        QLabel *lbl = new QLabel(this);

        rect.setX(edit->x() + edit->frameGeometry().width()+40);
        rect.setY(ui->leWord->y());
        rect.setWidth(50);
        rect.setHeight(20);
        lbl->setGeometry(rect);

        lbl->setText(text);
        lbl->setBuddy(edit);
        lbl->setStyleSheet("QLabel {color: red}");

        lbl->setVisible(true);
    }
    else
        this->close();
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        switch(keyEvent->key())
        {
        case Qt::Key_Escape:
            this->close();
            break;
        case Qt::Key_Enter:
        case Qt::Key_Return:
            if (this->lastDirection == VOGLET_CONFIG_DIRECTION_TRANSLATION)
                compareInput(ui->leWord, this->entry->word);
            else
                compareInput(ui->leTranslation, this->entry->translation);
            return true;
        }
    }
    return QMainWindow::eventFilter(object, event);
}
