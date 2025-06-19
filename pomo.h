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
    int shortbreakDuration;
    int LongbreakDuration;
    int CompletedWorkSessions;
    int longInterval;
    bool isRunning = false;
    SessionType currentSessionType;

    void runTimer(int duration);
    void determineNextSession();

public:

    Pomodoro(int workdur = 25,int shortBreakDur = 5,int longBreakDur = 15,int longBreakInt = 4);

    void startSession(); 
    void pause();
    void resume();
    void stop();

    SessionType getCurrentSessionType() const {return currentSessionType;};
};

#endif
