#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    void setsolvedQuestion(const uint32_t num)const;
    void setQuestionPerTime(const double num)const;
    void setTotalTimeElapsed(const uint32_t num)const;
private:
    Ui::Form *ui;
};

#endif // FORM_H
