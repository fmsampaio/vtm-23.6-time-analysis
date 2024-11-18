#include "TimeProfiler.h"

std::vector<time_point> TimeProfiler::previous;
std::vector<duration> TimeProfiler::durations;
std::map<STAGE, std::string> TimeProfiler::stageToString;

void TimeProfiler::init()  {
    durations.resize( NUM_STAGES );
    previous.resize( NUM_STAGES );
    
    for( size_t i = 0; i < NUM_STAGES; ++i ) {
        durations[i] = durations[i].zero();
    }

    stageToString[QT_LEVEL_0]= "QT_0";
    stageToString[QT_LEVEL_1] = "QT_1";
    stageToString[QT_LEVEL_2] = "QT_2";
    stageToString[QT_LEVEL_3] = "QT_3";
    stageToString[QT_LEVEL_4] = "QT_4";
    stageToString[INTER_OVERALL] = "INTER";
    stageToString[ENCODER_OVERALL] ="ENCODER";
}

void TimeProfiler::start( STAGE s ) {
    previous[s] = clock_s::now();
}

void TimeProfiler::stop( STAGE s ) {
    time_point now = clock_s::now();
    durations[s] += ( now - previous[s] );
}

void TimeProfiler::report() {
    std::cout << "\n\nTIME PROFILING REPORT" << std::endl;
    std::cout << "STAGE\tTime(ms)\n";
    for( size_t i = 0; i < NUM_STAGES; ++i ) {
        STAGE s = (STAGE) i;
        std::cout << stageToString[s] << "\t" << (durations[i].count()) << std::endl;
    }
}