#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
    int fixedPointValue;
    static const int fractionalBits = 8;

public:
    Fixed(); // デフォルトコンストラクタ
    Fixed(const Fixed &other); // コピーコンストラクタ
    Fixed &operator=(const Fixed &other); // コピー代入演算子オーバーロード
    ~Fixed(); // デストラクタ

    int getRawBits() const; // 生の固定小数点値を返すメンバ関数
    void setRawBits(int const raw); // 生の固定小数点値を設定するメンバ関数
};

#endif // FIXED_HPP