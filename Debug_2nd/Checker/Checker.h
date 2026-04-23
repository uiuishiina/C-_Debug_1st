#pragma once
#include"../Log/LogMacro.h"
#include"Checker_Struct_Parts.h"

#define Check_Value(condition) \
	do { \
		if (Check::Check(Check::Checker_Parts<decltype(condition)>(#condition, condition))) { \
			LOG_ERROR("Assertion failed: " #condition); \
		} \
	} while (0)


//チェッカーのクラス
class Checker
{
	static bool IsErrorImpl(bool condition) {
		return !condition;
	}
public:
	//アサートのチェック関数
	template<Check::Checker_Parts_Concept T>
	static bool Check(T value) {
		return IsErrorImpl(value);
	}

};