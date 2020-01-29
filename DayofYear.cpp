/********************************************************************
** Author: Gabrielle Pang
** Date: May 29, 2019
** Description: This is the implementation of the Day of Year class.
********************************************************************/
#include "DayofYear.hpp"
#include <string>
#include <iostream>

/********************************************************************
 * Description: This method takes in the user inputted number of 
 *              days in a year. Throws a InvalidRange exception
 *              if the number is not between 1 and 365
********************************************************************/
void DayOfYear::setDayOfYear(int num)
{
   if (num < 1 || num > 365)
   {
      throw DayOfYear::InvalidRange();
   }
   else
   {
      totNumOfDays = num;
      int index = 0;
      while (num > daysPerMonth[index])
      {
         num = num - daysPerMonth[index];
         index++;
      }
      month = Month[index];
      day = num;
   }
}

/********************************************************************
 * Description: This is the DayOfYear constructor. It takes in
 *              the users input of a month and day and sets the
 *              variables. If the month or day is invalid it 
 *              throws a InvalidDayMonth exception.
********************************************************************/
DayOfYear::DayOfYear(std::string mon, int date)
{

   if(checkValid(mon, date))
   {
      day = date;
      month = mon;
      calcDays(mon, date);
   }
   else
   {
      throw DayOfYear::InvalidDayMonth();
   }
}

/********************************************************************
 * Description: This is the operation overloading function for ++
 *              that deals with the case when the total Number of
 *              Days is over 366. In that case it loops back around
 *              to 1.
********************************************************************/
DayOfYear DayOfYear::operator++(int)
{
   totNumOfDays++;
   if (totNumOfDays == 366)
   {
      totNumOfDays = 1;
   }
   this->setDayOfYear(totNumOfDays);
   return *this;
}

/********************************************************************
 * Description: This is the operation overloading function for --
 *              that deals with the case when the total Number of
 *              Days goes to 0. In that case it loops back around
 *              to 365.
********************************************************************/
DayOfYear DayOfYear::operator--(int)
{
   totNumOfDays--;
   if (totNumOfDays == 0)
   {
      totNumOfDays = 365;
   }
   this->setDayOfYear(totNumOfDays);
   return *this;
}

/********************************************************************
 * Description: This is a function to print the day in the format
 *              of month date,(e.g. January 1)
********************************************************************/
void DayOfYear::printday()
{
   std::cout << month << " " << day << ".";
}

/********************************************************************
 * Description: This function figures out the conversion between
 *              Month and day to total number of days and sets 
 *              the total number of days to it the calculated result
********************************************************************/
void DayOfYear::calcDays(std::string mon, int date)
{
   int index = 0;
   int totDays = 0;
   while (mon != Month[index])
   {
      totDays += daysPerMonth[index];
      index++;
   }
   totDays += date;
   totNumOfDays = totDays;
}

/********************************************************************
 * Description: This function checks whether the user inputted a 
 *              valid month and day by comparing it to the arrays
 *              initialized in the Day Of Year class.
********************************************************************/
bool DayOfYear::checkValid(std::string mon, int date)
{
   int index = -1;
   for (int i = 0; i < 12; i++)
   {
      if (mon == Month[i])
      {
         index = i;
      }
   }
   if (index == -1)
   {
      return false;
   }
   else
   {
      if (date > daysPerMonth[index] || date < 1)
      {
         return false;
      }
      else
      {
         return true;
      }
   }
}

/********************************************************************
 * Description: This method gets the total number of days and 
 *              passes it so the user can see the total days in 
 *              the console.
********************************************************************/
int DayOfYear::getTotDays()
{
   return totNumOfDays;
}



                           
                                        
