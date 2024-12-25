#pragma once
#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include "Tools.h"

class DataInform {
public:
    std::string address;
    std::string area;
    std::string type;
    int size;

    int blockNum;
    int addInBlock;

    // Ĭ�Ϲ��캯��
    DataInform();

    // �������Ĺ��캯��
    DataInform(std::string address, std::string area, std::string type);

    // Get ����
    int GetSize(std::string type);
    int GetOffset(std::string address);
    int GetMiniOffset(std::string address);


    // ��ֵ������
    DataInform& operator=(const DataInform& other);
};

#endif // DATASTRUCTURE_H