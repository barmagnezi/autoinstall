#include "create_directory_action.h"
#include <iostream>
#include <string>
#include <sstream>


std::string CreateDirException::prefix_message() {
	return "Create directory failed with error code:";
}

CreateDirAction::CreateDirAction(std::wstring directory, LPSECURITY_ATTRIBUTES lpSecurityAttributes) : directory_(directory)
{
	if (CreateDirectory(directory_.c_str(
), lpSecurityAttributes))
	{
		std::wcout << L"Create " << directory_ << L"." << std::endl;
		dir_created_ = true;
	}
	else if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		throw DirAlreadyExists();
	}
	else
	{
		//throw CreateDirException(GetLastError());
		throw CreateDirException();
	}	
}

CreateDirAction::~CreateDirAction()
{
	 std::cout << std::uncaught_exception() << std::endl;
	if (dir_created_ && !is_install_success())
	{
		if (!RemoveDirectory(directory_.c_str()))
		{
			std::wcout << L"Error deleting directory " << directory_ << L", continue (" << GetLastError() << ")" <<std::endl;
		}
		else
		{
			std::wcout << L"Directory " << directory_ << L" deleted." << std::endl;
		}
	}
}