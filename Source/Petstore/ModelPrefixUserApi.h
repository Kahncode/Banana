/**
 * Swagger Petstore
 * This is a sample server Petstore server.  You can find out more about Swagger at [http://swagger.io](http://swagger.io) or on [irc.freenode.net, #swagger](http://swagger.io/irc/).  For this sample, you can use the api key `special-key` to test the authorization filters.
 *
 * OpenAPI spec version: 1.0.0
 * Contact: apiteam@swagger.io
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

#pragma once

#include "ModelPrefixBaseModel.h"

#include "CoreMinimal.h"

typedef TSharedPtr<IHttpRequest> FHttpRequestPtr;
typedef TSharedPtr<IHttpResponse, ESPMode::ThreadSafe> FHttpResponsePtr;

namespace CppNamespace 
{
    class PETSTORE_API ModelPrefixUserApi
	{
	public:
		ModelPrefixUserApi();
		~ModelPrefixUserApi();

		void SetURL(const FString& Url);
		void AddHeaderParam(const FString& Key, const FString& Value);
		void ClearHeaderParams();

		class CreateUserRequest;
    	class CreateUserResponse;
		class CreateUsersWithArrayInputRequest;
    	class CreateUsersWithArrayInputResponse;
		class CreateUsersWithListInputRequest;
    	class CreateUsersWithListInputResponse;
		class DeleteUserRequest;
    	class DeleteUserResponse;
		class GetUserByNameRequest;
    	class GetUserByNameResponse;
		class LoginUserRequest;
    	class LoginUserResponse;
		class LogoutUserRequest;
    	class LogoutUserResponse;
		class UpdateUserRequest;
    	class UpdateUserResponse;
		
        DECLARE_DELEGATE_OneParam(FCreateUserDelegate, const CreateUserResponse&);
        DECLARE_DELEGATE_OneParam(FCreateUsersWithArrayInputDelegate, const CreateUsersWithArrayInputResponse&);
        DECLARE_DELEGATE_OneParam(FCreateUsersWithListInputDelegate, const CreateUsersWithListInputResponse&);
        DECLARE_DELEGATE_OneParam(FDeleteUserDelegate, const DeleteUserResponse&);
        DECLARE_DELEGATE_OneParam(FGetUserByNameDelegate, const GetUserByNameResponse&);
        DECLARE_DELEGATE_OneParam(FLoginUserDelegate, const LoginUserResponse&);
        DECLARE_DELEGATE_OneParam(FLogoutUserDelegate, const LogoutUserResponse&);
        DECLARE_DELEGATE_OneParam(FUpdateUserDelegate, const UpdateUserResponse&);
        
        bool CreateUser(const CreateUserRequest& Request, const FCreateUserDelegate& Delegate = FCreateUserDelegate()) const;
        bool CreateUsersWithArrayInput(const CreateUsersWithArrayInputRequest& Request, const FCreateUsersWithArrayInputDelegate& Delegate = FCreateUsersWithArrayInputDelegate()) const;
        bool CreateUsersWithListInput(const CreateUsersWithListInputRequest& Request, const FCreateUsersWithListInputDelegate& Delegate = FCreateUsersWithListInputDelegate()) const;
        bool DeleteUser(const DeleteUserRequest& Request, const FDeleteUserDelegate& Delegate = FDeleteUserDelegate()) const;
        bool GetUserByName(const GetUserByNameRequest& Request, const FGetUserByNameDelegate& Delegate = FGetUserByNameDelegate()) const;
        bool LoginUser(const LoginUserRequest& Request, const FLoginUserDelegate& Delegate = FLoginUserDelegate()) const;
        bool LogoutUser(const LogoutUserRequest& Request, const FLogoutUserDelegate& Delegate = FLogoutUserDelegate()) const;
        bool UpdateUser(const UpdateUserRequest& Request, const FUpdateUserDelegate& Delegate = FUpdateUserDelegate()) const;
        
	private:
        void OnCreateUserResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FCreateUserDelegate Delegate) const;
        void OnCreateUsersWithArrayInputResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FCreateUsersWithArrayInputDelegate Delegate) const;
        void OnCreateUsersWithListInputResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FCreateUsersWithListInputDelegate Delegate) const;
        void OnDeleteUserResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FDeleteUserDelegate Delegate) const;
        void OnGetUserByNameResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetUserByNameDelegate Delegate) const;
        void OnLoginUserResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FLoginUserDelegate Delegate) const;
        void OnLogoutUserResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FLogoutUserDelegate Delegate) const;
        void OnUpdateUserResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUpdateUserDelegate Delegate) const;
        
		bool IsValid() const;
		void HandleResponse(FHttpResponsePtr HttpResponse, bool bSucceeded, Response& InOutResponse) const;

		FString Url;
		TMap<FString,FString> AdditionalHeaderParams;
	};

}
