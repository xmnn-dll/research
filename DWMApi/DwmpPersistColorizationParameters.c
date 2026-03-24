__int64 __fastcall DwmpPersistColorizationParameters(int *a1)
{
  LSTATUS v2; // eax
  signed int v3; // ebx
  int v4; // eax
  unsigned int v6; // edx
  int v7; // ecx
  HKEY hKey; // [rsp+60h] [rbp+8h] BYREF

  hKey = nullptr;
  if ( !a1 )
  {
    v3 = -2147024809;
    v6 = 138;
LABEL_17:
    v7 = v3;
    goto LABEL_26;
  }
  v2 = RegCreateKeyExW(
         HKEY_CURRENT_USER,
         L"Software\\Microsoft\\Windows\\DWM",
         0,
         nullptr,
         0,
         2u,
         nullptr,
         &hKey,
         nullptr);
  v3 = v2;
  if ( v2 > 0 )
    v3 = (unsigned __int16)v2 | 0x80070000;
  if ( v3 < 0 )
  {
    v6 = 150;
    goto LABEL_17;
  }
  v4 = DwmpSaveColorizationParameter(hKey, L"ColorizationColor", *a1);
  v3 = v4;
  if ( v4 < 0 )
  {
    v6 = 152;
  }
  else
  {
    v4 = DwmpSaveColorizationParameter(hKey, L"ColorizationColorBalance", a1[2]);
    v3 = v4;
    if ( v4 < 0 )
    {
      v6 = 153;
    }
    else
    {
      v4 = DwmpSaveColorizationParameter(hKey, L"ColorizationAfterglow", a1[1]);
      v3 = v4;
      if ( v4 < 0 )
      {
        v6 = 154;
      }
      else
      {
        v4 = DwmpSaveColorizationParameter(hKey, L"ColorizationAfterglowBalance", a1[3]);
        v3 = v4;
        if ( v4 < 0 )
        {
          v6 = 155;
        }
        else
        {
          v4 = DwmpSaveColorizationParameter(hKey, L"ColorizationBlurBalance", a1[4]);
          v3 = v4;
          if ( v4 < 0 )
          {
            v6 = 156;
          }
          else
          {
            v4 = DwmpSaveColorizationParameter(hKey, L"EnableWindowColorization", a1[5]);
            v3 = v4;
            if ( v4 < 0 )
            {
              v6 = 157;
            }
            else
            {
              v4 = DwmpSaveColorizationParameter(hKey, L"ColorizationGlassAttribute", a1[6]);
              v3 = v4;
              if ( v4 >= 0 )
                goto LABEL_12;
              v6 = 158;
            }
          }
        }
      }
    }
  }
  v7 = v4;
LABEL_26:
  DoStackCaptureDirect(v7, v6);
LABEL_12:
  if ( hKey )
    RegCloseKey(hKey);
  return (unsigned int)v3;
}
