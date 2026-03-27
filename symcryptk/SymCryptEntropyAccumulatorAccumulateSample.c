char __fastcall SymCryptEntropyAccumulatorAccumulateSample(__int64 a1)
{
  __int64 v2; // rax
  unsigned __int64 v3; // rbx
  __int64 v4; // rcx
  __int64 v5; // rdx
  unsigned __int64 v6; // rbx

  v2 = __rdtsc();
  v3 = *(_QWORD *)(a1 + 320);
  v4 = v2;
  *(_QWORD *)(a1 + 8 * ((v3 >> 6) & 0x1F)) = v2 ^ __ROR8__(*(_QWORD *)(a1 + 8 * ((v3 >> 6) & 0x1F)), 19);
  v5 = *(_QWORD *)(a1 + 336);
  if ( v5 && v3 < *(_QWORD *)(a1 + 344) )
  {
    v2 = 2 * v3;
    *(_QWORD *)(v5 + 8 * v2) = v3;
    *(_QWORD *)(v5 + 8 * v2 + 8) = v4;
  }
  v6 = v3 + 1;
  if ( (v6 & 0x3FF) == 0 )
  {
    if ( *(_BYTE *)(a1 + 360)
      || (LOBYTE(v2) = KeInsertQueueDpc((PRKDPC)(a1 + 256), (PVOID)v6, nullptr), (*(_BYTE *)(a1 + 360) = v2) == 0) )
    {
      v6 -= 1024LL;
      LOBYTE(v2) = SymCryptWipeAsm(a1 + (unsigned __int8)(v6 >> 3), 128);
      ++*(_DWORD *)(a1 + 356);
    }
  }
  *(_QWORD *)(a1 + 320) = v6;
  return v2;
}
