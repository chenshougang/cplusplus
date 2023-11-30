#pragma once

// #define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility> // ���� std::move
#include <cstring> // ���� std::strlen, std::strcpy

class StringContainer 
{
public:
    // ���캯��
    StringContainer(const char* str) 
    {
        std::cout << "Constructor called\n";
        size_ = std::strlen(str);
        data_ = new char[size_ + 1]; // +1 ���ڴ洢�ַ����Ľ�β���ַ� '\0'
        std::strcpy(data_, str);
    }

    // �ƶ����캯��
    StringContainer(StringContainer&& other) noexcept 
    {
        std::cout << "Move constructor called\n";
        // ֱ���ƶ���Դ
        size_ = other.size_;
        data_ = other.data_;
        // ��Դ�������Դ��Ϊ�գ������ظ��ͷ�
        other.size_ = 0;
        other.data_ = nullptr;
    }


    StringContainer& operator=(const StringContainer& other)
    {
        std::cout << "Assignment operator called\n";
        if (this != &other)
        {
            // �����Ը�ֵ
            delete[] data_;   // �ͷŵ�ǰ�������Դ
            size_ = other.size_;
            data_ = new char[size_ + 1];   // +1 ���ڴ洢�ַ����Ľ�β���ַ� '\0'
            std::strcpy(data_, other.data_);
        }

        return *this; // ���ص�ǰ��������ã���֧��������ֵ
    }
 

    StringContainer(const StringContainer& other)
    {
        std::cout << "copy constructor called\n";
        size_ = other.size_;
        data_ = new char[size_ + 1];
        std::strcpy(data_, other.data_);
    }


    // ��������
    ~StringContainer() 
    {
        std::cout << "Destructor called\n";
        delete[] data_;
    }

    void print_address()
    {
        std::cout << "data_ address = " << static_cast<const void*>(data_) << std::endl;
    }

    void print_message()
    {
        std::cout << "data_ = " << data_ << std::endl;
    }

private:
    size_t size_;
    char* data_;
};

// ����һ�� StringContainer ����ĺ���
StringContainer createStringContainer(const char* str) {
    return StringContainer(str);
}

