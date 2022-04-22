#pragma once
namespace EPMSSpace
{
	struct _PayRoll_t {
		float basic;
		float bonus;
	};
	typedef struct _PayRoll_t PayRoll_t;
	extern char empName[255];
	extern int empCode;
	extern PayRoll_t payRoll;

	void readEmp(void);
	void printEmp(void);
};