// This file was autogenerated by cloop - Cross Language Object Oriented Programming

#ifndef CALC_CPP_API_H
#define CALC_CPP_API_H

#include <stdint.h>

#ifndef CLOOP_CARG
#define CLOOP_CARG
#endif


template <typename Policy>
class CalcApi
{
private:
	class DoNotInherit
	{
	};

	template <typename T>
	class Inherit : public T
	{
	public:
		Inherit(DoNotInherit = DoNotInherit())
			: T(DoNotInherit())
		{
		}
	};

public:
	// Forward interfaces declarations

	class Disposable;
	class Status;
	class Factory;
	class Calculator;
	class Calculator2;

	// Interfaces declarations

	class Disposable
	{
	public:
		struct VTable
		{
			void* cloopDummy[1];
			uintptr_t version;
			void (CLOOP_CARG *dispose)(Disposable* self) throw();
		};

		void* cloopDummy[1];
		VTable* cloopVTable;

	protected:
		Disposable(DoNotInherit)
		{
		}

		~Disposable()
		{
		}

	public:
		static const unsigned VERSION = 1;

		void dispose()
		{
			static_cast<VTable*>(this->cloopVTable)->dispose(this);
		}
	};

	class Status : public Disposable
	{
	public:
		struct VTable : public Disposable::VTable
		{
			int (CLOOP_CARG *getCode)(const Status* self) throw();
			void (CLOOP_CARG *setCode)(Status* self, int code) throw();
		};

	protected:
		Status(DoNotInherit)
			: Disposable(DoNotInherit())
		{
		}

		~Status()
		{
		}

	public:
		static const unsigned VERSION = 2;

		static const int ERROR_1 = 1;
		static const int ERROR_2 = 2;
		static const int ERROR_12 = Status::ERROR_1 | Status::ERROR_2;

		int getCode() const
		{
			int ret = static_cast<VTable*>(this->cloopVTable)->getCode(this);
			return ret;
		}

		void setCode(int code)
		{
			static_cast<VTable*>(this->cloopVTable)->setCode(this, code);
		}
	};

	class Factory : public Disposable
	{
	public:
		struct VTable : public Disposable::VTable
		{
			Status* (CLOOP_CARG *createStatus)(Factory* self) throw();
			Calculator* (CLOOP_CARG *createCalculator)(Factory* self, Status* status) throw();
			Calculator2* (CLOOP_CARG *createCalculator2)(Factory* self, Status* status) throw();
			Calculator* (CLOOP_CARG *createBrokenCalculator)(Factory* self, Status* status) throw();
		};

	protected:
		Factory(DoNotInherit)
			: Disposable(DoNotInherit())
		{
		}

		~Factory()
		{
		}

	public:
		static const unsigned VERSION = 2;

		Status* createStatus()
		{
			Status* ret = static_cast<VTable*>(this->cloopVTable)->createStatus(this);
			return ret;
		}

		Calculator* createCalculator(Status* status)
		{
			typename Policy::Status status2(status);
			Calculator* ret = static_cast<VTable*>(this->cloopVTable)->createCalculator(this, status2);
			Policy::checkException(status2);
			return ret;
		}

		Calculator2* createCalculator2(Status* status)
		{
			typename Policy::Status status2(status);
			Calculator2* ret = static_cast<VTable*>(this->cloopVTable)->createCalculator2(this, status2);
			Policy::checkException(status2);
			return ret;
		}

		Calculator* createBrokenCalculator(Status* status)
		{
			typename Policy::Status status2(status);
			Calculator* ret = static_cast<VTable*>(this->cloopVTable)->createBrokenCalculator(this, status2);
			Policy::checkException(status2);
			return ret;
		}
	};

