/********************************************************************
** Author: Gabrielle Pang
** Date: May 29, 2019
** Description: This is the main program of DayofYear. It prompts
**              the user for option 1 or 2. Option 1 prompts the 
**              user for a number between 1 and 365 and converts
**              it to a date (e.g. February 1). Option 2 prompts the
**              user for a month and day and converts it to the
**              number of days in a year. Then provides the user
**              with the day before and the day after.
********************************************************************/
#include <iostream>
#include "DayofYear.hpp"
#include <string>

int main()
{
   int option = 0;
   int numOp1 = 0;
   std::string mon = "";
   std::cout << "Please choose an option (1 or 2): " << std::endl;
   std::cin >> option;
   if (option == 1)
   {
      std::cout << "This program converts a day given by a number 1 ";
      std::cout << "through 365 into a month and a day.";
      std::cout << std::endl;
      std::cout << "Enter a number: ";
      std::cin >> numOp1;
      try
      {
         DayOfYear obj("January", 1);
         obj.setDayOfYear(numOp1);
         obj.printday();
         std::cout << std::endl;
         obj--;
         std::cout << "The day before is ";
         obj.printday();
         std::cout << std::endl;
         obj++;
         obj++;
         std::cout << "The day after is ";
         obj.printday();
      }
      catch (DayOfYear::InvalidRange)
      {
         std::cout << "Invalid range for a day.";
         return -1;
      }
   }
   else
   {
      std::cout << "This program converts a month and day of month ";
      std::cout << "into a day of the year in the range 1...365.";
      std::cout << std::endl;
      std::cout << "Enter month and day (Example: January 3): ";
      std::cin >> mon >> numOp1;
      try
      {
         DayOfYear obj(mon, numOp1);
         std::cout << "It is day " << obj.getTotDays() << ".";
         std::cout << std::endl;
         obj--;
         std::cout << "The day before is ";
         obj.printday();
         std::cout << std::endl;
         obj++;
         obj++;
         std::cout << "The day after is ";
         obj.printday();
      }
      catch (DayOfYear::InvalidDayMonth)
      {
         std::cout << "Incorrect name or day of month.";
         return -1;
      }
   }
   return 0;
}

