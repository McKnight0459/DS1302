#include <stdio.h>
#include <DS1302.h>
const int RST   = 6;  //等同于CE
const int DAT   = 7;  //等同于IO
const int CLK = 8;  //等同于SCLK
DS1302 rtc(RST, DAT, CLK);

String dayAsString(const Time::Day day) {
  switch (day) {
    case Time::kSunday: return "Sunday";
    case Time::kMonday: return "Monday";
    case Time::kTuesday: return "Tuesday";
    case Time::kWednesday: return "Wednesday";
    case Time::kThursday: return "Thursday";
    case Time::kFriday: return "Friday";
    case Time::kSaturday: return "Saturday";
  }
  return "(unknown day)";
}

void printTime() {
  Time t = rtc.time();
  const String day = dayAsString(t.day);
  char buf[50];
  snprintf(buf, sizeof(buf), "%s %04d-%02d-%02d %02d:%02d:%02d",
           day.c_str(),
           t.yr, t.mon, t.date, t.hr, t.min, t.sec);//时间输出格式
  Serial.println(buf);
}

void setup() {
  Serial.begin(9600);
  rtc.writeProtect(false);
  rtc.halt(false);

  Time t(2016, 11, 8, 14, 48, 40, Time::kTuesday); // Sunday, September 22, 2013 at 01:38:50.
  //rtc.time(t);//初始化时间
}
void loop() {
  printTime();
  delay(1000);
}
