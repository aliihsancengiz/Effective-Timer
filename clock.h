#ifndef CLOCK_H
#define CLOCK_H

#include <QString>
#include <QDateTime>
#include <cstdint>

class Clock
{
    public:
        Clock();
        QString update(uint32_t timerValue);
};

#endif // CLOCK_H
