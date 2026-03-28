__int64 __fastcall CallerIdentity::CheckCapabilityFromProcessHandle(
        CallerIdentity *this,
        void *a2,
        unsigned __int16 *a3,
        void **a4)
{
  int ImpersonationTokenFromProcess; // eax
  void *v6; // rdx
  bool *v7; // r9
  unsigned int v8; // ebx
  int v10; // [rsp+20h] [rbp-8h]
  wil::details::in1diag3 *retaddr; // [rsp+28h] [rbp+0h]
  HANDLE hObject; // [rsp+38h] [rbp+10h] BYREF

  *(_BYTE *)a3 = 0;
  hObject = nullptr;
  ImpersonationTokenFromProcess = CallerIdentity::GetImpersonationTokenFromProcess(this, a2, (unsigned int)&hObject, a4);
  v8 = ImpersonationTokenFromProcess;
  if ( ImpersonationTokenFromProcess >= 0 )
    v8 = CallerIdentity::CheckCapabilityFromImpersonationToken((CallerIdentity *)hObject, v6, a3, v7);
  else
    wil::details::in1diag3::Return_Hr(
      retaddr,
      (void *)0x19,
      (unsigned int)"onecore\\shell\\lib\\calleridentity\\calleridentity_capability.cpp",
      (const char *)(unsigned int)ImpersonationTokenFromProcess,
      v10);
  if ( (char *)hObject - 1 <= (char *)0xFFFFFFFFFFFFFFFDLL )
    CloseHandle(hObject);
  return v8;
}