	class Calculator : public Disposable
	{
	public:
		struct VTable : public Disposable::VTable
		{
			int (CLOOP_CARG *sum)(const Calculator* self, Status* status, int n1, int n2) throw();
			int (CLOOP_CARG *getMemory)(const Calculator* self) throw();
			void (CLOOP_CARG *setMemory)(Calculator* self, int n) throw();
			void (CLOOP_CARG *sumAndStore)(Calculator* self, Status* status, int n1, int n2) throw();
		};

	protected:
		Calculator(DoNotInherit)
			: Disposable(DoNotInherit())
		{
		}

		~Calculator()
		{
		}

	public:
		static const unsigned VERSION = 4;

		int sum(Status* status, int n1, int n2) const
		{
			typename Policy::Status status2(status);
			int ret = static_cast<VTable*>(this->cloopVTable)->sum(this, status2, n1, n2);
			Policy::checkException(status2);
			return ret;
		}

		int getMemory() const
		{
			if (!Policy::template checkVersion<3>(this, 0))
			{
				return Status::ERROR_1;
			}
			int ret = static_cast<VTable*>(this->cloopVTable)->getMemory(this);
			return ret;
		}

		void setMemory(int n)
		{
			if (!Policy::template checkVersion<3>(this, 0))
			{
				return;
			}
			static_cast<VTable*>(this->cloopVTable)->setMemory(this, n);
		}

		void sumAndStore(Status* status, int n1, int n2)
		{
			typename Policy::Status status2(status);
			if (!Policy::template checkVersion<4>(this, status2))
			{
				Policy::checkException(status2);
				return;
			}
			static_cast<VTable*>(this->cloopVTable)->sumAndStore(this, status2, n1, n2);
			Policy::checkException(status2);
		}
	};

	class Calculator2 : public Calculator
	{
	public:
		struct VTable : public Calculator::VTable
		{
			int (CLOOP_CARG *multiply)(const Calculator2* self, Status* status, int n1, int n2) throw();
			void (CLOOP_CARG *copyMemory)(Calculator2* self, const Calculator* calculator) throw();
			void (CLOOP_CARG *copyMemory2)(Calculator2* self, const int* address) throw();
		};

	protected:
		Calculator2(DoNotInherit)
			: Calculator(DoNotInherit())
		{
		}

		~Calculator2()
		{
		}

	public:
		static const unsigned VERSION = 6;

		int multiply(Status* status, int n1, int n2) const
		{
			typename Policy::Status status2(status);
			int ret = static_cast<VTable*>(this->cloopVTable)->multiply(this, status2, n1, n2);
			Policy::checkException(status2);
			return ret;
		}

		void copyMemory(const Calculator* calculator)
		{
			static_cast<VTable*>(this->cloopVTable)->copyMemory(this, calculator);
		}

		void copyMemory2(const int* address)
		{
			if (!Policy::template checkVersion<6>(this, 0))
			{
				return;
			}
			static_cast<VTable*>(this->cloopVTable)->copyMemory2(this, address);
		}
	};

	// Interfaces implementations

	template <typename Name, typename Base>
	class DisposableBaseImpl : public Base
	{
	public:
		typedef Disposable Declaration;

		DisposableBaseImpl(DoNotInherit = DoNotInherit())
		{
			static struct VTableImpl : Base::VTable
			{
				VTableImpl()
				{
					this->version = Base::VERSION;
					this->dispose = &Name::cloopdisposeDispatcher;
				}
			} vTable;

			this->cloopVTable = &vTable;
		}

		static void CLOOP_CARG cloopdisposeDispatcher(Disposable* self) throw()
		{
			try
			{
				static_cast<Name*>(self)->Name::dispose();
			}
			catch (...)
			{
				Policy::catchException(0);
			}
		}
	};

	template <typename Name, typename Base = Inherit<Disposable> >
	class DisposableImpl : public DisposableBaseImpl<Name, Base>
	{
	protected:
		DisposableImpl(DoNotInherit = DoNotInherit())
		{
		}

	public:
		virtual ~DisposableImpl()
		{
		}

		virtual void dispose() = 0;
	};

