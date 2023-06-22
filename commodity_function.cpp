//
// Created by wangh on 2023/6/22.
//
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "menu.h"
#include "config.h"
using namespace std;

string GetcurTime()    // 获取当前时间
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    string curTime = to_string(1900 + ltm->tm_year) + "-" +
                        to_string(1 + ltm->tm_mon) + "-" +
                        to_string(ltm->tm_mday) +" " +
                        to_string(ltm->tm_hour) + ":" +
                        to_string(ltm->tm_min) + ":" +
                        to_string(ltm->tm_sec);
    return curTime;
}