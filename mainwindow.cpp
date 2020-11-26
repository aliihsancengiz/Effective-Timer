#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pTimer=new QTimer(this);

    connect(pTimer,SIGNAL(timeout()),this,SLOT(UpdateTimerTimeOut()));
    connect(ui->addHistory,SIGNAL(clicked()),this,SLOT(addButtonClicked()));
    connect(ui->Startbutton,SIGNAL(clicked()),this,SLOT(startButtonClicked()));
    connect(ui->StopButton,SIGNAL(clicked()),this,SLOT(stopButtonClicked()));
    connect(ui->ResetButton,SIGNAL(clicked()),this,SLOT(resetButtonClicked()));
    connect(ui->clearButton,SIGNAL(clicked()),this,SLOT(clearButtonClicked()));
    connect(ui->showButton,SIGNAL(clicked()),this,SLOT(showButtonClicked()));

    pStatForm = new Form();
    pStatForm->hide();

    pTimer->start(1000);

}

long long MainWindow::TimeCounter=0;
uint32_t MainWindow::QuestionCounter=0;

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateTimerTimeOut()
{
    if(started)
    {
        ui->LCDDisplay->display(mClock.update(TimeCounter++));
    }

}

void MainWindow::addButtonClicked()
{
    if(started)
    {
        Delta=TimeCounter-prev;
        prev=TimeCounter;
        mHist.addHistory("Question"+std::to_string(QuestionCounter++)+" Solved in "+std::to_string(Delta)+" seconds");
        ui->textBrowser->clear();
        QString temp(mHist.getHistory().c_str());
        ui->textBrowser->setText(temp);
    }
}

void MainWindow::startButtonClicked()
{
    started=1;
}

void MainWindow::resetButtonClicked()
{
    TimeCounter=0;
    prev=0;
}

void MainWindow::stopButtonClicked()
{
    started=0;
}

void MainWindow::clearButtonClicked()
{
    ui->textBrowser->clear();
    mHist.resetHistory();
    QuestionCounter=0;

}

void MainWindow::showButtonClicked()
{
    pStatForm->setTotalTimeElapsed(TimeCounter);
    pStatForm->setsolvedQuestion(QuestionCounter);
    pStatForm->setQuestionPerTime((float)((float)TimeCounter/(float)QuestionCounter));
    pStatForm->show();

//    this->hide();
}


