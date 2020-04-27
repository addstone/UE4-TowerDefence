// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleTutoria/Public/Tutoria/UI_TutorialSlot.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_TutorialSlot() {}
// Cross Module References
	SIMPLETUTORIA_API UClass* Z_Construct_UClass_UUI_TutorialSlot_NoRegister();
	SIMPLETUTORIA_API UClass* Z_Construct_UClass_UUI_TutorialSlot();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_SimpleTutoria();
// End Cross Module References
	void UUI_TutorialSlot::StaticRegisterNativesUUI_TutorialSlot()
	{
	}
	UClass* Z_Construct_UClass_UUI_TutorialSlot_NoRegister()
	{
		return UUI_TutorialSlot::StaticClass();
	}
	struct Z_Construct_UClass_UUI_TutorialSlot_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_TutorialSlot_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleTutoria,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_TutorialSlot_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Tutoria/UI_TutorialSlot.h" },
		{ "ModuleRelativePath", "Public/Tutoria/UI_TutorialSlot.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_TutorialSlot_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_TutorialSlot>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UUI_TutorialSlot_Statics::ClassParams = {
		&UUI_TutorialSlot::StaticClass,
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
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UUI_TutorialSlot_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_TutorialSlot_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUI_TutorialSlot()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UUI_TutorialSlot_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UUI_TutorialSlot, 2299799265);
	template<> SIMPLETUTORIA_API UClass* StaticClass<UUI_TutorialSlot>()
	{
		return UUI_TutorialSlot::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UUI_TutorialSlot(Z_Construct_UClass_UUI_TutorialSlot, &UUI_TutorialSlot::StaticClass, TEXT("/Script/SimpleTutoria"), TEXT("UUI_TutorialSlot"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_TutorialSlot);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
