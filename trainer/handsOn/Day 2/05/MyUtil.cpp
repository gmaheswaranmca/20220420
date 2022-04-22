#include<iostream>
#include"MyUtil.h"
namespace MyUtil {
	namespace in {
		void read(char* caption, int& data) {
			std::cout << caption;
			std::cin >> data;
		}
		void read(char* caption, float& data) {
			std::cout << caption;
			std::cin >> data;
		}
		void read(char* caption, char* data) {
			std::cout << caption;
			std::cin >> data;
		}
	}
	namespace out {
		void print(char* caption, int& data) {
			std::cout << caption << data << std::endl;
		}
		void print(char* caption, float& data) {
			std::cout << caption << data << std::endl;
		}
		void print(char* caption, char* data) {
			std::cout << caption << data << std::endl;
		}
	}
}