#pragma once

// #define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility> // 包含 std::move
#include <cstring> // 包含 std::strlen, std::strcpy

class StringContainer 
{
public:
    // 构造函数
    StringContainer(const char* str) 
    {
        std::cout << "Constructor called\n";
        size_ = std::strlen(str);
        data_ = new char[size_ + 1]; // +1 用于存储字符串的结尾空字符 '\0'
        std::strcpy(data_, str);
    }

    // 移动构造函数
    StringContainer(StringContainer&& other) noexcept 
    {
        std::cout << "Move constructor called\n";
        // 直接移动资源
        size_ = other.size_;
        data_ = other.data_;
        // 将源对象的资源置为空，避免重复释放
        other.size_ = 0;
        other.data_ = nullptr;
    }


    StringContainer& operator=(const StringContainer& other)
    {
        std::cout << "Assignment operator called\n";
        if (this != &other)
        {
            // 避免自赋值
            delete[] data_;   // 释放当前对象的资源
            size_ = other.size_;
            data_ = new char[size_ + 1];   // +1 用于存储字符串的结尾空字符 '\0'
            std::strcpy(data_, other.data_);
        }

        return *this; // 返回当前对象的引用，以支持连续赋值
    }
 

    StringContainer(const StringContainer& other)
    {
        std::cout << "copy constructor called\n";
        size_ = other.size_;
        data_ = new char[size_ + 1];
        std::strcpy(data_, other.data_);
    }


    // 析构函数
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

// 返回一个 StringContainer 对象的函数
StringContainer createStringContainer(const char* str) {
    return StringContainer(str);
}

