unit PascalClasses;

interface

uses CalcPascalApi;

type
	MyStatusImpl = class(StatusImpl)
		constructor create;

		procedure dispose(); override;
		function getCode(): Integer; override;
		procedure setCode(n: Integer); override;

	private
		code: Integer;
	end;

	MyCalculatorImpl = class(CalculatorImpl)
		constructor create;

		procedure dispose(); override;
		function sum(status: Status; n1: Integer; n2: Integer): Integer; override;
		function getMemory(): Integer; override;
		procedure setMemory(n: Integer); override;
		procedure sumAndStore(status: Status; n1: Integer; n2: Integer); override;

	private
		memory: Integer;
	end;

	MyCalculator2Impl = class(Calculator2Impl)
		constructor create;

		procedure dispose(); override;
		function sum(status: Status; n1: Integer; n2: Integer): Integer; override;
		function getMemory(): Integer; override;
		procedure setMemory(n: Integer); override;
		procedure sumAndStore(status: Status; n1: Integer; n2: Integer); override;
		function multiply(status: Status; n1: Integer; n2: Integer): Integer; override;
		procedure copyMemory(calculator: Calculator); override;

	private
		memory: Integer;
	end;

	MyBrokenCalculatorImpl = class(MyCalculatorImpl)
		function sum(status: Status; n1: Integer; n2: Integer): Integer; override;
	end;

implementation

//--------------------------------------

// MyStatusImpl


constructor MyStatusImpl.create;
begin
	inherited;
	code := 0;
end;

procedure MyStatusImpl.dispose();
begin
	self.destroy();
end;

function MyStatusImpl.getCode(): Integer;
begin
	Result := code;
end;

procedure MyStatusImpl.setCode(n: Integer);
begin
	code := n;
end;


//--------------------------------------

// MyCalculatorImpl


constructor MyCalculatorImpl.create;
begin
	inherited;
	memory := 0;
end;

procedure MyCalculatorImpl.dispose();
begin
	self.destroy();
end;

function MyCalculatorImpl.sum(status: Status; n1: Integer; n2: Integer): Integer;
begin
	if (n1 + n2 > 1000) then
	begin
		status.setCode(1);
		Result := 0;
	end
	else
		Result := n1 + n2;
end;

function MyCalculatorImpl.getMemory(): Integer;
begin
	Result := memory;
end;

procedure MyCalculatorImpl.setMemory(n: Integer);
begin
	memory := n;
end;

procedure MyCalculatorImpl.sumAndStore(status: Status; n1: Integer; n2: Integer);
begin
	setMemory(sum(status, n1, n2));
end;


//--------------------------------------

// MyCalculator2Impl


constructor MyCalculator2Impl.create;
begin
	inherited;
	memory := 0;
end;

procedure MyCalculator2Impl.dispose();
begin
	self.destroy();
end;

function MyCalculator2Impl.sum(status: Status; n1: Integer; n2: Integer): Integer;
begin
	if (n1 + n2 > 1000) then
	begin
		status.setCode(1);
		Result := 0;
	end
	else
		Result := n1 + n2;
end;

function MyCalculator2Impl.getMemory(): Integer;
begin
	Result := memory;
end;

procedure MyCalculator2Impl.setMemory(n: Integer);
begin
	memory := n;
end;

procedure MyCalculator2Impl.sumAndStore(status: Status; n1: Integer; n2: Integer);
begin
	setMemory(sum(status, n1, n2));
end;

function MyCalculator2Impl.multiply(status: Status; n1: Integer; n2: Integer): Integer;
begin
	Result := n1 * n2;
end;

procedure MyCalculator2Impl.copyMemory(calculator: Calculator);
begin
	setMemory(calculator.getMemory());
end;


//--------------------------------------

// MyBrokenCalculatorImpl


function MyBrokenCalculatorImpl.sum(status: Status; n1: Integer; n2: Integer): Integer;
begin
	Result := inherited sum(status, n1, n2) + 1;
end;


//--------------------------------------

// Library entry points


function createCalculator: Calculator; cdecl;
begin
	Result := MyCalculatorImpl.create();
end;

function createCalculator2: Calculator2; cdecl;
begin
	Result := MyCalculator2Impl.create();
end;

function createBrokenCalculator: Calculator; cdecl;
begin
	Result := MyBrokenCalculatorImpl.create();
end;

exports
	createCalculator,
	createCalculator2,
	createBrokenCalculator;

end.