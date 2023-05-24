// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MultiplayerSession/Public/MultiplayerSessionSubsystem.h"
#include "Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMultiplayerSessionSubsystem() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	MULTIPLAYERSESSION_API UClass* Z_Construct_UClass_UMultiplayerSessionSubsystem();
	MULTIPLAYERSESSION_API UClass* Z_Construct_UClass_UMultiplayerSessionSubsystem_NoRegister();
	MULTIPLAYERSESSION_API UFunction* Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnCreateSessionComplete__DelegateSignature();
	MULTIPLAYERSESSION_API UFunction* Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnDestroySessionComplete__DelegateSignature();
	MULTIPLAYERSESSION_API UFunction* Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnStartSessionComplete__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_MultiplayerSession();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics
	{
		struct _Script_MultiplayerSession_eventMultiplayerOnCreateSessionComplete_Parms
		{
			bool bWasSuccessful;
		};
		static void NewProp_bWasSuccessful_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasSuccessful;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful_SetBit(void* Obj)
	{
		((_Script_MultiplayerSession_eventMultiplayerOnCreateSessionComplete_Parms*)Obj)->bWasSuccessful = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful = { "bWasSuccessful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(_Script_MultiplayerSession_eventMultiplayerOnCreateSessionComplete_Parms), &Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//Delegate for the menu class to bind callbacks\n//The multicast means that once casted multiple classes can bind to him\n//Dynamic means the delegate can be serialized and saved or loaded from a blueprint graph (Event Dispatchers)\n" },
		{ "ModuleRelativePath", "Public/MultiplayerSessionSubsystem.h" },
		{ "ToolTip", "Delegate for the menu class to bind callbacks\nThe multicast means that once casted multiple classes can bind to him\nDynamic means the delegate can be serialized and saved or loaded from a blueprint graph (Event Dispatchers)" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_MultiplayerSession, nullptr, "MultiplayerOnCreateSessionComplete__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::_Script_MultiplayerSession_eventMultiplayerOnCreateSessionComplete_Parms), Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnCreateSessionComplete__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics
	{
		struct _Script_MultiplayerSession_eventMultiplayerOnDestroySessionComplete_Parms
		{
			bool bWasSuccessful;
		};
		static void NewProp_bWasSuccessful_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasSuccessful;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful_SetBit(void* Obj)
	{
		((_Script_MultiplayerSession_eventMultiplayerOnDestroySessionComplete_Parms*)Obj)->bWasSuccessful = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful = { "bWasSuccessful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(_Script_MultiplayerSession_eventMultiplayerOnDestroySessionComplete_Parms), &Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MultiplayerSessionSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_MultiplayerSession, nullptr, "MultiplayerOnDestroySessionComplete__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::_Script_MultiplayerSession_eventMultiplayerOnDestroySessionComplete_Parms), Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnDestroySessionComplete__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnStartSessionComplete__DelegateSignature_Statics
	{
		struct _Script_MultiplayerSession_eventMultiplayerOnStartSessionComplete_Parms
		{
			bool bWasSuccessful;
		};
		static void NewProp_bWasSuccessful_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasSuccessful;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful_SetBit(void* Obj)
	{
		((_Script_MultiplayerSession_eventMultiplayerOnStartSessionComplete_Parms*)Obj)->bWasSuccessful = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful = { "bWasSuccessful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(_Script_MultiplayerSession_eventMultiplayerOnStartSessionComplete_Parms), &Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MultiplayerSessionSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_MultiplayerSession, nullptr, "MultiplayerOnStartSessionComplete__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::_Script_MultiplayerSession_eventMultiplayerOnStartSessionComplete_Parms), Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnStartSessionComplete__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_MultiplayerSession_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	void UMultiplayerSessionSubsystem::StaticRegisterNativesUMultiplayerSessionSubsystem()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMultiplayerSessionSubsystem);
	UClass* Z_Construct_UClass_UMultiplayerSessionSubsystem_NoRegister()
	{
		return UMultiplayerSessionSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UMultiplayerSessionSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMultiplayerSessionSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_MultiplayerSession,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMultiplayerSessionSubsystem_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "IncludePath", "MultiplayerSessionSubsystem.h" },
		{ "ModuleRelativePath", "Public/MultiplayerSessionSubsystem.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMultiplayerSessionSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMultiplayerSessionSubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMultiplayerSessionSubsystem_Statics::ClassParams = {
		&UMultiplayerSessionSubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMultiplayerSessionSubsystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMultiplayerSessionSubsystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMultiplayerSessionSubsystem()
	{
		if (!Z_Registration_Info_UClass_UMultiplayerSessionSubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMultiplayerSessionSubsystem.OuterSingleton, Z_Construct_UClass_UMultiplayerSessionSubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMultiplayerSessionSubsystem.OuterSingleton;
	}
	template<> MULTIPLAYERSESSION_API UClass* StaticClass<UMultiplayerSessionSubsystem>()
	{
		return UMultiplayerSessionSubsystem::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMultiplayerSessionSubsystem);
	UMultiplayerSessionSubsystem::~UMultiplayerSessionSubsystem() {}
	struct Z_CompiledInDeferFile_FID_Users_Rene_Desktop_UE_Multiplayer_PlugIn_MPTesting_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_MultiplayerSessionSubsystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Rene_Desktop_UE_Multiplayer_PlugIn_MPTesting_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_MultiplayerSessionSubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMultiplayerSessionSubsystem, UMultiplayerSessionSubsystem::StaticClass, TEXT("UMultiplayerSessionSubsystem"), &Z_Registration_Info_UClass_UMultiplayerSessionSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMultiplayerSessionSubsystem), 1776486129U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Rene_Desktop_UE_Multiplayer_PlugIn_MPTesting_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_MultiplayerSessionSubsystem_h_1399739887(TEXT("/Script/MultiplayerSession"),
		Z_CompiledInDeferFile_FID_Users_Rene_Desktop_UE_Multiplayer_PlugIn_MPTesting_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_MultiplayerSessionSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Rene_Desktop_UE_Multiplayer_PlugIn_MPTesting_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_MultiplayerSessionSubsystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS