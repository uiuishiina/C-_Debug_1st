#pragma once
#include<string>
#include <string_view>

//@brief	ログレベル
namespace LogLevel {
	//ログの重要度
	enum class Loglevel {
		Info,
		Warning,
		Error,
		Unknown
	};

	//@brief	ログレベル変換関数
	static std::string_view ToString(Loglevel level) {
		std::string str{};
		switch (level)
		{
		case LogLevel::Loglevel::Info:
			str = "[ Info ]";
			return str;
		case LogLevel::Loglevel::Warning:
			str = "[ Warning ]";
			return str;
		case LogLevel::Loglevel::Error:
			str = "[ Error ]";
			return str;
		case LogLevel::Loglevel::Unknown:
			str = "[ Unknown ]";
			return str;
		default:
			str = "[  ]";
			return str;
		}
	}
}