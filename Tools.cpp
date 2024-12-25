#include "Tools.h"

std::vector<std::string> Tools::splitString(const char* input) {
	std::vector<std::string> result;
	std::stringstream ss(input);
	std::string token;

	// �����ŷָ��ַ���
	while (getline(ss, token, ',')) {
		result.push_back(token);
	}
	// profile�ļ��в����п��У���������vector����Խ�籨��
	return result;
}
std::vector<std::string> Tools::splitString(const std::string& str) {
	std::vector<std::string> result;
	std::regex pattern("([a-zA-Z]+)([0-9]+)(\\.[0-9]+)?(\\.[0-9]+)?");
	std::smatch matches;

	if (regex_match(str, matches, pattern)) {
		for (size_t i = 1; i < matches.size(); ++i) {
			if (matches[i].matched) {
				std::string part = matches[i].str();
				// Remove the dot if present
				if (part.front() == '.') {
					part = part.substr(1); // Remove the first character (dot)
				}
				result.push_back(part);
			}
		}
	}

	return result;
}
void Tools::printAllBits(unsigned char* buffer, size_t length) {
	for (size_t i = 0; i < length; ++i) {
		for (int j = 0; j < 8; j++) {
			std::cout << ((buffer[i] >> j) & 1);
		}
		std::cout << " ";  // ÿ���ֽ�֮��Ӹ��ո�
	}
	std::cout << std::endl;
}
int Tools::compareBit(unsigned char c1, unsigned char c2) {
	int result = 0;
	for (; result < 8; ++result) {
		// ��λ�Ƚ�
		if ((c1 & 1) != (c2 & 1)) {
			break;
		}
		// ����һλ���Ƚ���һλ
		c1 >>= 1;
		c2 >>= 1;
	}
	return result;
}
bool Tools::compareByte(unsigned char* buffer1, unsigned char* buffer2, int size) {

	for (int i = 0; i < size; ++i) {

		unsigned char byte1 = buffer1[i];
		unsigned char byte2 = buffer2[i];

		for (int bit = 0; bit < 8; ++bit) {
			unsigned char bit1 = (byte1 >> bit) & 0x01;
			unsigned char bit2 = (byte2 >> bit) & 0x01;

			if (bit1 != bit2) {
				return 0;
			}
		}
	}

	return 1;
}
void Tools::preciseSleep(double nanoseconds) {
	if (nanoseconds < 0) return;

	LARGE_INTEGER frequency;        // ��ʱ��Ƶ��
	LARGE_INTEGER start, end;       // ��ʼ�ͽ���ʱ��
	double elapsedTime;             // ��ʱ

	// ��ȡ��ʱ��Ƶ��
	QueryPerformanceFrequency(&frequency);

	// ��������ļ�ʱ������
	double counts = (nanoseconds * frequency.QuadPart) / 1000000000.0;

	// ��ȡ��ʼʱ��
	QueryPerformanceCounter(&start);

	do {
		// ��ȡ��ǰʱ��
		QueryPerformanceCounter(&end);

		// ����ʱ���
		elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart);

	} while (elapsedTime < counts);
}
void Tools::checkForEscExit() {
	while (1) {
	
		if (_kbhit()) { // ����Ƿ��а�������
			char key = _getch(); // ��ȡ���µļ�
			if (key == 27) { // 27 �� Esc ���� ASCII ��
				//std::cout << "��⵽ Esc �����˳�����" << std::endl;
				exit(0); // �˳�����
			}
		}
	}
}