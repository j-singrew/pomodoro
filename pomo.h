#ifndef POMO_H_
#define POMO_H_

#include <iostream>
enum class SessionType
{
    Work,
    ShortBreak,
    LongBreak
}
class  Pomodoro
{
private:
    int workDuration;
    int shortbreak;
    int Longbreak;
    int CompletedWorkSessions;
    int longInterval;
    SessionType currentSession;
public:
    Pomodoro(int workdu = 25,int shortBreakDur = 5,int longbreakDur = 15,int longBreakInt = 4);

    void start();
    void runsession(int duration);
    void nextSession();
    void pause();
    void resume();
    void stop();

    SessionType getCurrentSessionType() const {return currentSession}
}



#endif
