#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        // 通常のケース
        std::cout << "=== Normal Case Test ===" << std::endl;
        Bureaucrat normal("Normal", 75);
        std::cout << normal << std::endl;

        // グレードの増減をテスト
        std::cout << "\n=== Grade Modification Test ===" << std::endl;
        normal.incrementGrade();
        std::cout << "After increment: " << normal << std::endl;
        normal.decrementGrade();
        std::cout << "After decrement: " << normal << std::endl;

        // 最高グレードのテスト
        std::cout << "\n=== Highest Grade Test ===" << std::endl;
        Bureaucrat top("Top", 1);
        std::cout << top << std::endl;
        try {
            std::cout << "Attempting to increment grade 1..." << std::endl;
            top.incrementGrade();
        }
        catch (const Bureaucrat::GradeTooHighException& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        // 最低グレードのテスト
        std::cout << "\n=== Lowest Grade Test ===" << std::endl;
        Bureaucrat bottom("Bottom", 150);
        std::cout << bottom << std::endl;
        try {
            std::cout << "Attempting to decrement grade 150..." << std::endl;
            bottom.decrementGrade();
        }
        catch (const Bureaucrat::GradeTooLowException& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        // 無効なグレードでの生成テスト
        std::cout << "\n=== Invalid Grade Test ===" << std::endl;
        std::cout << "Attempting to create bureaucrat with grade 151..." << std::endl;
        Bureaucrat invalid("Invalid", 151);
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}