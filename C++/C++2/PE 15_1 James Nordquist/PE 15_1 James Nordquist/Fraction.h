#pragma once
/*************************************************************
* Author:		James Nordquist
* Filename:		Fraction.h
* Date Created:	5/18/2019
* Modifications:
**************************************************************/
/************************************************************************
* Class: Fraction
*
* Purpose: This class creates fractions, and allows them to be added or subtracted
*
* Manager functions:
* 	Fraction();
*		Default numerator and denominator are 0
*	Fraction(int numer, int denom);
*		If the user the variables are declared f1(1,2) this will make sure
*		that the numerator will be 1 and denominator will be 2
*	Add(Fraction left_frac, Fraction right_frac);
*		Adds fractions by multiplying the left numerator by the right denominator
*		and the right numerator by the left denominator and adding the products
*		over the left denominator by the right denominator then reduces if possible.
*	Subtract(Fraction left_frac, Fraction right_frac);
*		Subtracts fractions by multiplying the left numerator by the right denominator
*		and the right numerator by the left denominator and Subtracting the products
*		over the left denominator by the right denominator then reduces if possible.
*	Multiply(Fraction left_frac, Fraction right_frac);
*		Multiplies fractions by multiplying the left numerator by the right numerator
*		over the left demoninator by the rigth denominator then reduces if possible.
*	Divide(Fraction left_frac, Fraction right_frac);
*		Multiplies fractions by multiplying the left numerator by the right denominator
*		over the left denominator by the rigth numerator then reduces if possible.
*	Display();
*		Displays the m_numer / m_denom
*	SetNumer(int numer);
*		If the user wants to make their own numerator they must first define the variable i.e. Fraction f1;
*		then prompt the user for their numerator and pass it in by f1.SetNumer(UserNumer); Should be used
*		in unison with SetDenom.
*	SetDenom(int denom);
*		If the user wants to make their own denominator they must first define the variable i.e. Fraction f1;
*		then prompt the user for their denominator and pass it in by f1.SetDenom(UserDenom); Should be used
*		in unison with SetNumer.
*	GetNumer();
*		Returns m_numer;
*	GetDenom();
*		Returns m_denom;
*	~Fraction();
*	Reduce();
*		Reduces a fraction to its smallest possible amount.
*
* Methods:
*	m_denom
*		The denominator of the fraction.
*	m_numer
*		The numerator of the fraction.
*************************************************************************/

class Fraction
{
	public:
		Fraction();
		Fraction(int numer, int denom);
		void Add(Fraction left_frac, Fraction right_frac);
		void Subtract(Fraction left_frac, Fraction right_frac);
		void Multiply(Fraction left_frac, Fraction right_frac);
		void Divide(Fraction left_frac, Fraction right_frac);
		void Display();
		void SetNumer(int numer);
		void SetDenom(int denom);
		int GetNumer();
		int GetDenom();
		~Fraction();
	private:
		int m_denom = 1;
		int m_numer = 1;
		void Reduce();
};

