#pragma once
#include<string>

//@brief	ログ一回のデータ
namespace LogRecord
{
	//@brief	ログの種類
	enum class LogType {
		Level,	//ログレベル
		Func,	//関数名
		Line,	//行番号
		Class,	//呼び出しクラス
		Value	//変数
	};

	//@brief	ログ一回のデータ構造体
	struct LogRecord {
		LogType type;
		std::string value;
	};
}