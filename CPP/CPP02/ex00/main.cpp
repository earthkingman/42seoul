#include "Fixed.hpp"

int main(void)
{
    Fixed a;    // 빈 객체 생성 기본 생성자 호출
    Fixed b(a); //복사 생성자 호출  깊은 복사가 일어남
    Fixed c;    // 빈 객체 생성
    c = b;      //대입 연산자 오버로딩 호출 -> 대입연산자가 결국 복사 생성자를 호출함

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}