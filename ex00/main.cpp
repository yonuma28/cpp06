#include "ScalarConverter.hpp"
#include <iostream>

/**
 * @brief プログラムのメインエントリポイント
 * @param argc 引数の数
 * @param argv 引数の配列 (argv[1] にリテラル文字列を期待)
 * @return int 終了ステータス (0: 成功, 1: エラー)
 */
int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }

    try
    {
        ScalarConverter::convert(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: An unexpected error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
