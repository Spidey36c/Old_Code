/*************************************************************
* Author:		James Nordquist
* Filename:		Fraction.cpp
* Date Created:	5/18/2019
* Modifications:
**************************************************************/
#include <iostream>
using std::cout;
using std::endl;

#include "Fraction.h"

/**********************************************************************
* Purpose: Default Ctor
*
* Precondition:
*    
* Postcondition:
*      Allows a variable be defined without defining its m_numer or m_denom
*
************************************************************************/
Fraction::Fraction()
{

}
/**********************************************************************
* Purpose: If a Variable is defined with a numerator or a denominator
*		   This function will set the numer and denom correctly
*
* Precondition:
*	   numer - Numerator defined during declaration of a variable
*	   denom - Denominator defined during declaration of a variable
* Postcondition:
*      Sets the m_numer and m_denom of a declared variable if it was defined
*	   with one, i.e. Fraction f1(1,2);
*
************************************************************************/
Fraction::Fraction(int numer, int denom)
{
	SetNumer(numer);
	SetDenom(denom);
}
/**********************************************************************
* Purpose: Adds two fractions and places the end result in a third
*
* Precondition:
*	   left_frac - Fraction that has a numerator and denominator
*	   right_frac - Fraction that has a numerator and denominator
* Postcondition:
*      a third fraction is filled
*
************************************************************************/
void Fraction::Add(Fraction left_frac, Fraction right_frac)
{
	m_numer = (left_frac.m_numer*right_frac.m_denom) + (right_frac.m_numer*left_frac.m_denom);
	m_denom = left_frac.m_denom * right_frac.m_denom;
	Reduce();
}
/**********************************************************************
* Purpose: Subtracts two fractions and places the end result in a third
*
* Precondition:
*	   left_frac - Fraction that has a numerator and denominator
*	   right_frac - Fraction that has a numerator and denominator
* Postcondition:
*      a third fraction is filled
*
************************************************************************/
void Fraction::Subtract(Fraction left_frac, Fraction right_frac)
{
	m_numer = (left_frac.m_numer*right_frac.m_denom) - (right_frac.m_numer*left_frac.m_denom);
	m_denom = left_frac.m_denom * right_frac.m_denom;
	Reduce();
}
/**********************************************************************
* Purpose: Multiplies two fractions and places the end result in a third
*
* Precondition:
*	   left_frac - Fraction that has a numerator and denominator
*	   right_frac - Fraction that has a numerator and denominator
* Postcondition:
*      a third fraction is filled
*
************************************************************************/
void Fraction::Multiply(Fraction left_frac, Fraction right_frac)
{
	m_numer = left_frac.m_numer * right_frac.m_numer;
	m_denom = left_frac.m_denom * right_frac.m_denom;
	Reduce();
}
/**********************************************************************
* Purpose:	Divides two fractions and places the end result in a third
*
* Precondition:
*	   left_frac - Fraction that has a numerator and denominator
*	   right_frac - Fraction that has a numerator and denominator
* Postcondition:
*      a third fraction is filled
*
************************************************************************/
void Fraction::Divide(Fraction left_frac, Fraction right_frac)
{
	m_numer = left_frac.m_numer * right_frac.m_denom;
	m_denom = left_frac.m_denom * right_frac.m_numer;
	Reduce();
}
/**********************************************************************
* Purpose: Displays a fraction appropriatly
*
* Precondition:
*	   
* Postcondition:
*      The console is outputted m_numer/m_denom
*
************************************************************************/
void Fraction::Display()
{
	cout << m_numer << "/" << m_denom;
}
/**********************************************************************
* Purpose: Sets m_numer
*
* Precondition:
*	   numer - user defined numerator
* Postcondition:
*      m_numer is set to whatever int numer is
*
************************************************************************/
void Fraction::SetNumer(int numer)
{
	m_numer = numer;
}
/**********************************************************************
* Purpose: Sets m_denom
*
* Precondition:
*	   denom - user defined numerator
* Postcondition:
*      m_denom is set to whatever int denom is, except for 0
*
************************************************************************/
void Fraction::SetDenom(int denom)
{
	if (denom != 0)
	{
		m_denom = denom;
	}
}
/**********************************************************************
* Purpose: Returns m_numer
*
* Precondition:
*	   
* Postcondition:
*      m_numer is returned as an int
*
************************************************************************/
int Fraction::GetNumer()
{
	return m_numer;
}
/**********************************************************************
* Purpose: Returns m_denom
*
* Precondition:
*
* Postcondition:
*      m_denom is returned as an int
*
************************************************************************/
int Fraction::GetDenom()
{
	return m_denom;
}
/**********************************************************************
* Purpose: Reduces a fraction
*
* Precondition:
*
* Postcondition:
*     m_numer and m_denom of a fraction is reduced to it's smallest possible
*	  number
*
************************************************************************/
void Fraction::Reduce()
{
	int i = 2;
	while (i <= m_denom)
	{
		if (m_denom % i == 0 && m_numer % i == 0)
		{
			m_denom /= i;
			m_numer /= i;
			i = 1;
		}
		i++;
	}
}
/**********************************************************************
* Purpose: Dtor
*
* Precondition:
*
* Postcondition:
*      frees up allocated resources
*
************************************************************************/
Fraction::~Fraction()
{

}