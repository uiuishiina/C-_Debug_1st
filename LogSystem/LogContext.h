#pragma once
//@brief	構造体作成マクロ
#define LOG_CONTEXT() LogContext{__func__,__FILE__,__LINE__}
#define LOG_VALUE(expr) LogValue<decltype(expr)>{#expr,(expr)}


//@brief	マクロ取得専用ログ構造体
struct LogContext {
	char* Func_{};
	char* File_{};
	int	Line_{};
};

//@brief	マクロ取得変数構造体
template<typename T>
struct LogValue {
	char* Name_{};
	const T		Value_{};
};