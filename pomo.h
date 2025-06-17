#ifndef POMO_H_
#define POMO_H_

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <iomanip>

enum class SessionType
{
    Work,
    ShortBreak,
    LongBreak
};

class  Pomodoro
{
private:
    int workDuration;
    int shortbreak;
    int Longbreak;
    int CompletedWorkSessions;
    int longInterval;
    SessionType currentSession;
    void runsession(int duration);
    void nextSession();

public:
    Pomodoro(int workdur = 25,int shortBreakDur = 5,int longbreakDur = 15,int longBreakInt = 4);

    void start(); 
    void pause();
    void resume();
    void stop();

    SessionType getCurrentSessionType() const {return currentSession;};
};



#endif
