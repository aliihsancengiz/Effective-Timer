#include "clock.h"

Clock::Clock()
{

}

QString Clock::update(uint32_t timerValue)
{

    int min=(int)(timerValue/60);
    int second=timerValue-min*60;
    QTime  mTimeObj(min,second);
    return mTimeObj.toString("hh:mm");

}
