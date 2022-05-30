#include "vendingmachine.h" 

namespace vm
{
	//
	// ��������
	//
	VendingMachine::VendingMachine(size_t nslots)
		: _nslots(nslots)
		, _nadded(0)
		, _balance(0)
		, _slots(new SnackSlot*[_nslots])
	{}

	VendingMachine::~VendingMachine()
	{
		// ������� ������ ��������� �� �����
		// ���� ����� ������ �������� ������� �� ������
		delete[] _slots;
	}

	//
	// ���������� �����
	//
	void VendingMachine::addSlot(SnackSlot* slot)
	{
		if (_nadded < _nslots) {
			_slots[_nadded++] = slot;
		}
	}

	//
	// �������. ��� �������� ������� ������� ��������� �� ������� �� �����
	// ����
	//	�������� �������� � ������
	// �������
	//	��������� �� ������� � �����
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
	// ��������� ��������� ��������
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
	// �����. �������
	//
	std::ostream& operator<<(std::ostream& os, const VendingMachine& machine)
	{
		os << "�������: " << std::endl;
		for (size_t i = 0; i < machine._nslots; ++i) {
			os << *machine._slots[i];
		}
		return os;
	}

}