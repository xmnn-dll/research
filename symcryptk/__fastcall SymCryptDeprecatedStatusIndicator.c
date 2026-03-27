__int64 __fastcall SymCryptDeprecatedStatusIndicator(char *a1, unsigned int a2)
{
  __int64 result; // rax

  result = 0;
  if ( a1 )
  {
    if ( a2 < 0x38 )
      return result;
    strcpy(a1, "Entropy Source\n\nSelf-Tests\n\nShow Status\n\nShow Version\n\n");
  }
  return 56;
}
