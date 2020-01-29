/********************************************************************
** Author: Gabrielle Pang
** Date: May 29, 2019
** Description: This is the class for DayOfYear, it initializes
**              an array for the days in a normal year, and the
**              months in a year.
**              There are also 2 blank Exception classes for the 
**              main program to catch in the event that the user
**              inputs are out of range.
********************************************************************/
#ifndef DAYOFYEAR_HPP
#define DAYOFYEAR_HPP
#include <iostream>
#include <string>

class DayOfYear
{
private:
   int day;
   std::string month;
   int totNumOfDays;
public:
   int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   std::string Month[12] = {"January", "February", "March", "April",
   "May", "June", "July", "August", "September", "October",
   "November", "December"};
   int getTotDays();
   void setDayOfYear(int);
   void printday();
   bool checkValid(std::string, int);
   void calcDays(std::string, int);
   DayOfYear(std::string, int);
   DayOfYear operator++(int);
   DayOfYear operator--(int);
   class InvalidRange
   {
   };
   class InvalidDayMonth
   {
   };
};
#endif

