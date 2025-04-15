#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int fixedPointValue;
    static const int fractionalBits = 8;

public:
    Fixed(); // デフォルトコンストラクタ
    Fixed(const int value); // 整数を受け取るコンストラクタ
    Fixed(const float value); // 浮動小数点数を受け取るコンストラクタ
    Fixed(const Fixed &other); // コピーコンストラクタ
    Fixed &operator=(const Fixed &other); // コピー代入演算子オーバーロード
    ~Fixed(); // デストラクタ

    int getRawBits() const; // 生の固定小数点値を返すメンバ関数
    void setRawBits(int const raw); // 生の固定小数点値を設定するメンバ関数
    float toFloat() const; // 固定小数点値を浮動小数点数に変換するメンバ関数
    int toInt() const; // 固定小数点値を整数に変換するメンバ関数
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed); // 挿入演算子のオーバーロード

#endif // FIXED_HPP