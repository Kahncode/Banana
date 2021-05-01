// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "UE4APIGameModeBase.h"

#include "HttpModule.h"
#include "HttpManager.h"
#include "Misc/Paths.h"
#include "HttpRetrySystem.h"

DEFINE_LOG_CATEGORY_STATIC(LogUE4API, Log, All);

#include "ModelPrefixUserApiOperations.h"
#include "ModelPrefixPetApiOperations.h"
#include "ModelPrefixStoreApiOperations.h"
#include "ModelPrefixHelpers.h"

//#include "SwaggerDefaultApiOperations.h"


void AUE4APIGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	using namespace CppNamespace;

	FDateTime dt;
	bool success = CppNamespace::ParseDateTime(TEXT("2021-03-12T15:07:59.0333305Z"), dt);


	/*{
		auto testApi = MakeShared<SwaggerDefaultApi>();

		SwaggerDefaultApi::AddPetRequest request;
		request.Body.Int1 = 456789;
		request.Body.Int2 = 456789;
		request.Body.Int3 = 456789;
		request.Body.Number1 = 123.456789;
		request.Body.Number2 = 123.456789;
		request.Body.Number3 = 123.456789;
		request.Body.String = TEXT("hello world");
		request.Body.StringByte = { 1, 2, 3, 4, 5 };
		request.Body.StringBinary = { 1, 2, 3, 4, 5 };
		request.Body.Boolean = true;
		request.Body.Date = FDateTime::UtcNow();
		request.Body.DateTime = FDateTime::UtcNow();
		request.Body.Password = TEXT("hello world");

		testApi->AddPet(request);
	}*/


	m_petApi = MakeShared<ModelPrefixPetApi>();

	m_storeApi = MakeShared<ModelPrefixStoreApi>();

	m_userApi = MakeShared<ModelPrefixUserApi>();

	{
		ModelPrefixUserApi::CreateUserRequest request;
		request.Body.Username = "Kryofenix";
		request.Body.Email = "kryofenix@kryofenix.com";
		request.Body.Password = "Kryofenix";
		request.SetAutoRetryCount(5);
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
		request.SetRetryParams();

		request.Status = TArray<ModelPrefixPetApi::FindPetsByStatusRequest::StatusEnum>({ ModelPrefixPetApi::FindPetsByStatusRequest::StatusEnum::Sold });
		m_petApi->FindPetsByStatus(request, ModelPrefixPetApi::FFindPetsByStatusDelegate::CreateLambda([&pet](const ModelPrefixPetApi::FindPetsByStatusResponse& a_response)
			{
				if (a_response.IsSuccessful())
				{
					UE_LOG(LogUE4API, Log, TEXT("Success!"));
					if(a_response.Content.Num() > 0)
						pet = a_response.Content[0];
				}
			}));

		m_petApi->GetHttpRetryManager().BlockUntilFlushed(60);
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
		request.File = HttpFileInput(FPaths::Combine(FPaths::ProjectContentDir(), TEXT("headcrab.jpg")));
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
