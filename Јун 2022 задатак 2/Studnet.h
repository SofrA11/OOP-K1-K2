#pragma once
#include<iostream>
#include<string.h>
#include<exception>
using namespace std;
class Student
{
private:
	char* index;
	char* ime;
	char* prezime;
	double prosek;
public:
	Student()
	{
		index = new char[5];
		ime = new char[20];
		prezime = new char[30];
		prosek = 0;
	}
	Student(char* ind,char*i,char*p,double pro)
	{
		index = ind;
		ime = i;
		prezime = p;
		prosek = pro;
	}
	~Student()
	{
	}

	bool operator==(Student& S)
	{
		int t;
		strlen(index) < strlen(S.index) ? t = strlen(index) : t = strlen(S.index);
	
		for (int i = 0;i < t;i++)
		{
			if (index[i] != S.index[i])
			{
				return false;
			}
		}
		return true;
	
	}
	bool operator> (Student& S)
	{
		return prosek > S.prosek;
	}
	bool operator< (Student& S)
	{
		return prosek < S.prosek;
	}
	Student& operator= (Student& S)
	{
		index = S.index;
		ime = S.ime;
		prezime = S.prezime;
		prosek = S.prosek;
		return*this;
	}

	friend istream& operator>> (istream& ulaz, Student& S);
	friend ostream& operator<< (ostream& izlaz, Student& S);

};
istream& operator>> (istream& ulaz, Student& S)
{
	ulaz >> S.index >> S.ime >> S.prezime >> S.prosek;
	return ulaz;
}
ostream& operator<< (ostream& izlaz, Student& S)
{
	izlaz << "Student(index,ime,prezime,prosek): (" << S.index << ", " << S.ime << ", " << S.prezime << ", " << S.prosek <<")" << endl;
	return izlaz;
}