#pragma once
#pragma warning(disable : 4996) 
#include<ctime> 
#include <vector>
#include <iostream>
#include <string>
#include<iomanip>
#include "clsString.h"
class clsDraw {
public:
	static string generateLine(short length = 0, char symbol = '_') {
		string line = "";
		while (length != 0) {
			line += symbol;
			length--;
		}
		return line;
	};
	static string generateTabs(short length = 0) {
		string tabs = "";
		while (length != 0) {
			tabs += " ";
			length--;
		}
		return tabs;
	};
};
class clsDate
{
private:
	short _day = 0, _month = 0, _year = 0;
public:
	short getThisYear() {
		time_t t = time(0);
		tm* now = localtime(&t);
		return now->tm_year + 1900;
	}
	short getThisMonth() {
		time_t t = time(0);
		tm* now = localtime(&t);
		return now->tm_mon + 1;
	};
	short getThisDay() {
		time_t t = time(0);   //
		tm* now = localtime(&t);
		return  now->tm_mday;
	};
	short getThisHour() {
		time_t t = time(0);   //
		tm* now = localtime(&t);
		return now->tm_hour;
	};
	void print() {
		cout << _day << "/" << _month << "/" << _year;
	};
	bool isLeapYear(short year) {
		return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
	};
	short countDaysInMonth(short year, short month) {
		if (month < 1 || month > 12) return 0;
		short days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		return (month == 2) ? (isLeapYear(year) ? 29 : 28) : days[month];
	};
	bool isValidDate(clsDate date) {
		return(date._month >= 1 && date._month <= 12 &&
			date._day >= 1 && date._day <= countDaysInMonth(date._year, date._month));
	};
	bool isLastDayInMonth(clsDate date) {
		return date._day == countDaysInMonth(date._year, date._month);
	};
	bool isLastMonthInYear(short month) {
		return month == 12;
	};
	clsDate stringToDate(string stringDate) {
		clsDate date;
		try {
			vector<string>dateSliced = clsString::split(stringDate, "/");
			date._day = stoi(dateSliced.at(0));
			date._month = stoi(dateSliced.at(1));
			date._year = stoi(dateSliced.at(2));
		}
		catch (exception ex) {
			if (!isValidDate(date)) {
				cout << "Wrong input !!!\n";
				date._day = 1;
				date._month = 1;
				date._year = 1900;
			}
		}
		return date;
	};
	clsDate increaseDateByOneDay(clsDate date) {
		if (isLastDayInMonth(date)) {
			if (isLastMonthInYear(date._month)) {
				date._year++;
				date._month = 1;
			}
			else {
				date._month++;
			}
			date._day = 1;
		}
		else {
			date._day++;
		}
		return date;
	}
	clsDate increaseDateByXDay(clsDate date, short days) {
		for (short i = 1;i <= days;i++) {
			date = increaseDateByOneDay(date);
		}
		return date;
	};
	string getMonthName(short& month) {
		string monthsNames[] = { "","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return monthsNames[month];
	};
	string getWeekDayName(short dayOrder) {
		string weekDays[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return weekDays[dayOrder];
	}
	short getOrderWeekDayOfDate(short day, short month, short year) {
		short a = floor((14 - month) / 12);
		short y = year - a;
		short m = month + 12 * a - 2;
		short d = day + y + floor(y / 4) - floor(y / 100) + floor(y / 400) + floor(31 * m / 12);
		//short d = 5 + day + y + floor(y / 4) + floor(31 * m / 12);
		d = d % 7;
		return d;
	}
	short getOrderWeekDayOfDate(clsDate date) {
		return getOrderWeekDayOfDate(date._day, date._month, date._year);
	}
	void printHeader(short& month) {
		cout << "\n" << clsDraw::generateTabs(2);
		cout << clsDraw::generateLine(15) << getMonthName(month) << clsDraw::generateLine(15) << "\n\n";
		cout << clsDraw::generateTabs(2);
		cout << setw(3) << getWeekDayName(0) << "  ";
		cout << setw(3) << getWeekDayName(1) << "  ";
		cout << setw(3) << getWeekDayName(2) << "  ";
		cout << setw(3) << getWeekDayName(3) << "  ";
		cout << setw(3) << getWeekDayName(4) << "  ";
		cout << setw(3) << getWeekDayName(5) << "  ";
		cout << setw(3) << getWeekDayName(6) << "  ";
		cout << endl;

	}
	void printFooter() {
		cout << "\n" << clsDraw::generateTabs(2);
		cout << clsDraw::generateLine(18) << clsDraw::generateLine(15) << "\n\n";
	}
	void printBody(short& year, short& month) {
		short firstDay = getOrderWeekDayOfDate(1, month, year);
		short countMonthDays = countDaysInMonth(year, month);
		short currentDay = 1;

		cout << clsDraw::generateTabs(2);
		for (short i = 0;currentDay <= countMonthDays;i++) {
			if (i >= firstDay) {
				cout << setw(3) << currentDay << "  ";
				currentDay++;
			}
			else {
				cout << setw(3) << " " << "  ";
			}

			if ((i + 1) % 7 == 0) {
				cout << endl;
				cout << clsDraw::generateTabs(2);
			}
		}
	}
	void printMonthCalendar(short year, short month) {
		printHeader(month);
		printBody(year, month);
		printFooter();
	}
	void printYearCalendar() {
		cout << clsDraw::generateTabs(2) << clsDraw::generateLine(33, '=') << "\n";
		cout << clsDraw::generateTabs(12) << "Calendar - " << _year << "\n";
		cout << clsDraw::generateTabs(2) << clsDraw::generateLine(33, '=') << "\n";
		for (short i = 1;i <= 12;i++) {
			printMonthCalendar(_year, i);
		};
	};
	clsDate() {
		_day = getThisDay();
		_month = getThisMonth();
		_year = getThisYear();
	};
	clsDate(short day, short month, short year) {
		_day = day;
		_month = month;
		_year = year;
	};
	clsDate(string stringDate) {
		*this = stringToDate(stringDate);
	};
	clsDate(short days, short year) {
		_day = 1, _month = 1, _year = year;
		*this = increaseDateByXDay(*this, days);
	};
};
