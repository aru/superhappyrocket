#ifndef RTTI_H
#define RTTI_H

#include "CoreLIB.h"

namespace SHR
{
	class Rtti
	{
	public:
		// Construction and destruction.  The name must be unique among all
		// objects in the system.  In the Wm5 namespace, a class Foo should use
		// "Wm5.Foo".  If an application has another namespace, SomeName, then
		// the name should be "SomeName.Foo".
		Rtti (const char* name, const Rtti* baseType);
		~Rtti ();

		inline const char* GetName () const;
		inline bool IsExactly (const Rtti& type) const;
		bool IsDerived (const Rtti& type) const;

	private:
		const char* mName;
		const Rtti* mBaseType;
		};

	#include "Rtti.inl"
}

#endif