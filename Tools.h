#pragma once
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <regex>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>

class Tools {
public:
	static std::vector<std::string> splitString(const char* input);     // �ָ��ַ���
	static std::vector<std::string> splitString(const std::string& str);
	static void printAllBits(unsigned char* buffer, size_t length);   // ��ӡ����bit
	static int compareBit(unsigned char c1, unsigned char c2);  // ��λ�ԱȲ����ز�ͬ��λ�±�
	static bool compareByte(unsigned char* buffer1, unsigned char* buffer2, int size); // �ж��Ƿ���ͬ
	static void preciseSleep(double nanoseconds);   // ���뼶��ʱ��
	static void checkForEscExit();
};