	template <typename Name, typename Base>
	class StatusBaseImpl : public Base
	{
	public:
		typedef Status Declaration;

		StatusBaseImpl(DoNotInherit = DoNotInherit())
		{
			static struct VTableImpl : Base::VTable
			{
				VTableImpl()
				{
					this->version = Base::VERSION;
					this->dispose = &Name::cloopdisposeDispatcher;
					this->getCode = &Name::cloopgetCodeDispatcher;
					this->setCode = &Name::cloopsetCodeDispatcher;
				}
			} vTable;

			this->cloopVTable = &vTable;
		}

		static int CLOOP_CARG cloopgetCodeDispatcher(const Status* self) throw()
		{
			try
			{
				return static_cast<const Name*>(self)->Name::getCode();
			}
			catch (...)
			{
				Policy::catchException(0);
				return static_cast<int>(0);
			}
		}

		static void CLOOP_CARG cloopsetCodeDispatcher(Status* self, int code) throw()
		{
			try
			{
				static_cast<Name*>(self)->Name::setCode(code);
			}
			catch (...)
			{
				Policy::catchException(0);
			}
		}

		static void CLOOP_CARG cloopdisposeDispatcher(Disposable* self) throw()
		{
			try
			{
				static_cast<Name*>(self)->Name::dispose();
			}
			catch (...)
			{
				Policy::catchException(0);
			}
		}
	};

	template <typename Name, typename Base = DisposableImpl<Name, Inherit<Status> > >
	class StatusImpl : public StatusBaseImpl<Name, Base>
	{
	protected:
		StatusImpl(DoNotInherit = DoNotInherit())
		{
		}

	public:
		virtual ~StatusImpl()
		{
		}

		virtual int getCode() const = 0;
		virtual void setCode(int code) = 0;
	};

	template <typename Name, typename Base>
	class FactoryBaseImpl : public Base
	{
	public:
		typedef Factory Declaration;

		FactoryBaseImpl(DoNotInherit = DoNotInherit())
		{
			static struct VTableImpl : Base::VTable
			{
				VTableImpl()
				{
					this->version = Base::VERSION;
					this->dispose = &Name::cloopdisposeDispatcher;
					this->createStatus = &Name::cloopcreateStatusDispatcher;
					this->createCalculator = &Name::cloopcreateCalculatorDispatcher;
					this->createCalculator2 = &Name::cloopcreateCalculator2Dispatcher;
					this->createBrokenCalculator = &Name::cloopcreateBrokenCalculatorDispatcher;
				}
			} vTable;

			this->cloopVTable = &vTable;
		}

		static Status* CLOOP_CARG cloopcreateStatusDispatcher(Factory* self) throw()
		{
			try
			{
				return static_cast<Name*>(self)->Name::createStatus();
			}
			catch (...)
			{
				Policy::catchException(0);
				return static_cast<Status*>(0);
			}
		}

		static Calculator* CLOOP_CARG cloopcreateCalculatorDispatcher(Factory* self, Status* status) throw()
		{
			try
			{
				return static_cast<Name*>(self)->Name::createCalculator(status);
			}
			catch (...)
			{
				Policy::catchException(status);
				return static_cast<Calculator*>(0);
			}
		}

		static Calculator2* CLOOP_CARG cloopcreateCalculator2Dispatcher(Factory* self, Status* status) throw()
		{
			try
			{
				return static_cast<Name*>(self)->Name::createCalculator2(status);
			}
			catch (...)
			{
				Policy::catchException(status);
				return static_cast<Calculator2*>(0);
			}
		}

		static Calculator* CLOOP_CARG cloopcreateBrokenCalculatorDispatcher(Factory* self, Status* status) throw()
		{
			try
			{
				return static_cast<Name*>(self)->Name::createBrokenCalculator(status);
			}
			catch (...)
			{
				Policy::catchException(status);
				return static_cast<Calculator*>(0);
			}
		}

