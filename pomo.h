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
    bool isPaused = false;
    std::chrono::high_resolution_clock::time_point sessionStartTime;
    std::chrono::duration<double> elapsedSessionTime;


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
    bool getIsRunning() const {return isRunning;}
    bool getIsPaused() const{return isPaused;}
};

#endif
