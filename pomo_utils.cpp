#include "pomo.h";
#include <chrono>
#include <thread>
#include <chrono>



using namespace std::chrono_literals;
using namespace std;

enum SessionType {
    Work_Session,
    Short_break,
    long_break
};

SessionType current_session_type = Work_Session;
int  Session_Counter;

void  start(SessionType type)
{
    int duration_minutes;
    std::string session_name;

    switch (type){
        case Work_Session:
            duration_minutes = 25;
            session_name = "Work session";
            break;
        case Short_break:
            duration_minutes = 15;
            session_name = "Short Break";
            break;
        case long_break:
            duration_minutes = 15;
            session_name = "Long break";
            break;
    }
    std::cout <<"\nstring "<< session_name << " for " << duration_minutes << "minutes." << std::endl;
    runsession(duration_minutes,session_name );


}

void runsession(int duration_minutes,std::string session_name)
{

    const auto timer_duration_chrono = std::chrono::minutes(duration_minutes);
    std::string current_session = session_name;
    
    auto start_time = std::chrono::high_resolution_clock::now();
    std::cout << "Session started for " << duration_minutes << "minutes." << std::endl;

    while (true){
        auto current_time = std::chrono::high_resolution_clock::now();
        auto elapsed_time = current_time - start_time;

        if ( elapsed_time >= timer_duration_chrono){
            std::cout << "Session duation ("<<duration_minutes <<"minutes) reached." << std::endl;

            break;
        }
    }
    auto end_time = std::chrono::high_resolution_clock::now();

    auto actual_elapsed_duration = end_time - start_time;

    auto actual_elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(actual_elapsed_duration);

    std::cout << "Session ended. Actual elapsed time: " << actual_elapsed_ms.count() <<"milliseconds." << std::endl;
    nextSession(current_session);
}

void nextSession(){ 
    if (current_session_type == Work_Session){
        Session_Counter++;
        if ( Session_Counter % 4 == 0 ){
            current_session_type = long_break;
        }else{
            current_session_type =  Short_break;
        }
        
    }else if (current_session_type == Short_break){
        current_session_type = Work_Session;
    }else if (current_session_type == long_break){
        Session_Counter = 0;
        current_session_type = Work_Session;
    }
    start(current_session_type);
}

void pause()
{

}

void resume()
{

}

void stop()
{

}