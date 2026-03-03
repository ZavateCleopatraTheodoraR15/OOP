#pragma once
#include<string>
using namespace std;

class Student
{
private:

	string name;
	float Nota_Mate;
	float Nota_Engleza;
	float Nota_Istorie;

public:

	void SetName(const string& n);
	string GetName() const;

	bool SetNotaMate(float grade);
	float GetNotaMate() const;

	bool SetNotaEngleza(float grade);
	float GetNotaEngleza() const;

	bool SetNotaIstorie(float grade);
	float GetNotaIstorie() const;

	float GetMedie() const;

};