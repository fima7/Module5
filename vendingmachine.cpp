#include "vendingmachine.h" 

namespace vm
{
	//
	// Создание
	//
	VendingMachine::VendingMachine(size_t nslots)
		: _nslots(nslots)
		, _nadded(0)
		, _balance(0)
		, _slots(new SnackSlot*[_nslots])
	{}

	VendingMachine::~VendingMachine()
	{
		// Удаляем только указатели на лотки
		// Сами лотки удалит владелец который их создал
		delete[] _slots;
	}

	//
	// Добавление лотка
	//
	void VendingMachine::addSlot(SnackSlot* slot)
	{
		if (_nadded < _nslots) {
			_slots[_nadded++] = slot;
		}
	}

	//
	// Покупка. При успешной покупке удаляет указатель на продукт из лотка
	// Вход
	//	Название продукта и деньги
	// Возврат
	//	Указатель на продукт и сдача
	//
	Delivery VendingMachine::Buy(const std::string& snackName, money_t money)
	{
		for (size_t i = 0; i < _nadded; ++i) {
			for (size_t j = 0; j < _slots[i]->getItemsCount(); ++j) {
				const Snack* snack = _slots[i]->getSnack(j);
				if (snack->getName() == snackName) {
					_slots[i]->rmSnack(j);
					if (money >= snack->getPrice()) {
						_balance += snack->getPrice();
						return { snack, money - snack->getPrice() };
					} else {
						return { nullptr, money };
					}

				}
			}
		}
		return { nullptr, money };
	}

	//
	// Получение состояния автомата
	//
	money_t VendingMachine::getBalance() const
	{
		return _balance;
	}

	size_t VendingMachine::getSnacksCount() const
	{
		return _nadded;
	}

	size_t VendingMachine::getEmptySlotsCount() const
	{
		return _nslots - _nadded;
	}

	//
	// Вывод. Витрина
	//
	std::ostream& operator<<(std::ostream& os, const VendingMachine& machine)
	{
		os << "Витрина: " << std::endl;
		for (size_t i = 0; i < machine._nslots; ++i) {
			os << *machine._slots[i];
		}
		return os;
	}

}