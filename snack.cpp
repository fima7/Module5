
#include "snack.h" 
#include "vmtypes.h"

#include <iostream>

namespace vm
{
	//
	// ��������
	//

	Snack::Snack(const std::string& name, money_t price = UNDEF_PRICE, calories_t calories = UNDEF_CALORIES) 
		: _name(name)
		, _price(price)
		, _calories(calories)
	{}

	// 
	// ������ � ��������
	//
	const std::string& Snack::getName() const
	{
		return _name;
	}

	void Snack::setName(const std::string& name) 
	{
		_name = name;
	}

	money_t Snack::getPrice() const
	{
		return _price;
	}

	void Snack::setPrice(money_t money)
	{
		_price = money;
	}

	calories_t Snack::getCalories() const
	{
		return _calories;
	}

	void Snack::setCalories(calories_t calories)
	{
		_calories = calories;
	}

	//
	// ����� �������� 
	//
	std::ostream& operator << (std::ostream& os, const Snack& snack)
	{
		os << "��������: " << snack._name
			<< " ���������: " << snack._price
			<< " ������������: " << snack._calories;

		return os;
	}


}