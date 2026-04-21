#pragma once
#include<unordered_map>
#include<string>
#include"LogType.h"
#include"LogLevel.h"

//@brief	ログ一回の情報転送用構造体
struct LogRecordMap
{
	//===========================================
	LogLevel::Loglevel Level_{};	//ログレベル
	std::unordered_map<LogType::LogType, std::string> MapData_{};	//ログ本体
	//===========================================

	//@brief	コンストラクタ
	explicit LogRecordMap(LogLevel::Loglevel level) noexcept
		: Level_(level) {};

	//mapプッシュ関数
	void Push(LogType::LogType type, std::string str) {
		EraseCode(str);
		MapData_.try_emplace(type, std::move(str));
	}


	//@brief	ログレベル取得関数
	[[nodiscard]] const LogLevel::Loglevel GetLevel()const noexcept {
		return Level_;
	}

	//LogType所持確認関数
	[[nodiscard]] bool IsHave(LogType::LogType type)const noexcept {
		return MapData_.find(type) != MapData_.end();
	}

	//LogType別登録文字列取得関数
	[[nodiscard]] const std::string& GetData(LogType::LogType type)const noexcept {
		const auto it = MapData_.find(type);
		if (it == MapData_.end()) {
			static const std::string notFound = "Not Found MapData_";
			return notFound;
		}
		return it->second;
	}

	//文字コード消去関数
private:
	void EraseCode(std::string& str)noexcept {
		str.erase(std::remove_if(str.begin(), str.end(), [](char c) { return c == '\n' || c == '\r'; }), str.end());
	}
};