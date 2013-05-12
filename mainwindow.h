#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    CConfig *config;
};

#endif // MAINWINDOW_H
