#pragma once
#include <Windows.h>
#include <string>
#include <exception>

class WindowsException : public std::exception
{
	DWORD windows_error_code_;
public:
	WindowsException();
	
	virtual std::string prefix_message(); // Virtual function to change prefix message of print_error_message
	void print_error_code_message();
};
