#pragma once
#include <DX3D/Core/Base.h>

namespace dx3d
{
	class Base
	{
	public:
		explicit Base(const BaseDesc& desc);
		virtual ~Base();
		virtual Logger& getLogger()const noexcept final;

	protected:
		Base(const Base&) = delete;
		Base(Base&&) = delete;
		Base& operator = (const Base&) = delete;
		Base& operator = (Base&&) = delete;

		// Singleton, Dependency enjection - learn more
	protected:
		Logger& m_logger;
	};

}

