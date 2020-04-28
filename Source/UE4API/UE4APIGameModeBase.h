// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "Petstore/ModelPrefixStoreApi.h"
#include "Petstore/ModelPrefixPetApi.h"
#include "Petstore/ModelPrefixUserApi.h"

#include "UE4APIGameModeBase.generated.h"

using namespace CppNamespace;
/**
 * 
 */
UCLASS()
class UE4API_API AUE4APIGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	void BeginPlay() override;

	TSharedPtr<ModelPrefixPetApi> m_petApi;
	TSharedPtr<ModelPrefixStoreApi> m_storeApi;
	TSharedPtr<ModelPrefixUserApi> m_userApi;
};
