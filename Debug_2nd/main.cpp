#include"../Debug_2nd/Log/LogMacro.h"

int main()
{
	
	LogPipeline::GetInstance().Initialize();	//ログパイプラインの初期化
	//ログの処理
	LOG_INFO(LOG_HEADER(Message, "aiueo"));
	int i = 100;
	LOG_ERROR(LOG_CONTEXT(), LOG_VALUE(i), LOG_HEADER(Message, "Hello, World!"));
	//LogPipeline::GetInstance().Process(Log::Level::Level::Error, Log::Header::Hedder(Log::Header::Type::File, "main.cpp"), Log::Header::Hedder(Log::Header::Type::Line, "11"), Log::Header::Hedder(Log::Header::Type::Func, "main"), Log::Header::Hedder(Log::Header::Type::Value, "An error occurred!"));
	return 0;
}