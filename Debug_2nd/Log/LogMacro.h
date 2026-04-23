#pragma once
#include"Log_pipline.h"

#define LOG_HEADER(type, value) Log::Header::Hedder(Log::Header::Type::type, value)	//ログヘッダーマクロ
#define LOG_CONTEXT()  Log::Header::Hedder(Log::Header::Type::Func, __func__),Log::Header::Hedder(Log::Header::Type::File, __FILE__), Log::Header::Hedder(Log::Header::Type::Line, std::to_string(__LINE__))	//ログコンテキストマクロ

#define log_value(expr) (std::string(#expr) + "  =  " + std::to_string(expr))
#define LOG_VALUE(expr) Log::Header::Hedder(Log::Header::Type::Value, log_value(expr))

#define LOG_INFO(...) LogPipeline::GetInstance().Process(Log::Level::Level::Info, __VA_ARGS__)
#define LOG_ERROR(...) LogPipeline::GetInstance().Process(Log::Level::Level::Error, __VA_ARGS__)
