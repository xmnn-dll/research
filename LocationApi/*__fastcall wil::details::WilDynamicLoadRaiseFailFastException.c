void __fastcall wil::details::WilDynamicLoadRaiseFailFastException(
        wil::details *this,
        struct _EXCEPTION_RECORD *a2,
        struct _CONTEXT *a3)
{
  HMODULE ModuleHandleW; // rax

  ModuleHandleW = GetModuleHandleW(L"kernelbase.dll");
  if ( GetProcAddress(ModuleHandleW, "RaiseFailFastException") )
    _guard_dispatch_icall_fptr();
}
