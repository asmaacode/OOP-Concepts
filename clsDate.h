#pragma once
#pragma warning(disable : 4996) 
#include<ctime> 
#include <vector>
#include <iostream>
#include <string>
#include "clsString.h"
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
