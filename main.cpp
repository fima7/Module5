#include "snack.h"
#include "snackslot.h"
#include "vendingmachine.h"
#include "vmtypes.h"

#include <iostream>
#include <string>

static const size_t snacks_max = 1024;

// Создание продуктов
static vm::Snack** createSnacks(const std::string& name, vm::money_t price, vm::calories_t calories, size_t nsnacks)
{
	using namespace vm;

	if (name.empty() || price == UNDEF_PRICE || calories == UNDEF_CALORIES || nsnacks > snacks_max) {
		return nullptr;
	}

	Snack** snacks = new Snack * [nsnacks];
	for (size_t i = 0; i < nsnacks; ++i) {
		snacks[i] = new Snack(name, price, calories);
	}
	return snacks;
}

// Удаление продуктов
static void cleanupSnacks(vm::Snack** snacks, size_t nsnacks)
{
	if (nsnacks > snacks_max) {
		return;
	}

	for (size_t i = 0; i < nsnacks; ++i) {
		delete snacks[i];
	}
}

// Пример использования торгового автомата
static void vendingMachine()
{
	using namespace vm;

	setlocale(LC_ALL, "");
	
	// продукты
	Snack **snikerses = createSnacks("Snikers", 5, 2000, 8);
	Snack **marses = createSnacks("Mars", 6, 1500, 8);
	Snack **buratinos = createSnacks("Buratino", 7, 3000, 8);

	// printSnacks(snikerses, 11);
	// printSnacks(marses, 15);
	// printSnacks(buratinos, 17);

	
	// Трговый автомамт
	const size_t nslots = 3;
	const size_t slotsize = 8;
	vm::SnackSlot** slots = new SnackSlot*[nslots];

	for (size_t i = 0; i < nslots; ++i) {
		slots[i] = new SnackSlot(slotsize);
	}


	for (size_t i = 0; i < 8 && slots[0]->getEmptyItemsCount(); ++i) {
		slots[0]->addSnack(snikerses[i]);
	}

	for (size_t i = 0; i < 8 && slots[1]->getEmptyItemsCount(); ++i) {
		slots[1]->addSnack(marses[i]);
	}

	for (size_t i = 0; i < 8 && slots[2]->getEmptyItemsCount(); ++i) {
		slots[2]->addSnack(buratinos[i]);
	}

	// std::cout << *slots[0];
	// std::cout << *slots[1];
	// std::cout << *slots[2];

	VendingMachine *machine = new VendingMachine(nslots);
	for (size_t i = 0; i < nslots; ++i) {
		machine->addSlot(slots[i]);
	}


	{ // Нет продукта
		std::cout << *machine << std::endl;
		std::cout << "Баланс: " << machine->getBalance() << std::endl;

		Delivery delivery = machine->Buy("Tokpoki", 30);

		if (!delivery.snack) {
			std::cout << "Нет такого, вот деньги " << delivery.moneyBack << std::endl;
		}

		std::cout << *machine << std::endl;
		std::cout << "Баланс: " << machine->getBalance() << std::endl;
	}
	{ // Не хватает денег
		std::cout << *machine << std::endl;
		std::cout << "Баланс: " << machine->getBalance() << std::endl;

		Delivery delivery = machine->Buy("Snikers", 1);

		if (!delivery.snack) {
			std::cout << "Мало денег, заберите обратно " << delivery.moneyBack << std::endl;
		}

		std::cout << *machine << std::endl;
		std::cout << "Баланс: " << machine->getBalance() << std::endl;

	}
	{ // Типичная покупка
		std::cout << *machine << std::endl;
		std::cout << "Баланс: " << machine->getBalance() << std::endl;

		Delivery delivery = machine->Buy("Snikers", 20);
		if (delivery.snack) {
			std::cout << "Заберите " << delivery.snack->getName() << " и сдачу " << delivery.moneyBack << std::endl;
		}

		std::cout << *machine << std::endl;
		std::cout << "Баланс: " << machine->getBalance() << std::endl;
	}


	// очистка
	for (size_t i = 0; i < nslots; ++i) {
		delete slots[i];
	}
	delete[] slots;

	cleanupSnacks(buratinos, 8);
	delete[] buratinos;

	cleanupSnacks(marses, 8);
	delete[] marses;

	cleanupSnacks(snikerses, 8);
	delete[] snikerses;

}


const size_t slotCount = 10;
using namespace vm;



int main()
{
	vendingMachine();

	// по заданию
	Snack *snikers = new Snack("Snikers", 1, 1);
	Snack *mars = new Snack("Mars", 1, 1);

	SnackSlot* slot = new SnackSlot(10);

	slot->addSnack(snikers);
	slot->addSnack(mars);

	VendingMachine* machine = new vm::VendingMachine(slotCount);

	machine->addSlot(slot);

	std::cout << machine->getEmptySlotsCount() << std::endl;

	delete machine;
	delete slot;
	delete snikers;
	delete mars;
	
}

