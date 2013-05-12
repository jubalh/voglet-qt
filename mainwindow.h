#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QLineEdit>
#include "entry.h"
#include "config.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setEntry(CEntry *entry);
    void setConfig(CConfig *config);
private:
    Ui::MainWindow *ui;
    CEntry *entry;
    CConfig *config;
    VOGLET_CONFIG_DIRECTION lastDirection;
    void setTranslation(CEntry *entry);
    void setWord(CEntry *entry);
    void compareInput(QLineEdit *edit, QString &text);
    bool eventFilter(QObject *object, QEvent *event);
};

#endif // MAINWINDOW_H
