// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "UE4APIGameModeBase.h"

#include "HttpModule.h"
#include "HttpManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogUE4API, Log, All);

#include "Petstore/ModelPrefixUserApiOperations.h"
#include "Petstore/ModelPrefixPetApiOperations.h"
#include "Petstore/ModelPrefixStoreApiOperations.h"

void AUE4APIGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	m_petApi = MakeShared<ModelPrefixPetApi>();

	m_storeApi = MakeShared<ModelPrefixStoreApi>();

	m_userApi = MakeShared<ModelPrefixUserApi>();

	{
		ModelPrefixUserApi::CreateUserRequest request;
		request.Body.Username = "Kryofenix";
		request.Body.Email = "kryofenix@kryofenix.com";
		request.Body.Password = "Kryofenix";
		m_userApi->CreateUser(request, ModelPrefixUserApi::FCreateUserDelegate::CreateLambda([](const ModelPrefixUserApi::CreateUserResponse& a_response)
			{
				if (a_response.IsSuccessful())
				{
					UE_LOG(LogUE4API, Log, TEXT("Success!"));
				}
				else
				{
					UE_LOG(LogUE4API, Error, TEXT("Fail!"));
				}
			}));
	}

	FHttpModule::Get().GetHttpManager().Flush(false);

	{
		ModelPrefixUserApi::LoginUserRequest request;
		request.Username = "Kryofenix";
		request.Password = "Kryofenix";
		m_userApi->LoginUser(request, ModelPrefixUserApi::FLoginUserDelegate::CreateLambda([](const ModelPrefixUserApi::LoginUserResponse& a_response) 
			{
				if (a_response.IsSuccessful())
				{
					UE_LOG(LogUE4API, Log, TEXT("Success! %s"), *a_response.Content);
				}
			}));
	}

	FHttpModule::Get().GetHttpManager().Flush(false);
	
	{
		ModelPrefixPetApi::FindPetsByStatusRequest request;
		request.Status = TArray<FString>({ TEXT("sold") });
		m_petApi->FindPetsByStatus(request, ModelPrefixPetApi::FFindPetsByStatusDelegate::CreateLambda([](const ModelPrefixPetApi::FindPetsByStatusResponse& a_response)
			{
				if (a_response.IsSuccessful())
				{
					UE_LOG(LogUE4API, Log, TEXT("Success!"));
				}
			}));
	}

	FHttpModule::Get().GetHttpManager().Flush(false);
}
