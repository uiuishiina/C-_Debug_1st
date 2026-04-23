#pragma once

namespace Check
{	
	//チェッカーのパーツの概念
	template<typename T>
	concept Checker_Parts_Concept = std::equality_comparable<T>;

}