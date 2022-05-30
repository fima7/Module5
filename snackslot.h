#pragma once

#include "snack.h" 

#include <ostream>

namespace vm
{
	// Описание лотка для продуктов
	class SnackSlot
	{
	public: // создание
		SnackSlot(size_t nsnacks);
		~SnackSlot();
	public: // добавление или удаление продукта в или из лотка
		void addSnack(const Snack* snack);
		void rmSnack(size_t index);
	public: // доступ к продукту и количеству мест в лотке
		const Snack* getSnack(size_t index) const;
		size_t getEmptyItemsCount() const;
		size_t getItemsCount() const;
	public: // вывод
		friend std::ostream& operator<<(std::ostream& os, const SnackSlot& slot);
	private:
		size_t _nsnacks;	// мест под продукты в лотке
		size_t _nadded;		// положено продуктов в лоток 
		const Snack **_snacks;
	};
}
