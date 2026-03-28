__int64 __fastcall Hook_ActivateAudioInterfaceAsync(void *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  LPVOID v7; // rbp
  unsigned int v9; // ebx
  LPVOID pv[3]; // [rsp+30h] [rbp-18h] BYREF

  pv[0] = nullptr;
  v7 = a1;
  if ( (int)NS_ActivateAudioInterfaceAsyncXboxSupport::GetDeviceIdFromXboxAudioDeviceId(0, a1, pv) >= 0 )
    v7 = pv[0];
  v9 = qword_180013C98(v7, a2, a3, a4, a5);
  CoTaskMemFree(pv[0]);
  return v9;
}
