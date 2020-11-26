#include "history.h"

History::History(QWidget *parent) : QMainWindow(parent)
{

}

void History::addHistory(const std::string &elem)
{
    mHistory.append(elem+"\n");
}

std::string History::getHistory() const
{
    return mHistory;
}

void History::resetHistory()
{
    mHistory.clear();
}

