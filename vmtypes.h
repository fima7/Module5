#pragma once

#include <cinttypes>
#include <limits>

// Базовые типы данных для торгового автомата
namespace vm
{
	using money_t = uint32_t;
	using calories_t = uint32_t;
	const money_t UNDEF_PRICE = std::numeric_limits<money_t>::max();
	const uint32_t UNDEF_CALORIES = std::numeric_limits<uint32_t>::max();
}



