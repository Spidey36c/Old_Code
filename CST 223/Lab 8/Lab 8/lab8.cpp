// lab8.cpp : This file contains the unit tests
//

/************************************************
	 ___     ___       ____    ___   ______
	|   \   /   \     |    \  /   \ |      |
	|    \ |     |    |  _  ||     ||      |
	|  D  ||  O  |    |  |  ||  O  ||_|  |_|
	|     ||     |    |  |  ||     |  |  |
	|     ||     |    |  |  ||     |  |  |
	|_____| \___/     |__|__| \___/   |__|

 ___ ___   ___   ___    ____  _____  __ __  __
|   |   | /   \ |   \  |    ||     ||  |  ||  |
| _   _ ||     ||    \  |  | |   __||  |  ||  |
|  \_/  ||  O  ||  D  | |  | |  |_  |  ~  ||__|
|   |   ||     ||     | |  | |   _] |___, | __
|   |   ||     ||     | |  | |  |   |     ||  |
|___|___| \___/ |_____||____||__|   |____/ |__|

************************************************/

/*
 * Be sure to read an honor the above comment
 * Feel free to comment out tests if while you are working,
 * HOWEVER, remember to uncomment them and run before turn in.
 */

#include "pch.h"
#include <iostream>

 // Catch2 testing framework
#include "catch2.h"

 // Lab under test
#define LAB8_CODE
#include "lab8.h"

using namespace std;

//----------------------------------------------------------------------------
#ifdef LAB8_A

class PrependString {
public:
	string action(string str)
	{
		return string("->") + str;
	}
};

class AppendString {
public:
	string action(string str)
	{
		return str + string("<-");
	}
};

class WrapString {
public:
	string action(string str)
	{
		return string("[") + str + string("]");
	}
};

TEST_CASE("one action", "[LAB8_A]") {
	REQUIRE(act1(string("a"), AppendString()) == string("a<-"));
	REQUIRE(act1(string("b"), PrependString()) == string("->b"));
	REQUIRE(act1(string("c"), WrapString()) == string("[c]"));
}

//----------------------------------------------------------------------------
#ifdef LAB8_B

TEST_CASE("two actions", "[LAB8_A]") {
	REQUIRE(act1(string("a"), AppendString(), WrapString()) == string("[a<-]"));
	REQUIRE(act1(string("b"), WrapString(), PrependString()) == string("->[b]"));
	REQUIRE(act1(string("c"), WrapString(), WrapString()) == string("[[c]]"));
}

#endif // LAB8_B
#endif // LAB8_A

//----------------------------------------------------------------------------
#ifdef LAB8_C
class State {
	string str;
	friend class PrependState;
	friend class WrapState;
	friend class AppendState;

public:
	State(const char* s) : str(s)
	{
	}
	inline string getString() { return str; }
};

class PrependState {
public:
	void action(State &s)
	{
		s.str = string("->") + s.str;
	}
};

class AppendState {
public:
	void action(State &s)
	{
		s.str = s.str + string("<-");
	}
};

class WrapState {
public:
	void action(State &s)
	{
		s.str = string("[") + s.str + string("]");
	}
};

TEST_CASE("pipeline", "[LAB8_C]") {
	{
		State state("a");
		pipeline(state, AppendState());
		REQUIRE(state.getString() == string("a<-"));
	}
	{
		State state("b");
		pipeline(state, WrapState(), PrependState());
		REQUIRE(state.getString() == string("->[b]"));
	}
	{
		State state("c");
		pipeline(state, PrependState(), WrapState(), AppendState());
		REQUIRE(state.getString() == string("[->c]<-"));
	}
}
#endif // LAB8_C

//----------------------------------------------------------------------------
#ifdef LAB8_D
class Registers {
	int a;
	int b;
	int c;
	int pc;
public:
	Registers(int a, int b, int c) : a(a), b(b), c(c), pc(0) {}
	inline int getPC() { return pc; }
	inline void incPC() { ++pc; }
	inline void resetPC() { pc = 0; }
	inline int getA() { return a; }
	inline void setA(int value) { a = value; }
	inline int getB() { return b; }
	inline void setB(int value) { b = value; }
	inline int getC() { return c; }
	inline void setC(int value) { c = value; }
};

class AddAB {
public:
	inline void execute(Registers &reg) {
		//        puts("AddAB");
		reg.setA(reg.getA() + reg.getB());
		reg.incPC();
	}
};

class DecC {
public:
	inline void execute(Registers &reg) {
		//        puts("DecC");
		reg.setC(reg.getC() - 1);
		reg.incPC();
	}
};

class RestartIfCNot0 {
public:
	inline void execute(Registers &reg) {
		//        puts("RestartIfCNot0");
		if (reg.getC() != 0) {
			reg.resetPC();
		}
		else {
			reg.incPC();
		}
	}
};

TEST_CASE("vm", "[LAB8_D]") {
	{
		Registers registers(0, 2, 3);
		vm(registers, DecC());
		REQUIRE(registers.getC() == 2);
	}
	{
		Registers registers(0, 2, 3);
		vm(registers, AddAB(), DecC(), RestartIfCNot0());
		REQUIRE(registers.getA() == 6);
		REQUIRE(registers.getB() == 2);
		REQUIRE(registers.getC() == 0);
	}
}
#endif // LAB8_D
