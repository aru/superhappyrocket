#ifndef OBJECT_H
#define OBJECT_H

#include "CoreLIB.h"
#include "Rtti.h"

namespace SHR
{
	class Object
	{
	// Run-time type information.
	public:
		virtual const Rtti& GetRttiType () const;
		bool IsExactly (const Rtti& type) const;
		bool IsDerived (const Rtti& type) const;
		bool IsExactlyTypeOf (const Object* object) const;
		bool IsDerivedTypeOf (const Object* object) const;
		static const Rtti TYPE;

	// Names for objects.
	public:
		void SetName (const std::string& name);
		const std::string& GetName () const;
		virtual Object* GetObjectByName (const std::string& name);
		virtual void GetAllObjectsByName (const std::string& name,
			std::vector<Object*>& objects);
	private:
		std::string mName;

		// Abstract base class.  Construction and destruction.
	protected:
		Object ();
	public:
		virtual ~Object ();
	};
}

#endif