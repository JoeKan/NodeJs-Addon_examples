#include <node.h>

using namespace v8;

void SumArray(const FunctionCallbackInfo<Value>& args){
	double result = 0.0;
	Isolate* isolate = args.GetIsolate();

	if(args.Length() < 1){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	Local<Array> jsArray = Local<Array>::Cast(args[0]);

	for(int i=0, l = jsArray->Length(); i<l ;i++){
		Local<Value> val = jsArray->Get(i);
		result+= val->NumberValue();
	}

	args.GetReturnValue().Set(result);
}

void init(Local<Object> exports){
	NODE_SET_METHOD(exports, "sumArray", SumArray);
}

NODE_MODULE(addon, init)