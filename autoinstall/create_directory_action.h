#pragma once
#include "install_action.h"
#include "windows_exception.h"


class CreateDirException : public WindowsException
{
	std::string prefix_message() const;
};

class DirAlreadyExists : public std::exception {};

class CreateDirAction : public InstallAction
{
private:
	const std::wstring directory_;
public:
	CreateDirAction(const std::wstring& directory, 
		const LPSECURITY_ATTRIBUTES& lpSecurityAttributes=NULL);
	~CreateDirAction();
};
