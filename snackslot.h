#pragma once

#include "snack.h" 

#include <ostream>

namespace vm
{
	// �������� ����� ��� ���������
	class SnackSlot
	{
	public: // ��������
		SnackSlot(size_t nsnacks);
		~SnackSlot();
	public: // ���������� ��� �������� �������� � ��� �� �����
		void addSnack(const Snack* snack);
		void rmSnack(size_t index);
	public: // ������ � �������� � ���������� ���� � �����
		const Snack* getSnack(size_t index) const;
		size_t getEmptyItemsCount() const;
		size_t getItemsCount() const;
	public: // �����
		friend std::ostream& operator<<(std::ostream& os, const SnackSlot& slot);
	private:
		size_t _nsnacks;	// ���� ��� �������� � �����
		size_t _nadded;		// �������� ��������� � ����� 
		const Snack **_snacks;
	};
}
