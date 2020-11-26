#ifndef HISTORY_H
#define HISTORY_H

#include <QMainWindow>
#include <string>


class History : public QMainWindow
{
    Q_OBJECT
    public:
        explicit History(QWidget *parent = nullptr);
        void addHistory(const std::string& elem);
        std::string getHistory() const;
        void resetHistory();
    signals:

    private:
        std::string mHistory;

};

#endif // HISTORY_H
