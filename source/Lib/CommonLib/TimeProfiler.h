
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <iostream>

#include <stack>
#include <array>
#include <vector>
#include <chrono>

enum STAGE {  
  QT_LEVEL_0 = 0,
  QT_LEVEL_1 = 1,
  QT_LEVEL_2 = 2,
  QT_LEVEL_3 = 3,
  QT_LEVEL_4 = 4,
  QT_LEVEL_5 = 5,
  INTER_OVERALL = 6,

  NUM_STAGES = 7
};

typedef std::milli rep;
typedef std::chrono::steady_clock clock_s;
typedef std::chrono::time_point<clock_s> time_point;
typedef std::chrono::duration<double, rep> duration;

class TimeProfiler {  

  private:
    static std::vector<time_point> previous;

  public:
    static std::vector<duration> durations;

    static void init();
    static void start( STAGE s );
    static void stop( STAGE s );
    static void report();
};