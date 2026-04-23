#pragma once
#include"../Log/LogMacro.h"

#define ASSERT(condition) \
	do { \
		if (Assert::IsError(Assert_Parts<decltype(condition)>(#condition, condition))) { \
			LOG_ERROR("Assertion failed: " #condition); \
		} \
	} while (0)

//アサートのパーツの概念
template<typename T>
concept Assert_Parts_Concept = std::equality_comparable<T>;

//アサートのパーツ構造体
template<Assert_Parts_Concept T>
struct Assert_Parts
{
	std::string name;	//アサートの値の名前
	T value;	//アサートの値

	Assert_Parts() = delete;
	Assert_Parts(const std::string& name, const T& value) : name(name), value(value) {}
};

//アサートクラス
class Assert
{
	static bool Check(bool condition) {
		return !condition;
	}
public:
	//アサートのチェック関数
	template<Assert_Parts_Concept T>
	static bool IsError(Assert_Parts<T> parts) {
		return Check(parts.value);
	}

};