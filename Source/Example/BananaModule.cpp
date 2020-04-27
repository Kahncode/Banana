#include "BananaModule.h"

#include "Templates/SharedPointer.h"

DEFINE_LOG_CATEGORY(LogBanana);

void BananaModule::StartupModule()
{
}

void BananaModule::ShutdownModule()
{
}

TSharedPtr<Banana::BananaAPI> BananaModule::CreateClientAPI() const
{
	return MakeShared<Banana::BananaAPI>();
}

IMPLEMENT_MODULE(BananaModule, Banana);
