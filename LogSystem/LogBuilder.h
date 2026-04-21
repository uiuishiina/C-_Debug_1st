#pragma once
#include"LogContext.h"
#include"LogLevel.h"
#include"LogRecordMap.h"


class LogBuilder final
{
	void Apply(LogRecordMap& map, const LogContext& context)noexcept {
		map.Push(LogType::LogType::Func, context.Func_);
		map.Push(LogType::LogType::File, context.File_);
		map.Push(LogType::LogType::Line, std::to_string(context.Line_));
	}

	void Apply(LogRecordMap& map, const std::string& context)noexcept {
		map.Push(LogType::LogType::Message, context);
	}

	template<typename T>
	void Apply(LogRecordMap& map, const LogValue<T>& value)noexcept {
		std::string str{};
		str = value.Name_ + " = " + std::to_string(value.Value_);
		map.Push(LogType::LogType::Value, str);
	}
public:
	template<typename... Args>
	static LogRecordMap Build(LogLevel::Loglevel level,Args&&... args) {
		LogRecordMap map_{ level };
		(Apply(map_, std::forward<Args>(args)), ...);
		return map_;
	}
};