		static void CLOOP_CARG cloopdisposeDispatcher(Disposable* self) throw()
		{
			try
			{
				static_cast<Name*>(self)->Name::dispose();
			}
			catch (...)
			{
				Policy::catchException(0);
			}
		}
	};

	template <typename Name, typename Base = DisposableImpl<Name, Inherit<Factory> > >
	class FactoryImpl : public FactoryBaseImpl<Name, Base>
	{
	protected:
		FactoryImpl(DoNotInherit = DoNotInherit())
		{
		}

	public:
		virtual ~FactoryImpl()
		{
		}

		virtual Status* createStatus() = 0;
		virtual Calculator* createCalculator(Status* status) = 0;
		virtual Calculator2* createCalculator2(Status* status) = 0;
		virtual Calculator* createBrokenCalculator(Status* status) = 0;
	};

	template <typename Name, typename Base>
	class CalculatorBaseImpl : public Base
	{
	public:
		typedef Calculator Declaration;

		CalculatorBaseImpl(DoNotInherit = DoNotInherit())
		{
			static struct VTableImpl : Base::VTable
			{
				VTableImpl()
				{
					this->version = Base::VERSION;
					this->dispose = &Name::cloopdisposeDispatcher;
					this->sum = &Name::cloopsumDispatcher;
					this->getMemory = &Name::cloopgetMemoryDispatcher;
					this->setMemory = &Name::cloopsetMemoryDispatcher;
					this->sumAndStore = &Name::cloopsumAndStoreDispatcher;
				}
			} vTable;

			this->cloopVTable = &vTable;
		}

		static int CLOOP_CARG cloopsumDispatcher(const Calculator* self, Status* status, int n1, int n2) throw()
		{
			try
			{
				return static_cast<const Name*>(self)->Name::sum(status, n1, n2);
			}
			catch (...)
			{
				Policy::catchException(status);
				return static_cast<int>(0);
			}
		}

		static int CLOOP_CARG cloopgetMemoryDispatcher(const Calculator* self) throw()
		{
			try
			{
				return static_cast<const Name*>(self)->Name::getMemory();
			}
			catch (...)
			{
				Policy::catchException(0);
				return static_cast<int>(0);
			}
		}

		static void CLOOP_CARG cloopsetMemoryDispatcher(Calculator* self, int n) throw()
		{
			try
			{
				static_cast<Name*>(self)->Name::setMemory(n);
			}
			catch (...)
			{
				Policy::catchException(0);
			}
		}

		static void CLOOP_CARG cloopsumAndStoreDispatcher(Calculator* self, Status* status, int n1, int n2) throw()
		{
			try
			{
				static_cast<Name*>(self)->Name::sumAndStore(status, n1, n2);
			}
			catch (...)
			{
				Policy::catchException(status);
			}
		}

		static void CLOOP_CARG cloopdisposeDispatcher(Disposable* self) throw()
		{
			try
			{
				static_cast<Name*>(self)->Name::dispose();
			}
			catch (...)
			{
				Policy::catchException(0);
			}
		}
	};

	template <typename Name, typename Base = DisposableImpl<Name, Inherit<Calculator> > >
	class CalculatorImpl : public CalculatorBaseImpl<Name, Base>
	{
	protected:
		CalculatorImpl(DoNotInherit = DoNotInherit())
		{
		}

	public:
		virtual ~CalculatorImpl()
		{
		}

		virtual int sum(Status* status, int n1, int n2) const = 0;
		virtual int getMemory() const = 0;
		virtual void setMemory(int n) = 0;
		virtual void sumAndStore(Status* status, int n1, int n2) = 0;
	};

	template <typename Name, typename Base>
	class Calculator2BaseImpl : public Base
	{
	public:
		typedef Calculator2 Declaration;

