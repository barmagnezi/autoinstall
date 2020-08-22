#pragma once
#include <exception>
#include <string>

class InstallAction
{
protected:
	bool install_success_ = false;
public:
	void update_install_success();
	bool is_install_success();
	virtual ~InstallAction() = default;
};