/**
 * OpenAPI Petstore
 * This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.
 *
 * OpenAPI spec version: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * https://github.com/OpenAPITools/openapi-generator
 * Do not edit the class manually.
 */

#pragma once

#include "CoreMinimal.h"
#include "ModelPrefixBaseModel.h"

namespace CppNamespace 
{

class PETSTORE_API ModelPrefixPetApi
{
public:
	ModelPrefixPetApi();
	~ModelPrefixPetApi();

	void SetURL(const FString& Url);
	void AddHeaderParam(const FString& Key, const FString& Value);
	void ClearHeaderParams();

	class AddPetRequest;
	class AddPetResponse;
	class DeletePetRequest;
	class DeletePetResponse;
	class FindPetsByStatusRequest;
	class FindPetsByStatusResponse;
	class FindPetsByTagsRequest;
	class FindPetsByTagsResponse;
	class GetPetByIdRequest;
	class GetPetByIdResponse;
	class UpdatePetRequest;
	class UpdatePetResponse;
	class UpdatePetWithFormRequest;
	class UpdatePetWithFormResponse;
	class UploadFileRequest;
	class UploadFileResponse;
	
    DECLARE_DELEGATE_OneParam(FAddPetDelegate, const AddPetResponse&);
    DECLARE_DELEGATE_OneParam(FDeletePetDelegate, const DeletePetResponse&);
    DECLARE_DELEGATE_OneParam(FFindPetsByStatusDelegate, const FindPetsByStatusResponse&);
    DECLARE_DELEGATE_OneParam(FFindPetsByTagsDelegate, const FindPetsByTagsResponse&);
    DECLARE_DELEGATE_OneParam(FGetPetByIdDelegate, const GetPetByIdResponse&);
    DECLARE_DELEGATE_OneParam(FUpdatePetDelegate, const UpdatePetResponse&);
    DECLARE_DELEGATE_OneParam(FUpdatePetWithFormDelegate, const UpdatePetWithFormResponse&);
    DECLARE_DELEGATE_OneParam(FUploadFileDelegate, const UploadFileResponse&);
    
    bool AddPet(const AddPetRequest& Request, const FAddPetDelegate& Delegate = FAddPetDelegate()) const;
    bool DeletePet(const DeletePetRequest& Request, const FDeletePetDelegate& Delegate = FDeletePetDelegate()) const;
    bool FindPetsByStatus(const FindPetsByStatusRequest& Request, const FFindPetsByStatusDelegate& Delegate = FFindPetsByStatusDelegate()) const;
    bool FindPetsByTags(const FindPetsByTagsRequest& Request, const FFindPetsByTagsDelegate& Delegate = FFindPetsByTagsDelegate()) const;
    bool GetPetById(const GetPetByIdRequest& Request, const FGetPetByIdDelegate& Delegate = FGetPetByIdDelegate()) const;
    bool UpdatePet(const UpdatePetRequest& Request, const FUpdatePetDelegate& Delegate = FUpdatePetDelegate()) const;
    bool UpdatePetWithForm(const UpdatePetWithFormRequest& Request, const FUpdatePetWithFormDelegate& Delegate = FUpdatePetWithFormDelegate()) const;
    bool UploadFile(const UploadFileRequest& Request, const FUploadFileDelegate& Delegate = FUploadFileDelegate()) const;
    
private:
    void OnAddPetResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FAddPetDelegate Delegate) const;
    void OnDeletePetResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FDeletePetDelegate Delegate) const;
    void OnFindPetsByStatusResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FFindPetsByStatusDelegate Delegate) const;
    void OnFindPetsByTagsResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FFindPetsByTagsDelegate Delegate) const;
    void OnGetPetByIdResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetPetByIdDelegate Delegate) const;
    void OnUpdatePetResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUpdatePetDelegate Delegate) const;
    void OnUpdatePetWithFormResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUpdatePetWithFormDelegate Delegate) const;
    void OnUploadFileResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUploadFileDelegate Delegate) const;
    
	bool IsValid() const;
	void HandleResponse(FHttpResponsePtr HttpResponse, bool bSucceeded, Response& InOutResponse) const;

	FString Url;
	TMap<FString,FString> AdditionalHeaderParams;
};
	
}
