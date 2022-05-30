#include "snackslot.h"

namespace vm
{
	// 
	// Создание и удаление
	// 
	SnackSlot::SnackSlot(size_t nsnacks)
		: _nsnacks(nsnacks)
		, _nadded(0)
		, _snacks(new const Snack*[_nsnacks])
	{}

	SnackSlot::~SnackSlot()
	{
		// Удаляем только то что создали
		// Сами продукты Snack удалит владелец, который их создал
		delete [] _snacks;
	}

	// 
	// Добавление и удаление продукта 
	//
	void SnackSlot::addSnack(const Snack* snack)
	{
		if (_nadded < _nsnacks) {
			_snacks[_nadded++] = snack;
		}
	}

	void SnackSlot::rmSnack(size_t index)
	{
		// Места справа в слотах пустые
		_snacks[index] = _snacks[_nadded - 1];
		_snacks[_nadded - 1] = nullptr;
		--_nadded;
	}


	// 
	// Получение продукта, количества свободных и занятых мест лотках
	//
	size_t SnackSlot::getEmptyItemsCount() const
	{
		return _nsnacks - _nadded;
	}

	size_t SnackSlot::getItemsCount() const
	{
		return _nadded;
	}

	const Snack* SnackSlot::getSnack(size_t index) const
	{
		if (index >= _nsnacks) {
			return nullptr;
		}
		return _snacks[index];
	}


	//
	// Вывод информации о содержимом лотка
	//
	std::ostream& operator<<(std::ostream& os, const SnackSlot& slot)
	{
		for (size_t i = 0; i < slot._nadded; ++i) {
			os << *(slot._snacks[i]) << std::endl;
		}
		return os;
	}
}
	