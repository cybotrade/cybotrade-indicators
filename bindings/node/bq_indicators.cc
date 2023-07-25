#include "external/indicators.h"
#include <napi.h>

// A helper function to convert a Napi::Array to a double array.
static double *getArray(Napi::Array input, int offset) {
  const uint32_t size = input.Length() - offset;

  double *ret = (double *)malloc(sizeof(double) * size);

  for (uint32_t i = 0; i < size; i++)
    ret[i] = input.Get(i + offset).As<Napi::Number>().DoubleValue();

  return ret;
}

// A function to be called from JavaScript land that returns the start 
// index of a given indicator's results.
Napi::Value StartByIndex(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() < 2) {
    Napi::TypeError::New(env, "Wrong number of arguments. Expecting: index, options.")
      .ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[0].IsNumber()) {
    Napi::TypeError::New(env, "Expecting first argument to be function index number.")
      .ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[1].IsArray()) {
    Napi::TypeError::New(env, "Expecting second argument to be array of options.")
      .ThrowAsJavaScriptException();
    return env.Undefined();
  }

  const int32_t index = info[0].As<Napi::Number>().Int32Value();
  if (index < 0 || index > TI_INDICATOR_COUNT) {
    Napi::TypeError::New(env, "Invalid indicator index. Expected index between " + std::to_string(0) + " and " + std::to_string(TI_INDICATOR_COUNT) + " but got " + std::to_string(index) + ".")
      .ThrowAsJavaScriptException();
    return env.Undefined();
  }

  const ti_indicator_info *ind = ti_indicators + index;

  Napi::Array _options = info[1].As<Napi::Array>();
  if ((unsigned int)ind->options != _options.Length()) {
    Napi::TypeError::New(env, "Invalid number of options. Expected " + std::to_string(ind->options) + ", got " + std::to_string(_options.Length()) + ".")
      .ThrowAsJavaScriptException();
    return env.Undefined();
  }

  double *options = getArray(_options, 0);

  const int start = ind->start(options);

  free(options);

  return Napi::Number::New(env, (double) start);
}

Napi::Value CallByIndex(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments. Expecting: index, inputs and options.")
      .ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[0].IsNumber()) {
    Napi::TypeError::New(env, "Expecting first argument to be function index number.")
      .ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[1].IsArray()) {
    Napi::TypeError::New(env, "Expecting second argument to be array of inputs.")
      .ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[2].IsArray()) {
    Napi::TypeError::New(env, "Expecting third argument to be array of options.")
      .ThrowAsJavaScriptException();
    return env.Undefined();
  }

  const int32_t index = info[0].As<Napi::Number>().Int32Value();
  if (index < 0 || index > TI_INDICATOR_COUNT) {
    Napi::TypeError::New(env, "Invalid indicator index. Expected index between " + std::to_string(0) + " and " + std::to_string(TI_INDICATOR_COUNT) + " but got " + std::to_string(index) + ".")
      .ThrowAsJavaScriptException();
    return env.Undefined();
  }

  const ti_indicator_info *ind = ti_indicators + index;

  Napi::Array inputs = info[1].As<Napi::Array>();
  if ((uint32_t)ind->inputs != inputs.Length()) {
    Napi::TypeError::New(env, "Invalid number of inputs. Expected " + std::to_string(ind->inputs) + ", got " + std::to_string(inputs.Length()) + ".")
      .ThrowAsJavaScriptException();
    return env.Undefined();
  }

  Napi::Array options = info[2].As<Napi::Array>();
  if ((uint32_t)ind->options != options.Length()) {
    Napi::TypeError::New(env, "Invalid number of options. Expected " + std::to_string(ind->options) + ", got " + std::to_string(options.Length()) + ".")
      .ThrowAsJavaScriptException();
    return env.Undefined();
  }

  double *inputArr[TI_MAXINDPARAMS] = {0};
  int inSize = -1;

  // Find smallest size of input.
  for (int i = 0; i < ind->inputs; i++) {
    Napi::Array input = inputs.Get(i).As<Napi::Array>();
    const int size = input.Length();
    if (inSize == -1 || size < inSize)
      inSize = size;
  }

  // Get input arrays.
  for (int i = 0; i < ind->inputs; i++) {
    Napi::Array input = inputs.Get(i).As<Napi::Array>();
    const int offset = input.Length() - inSize;
    inputArr[i] = getArray(input, offset);
  }

  // Get option array.
  double *optionArr = getArray(options, 0);

  // Setup output arrays.
  const int start = ind->start(optionArr);
  const int outSize = start >= 0 ? inSize - start : 0;

  double *outputArr[TI_MAXINDPARAMS] = {0};
  for (int i = 0; i < ind->outputs; i++)
    outputArr[i] = (double *)malloc(sizeof(double) * outSize);

  // Do the calculation.
  int result = ind->indicator(
    inSize, 
    (const double **)inputArr, 
    optionArr, 
    (double **)outputArr
  );

  // Clean up inputs.
  for (int i = 0; i < ind->inputs; i++) free(inputArr[i]);

  // Clean up options.
  free(optionArr);

  // Handle error.
  if (result != TI_OKAY) {
    // Clean up outputs.
    for (int i = 0; i < ind->outputs; i++) free(outputArr[i]);

    switch (result) {
      case TI_INVALID_OPTION:
        Napi::TypeError::New(env, "Invalid option.")
          .ThrowAsJavaScriptException();
        return env.Undefined();
      case TI_OUT_OF_MEMORY:
        Napi::TypeError::New(env, "Out of memory.")
          .ThrowAsJavaScriptException();
        return env.Undefined();
      default:
        Napi::TypeError::New(env, "Unknown error.")
          .ThrowAsJavaScriptException();
        return env.Undefined();
    }
  }

  Napi::Array outputs = Napi::Array::New(env, ind->outputs);

  for (int i = 0; i < ind->outputs; i++) {
    Napi::Array output = Napi::Array::New(env, outSize);
    for (int j = 0; j < outSize; j++)
      output.Set(j, Napi::Number::New(env, outputArr[i][j]));
    outputs.Set(i, output);
  }

  // Clean up outputs.
  for (int i = 0; i < ind->outputs; i++) free(outputArr[i]);

  return outputs;
}