		Calculator2BaseImpl(DoNotInherit = DoNotInherit())
		{
			static struct VTableImpl : Base::VTable
			{
				VTableImpl()
				{
					this->version = Base::VERSION;
					this->dispose = &Name::cloopdisposeDispatcher;
					this->sum = &Name::cloopsumDispatcher;
					this->getMemory = &Name::cloopgetMemoryDispatcher;
					this->setMemory = &Name::cloopsetMemoryDispatcher;
					this->sumAndStore = &Name::cloopsumAndStoreDispatcher;
					this->multiply = &Name::cloopmultiplyDispatcher;
					this->copyMemory = &Name::cloopcopyMemoryDispatcher;
					this->copyMemory2 = &Name::cloopcopyMemory2Dispatcher;
				}
			} vTable;

			this->cloopVTable = &vTable;
		}

		static int CLOOP_CARG cloopmultiplyDispatcher(const Calculator2* self, Status* status, int n1, int n2) throw()
		{
			try
			{
				return static_cast<const Name*>(self)->Name::multiply(status, n1, n2);
			}
			catch (...)
			{
				Policy::catchException(status);
				return static_cast<int>(0);
			}
		}

		static void CLOOP_CARG cloopcopyMemoryDispatcher(Calculator2* self, const Calculator* calculator) throw()
		{
			try
			{
				static_cast<Name*>(self)->Name::copyMemory(calculator);
			}
			catch (...)
			{
				Policy::catchException(0);
			}
		}

		static void CLOOP_CARG cloopcopyMemory2Dispatcher(Calculator2* self, const int* address) throw()
		{
			try
			{
				static_cast<Name*>(self)->Name::copyMemory2(address);
			}
			catch (...)
			{
				Policy::catchException(0);
			}
		}

		static int CLOOP_CARG cloopsumDispatcher(const Calculator* self, Status* status, int n1, int n2) throw()
		{
			try
			{
				return static_cast<const Name*>(self)->Name::sum(status, n1, n2);
			}
			catch (...)
			{
				Policy::catchException(status);
				return static_cast<int>(0);
			}
		}

		static int CLOOP_CARG cloopgetMemoryDispatcher(const Calculator* self) throw()
		{
			try
			{
				return static_cast<const Name*>(self)->Name::getMemory();
			}
			catch (...)
			{
				Policy::catchException(0);
				return static_cast<int>(0);
			}
		}

		static void CLOOP_CARG cloopsetMemoryDispatcher(Calculator* self, int n) throw()
		{
			try
			{
				static_cast<Name*>(self)->Name::setMemory(n);
			}
			catch (...)
			{
				Policy::catchException(0);
			}
		}

		static void CLOOP_CARG cloopsumAndStoreDispatcher(Calculator* self, Status* status, int n1, int n2) throw()
		{
			try
			{
				static_cast<Name*>(self)->Name::sumAndStore(status, n1, n2);
			}
			catch (...)
			{
				Policy::catchException(status);
			}
		}

		static void CLOOP_CARG cloopdisposeDispatcher(Disposable* self) throw()
		{
			try
			{
				static_cast<Name*>(self)->Name::dispose();
			}
			catch (...)
			{
				Policy::catchException(0);
			}
		}
	};

	template <typename Name, typename Base = CalculatorImpl<Name, Inherit<DisposableImpl<Name, Inherit<Calculator2> > > > >
	class Calculator2Impl : public Calculator2BaseImpl<Name, Base>
	{
	protected:
		Calculator2Impl(DoNotInherit = DoNotInherit())
		{
		}

	public:
		virtual ~Calculator2Impl()
		{
		}

		virtual int multiply(Status* status, int n1, int n2) const = 0;
		virtual void copyMemory(const Calculator* calculator) = 0;
		virtual void copyMemory2(const int* address) = 0;
	};
};

template <typename Policy> const int CalcApi<Policy>::Status::ERROR_1;
template <typename Policy> const int CalcApi<Policy>::Status::ERROR_2;
template <typename Policy> const int CalcApi<Policy>::Status::ERROR_12;


#endif	// CALC_CPP_API_H
