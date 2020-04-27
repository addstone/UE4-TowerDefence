// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleTutoria/Public/Tutoria/UI_TutoriaSystem.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_TutoriaSystem() {}
// Cross Module References
	SIMPLETUTORIA_API UClass* Z_Construct_UClass_UUI_TutoriaSystem_NoRegister();
	SIMPLETUTORIA_API UClass* Z_Construct_UClass_UUI_TutoriaSystem();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_SimpleTutoria();
// End Cross Module References
	void UUI_TutoriaSystem::StaticRegisterNativesUUI_TutoriaSystem()
	{
	}
	UClass* Z_Construct_UClass_UUI_TutoriaSystem_NoRegister()
	{
		return UUI_TutoriaSystem::StaticClass();
	}
	struct Z_Construct_UClass_UUI_TutoriaSystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_TutoriaSystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleTutoria,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_TutoriaSystem_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Tutoria/UI_TutoriaSystem.h" },
		{ "ModuleRelativePath", "Public/Tutoria/UI_TutoriaSystem.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_TutoriaSystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_TutoriaSystem>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UUI_TutoriaSystem_Statics::ClassParams = {
		&UUI_TutoriaSystem::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UUI_TutoriaSystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_TutoriaSystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUI_TutoriaSystem()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UUI_TutoriaSystem_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UUI_TutoriaSystem, 1152612026);
	template<> SIMPLETUTORIA_API UClass* StaticClass<UUI_TutoriaSystem>()
	{
		return UUI_TutoriaSystem::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UUI_TutoriaSystem(Z_Construct_UClass_UUI_TutoriaSystem, &UUI_TutoriaSystem::StaticClass, TEXT("/Script/SimpleTutoria"), TEXT("UUI_TutoriaSystem"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_TutoriaSystem);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
