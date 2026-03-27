__int64 __fastcall SymCryptModuleInit(int a1, unsigned int a2)
{
  _security_init_cookie();
  if ( a1 != 103 || a2 > 4 )
    SymCryptFatal(0x76657273u);
  return SymCryptInit();
}
