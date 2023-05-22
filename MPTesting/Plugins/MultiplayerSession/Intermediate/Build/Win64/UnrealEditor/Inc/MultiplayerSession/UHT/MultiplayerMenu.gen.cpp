// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MultiplayerSession/Public/MultiplayerMenu.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMultiplayerMenu() {}
// Cross Module References
	MULTIPLAYERSESSION_API UClass* Z_Construct_UClass_UMultiplayerMenu();
	MULTIPLAYERSESSION_API UClass* Z_Construct_UClass_UMultiplayerMenu_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_MultiplayerSession();
// End Cross Module References
	DEFINE_FUNCTION(UMultiplayerMenu::execJoinButtonClicked)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->JoinButtonClicked();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMultiplayerMenu::execHostButtonClicked)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HostButtonClicked();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMultiplayerMenu::execOnCreateSession)
	{
		P_GET_UBOOL(Z_Param_bWasSuccesful);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnCreateSession(Z_Param_bWasSuccesful);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMultiplayerMenu::execMenuSetUp)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_NumConnections);
		P_GET_PROPERTY(FStrProperty,Z_Param_TypeOfMatch);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MenuSetUp(Z_Param_NumConnections,Z_Param_TypeOfMatch);
		P_NATIVE_END;
	}
	void UMultiplayerMenu::StaticRegisterNativesUMultiplayerMenu()
	{
		UClass* Class = UMultiplayerMenu::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "HostButtonClicked", &UMultiplayerMenu::execHostButtonClicked },
			{ "JoinButtonClicked", &UMultiplayerMenu::execJoinButtonClicked },
			{ "MenuSetUp", &UMultiplayerMenu::execMenuSetUp },
			{ "OnCreateSession", &UMultiplayerMenu::execOnCreateSession },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMultiplayerMenu_HostButtonClicked_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMultiplayerMenu_HostButtonClicked_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//because this is bind to ad on click event or delegate that exit in new button class we have to use UFUNCTION\n" },
		{ "ModuleRelativePath", "Public/MultiplayerMenu.h" },
		{ "ToolTip", "because this is bind to ad on click event or delegate that exit in new button class we have to use UFUNCTION" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMultiplayerMenu_HostButtonClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMultiplayerMenu, nullptr, "HostButtonClicked", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMultiplayerMenu_HostButtonClicked_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMultiplayerMenu_HostButtonClicked_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMultiplayerMenu_HostButtonClicked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMultiplayerMenu_HostButtonClicked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMultiplayerMenu_JoinButtonClicked_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMultiplayerMenu_JoinButtonClicked_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MultiplayerMenu.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMultiplayerMenu_JoinButtonClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMultiplayerMenu, nullptr, "JoinButtonClicked", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMultiplayerMenu_JoinButtonClicked_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMultiplayerMenu_JoinButtonClicked_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMultiplayerMenu_JoinButtonClicked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMultiplayerMenu_JoinButtonClicked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMultiplayerMenu_MenuSetUp_Statics
	{
		struct MultiplayerMenu_eventMenuSetUp_Parms
		{
			int32 NumConnections;
			FString TypeOfMatch;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_NumConnections;
		static const UECodeGen_Private::FStrPropertyParams NewProp_TypeOfMatch;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMultiplayerMenu_MenuSetUp_Statics::NewProp_NumConnections = { "NumConnections", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(MultiplayerMenu_eventMenuSetUp_Parms, NumConnections), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMultiplayerMenu_MenuSetUp_Statics::NewProp_TypeOfMatch = { "TypeOfMatch", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(MultiplayerMenu_eventMenuSetUp_Parms, TypeOfMatch), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMultiplayerMenu_MenuSetUp_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultiplayerMenu_MenuSetUp_Statics::NewProp_NumConnections,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultiplayerMenu_MenuSetUp_Statics::NewProp_TypeOfMatch,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMultiplayerMenu_MenuSetUp_Statics::Function_MetaDataParams[] = {
		{ "CPP_Default_NumConnections", "4" },
		{ "CPP_Default_TypeOfMatch", "FreeForAll" },
		{ "ModuleRelativePath", "Public/MultiplayerMenu.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMultiplayerMenu_MenuSetUp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMultiplayerMenu, nullptr, "MenuSetUp", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMultiplayerMenu_MenuSetUp_Statics::MultiplayerMenu_eventMenuSetUp_Parms), Z_Construct_UFunction_UMultiplayerMenu_MenuSetUp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMultiplayerMenu_MenuSetUp_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMultiplayerMenu_MenuSetUp_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMultiplayerMenu_MenuSetUp_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMultiplayerMenu_MenuSetUp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMultiplayerMenu_MenuSetUp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics
	{
		struct MultiplayerMenu_eventOnCreateSession_Parms
		{
			bool bWasSuccesful;
		};
		static void NewProp_bWasSuccesful_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasSuccesful;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::NewProp_bWasSuccesful_SetBit(void* Obj)
	{
		((MultiplayerMenu_eventOnCreateSession_Parms*)Obj)->bWasSuccesful = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::NewProp_bWasSuccesful = { "bWasSuccesful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(MultiplayerMenu_eventOnCreateSession_Parms), &Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::NewProp_bWasSuccesful_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::NewProp_bWasSuccesful,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//Callbacks for custom delegate on the multiplayer Session Subsystem\n" },
		{ "ModuleRelativePath", "Public/MultiplayerMenu.h" },
		{ "ToolTip", "Callbacks for custom delegate on the multiplayer Session Subsystem" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMultiplayerMenu, nullptr, "OnCreateSession", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::MultiplayerMenu_eventOnCreateSession_Parms), Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMultiplayerMenu);
	UClass* Z_Construct_UClass_UMultiplayerMenu_NoRegister()
	{
		return UMultiplayerMenu::StaticClass();
	}
	struct Z_Construct_UClass_UMultiplayerMenu_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HostButton_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HostButton;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JoinButton_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JoinButton;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMultiplayerMenu_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_MultiplayerSession,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMultiplayerMenu_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMultiplayerMenu_HostButtonClicked, "HostButtonClicked" }, // 1074951185
		{ &Z_Construct_UFunction_UMultiplayerMenu_JoinButtonClicked, "JoinButtonClicked" }, // 9383732
		{ &Z_Construct_UFunction_UMultiplayerMenu_MenuSetUp, "MenuSetUp" }, // 3220147905
		{ &Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession, "OnCreateSession" }, // 3241903352
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMultiplayerMenu_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "IncludePath", "MultiplayerMenu.h" },
		{ "ModuleRelativePath", "Public/MultiplayerMenu.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMultiplayerMenu_Statics::NewProp_HostButton_MetaData[] = {
		{ "BindWidjet", "" },
		{ "Comment", "//this is used for link the button widget to our button variable in c++ the variable has to have the exact same name of the button\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MultiplayerMenu.h" },
		{ "ToolTip", "this is used for link the button widget to our button variable in c++ the variable has to have the exact same name of the button" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMultiplayerMenu_Statics::NewProp_HostButton = { "HostButton", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UMultiplayerMenu, HostButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMultiplayerMenu_Statics::NewProp_HostButton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMultiplayerMenu_Statics::NewProp_HostButton_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMultiplayerMenu_Statics::NewProp_JoinButton_MetaData[] = {
		{ "BindWidjet", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MultiplayerMenu.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMultiplayerMenu_Statics::NewProp_JoinButton = { "JoinButton", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UMultiplayerMenu, JoinButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMultiplayerMenu_Statics::NewProp_JoinButton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMultiplayerMenu_Statics::NewProp_JoinButton_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMultiplayerMenu_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMultiplayerMenu_Statics::NewProp_HostButton,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMultiplayerMenu_Statics::NewProp_JoinButton,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMultiplayerMenu_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMultiplayerMenu>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMultiplayerMenu_Statics::ClassParams = {
		&UMultiplayerMenu::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UMultiplayerMenu_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UMultiplayerMenu_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMultiplayerMenu_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMultiplayerMenu_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMultiplayerMenu()
	{
		if (!Z_Registration_Info_UClass_UMultiplayerMenu.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMultiplayerMenu.OuterSingleton, Z_Construct_UClass_UMultiplayerMenu_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMultiplayerMenu.OuterSingleton;
	}
	template<> MULTIPLAYERSESSION_API UClass* StaticClass<UMultiplayerMenu>()
	{
		return UMultiplayerMenu::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMultiplayerMenu);
	UMultiplayerMenu::~UMultiplayerMenu() {}
	struct Z_CompiledInDeferFile_FID_Users_Rene_Desktop_UE_Multiplayer_PlugIn_MPTesting_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_MultiplayerMenu_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Rene_Desktop_UE_Multiplayer_PlugIn_MPTesting_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_MultiplayerMenu_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMultiplayerMenu, UMultiplayerMenu::StaticClass, TEXT("UMultiplayerMenu"), &Z_Registration_Info_UClass_UMultiplayerMenu, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMultiplayerMenu), 2393751370U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Rene_Desktop_UE_Multiplayer_PlugIn_MPTesting_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_MultiplayerMenu_h_1990549676(TEXT("/Script/MultiplayerSession"),
		Z_CompiledInDeferFile_FID_Users_Rene_Desktop_UE_Multiplayer_PlugIn_MPTesting_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_MultiplayerMenu_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Rene_Desktop_UE_Multiplayer_PlugIn_MPTesting_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_MultiplayerMenu_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
