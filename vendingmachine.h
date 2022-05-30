#pragma once

#include "snackslot.h"
#include "snack.h"
#include "vmtypes.h" 

#include <string> 

namespace vm
{
	// ��������� �������
	struct Delivery
	{
		const Snack* snack; // ���� nulltpr, �� ������ �� �������
		money_t moneyBack;	// ����� ��� ������� ������� ��� ������� ��� ��������� 
	};

	// �������� ��������� ��������
	class VendingMachine
	{
	public: // �������� � ��������
		VendingMachine(size_t nslots);
		~VendingMachine();
	public: // ���������� �����
		void addSlot(SnackSlot* slot);
	public: // �������
		Delivery Buy(const std::string& snackName, money_t money);
	public: // ��������� ��������� �������� 
		size_t getSnacksCount() const;
		size_t getEmptySlotsCount() const;
		money_t getBalance() const;
	public: // �����, ���� �������
		friend std::ostream& operator<<(std::ostream& os, const VendingMachine& machine);
	private:
		size_t _nslots; // ����� ������
		size_t _nadded; // ������� ������ ��������� � �������
		money_t _balance; // ������� ����� � ������� ��������
		SnackSlot** _slots;
	};
}
