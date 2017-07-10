#ifndef SPELL_HEADER_INCLUDED
#define SPELL_HEADER_INCLUDED

class Spell
{
private:
	char* spellDescr;
	char* type;
	int power;
public:
	Spell();
	Spell(const Spell&);
	Spell& operator=(const Spell&);
	~Spell();

	void setSpellDescr(char*);
	void setType(char*);
	void setPower(int);

	int getPower() const;
private:
	void copy(const Spell&);
};

#endif //SPELL_HEADER_INCLUDED