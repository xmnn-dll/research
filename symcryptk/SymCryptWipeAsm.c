__int64 __fastcall SymCryptWipeAsm(__int64 a1, unsigned __int64 a2)
{
  bool v2; // cf
  unsigned __int64 i; // rdx
  unsigned int v4; // edx
  __int64 result; // rax

  if ( a2 < 0x10 )
  {
    result = 0;
    if ( (unsigned int)a2 < 8 )
    {
      if ( (unsigned int)a2 < 4 )
      {
        if ( (unsigned int)a2 < 2 )
        {
          if ( (_DWORD)a2 )
            *(_BYTE *)a1 = 0;
        }
        else
        {
          *(_WORD *)a1 = 0;
          *(_WORD *)(a1 + a2 - 2) = 0;
        }
      }
      else
      {
        *(_DWORD *)a1 = 0;
        *(_DWORD *)(a1 + a2 - 4) = 0;
      }
    }
    else
    {
      *(_QWORD *)a1 = 0;
      *(_QWORD *)(a1 + a2 - 8) = 0;
    }
  }
  else if ( (a1 & 0xF) != 0
         && (*(_QWORD *)a1 = 0, *(_QWORD *)(a1 + 8) = 0, result = -(int)a1 & 0xF, a1 += result, a2 -= result, a2 < 0x10) )
  {
    *(_QWORD *)(a1 + a2 - 16) = 0;
    *(_QWORD *)(a1 + a2 - 8) = 0;
    return 0;
  }
  else
  {
    *(_OWORD *)a1 = 0;
    if ( (a2 & 0x10) != 0 )
      a1 += 16;
    v2 = a2 < 0x20;
    for ( i = a2 - 32; !v2; i -= 32LL )
    {
      *(_OWORD *)a1 = 0;
      *(_OWORD *)(a1 + 16) = 0;
      a1 += 32;
      v2 = i < 0x20;
    }
    v4 = i & 0xF;
    if ( v4 )
    {
      *(_QWORD *)(a1 + v4 - 16) = 0;
      *(_QWORD *)(a1 + v4 - 8) = 0;
      return 0;
    }
  }
  return result;
}
