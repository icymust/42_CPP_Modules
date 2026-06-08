/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 15:50:11 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/08 17:58:27 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MateriaSource.hpp"
#include "../lib/Character.hpp"
#include "../lib/Ice.hpp"
#include "../lib/Cure.hpp"
#include <iostream>

void subjectTest() {
	std::cout << "=== SUBJECT TEST ===" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
	
	std::cout << std::endl;
}

void deepCopyTest() {
	std::cout << "=== DEEP COPY TEST ===" << std::endl;
	Character* alice = new Character("alice");
	alice->equip(new Ice());
	alice->equip(new Cure());
	
	Character* alice_copy = new Character(*alice);
	std::cout << "Original alice: ";
	alice->use(0, *alice_copy);
	std::cout << "Copied alice: ";
	alice_copy->use(0, *alice);
	
	delete alice;
	std::cout << "After deleting original: ";
	alice_copy->use(1, *alice_copy);
	
	delete alice_copy;
	std::cout << std::endl;
}

void fullInventoryTest() {
	std::cout << "=== FULL INVENTORY TEST ===" << std::endl;
	Character* hero = new Character("hero");
	AMateria* extra = new Ice();
	
	hero->equip(new Ice());
	hero->equip(new Cure());
	hero->equip(new Ice());
	hero->equip(new Cure());
	std::cout << "Inventory full (4 materias equipped)" << std::endl;
	
	hero->equip(extra);
	std::cout << "Tried to equip 5th materia (should be ignored)" << std::endl;
	
	delete extra;
	delete hero;
	std::cout << std::endl;
}

void unequipTest() {
	std::cout << "=== UNEQUIP TEST (Memory Management) ===" << std::endl;
	Character* player = new Character("player");
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	
	player->equip(ice);
	player->equip(cure);
	
	std::cout << "Before unequip:" << std::endl;
	player->use(0, *player);
	player->use(1, *player);
	
	player->unequip(0);
	std::cout << "After unequipping slot 0:" << std::endl;
	player->use(0, *player);
	player->use(1, *player);
	
	delete ice;
	delete player;
	std::cout << std::endl;
}

void invalidIndexTest() {
	std::cout << "=== INVALID INDEX TEST ===" << std::endl;
	Character* test = new Character("test");
	test->equip(new Ice());
	
	std::cout << "Using valid index (0):" << std::endl;
	test->use(0, *test);
	
	std::cout << "Using invalid indices (should do nothing):" << std::endl;
	test->use(-1, *test);
	test->use(5, *test);
	test->use(2, *test);
	
	std::cout << "Unequipping invalid indices (should do nothing):" << std::endl;
	test->unequip(-1);
	test->unequip(10);
	test->unequip(3);
	
	delete test;
	std::cout << std::endl;
}

void unknownMateriaTest() {
	std::cout << "=== UNKNOWN MATERIA TEST ===" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	
	AMateria* ice = src->createMateria("ice");
	AMateria* fire = src->createMateria("fire");
	
	if (ice)
		std::cout << "Created ice: " << ice->getType() << std::endl;
	if (!fire)
		std::cout << "Fire materia not learned (returned NULL)" << std::endl;
	
	delete ice;
	delete src;
	std::cout << std::endl;
}

void materiaSourceCopyTest() {
	std::cout << "=== MATERIA SOURCE COPY TEST ===" << std::endl;
	MateriaSource* original = new MateriaSource();
	original->learnMateria(new Ice());
	original->learnMateria(new Cure());
	
	MateriaSource* copy = new MateriaSource(*original);
	delete original;
	
	AMateria* ice = copy->createMateria("ice");
	AMateria* cure = copy->createMateria("cure");
	
	if (ice)
		std::cout << "Copy can create: " << ice->getType() << std::endl;
	if (cure)
		std::cout << "Copy can create: " << cure->getType() << std::endl;
	
	delete ice;
	delete cure;
	delete copy;
	std::cout << std::endl;
}

void assignmentOperatorTest() {
	std::cout << "=== ASSIGNMENT OPERATOR TEST ===" << std::endl;
	Character* john = new Character("John");
	john->equip(new Ice());
	john->equip(new Cure());
	
	Character* jane = new Character("Jane");
	jane->equip(new Ice());
	
	std::cout << "Before assignment:" << std::endl;
	std::cout << "John: ";
	john->use(0, *jane);
	std::cout << "Jane: ";
	jane->use(0, *john);
	
	*jane = *john;
	
	std::cout << "After jane = john:" << std::endl;
	std::cout << "Jane's name: " << jane->getName() << std::endl;
	std::cout << "Jane using slot 0: ";
	jane->use(0, *john);
	std::cout << "Jane using slot 1: ";
	jane->use(1, *john);
	
	delete john;
	delete jane;
	std::cout << std::endl;
}

int main() {
	subjectTest();
	deepCopyTest();
	fullInventoryTest();
	unequipTest();
	invalidIndexTest();
	unknownMateriaTest();
	materiaSourceCopyTest();
	assignmentOperatorTest();
	
	std::cout << "=== ALL TESTS COMPLETE ===" << std::endl;
	return 0;
}