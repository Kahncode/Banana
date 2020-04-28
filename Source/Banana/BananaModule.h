#pragma once

#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "Logging/LogMacros.h"

#include "BananaAPI.h"

DECLARE_LOG_CATEGORY_EXTERN(LogBanana, Log, All);

class BANANA_API BananaModule : public IModuleInterface
{
public:
	void StartupModule() override;
	void ShutdownModule() override;

    /**
    * Singleton-like access to this module's interface.  This is just for convenience!
    * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
    *
    * @return Returns singleton instance, loading the module on demand if needed
    */
    static inline BananaModule& Get()
    {
        return FModuleManager::LoadModuleChecked<BananaModule>("Banana");
    }

    TSharedPtr<Banana::BananaAPI> CreateClientAPI() const;
};
