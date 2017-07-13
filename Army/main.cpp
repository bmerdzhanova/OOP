#include <iostream>
#include "Soldier.h"
#include "Sergeant.h"
#include "MagicBook.h"
#include "Commander.h"

int main()
{
	Soldier* squad = new Soldier[3];
	squad[0].setName("Ivan");
	squad[0].setAge(23);
	squad[0].setLevel(10);
	squad[0].setSalary(100);
	squad[1].setName("Maria");
	squad[1].setAge(25);
	squad[1].setLevel(5);
	squad[1].setSalary(200);
	squad[2].setName("Vasil");
	squad[2].setAge(20);
	squad[2].setLevel(6);
	squad[2].setSalary(50);
	//-------------------------------------
	Sergeant s;
	s.setName("Betty");
	s.setAge(20);
	s.setLevel(20);
	s.setSalary(100000);
	s.setSquadDescr("Untouchables");
	s.setSquad(squad, 3);
	Sergeant b;
	b = s;
	//-------------------------------------
	MagicBook m;
	Spell n;
	n.setSpellDescr("spell");
	n.setType("evil");
	n.setPower(10);
	Spell n2;
	n2.setSpellDescr("second_spell");
	n2.setPower(5);
	n2.setType("good");
	m.addSpell(n);
	m.addSpell(n2);
	m.useSpell(0);
	//---------------------------------------

	return 0;
}
