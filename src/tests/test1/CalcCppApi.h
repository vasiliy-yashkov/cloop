#ifndef CALC_CPP_API_H
#define CALC_CPP_API_H

#include <stdint.h>
#include <stdarg.h>


template <typename Policy>
class CalcApi
{
private:
	template <typename T>
	class VTableInitializer
	{
	public:
		VTableInitializer(unsigned version, ...)
		{
			va_list va;
			va_start(va, version);

			vTable.version = version;

			void** end = ((void**) &vTable.version) + version;

			for (void** p = (void**) &vTable.version; p < end; )
				*++p = va_arg(va, void*);

			va_end(va);
		}

		T vTable;
	};

public:
	// Interfaces declarations

	class Calculator
	{
	protected:
		struct VTable
		{
			void* cloopDummy[1];
			uintptr_t version;
			void (*dispose)(Calculator* self);
			int (*sum)(Calculator* self, int n1, int n2);
			int (*getMemory)(Calculator* self);
			void (*setMemory)(Calculator* self, int n);
			void (*sumAndStore)(Calculator* self, int n1, int n2);
		};

	protected:
		void* cloopDummy[1];
		VTable* cloopVTable;

	public:
		static const int VERSION = sizeof(VTable) / sizeof(void*) - 2;

		void dispose()
		{
			Policy::template checkVersion<1>(this);
			static_cast<VTable*>(this->cloopVTable)->dispose(this);
		}

		int sum(int n1, int n2)
		{
			Policy::template checkVersion<2>(this);
			return static_cast<VTable*>(this->cloopVTable)->sum(this, n1, n2);
		}

		int getMemory()
		{
			Policy::template checkVersion<3>(this);
			return static_cast<VTable*>(this->cloopVTable)->getMemory(this);
		}

		void setMemory(int n)
		{
			Policy::template checkVersion<4>(this);
			static_cast<VTable*>(this->cloopVTable)->setMemory(this, n);
		}

		void sumAndStore(int n1, int n2)
		{
			Policy::template checkVersion<5>(this);
			static_cast<VTable*>(this->cloopVTable)->sumAndStore(this, n1, n2);
		}
	};

	class Calculator2 : public Calculator
	{
	protected:
		struct VTable : public Calculator::VTable
		{
			int (*multiply)(Calculator2* self, int n1, int n2);
		};

	public:
		static const int VERSION = sizeof(VTable) / sizeof(void*) - 2;

		int multiply(int n1, int n2)
		{
			Policy::template checkVersion<6>(this);
			return static_cast<VTable*>(this->cloopVTable)->multiply(this, n1, n2);
		}
	};

	// Interfaces implementations

	template <typename Name, typename Base>
	class CalculatorBaseImpl : public Base
	{
	public:
		CalculatorBaseImpl()
		{
			static VTableInitializer<typename Base::VTable> vTableInit(
				Base::VERSION,
				&Name::cloopdisposeDispatcher,
				&Name::cloopsumDispatcher,
				&Name::cloopgetMemoryDispatcher,
				&Name::cloopsetMemoryDispatcher,
				&Name::cloopsumAndStoreDispatcher
			);

			this->cloopVTable = &vTableInit.vTable;
		}

		static void cloopdisposeDispatcher(Calculator* self) throw()
		{
			static_cast<Name*>(self)->Name::dispose();
		}

		static int cloopsumDispatcher(Calculator* self, int n1, int n2) throw()
		{
			return static_cast<Name*>(self)->Name::sum(n1, n2);
		}

		static int cloopgetMemoryDispatcher(Calculator* self) throw()
		{
			return static_cast<Name*>(self)->Name::getMemory();
		}

		static void cloopsetMemoryDispatcher(Calculator* self, int n) throw()
		{
			static_cast<Name*>(self)->Name::setMemory(n);
		}

		static void cloopsumAndStoreDispatcher(Calculator* self, int n1, int n2) throw()
		{
			static_cast<Name*>(self)->Name::sumAndStore(n1, n2);
		}
	};

	template <typename Name, typename Base = Calculator>
	class CalculatorImpl : public CalculatorBaseImpl<Name, Base>
	{
	public:
		virtual ~CalculatorImpl()
		{
		}

		virtual void dispose() = 0;
		virtual int sum(int n1, int n2) = 0;
		virtual int getMemory() = 0;
		virtual void setMemory(int n) = 0;
		virtual void sumAndStore(int n1, int n2) = 0;
	};

	template <typename Name, typename Base>
	class Calculator2BaseImpl : public Base
	{
	public:
		Calculator2BaseImpl()
		{
			static VTableInitializer<typename Base::VTable> vTableInit(
				Base::VERSION,
				&Name::cloopdisposeDispatcher,
				&Name::cloopsumDispatcher,
				&Name::cloopgetMemoryDispatcher,
				&Name::cloopsetMemoryDispatcher,
				&Name::cloopsumAndStoreDispatcher,
				&Name::cloopmultiplyDispatcher
			);

			this->cloopVTable = &vTableInit.vTable;
		}

		static int cloopmultiplyDispatcher(Calculator2* self, int n1, int n2) throw()
		{
			return static_cast<Name*>(self)->Name::multiply(n1, n2);
		}
	};

	template <typename Name, typename Base = CalculatorImpl<Name, Calculator2> >
	class Calculator2Impl : public Calculator2BaseImpl<Name, Base>
	{
	public:
		virtual ~Calculator2Impl()
		{
		}

		virtual int multiply(int n1, int n2) = 0;
	};
};

#endif	// CALC_CPP_API_H
