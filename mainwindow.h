#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include "clock.h"
#include "history.h"
#include "form.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
        void UpdateTimerTimeOut();
        void addButtonClicked();
        void startButtonClicked();
        void resetButtonClicked();
        void stopButtonClicked();
        void clearButtonClicked();
        void showButtonClicked();

private:
        Ui::MainWindow *ui;
        QTimer* pTimer;
        Clock mClock;
        History mHist;
        bool started=0;
        static long long TimeCounter;
        static uint32_t QuestionCounter;
        uint32_t Delta=0,prev=0;
        Form* pStatForm;

};

#endif // MAINWINDOW_H
