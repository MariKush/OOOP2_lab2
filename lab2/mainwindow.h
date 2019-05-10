#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <gtest/gtest.h>

#include "naturalNumberAlgorithms/naturalui.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Masha_BTN_clicked();

private:
    Ui::MainWindow *ui;
    NaturalUI * natural;

    FRIEND_TEST(mainwindow, natural);
};

#endif // MAINWINDOW_H
