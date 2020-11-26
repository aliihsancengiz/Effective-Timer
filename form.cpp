#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::setsolvedQuestion(const uint32_t num) const
{
    this->ui->lineEdit->setText(QString::number(num));
}

void Form::setQuestionPerTime(const double num) const
{
    this->ui->lineEdit_2->setText(QString::number(num));
}

void Form::setTotalTimeElapsed(const uint32_t num) const
{
    this->ui->lineEdit_3->setText(QString::number(num));
}
