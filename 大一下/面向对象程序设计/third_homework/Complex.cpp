#include "Complex.h"
#include <iomanip>
#include <cmath>

// 1. 构造函数实现
Complex::Complex(double Re, double Im) : Re(Re), Im(Im) {}

// 转换构造函数：允许 double 隐式转换为 Complex，从而完美支持混合运算
Complex::Complex(double d) : Re(d), Im(0.0) {}

// 2. 单目运算符重载
// 取共轭：实部不变，虚部取反
Complex Complex::operator~() const {
    return Complex(Re, -Im);
}

// 取负数：实部和虚部均取反
Complex Complex::operator-() const {
    return Complex(-Re, -Im);
}

// 3. 全局双目四则运算符重载
// 加法：(a + bi) + (c + di) = (a + c) + (b + d)i
Complex operator+(Complex c1, Complex c2) {
    return Complex(c1.Re + c2.Re, c1.Im + c2.Im);
}

// 减法：(a + bi) - (c + di) = (a - c) + (b - d)i
Complex operator-(Complex c1, Complex c2) {
    return Complex(c1.Re - c2.Re, c1.Im - c2.Im);
}

// 乘法：(a + bi) * (c + di) = (ac - bd) + (bc + ad)i
Complex operator*(Complex c1, Complex c2) {
    return Complex(c1.Re * c2.Re - c1.Im * c2.Im, c1.Re * c2.Im + c1.Im * c2.Re);
}

// 除法：((ac + bd) / (c^2 + d^2)) + ((bc - ad) / (c^2 + d^2))i
Complex operator/(Complex c1, Complex c2) {
    double denom = c2.Re * c2.Re + c2.Im * c2.Im;
    return Complex((c1.Re * c2.Re + c1.Im * c2.Im) / denom,
                   (c1.Im * c2.Re - c1.Re * c2.Im) / denom);
}

// 4. 计算复数模长的全局函数
double abs(Complex & c) {
    return sqrt(c.Re * c.Re + c.Im * c.Im);
}

// 5. 用户自定义字面量 i 的实现
Complex operator""i(unsigned long long Im) {
    return Complex(0.0, static_cast<double>(Im));
}

Complex operator""i(long double Im) {
    return Complex(0.0, static_cast<double>(Im));
}

// 6. 流输出运算符重载（核心格式控制陷阱区）
ostream & operator<<(ostream & os, const Complex & c) {
    // 定义绝对值小于 10^-5 为 0
    bool real_zero = std::abs(c.Re) < 1e-5;
    bool imag_zero = std::abs(c.Im) < 1e-5;

    // 暂存原有的流状态，并设置为保留两位小数的浮点格式
    std::ios_base::fmtflags f(os.flags());
    os << std::fixed << std::setprecision(2);

    if (real_zero && imag_zero) {
        // 两者都为 0 时输出 0.00
        os << "0.00";
    } else if (real_zero) {
        // 实部为 0，只输出虚部
        os << c.Im << "i";
    } else if (imag_zero) {
        // 虚部为 0，只输出实部
        os << c.Re;
    } else {
        // 两者均不为 0
        os << c.Re;
        if (c.Im > 0) {
            os << " + " << c.Im << "i";
        } else {
            os << " - " << std::abs(c.Im) << "i"; // 负号两边带空格
        }
    }

    // 恢复流的原始状态
    os.flags(f);
    return os;
}