#ifndef SCALARCONVERTER
 # define SCALARCONVERTE

# include <string>
# include <iostream>
# include <string>
# include <limits>
# include <cmath>
# include <iomanip>
# include <cstdlib>

/**
 * @file ScalarConverter.hpp
 * @brief スカラ型のリテラル文字列を検出し、各型へ変換・表示するクラス
 */

class ScalarConverter
{
    public:
        /**
         * @brief リテラル文字列が該当するスカラ型の種類
        */
        enum e_type
        {
            CHAR,   /**< 文字型リテラル */
            INT,    /**< 整数型リテラル */
            FLOAT,  /**< 単精度浮動小数点リテラル */
            DOUBLE, /**< 倍精度浮動小数点リテラル */
            PSEUDO, /**< 擬似リテラル（nan, inf等） */
            INVALID /**< 解釈不能な文字列 */
        };

        /**
         * @brief 文字列表現のリテラルを char, int, float, double に変換して出力する
         * @param literal C++リテラルの文字列形式
         * @note このメソッド内で型の検出、実際の型への変換、他の型への明示的変換、結果の表示をすべて行う
		*/
        static void convert(const std::string& literal);

    private:
        /**
         * @brief 文字列の内容を解析し、最適なスカラ型を特定する
         * @param literal 解析対象の文字列
         * @return 文字列の構造に基づいた e_type 列挙型の値
         */
        static e_type detectType(const std::string& literal);

        /* --- OCF --- */
        /**
         * @brief インスタンス化を禁止するため非公開とする
         */
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter& operator=(const ScalarConverter& copy);
};


#endif //SCALARCONVERTER
