#include "CalcCApi.h"


CLOOP_EXTERN_C void Calculator_dispose(struct Calculator* self)
{
	self->vtable->dispose(self);
}

CLOOP_EXTERN_C int Calculator_sum(struct Calculator* self, int n1, int n2)
{
	return self->vtable->sum(self, n1, n2);
}

CLOOP_EXTERN_C int Calculator_getMemory(struct Calculator* self)
{
	return self->vtable->getMemory(self);
}

CLOOP_EXTERN_C void Calculator_setMemory(struct Calculator* self, int n)
{
	self->vtable->setMemory(self, n);
}

CLOOP_EXTERN_C void Calculator_sumAndStore(struct Calculator* self, int n1, int n2)
{
	self->vtable->sumAndStore(self, n1, n2);
}

CLOOP_EXTERN_C void Calculator2_dispose(struct Calculator2* self)
{
	self->vtable->dispose(self);
}

CLOOP_EXTERN_C int Calculator2_sum(struct Calculator2* self, int n1, int n2)
{
	return self->vtable->sum(self, n1, n2);
}

CLOOP_EXTERN_C int Calculator2_getMemory(struct Calculator2* self)
{
	return self->vtable->getMemory(self);
}

CLOOP_EXTERN_C void Calculator2_setMemory(struct Calculator2* self, int n)
{
	self->vtable->setMemory(self, n);
}

CLOOP_EXTERN_C void Calculator2_sumAndStore(struct Calculator2* self, int n1, int n2)
{
	self->vtable->sumAndStore(self, n1, n2);
}

CLOOP_EXTERN_C int Calculator2_multiply(struct Calculator2* self, int n1, int n2)
{
	return self->vtable->multiply(self, n1, n2);
}

