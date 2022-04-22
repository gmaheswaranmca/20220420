#pragma once
namespace MyUtil {
	namespace in {
		void read(char* caption, int& data);
		void read(char* caption, float& data);
		void read(char* caption, char* data);
	}
	namespace out {
		void print(char* caption, int& data);
		void print(char* caption, float& data);
		void print(char* caption, char* data);
	}
}