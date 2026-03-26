char __fastcall BlAmdSlSupported(unsigned int *a1)
{
  char v2; // bl
  char v3; // si
  _BYTE v5[8]; // [rsp+20h] [rbp-28h] BYREF
  int v6; // [rsp+28h] [rbp-20h]
  wchar_t *Str; // [rsp+58h] [rbp+10h] BYREF
  __int64 v8; // [rsp+60h] [rbp+18h] BYREF

  v2 = 0;
  if ( (unsigned int)BlArchGetCpuVendor() == 1 )
  {
    if ( (unsigned __int8)BlArchIsCpuIdFunctionSupported(2147483649LL) )
    {
      BlArchCpuId(2147483649LL, 0, v5);
      if ( (v6 & 0x1000) != 0 )
      {
        v3 = 0;
        Str = nullptr;
        if ( (int)BlUtlGetAcpiTable(&v8, 1397904969) >= 0 && (*(_BYTE *)(v8 + 36) & 2) != 0 )
          goto LABEL_13;
        if ( (int)BlGetBootOptionString(qword_54F578, 301989936, &Str) >= 0 )
        {
          if ( !Str )
            return v2;
          if ( wcsstr(Str, L"DMAGUARDPOLICY=ENABLE") ) // VARIABLE/STRING
            v3 = 1;
        }
        if ( Str )
          BlMmFreeHeap(Str);
        if ( v3 )
        {
LABEL_13:
          if ( !a1 )
            return 1;
          if ( (int)BlFileOpen(*a1, L"\\Windows\\System32\\amddrtm.dll", 129, &Str) >= 0 ) // path ;module
          {
            BlFileClose((unsigned int)Str);
            return 1;
          }
        }
      }
    }
  }
  return v2;
}
