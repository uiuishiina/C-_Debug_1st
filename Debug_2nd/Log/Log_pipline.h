#pragma once
#include"LogBuilder.h"
#include"LoggerManager.h"


//ログパイプラインクラス
class LogPipeline final
{
	LogBuilder builder;	//ログビルダークラスのインスタンス
	LoggerManager logger_manager;	//ロガーマネージャークラスのインスタンス

	LogPipeline() = default;
	~LogPipeline() = default;
	LogPipeline(const LogPipeline&) = delete;
	LogPipeline& operator=(const LogPipeline&) = delete;
	LogPipeline(LogPipeline&&) = delete;
	LogPipeline& operator=(LogPipeline&&) = delete;
public:
	//シングルトンの実装
	static LogPipeline& GetInstance() {
		static LogPipeline instance;	//静的なインスタンスを返す
		return instance;
	}

	//初期化関数
	void Initialize()
	{
		logger_manager.Initialize();
	}

	//ログの処理関数
	template<Log_Struct_Parts... Args>
	void Process(Log::Level::Level level,Args&&... args)
	{
		//ログ構造体をビルド
		auto record = builder.BuildLog<Args...>(level, std::forward<Args>(args)...);
		//ログをロガーマネージャーに送信
		logger_manager.SendLog(record);
	}
};