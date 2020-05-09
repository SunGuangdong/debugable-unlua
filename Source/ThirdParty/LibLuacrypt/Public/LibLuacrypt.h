// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "LuaLibFeature.h"
#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

struct lua_State;

class LIBLUACRYPT_API FLibLuacryptModule : public FLuaLibFeature
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void SetupLuacrypt(lua_State* L);

	static inline FLibLuacryptModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FLibLuacryptModule>("LibLuacrypt");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("LibLuacrypt");
	}

	virtual void RegisterLuaLib(lua_State* L);
	virtual void UnRegisterLuaLib(lua_State* L);
	virtual FName GetLibName()const;
protected:

};