// A function to initialize the module.
Napi::Object Init(Napi::Env env, Napi::Object exports) {
  Napi::Object indicators = Napi::Object::New(env);

  const ti_indicator_info *info = ti_indicators;
  while (info->name != 0) {
    Napi::Object ind = Napi::Object::New(env);

    ind.Set(
      Napi::String::New(env, "index"),
      Napi::Number::New(env, info - ti_indicators)
    );
    ind.Set(
      Napi::String::New(env, "name"),
      Napi::String::New(env, info->name)
    );
    ind.Set(
      Napi::String::New(env, "fullName"),
      Napi::String::New(env, info->full_name)
    );

    char const *type = "unknown";

    switch (info->type) {
      case TI_TYPE_OVERLAY:
        type = "overlay";
        break;
      case TI_TYPE_INDICATOR:
        type = "indicator";
        break;
      case TI_TYPE_MATH:
        type = "math";
        break;
      case TI_TYPE_SIMPLE:
        type = "simple";
        break;
      case TI_TYPE_COMPARATIVE:
        type = "comparative";
        break;
    }

    ind.Set(
      Napi::String::New(env, "type"), 
      Napi::String::New(env, type)
    );
    ind.Set(
      Napi::String::New(env, "inputs"),
      Napi::Number::New(env, (double) info->inputs)
    );
    ind.Set(
      Napi::String::New(env, "options"),
      Napi::Number::New(env, (double) info->options)
    );
    ind.Set(
      Napi::String::New(env, "outputs"),
      Napi::Number::New(env, (double) info->outputs)
    );

    Napi::Array inputNames = Napi::Array::New(env, info->inputs);
    for (int i = 0; i < info->inputs; i++)
      inputNames.Set(i, Napi::String::New(env, info->input_names[i]));
    ind.Set(
      Napi::String::New(env, "inputNames"),
      inputNames
    );

    Napi::Array optionNames = Napi::Array::New(env, info->options);
    for (int i = 0; i < info->options; i++)
      optionNames.Set(i, Napi::String::New(env, info->option_names[i]));
    ind.Set(
      Napi::String::New(env, "optionNames"),
      optionNames
    );

    Napi::Array outputNames = Napi::Array::New(env, info->outputs);
    for (int i = 0; i < info->outputs; i++)
      outputNames.Set(i, Napi::String::New(env, info->output_names[i]));
    ind.Set(
      Napi::String::New(env, "outputNames"),
      outputNames
    );

    indicators.Set(
      Napi::String::New(env, info->name),
      ind
    );

    info++;
  }

  exports.Set(
    Napi::String::New(env, "startByIndex"), 
    Napi::Function::New(env, StartByIndex)
  );
  exports.Set(
    Napi::String::New(env, "callByIndex"), 
    Napi::Function::New(env, CallByIndex)
  );
  exports.Set(
    Napi::String::New(env, "indicators"),
    indicators
  );
  exports.Set(
    Napi::String::New(env, "version"),
    Napi::String::New(env, TI_VERSION)
  );
  return exports;
}

NODE_API_MODULE(indicators, Init)