// DiscShopProgramStruct.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

const int MAX=99;
const int TYPE=2;

struct Customer
{
	char Name[50];
	char ID[15];
	char NoHP[20];
	int CDSell;
	int CDRent;
	int Day;
	double Total;
};

void GetInput(Customer[] ,int );
void FindHighLow(Customer[] ,int ,double& ,double& );
void EndResult(int ,int ,int ,double ,double ,double ,double );
void Search(Customer[] ,double[][TYPE] ,int );
void SortInc(Customer[] ,int );

void main()
{
	Customer Detail[MAX];
	double Sales[MAX][TYPE],TotalSales=0,TotalCDPurchase=0,TotalCDRent=0,average,low,high;
	int NoCust=0;
	for(int h=0;h<MAX;h++)
	{	
		Detail[h].Day=0;
		Detail[h].CDRent=0;
		Detail[h].CDSell=0;
		for(int j=0;j<TYPE;j++)
		{
			Sales[h][j]=0;

		}
		
	}
	int i=0;
	char NextCust='Y';
	while(NextCust=='Y')
	{
		cout<<"------------------------------------------------------------------------------\n";
 		GetInput(Detail ,i );
		for(int j=0;j<TYPE;j++)
		{
			if (j==0)
			{
				cout<<"How many CDs do you want purchase [RM20/ea]        : ";
				cin>>Detail[i].CDSell;
				TotalCDPurchase+=Detail[i].CDSell;
				Sales[i][0]=Detail[i].CDSell*20;
			}
			else 
			{
				cout<<"How many CD do you wish to rent   [RM2/ea perday]  : ";
				cin>>Detail[i].CDRent;
				TotalCDRent+=Detail[i].CDRent;
				if(Detail[i].CDRent!=0)
				{
					cout<<"How many day/s would you like to rent              : ";
					cin>>Detail[i].Day;
					Sales[i][1]=Detail[i].CDRent*(Detail[i].Day*2);
				}
			}
		}
		cout<<endl;
		cout<<"--------------------------------------------------------------------------------\n";
		cout<<"Name                         : "<<Detail[i].Name<<endl;
		cout<<"ID number                    : "<<Detail[i].ID<<endl;
		cout<<"Contact Number               : "<<Detail[i].NoHP<<endl;
		for(int j=0;j<TYPE;j++)
		{
			if (j==0)
			{
				cout<<"CD you purchased             : "<<Detail[i].CDSell<<endl;
				
			}
			else 
			{
				cout<<"CD rented                    : "<<Detail[i].CDRent<<endl;
				cout<<"Day rented                   : "<<Detail[i].Day<<endl;
			}
		}
		cout<<"Price for purchased CD       : RM "<<Sales[i][0]<<endl;
		cout<<"Price for rented    CD       : RM "<<Sales[i][1]<<endl;
		Detail[i].Total=Sales[i][0]+Sales[i][1];
		cout<<"Total amount to be paid      : RM "<<Detail[i].Total<<endl;
		cout<<"------------------------------------------------------------------------------\n";
		TotalSales+=Detail[i].Total;
		cout<<"Do you want to continue to the next customer [press 'Y' to continue]: ";
		cin>>NextCust;
		cout<<endl;
		i++;
		NoCust++;
		system("cls");
	}
	FindHighLow(Detail,NoCust,low,high);
	average=TotalSales/NoCust;

	Search(Detail,Sales,NoCust);
	EndResult(TotalCDPurchase,TotalCDRent,NoCust,average,TotalSales,high,low);
	SortInc(Detail,NoCust);
		
	_getch();
}


void GetInput(Customer Detail[],int index)
{
	cout<<"Please enter your name            : ";
	cin.clear();
	cin.sync();
	cin.getline(Detail[index].Name,50);
	cout<<"Please enter your ID number       : ";
	cin>>Detail[index].ID;
	cout<<"Please enter your phone number    : ";
	cin>>Detail[index].NoHP;
}

void FindHighLow(Customer Detail[],int Index,double& Low,double& High)
{
	High=Detail[0].Total;
	Low=Detail[0].Total;
	for(int i=0;i<Index;i++)
	{
		if(High<Detail[i].Total)
			High=Detail[i].Total;
		if(Low>Detail[i].Total)
			Low=Detail[i].Total;
	}
}

void EndResult(int CDsold,int CDRented,int NumCust,double Avg,double TotSales,double High,double Low)
{
	cout<<"------------------------------------------------------------------------------\n";
	cout<<"CD been purchased by customer : "<< CDsold <<endl;
	cout<<"CD been rented by customer    : "<< CDRented <<endl;
	cout<<"The number of customer        : "<< NumCust <<endl;
	cout<<"The average sales             : "<< Avg <<endl;
	cout<<"The total sales               : RM"<< TotSales <<endl;
	cout<<"The highest sales             : RM"<< High <<endl;
	cout<<"The lowest  sales             : RM"<< Low <<endl;
	cout<<"------------------------------------------------------------------------------\n";
	cout<<endl;
}

void Search(Customer Detail[],double CustSales[][TYPE],int Max)
{
	char Search[20],Loop;
	int Get;

	cout<<"Do you want to search a customer [press 'Y' to continue]: ";
	cin>>Loop;
	system("cls");
	while(Loop=='Y')
	{
		cout<<"\n--------------------------------------------------------------------------------\n";
		cout<<"Please Enter ID to search their detail : ";
		cin>>Search;

		int i=0;
		bool found=0;
		while(!found && i<Max)
		{
			if(strcmp(Search,Detail[i].ID)==0)
			{	
				found=true;
			}
			
			else

			i++;
		}
		
		if(found)
		{	Get=i;
			cout<<"--------------------------------------------------------------------------------\n";
			cout<<"Name                         : "<<Detail[Get].Name<<endl;
			cout<<"ID number                    : "<<Detail[Get].ID<<endl;
			cout<<"Contact Number               : "<<Detail[Get].NoHP<<endl;
			for(int j=0;j<TYPE;j++)
			{
				if (j==0)
				{
					cout<<"CD you purchased             : "<<Detail[Get].CDSell<<endl;
					
				}
				else 
				{
					cout<<"CD rented                    : "<<Detail[Get].CDRent<<endl;
					cout<<"Day rented                   : "<<Detail[Get].Day<<endl;
				}
			}
			cout<<"Price for purchased CD       : RM "<<CustSales[Get][0]<<endl;
			cout<<"Price for rented    CD       : RM "<<CustSales[Get][1]<<endl;
			Detail[Get].Total=CustSales[Get][0]+CustSales[Get][1];
			cout<<"Total amount to be paid      : RM "<<Detail[Get].Total<<endl;
			cout<<"------------------------------------------------------------------------------\n";
			cout<<endl;
		}

		else
			cout<<"\nNot in service!!\n\n";

		cout<<"Do you want to search another customer [press 'Y' to continue] : ";
		cin>>Loop;
		cout<<endl;
		system("cls");
	}
}

void SortInc(Customer Detail[],int Max)
{
	double Temp;
	for(int i=0;i<Max-1;i++)
	{
		if(Detail[i+1].Total>Detail[i].Total)
		{
			Temp=Detail[i+1].Total;
			Detail[i+1].Total=Detail[i].Total;
			Detail[i].Total=Temp;
		}
	}

	cout<<"Highest sales made in decreasing order : \n";
	for(int j=0;j<Max;j++)
		cout<<j+1<<". "<<Detail[j].Total<<"\n";
	cout<<endl;
}

