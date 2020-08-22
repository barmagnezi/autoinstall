#pragma once

/**
* Abstract class that represent some action that done by installation.
* The class do some action in constructor and revert it automatically if installation failed.
* The subclasses will use is_install_success function to check if installtion finish successfully.
*/
class InstallAction
{
private:
	bool install_success_ = false;
public:
	void update_install_success();
	bool is_install_success() const;
	virtual ~InstallAction() = default;
};