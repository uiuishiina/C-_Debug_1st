#pragma once
#include"Log_pipline.h"

#define LOG_HEADER(type, value) Log::Header::Hedder(Log::Header::Type::type, value)	//ログヘッダーマクロ
#define LOG_CONTEXT()  Log::Header::Hedder(Log::Header::Type::Func, __func__),Log::Header::Hedder(Log::Header::Type::File, __FILE__), Log::Header::Hedder(Log::Header::Type::Line, std::to_string(__LINE__))	//ログコンテキストマクロ

#define LOG_INFO(...) LogPipeline::GetInstance().Process(Log::Level::Level::Info, __VA_ARGS__)
