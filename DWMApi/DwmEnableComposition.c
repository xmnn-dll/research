HRESULT __stdcall DwmEnableComposition(UINT uCompositionAction)
{
  int v1; // edx
  int IsOptedIn; // eax
  char v4; // al

  if ( byte_1800259BD )
  {
    v4 = byte_1800259BC;
  }
  else
  {
    IsOptedIn = WinSqmIsOptedIn();
    byte_1800259BD = -10;
    v4 = IsOptedIn != 0;
    byte_1800259BC = -1;
  }
  if ( v4 )
    SQMAppDisablingComposition(uCompositionAction, v1);
  return 0;
