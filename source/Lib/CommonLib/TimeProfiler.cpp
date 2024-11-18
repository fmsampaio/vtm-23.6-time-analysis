#include "TimeProfiler.h"

std::vector<time_point> TimeProfiler::previous;
std::vector<duration> TimeProfiler::durations;

void TimeProfiler::init()  {
    durations.resize( NUM_STAGES );
    previous.resize( NUM_STAGES );
    for( size_t i = 0; i < NUM_STAGES; ++i ) {
        durations[i] = durations[i].zero();
    }
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
        std::cout << i << "\t" << (durations[i].count()) << std::endl;
    }
}