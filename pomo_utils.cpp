#include "pomo.h"



using namespace std::chrono_literals;
using namespace std;



Pomodoro:: Pomodoro(int  workDur,int shortBreakDur,int longbreakDur,int longBreakInt)
        : workDuration(workDur),
          shortbreakDuration(shortBreakDur),
          LongbreakDuration(longbreakDur),
          CompletedWorkSessions(0),
          longInterval(longBreakInt),
          currentSessionType(SessionType::Work)
{

};

void Pomodoro::runTimer(int duration_minutes)
{
    const auto timer_duration_chrono = std::chrono::minutes(duration_minutes);

    if (!isPaused){
        sessionStartTime = std::chrono::high_resolution_clock::now();
        elapsedSessionTime = std::chrono::duration<double>::zero();
    }else{
        elapsedSessionTime = std::chrono::duration_cast<std::chrono::high_resolution_clock::duration>(elapsedSessionTime);
        sessionStartTime = std::chrono::high_resolution_clock::now() - elapsedSessionTime;
        isPaused = false;
    }
    isRunning = true;
    std::cout <<" (Time started)" << endl;


    while (isRunning)
    {

        if (isPaused)
        {
            std::this_thread::sleep_for(100ms);
            continue;
        }

        auto current_time = std::chrono::high_resolution_clock::now();
        auto elapsed_time = current_time - sessionStartTime;

        elapsedSessionTime = elapsed_time;
        auto remaining_time = timer_duration_chrono - elapsed_time;
        
        if (remaining_time <= 0ms)
        {
            std::cout <<"\r" <<std::string(30,' ') << "\r" <<std::flush;
            std::cout << "Session duration("<<duration_minutes <<"minutes) reached." << std::endl;
        }
    }
}


void  Pomodoro::startSession()
{
    if (isRunning){
        std::cout << "\nA session is already running. Please pause or stop it first." << std::endl;
        return;
    }

    int duration_minutes;
    std::string session_name;
    switch (getCurrentSessionType())
        {   
            case SessionType::Work:
                duration_minutes = workDuration;
                session_name = "Work session";
                break;
            case SessionType::ShortBreak:
                duration_minutes = shortbreakDuration;
                session_name = "Short Break";
                break;
            case SessionType::LongBreak:
                duration_minutes = LongbreakDuration;
                session_name = "Long break";
                break;
            default:
                duration_minutes = 0;
                session_name = "Unknown. Session Type";
                cerr << "Error:Uknown. SessionTyp encountered in startSession!" << endl;
                return;
        }
    

        std::cout <<"\nstring "<< session_name << " for " << duration_minutes << "minutes." << std::endl;
        runTimer(duration_minutes);
    }





void Pomodoro::determineNextSession()
{

    if (currentSessionType == SessionType::Work)
    {
        CompletedWorkSessions++;
        if (CompletedWorkSessions % longInterval == 0)
        {
            currentSessionType = SessionType::LongBreak; 
        }
        else
        {
            currentSessionType = SessionType::ShortBreak; 
        }
    }

    else if (currentSessionType == SessionType::ShortBreak)
    {
        currentSessionType = SessionType::Work;
    }

    else if (currentSessionType == SessionType::LongBreak)
    {
        CompletedWorkSessions = 0; 
        currentSessionType = SessionType::Work; 
    }
}


void Pomodoro::pause()
{
    if(isRunning && !isPaused){
        isPaused =true;
        std::cout << "\nTimer paused." << std::endl;
    }else if(isPaused){
        std::cout << "\nTimer is already paused." << std::endl;
    }else{
        std::cout << "\nTimer is not running, nothing to pause." << std::endl;
    }
}

void Pomodoro::resume()
{
    if(isRunning && isPaused){
        isPaused = false;
        std::cout <<"\nTimer Resumed." << std::endl;
    }else if (!isRunning){
        std::cout << "\nTimer is not running, cannot resume." << std::endl;
    }else{
        std::cout << "\nTimer is already running." << std::endl;
    }
}

void Pomodoro::stop()
{
    if (isRunning) {
        isRunning = false; 
        isPaused = false; 
        elapsedSessionTime = std::chrono::duration<double>::zero();
        std::cout << "\nTimer Stopped." << std::endl;
    } else {
        std::cout << "\nTimer is not running, nothing to stop." << std::endl;
    }


}