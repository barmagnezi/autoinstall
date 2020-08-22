#include "install_action.h"

void InstallAction::update_install_success()
{
	install_success_ = true;
}

bool InstallAction::is_install_success()
{
	return install_success_;
}