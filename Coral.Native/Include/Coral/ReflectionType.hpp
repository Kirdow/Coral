﻿#pragma once

#include "Core.hpp"

namespace Coral {

	class HostInstance;
	class ManagedField;
	struct MethodInfo;
	
	class ReflectionType
	{
	public:
		const CharType* FullName = nullptr;
		const CharType* Name = nullptr;
		const CharType* Namespace = nullptr;
		const CharType* BaseTypeName = nullptr;
		const CharType* AssemblyQualifiedName = nullptr;

		ReflectionType& GetBaseType();

		const std::vector<ManagedField>& GetFields();
		const std::vector<MethodInfo>& GetMethods();

		bool IsAssignableTo(const ReflectionType& InOther) const;
		bool IsAssignableFrom(const ReflectionType& InOther) const;

	private:
		HostInstance* m_Host = nullptr;

		friend class HostInstance;
	};
	
}

