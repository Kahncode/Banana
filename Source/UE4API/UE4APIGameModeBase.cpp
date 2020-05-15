// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "UE4APIGameModeBase.h"

#include "HttpModule.h"
#include "HttpManager.h"
#include "Misc/Paths.h"

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

		FHttpModule::Get().GetHttpManager().Flush(false);
	}

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

		FHttpModule::Get().GetHttpManager().Flush(false);
	}

	ModelPrefixPet pet;
	
	{
		ModelPrefixPetApi::FindPetsByStatusRequest request;
		request.Status = TArray<FString>({ TEXT("sold") });
		m_petApi->FindPetsByStatus(request, ModelPrefixPetApi::FFindPetsByStatusDelegate::CreateLambda([&pet](const ModelPrefixPetApi::FindPetsByStatusResponse& a_response)
			{
				if (a_response.IsSuccessful())
				{
					UE_LOG(LogUE4API, Log, TEXT("Success!"));
					if(a_response.Content.Num() > 0)
						pet = a_response.Content[0];
				}
			}));

		FHttpModule::Get().GetHttpManager().Flush(false);
	}

	{
		ModelPrefixPetApi::UpdatePetWithFormRequest request;
		request.PetId = pet.Id.GetValue();
		request.Name = TEXT("Banana");
		m_petApi->UpdatePetWithForm(request, ModelPrefixPetApi::FUpdatePetWithFormDelegate::CreateLambda([&pet](const ModelPrefixPetApi::UpdatePetWithFormResponse& a_response)
			{
				if (a_response.IsSuccessful())
				{
					UE_LOG(LogUE4API, Log, TEXT("Success!"));
				}
			}));

		FHttpModule::Get().GetHttpManager().Flush(false);
	}

	{
		ModelPrefixPetApi::GetPetByIdRequest request;
		request.PetId = pet.Id.GetValue();
		m_petApi->GetPetById(request, ModelPrefixPetApi::FGetPetByIdDelegate::CreateLambda([&pet](const ModelPrefixPetApi::GetPetByIdResponse& a_response)
		{
			if (a_response.IsSuccessful())
			{
				if (a_response.Content.Name == TEXT("Banana"))
				{
					UE_LOG(LogUE4API, Log, TEXT("Success!"));
				}
			}
		}));

		FHttpModule::Get().GetHttpManager().Flush(false);
	}

	{
		ModelPrefixPetApi::UploadFileRequest request;
		request.PetId = pet.Id.GetValue();
		request.File = FPaths::Combine(FPaths::ProjectContentDir(), TEXT("headcrab.jpg"));
		m_petApi->UploadFile(request, ModelPrefixPetApi::FUploadFileDelegate::CreateLambda([&pet](const ModelPrefixPetApi::UploadFileResponse& a_response)
			{
				if (a_response.IsSuccessful())
				{
					UE_LOG(LogUE4API, Log, TEXT("Success!"));
				}
			}));

		FHttpModule::Get().GetHttpManager().Flush(false);
	}
}
