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
    auto start_time = std::chrono::high_resolution_clock::now();


    std::cout <<" (Time started)" << endl;


    while (true)
    {
        auto current_time = std::chrono::high_resolution_clock::now();
        auto elapsed_time = current_time - start_time;

        auto remaining_time_chrono = timer_duration_chrono - elapsed_time;

        if ( remaining_time_chrono  <= 0ms)
        {
            cout <<"\r" << string(30,' ') << "\r" << flush;
            std::cout << "Session duation ("<< duration_minutes <<" minutes) reached." << std::endl;
            break;
        }

        auto minutes = std::chrono::duration_cast<std::chrono::minutes>(remaining_time_chrono);
        auto seconds = std::chrono::duration_cast<std::chrono::seconds>(remaining_time_chrono - minutes);

        cout << "\r"
             << setw(2) << setfill('0') << minutes.count() << ":"
             << setw(2) << setfill('0') << seconds.count() << flush;

        std::this_thread::sleep_for(1s);
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto actual_elapsed_duration = end_time - start_time;
    auto actual_elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(actual_elapsed_duration);

    std::cout << "Session ended. Actual elapsed time: " << actual_elapsed_ms.count() <<"milliseconds." << std::endl;
    nextSession();
}


void  Pomodoro::startSession()
{
    int duration_minutes;
    std::string session_name;

    switch (getCurrentSessionType)
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




void  Pomodoro::determineNextSession()
{ 
    if (getCurrentSessionType == SessionType::Work)
    {
        CompletedWorkSessions++;
        if ( CompletedWorkSessions % longInterval == 0 ){
           getCurrentSessionType = SessionType::LongBreak;
        }else{
            getCurrentSessionTypen =  SessionType::ShortBreak;
        }   
    }
    else if ( getCurrentSessionType ==  SessionType::ShortBreak){
        getCurrentSessionTypen = SessionType::Work;
    }else if ( getCurrentSessionType == SessionType::LongBreak){
        CompletedWorkSessions = 0;
        getCurrentSessionType = SessionType::Work;
    }
}

void Pomodoro::pause()
{

}

void Pomodoro::resume()
{

}

void Pomodoro::stop()
{

}