#pragma once

//@brief	ログタイプ
namespace LogType
{
	//@brief	ログの種類
	enum class LogType {
		Func,		//関数名
		File,		//ファイル名
		Line,		//行番号
		Class,		//呼び出しクラス
		Value,		//変数
		Message,	//メッセージ
	};
}