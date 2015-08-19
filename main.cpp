// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

void FindHighLow(double[], int, double&, double&);
void EndResult(int, int, int, double, double, double, double);

int main()
{
	const int MAX=99;
	string name[MAX];
	string id[MAX];
	int CDSell[MAX], CDRent[MAX], CDRentDay[MAX], custNo = 0,NoHP[MAX], numberCDSell=0, numberCDRent=0;
	double totalCDSell[MAX], totalCDRent[MAX], total[MAX], TotalSales = 0,low,high,average;
	string type;

	char nextCust = 'Y';
	int i = 0;
	while (nextCust == 'Y')
	{
		cout << "Please input name : ";
		cin >> name[i];
		cout << "Please input ID number : ";
		cin >> id[i];
		cout << "Please input Phone Number : ";
		cin >> NoHP[i];


		cout << name[i];
		cout << " are you want buy CD or rent CD [buy,rent] : ";
		cin >> type;
		if (type == "buy")
		{
			cout << "How many CDs do you want purchase [RM20/ea]        : ";
			cin >> CDSell[i];
			numberCDSell += CDSell[i];
			totalCDSell[i] = CDSell[i] * 20;
			totalCDRent[i] = 0;
		}
		else
		{
			cout << "How many CD do you wish to rent   [RM2/ea perday]  : ";
			cin >> CDRent[i];
			cout << "How many day/s would you like to rent              : ";
			cin >> CDRentDay[i];
			numberCDRent += CDRent[i];
			totalCDRent[i] = CDRent[i] * CDRentDay[i] * 2;
			totalCDSell[i] = 0;
		}
		cout << "--------------------------------------------------------------------------------\n";
		cout << "Name                         : " << name[i] << endl;
		cout << "ID number                    : " << id[i] << endl;
		cout << "Contact Number               : " << NoHP[i] << endl;
		if (type == "buy")
		{
			cout << "CD you purchased             : " << CDSell[i] << endl;
			cout << "Price for purchased CD       : RM " << totalCDSell[i] << endl;
		}
		else
		{
			cout << "CD rented                    : " << CDRent[i] << endl;
			cout << "Day rented                   : " << CDRentDay[i] << endl;
			cout << "Price for rented    CD       : RM " << totalCDRent[i] << endl;
		}
		
		
		total[i] = totalCDSell[i] + totalCDRent[i];
		cout << "Total amount to be paid      : RM " << total[i] << endl;
		cout << "------------------------------------------------------------------------------\n";
		TotalSales += total[i];

		cout << "Next Customer [Y,N] :";
		cin >> nextCust;
		custNo += 1;
		i++;
	}

	FindHighLow(total, custNo, low, high);
	average = TotalSales / custNo;
	EndResult(numberCDSell, numberCDRent, custNo, average, TotalSales, high, low);


	_getch();
    return 0;
}

void FindHighLow(double total[], int Index, double& Low, double& High)
{
	High = total[0];
	Low = total[0];
	for (int i = 0;i<Index;i++)
	{
		if (High<total[i])
			High = total[i];
		if (Low>total[i])
			Low = total[i];
	}
}

void EndResult(int CDsold, int CDRented, int NumCust, double Avg, double TotSales, double High, double Low)
{
	cout << "------------------------------------------------------------------------------\n";
	cout << "CD been purchased by customer : " << CDsold << endl;
	cout << "CD been rented by customer    : " << CDRented << endl;
	cout << "The number of customer        : " << NumCust << endl;
	cout << "The average sales             : " << Avg << endl;
	cout << "The total sales               : RM" << TotSales << endl;
	cout << "The highest sales             : RM" << High << endl;
	cout << "The lowest  sales             : RM" << Low << endl;
	cout << "------------------------------------------------------------------------------\n";
	cout << endl;
}
