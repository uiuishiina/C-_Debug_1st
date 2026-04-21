#pragma once

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
	static constexpr const char* ToString(const Loglevel& level) {
		switch (level)
		{
		case Loglevel::Info:		return "[ Info ]";
		case Loglevel::Warning:		return "[ Warning ]";
		case Loglevel::Error:		return "[ Error ]";
		case Loglevel::Unknown:		return "[ Unknown ]";
		default:					return "[  ]";
		}
	}
}