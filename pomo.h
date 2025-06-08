#ifndef POMO_H_
#define POMO_H_

#include <iostream>
enum class SessionType
{
    Work,
    ShortBreak,
    LongBreak,
};

class  PomodoroSession
{
private:
    int duration;
    int shortbreak;
    int longbreak;
    int completedWorkSessions;
    int longBreakSetting;
    SessionType currentSession;
public:
    PomodoroSession();
    void start();
    void runsession(int duration);
    void nextSession();
    void pause();
    void  resume();
    void stop();
};

#endif
