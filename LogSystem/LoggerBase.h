#pragma once
#include<memory>
#include"LogRecordMap.h"
#include"LogFormatterBase.h"

class LoggerBase
{
	std::shared_ptr<LogFormatterBase> Formatter_{};
public:
	explicit LoggerBase(std::shared_ptr<LogFormatterBase> formatter) :
		Formatter_(formatter) {
	};
	virtual ~LoggerBase() = default;

	virtual void Submit(LogRecordMap map) = 0;
};