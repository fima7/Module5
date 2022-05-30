#pragma once

#include "snackslot.h"
#include "snack.h"
#include "vmtypes.h" 

#include <string> 

namespace vm
{
	// Результат покупки
	struct Delivery
	{
		const Snack* snack; // Если nulltpr, то покпка не удалась
		money_t moneyBack;	// Сдача при удачной покупке или возврат при неудачной 
	};

	// Описание торгового автомата
	class VendingMachine
	{
	public: // создание и удаление
		VendingMachine(size_t nslots);
		~VendingMachine();
	public: // добавление лотка
		void addSlot(SnackSlot* slot);
	public: // покупка
		Delivery Buy(const std::string& snackName, money_t money);
	public: // получение состояния автомата 
		size_t getSnacksCount() const;
		size_t getEmptySlotsCount() const;
		money_t getBalance() const;
	public: // вывод, типа витрина
		friend std::ostream& operator<<(std::ostream& os, const VendingMachine& machine);
	private:
		size_t _nslots; // всего лотков
		size_t _nadded; // сколько лотков вставлено в автомат
		money_t _balance; // сколько денег в копилке автомата
		SnackSlot** _slots;
	};
}
