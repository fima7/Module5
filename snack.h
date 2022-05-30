#pragma once

#include "vmtypes.h"

#include <string>
#include <ostream>
#include <string>

namespace vm
{
	// Описание продукта, сождержащее название, калории и стоимость 
	class Snack
	{
	public: // создание
		Snack(const std::string& name, money_t price, calories_t calories);
	public: // доступ к наззванию, калорийности, стоимости
		const std::string& getName() const;
		void setName(const std::string& name);

		money_t getPrice() const;
		void setPrice(money_t money);

		calories_t getCalories() const;
		void setCalories(calories_t calories);

	public: // выввод  
		friend std::ostream& operator << (std::ostream& os, const Snack& snack);
	private:
		std::string _name;
		calories_t _calories;
		money_t _price;
	};
}

