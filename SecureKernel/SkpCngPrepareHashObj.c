__int64 __fastcall SkpCngPrepareHashObj(__int64 a1, __int64 a2)
{
  NTSTATUS Property; // edi
  ULONG *v4; // rsi
  UCHAR *SystemHeap; // rax
  void *v7; // rcx
  __int64 v8; // rdx
  ULONG cbOutput; // [rsp+50h] [rbp+8h] BYREF
  int v10; // [rsp+54h] [rbp+Ch]

  v10 = HIDWORD(a1);
  cbOutput = 4;
  *(_QWORD *)a2 = 0;
  Property = BCryptOpenAlgorithmProvider((BCRYPT_ALG_HANDLE *)a2, L"SHA256", nullptr, 1u);
  if ( Property >= 0 )
  {
    v4 = (ULONG *)(a2 + 24);
    Property = BCryptGetProperty(*(BCRYPT_HANDLE *)a2, L"ObjectLength", (PUCHAR)(a2 + 24), cbOutput, &cbOutput, 0);
    if ( Property >= 0 )
    {
      SystemHeap = (UCHAR *)SkAllocateSystemHeap(*v4);
      if ( !SystemHeap )
        _InterlockedIncrement(&SkPoolAllocationsFailed);
      *(_QWORD *)(a2 + 16) = SystemHeap;
      if ( SystemHeap )
      {
        Property = BCryptCreateHash(
                     *(BCRYPT_ALG_HANDLE *)a2,
                     (BCRYPT_HASH_HANDLE *)(a2 + 8),
                     SystemHeap,
                     *v4,
                     nullptr,
                     0,
                     0);
        if ( Property >= 0 )
          return (unsigned int)Property;
      }
      else
      {
        Property = -1073741670;
      }
    }
  }
  v7 = *(void **)(a2 + 8);
  if ( v7 )
    BCryptDestroyHash(v7);
  v8 = *(_QWORD *)(a2 + 16);
  if ( v8 )
    SkFreePool(512, v8);
  if ( *(_QWORD *)a2 )
    BCryptCloseAlgorithmProvider(*(BCRYPT_ALG_HANDLE *)a2, 0);
  return (unsigned int)Property;
}
