__int64 __fastcall SymCryptEntropyAccumulatorInit1(__int64 a1, __int64 a2)
{
  signed __int32 v3; // ebx
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rdx

  v3 = _InterlockedExchangeAdd(&g_SymCryptEntropyAccumulatorNextId, 1u);
  v4 = a2 & 0xFFFFFFFFFFFFFC00uLL;
  *(_DWORD *)(a1 + 352) = v3;
  if ( !v3 && v4 )
  {
    v5 = 0x8000000;
    if ( v4 < 0x8000000 )
      v5 = v4;
    *(_QWORD *)(a1 + 344) = v5;
    *(_QWORD *)(a1 + 336) = ExAllocatePool2(64, 16 * (v5 + 8 * (v5 >> 10)), 1634026323);
  }
  SymCryptWipeAsm(a1, 256);
  *(_QWORD *)(a1 + 328) = 0;
  *(_DWORD *)(a1 + 356) = 0;
  *(_QWORD *)(a1 + 320) = (3 * (_WORD)v3) & 0x3FF;
  return 0;
}
