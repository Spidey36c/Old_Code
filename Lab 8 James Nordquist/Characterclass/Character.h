#ifndef CHARACTER_H
#define CHARACTER_H
#include <ostream>
using std::ostream;
#include <string>
using std::string;
class Character
{
public:
	Character();
	Character(int hp, int armor, int dmg, string name);
	Character(const Character &copy);
	Character &operator =(const Character &rhs);
	~Character();
	void generateFull();
	void generateStats();
	int attack();
	void defend(int dmg);
	void stanceChange();
	void setHealth(int hp);
	void setGameState(int state);
	void setArmor(int armor);
	void setRound(int round);
	void setDamage(int dmgm, int dmgx);
	void setName(string name);
	void gameOver();
	int getGameState() const;
	int getHealth() const;
	int getMaxHealth() const;
	int getArmor() const;
	int getRound() const;
	int getDamageMin() const;
	int getDamageMax() const;
	string getName() const;
	friend ostream &operator <<(ostream &os, const Character &rhs);
private:
	int m_gameState; //0 is normal gameplay, 1 is lose state, 2 is win state
	int m_stance = 1; //1 is normal strike, 2 is block(more armor, less damage), 3 is berserk(less armor, more damage)
	int m_maxhealth; //so that any healing wont go beyond this number
	int m_health;
	int m_armor;
	int m_round;
	int m_dmgmin;
	int m_dmgmax;
	string m_name;
};

#endif