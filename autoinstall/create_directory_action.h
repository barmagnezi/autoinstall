#pragma once

#include <string>
#include <Windows.h>

#include "install_action.h"
#include "windows_exception.h"


class CreateDirException : public WindowsException
{
	std::string prefix_message();
};

class DirAlreadyExists : public std::exception {};

class CreateDirAction : public InstallAction
{
private:
	bool dir_created_ = false;
	std::wstring directory_;
public:
	CreateDirAction(std::wstring directory, 
		LPSECURITY_ATTRIBUTES lpSecurityAttributes=NULL);
	~CreateDirAction();
};
