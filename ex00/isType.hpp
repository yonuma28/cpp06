#ifndef ISTYPE_HPP
# define ISTYPE_HPP

# include <string>
# include <iostream>

/**
 * @brief 各スカラ型の判定を行うヘルパー関数群
 */

bool isChar(const std::string& str);
bool isInt(const std::string& str);
bool isFloat(const std::string& str);
bool isDouble(const std::string& str);

/**
 * @brief nan, nanf, inf 等の特殊な文字列を判定する
 */
bool isPseudo(const std::string& str);

#endif
