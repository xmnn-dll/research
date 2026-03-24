_int64 __fastcall UnattendSearchDrives(int a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v6; // edi
  wchar_t *v7; // rsi
  BOOL v8; // ebx
  UINT DriveTypeW; // r14d
  unsigned __int64 v10; // rax
  BOOL VolumeInformationW; // eax
  int v12; // ecx
  ULONG NewMode; // [rsp+40h] [rbp-20h] BYREF
  DWORD FileSystemFlags; // [rsp+44h] [rbp-1Ch] BYREF
  WCHAR RootPathName[4]; // [rsp+48h] [rbp-18h] BYREF // USB

  wcscpy(RootPathName, L"?:\\"); // USB | E: | F:
  NewMode = 0;
  WdsSuppressErrorPopups(&NewMode);
  v6 = 0;
  v7 = aAbcdefghijklmn;
  do
  {
    if ( **(int **)(a4 + 48) < 0 || !*v7 )
      break;
    RootPathName[0] = *v7;
    v8 = 0;
    DriveTypeW = GetDriveTypeW(RootPathName);
    v10 = 0;
    while ( !v8 )
    {
      v8 = *(_DWORD *)((char *)&qword_18002B3F8 + v10) == DriveTypeW;
      v10 += 4LL;
      if ( v10 >= 8 )
      {
        if ( !v8 )
          goto LABEL_13;
        break;
      }
    }
    FileSystemFlags = 0;
    VolumeInformationW = GetVolumeInformationW(RootPathName, nullptr, 0, nullptr, nullptr, &FileSystemFlags, nullptr, 0);
    FileSystemFlags &= -VolumeInformationW;
    if ( (FileSystemFlags & 0x80000) != 0 || (v12 = 0, DriveTypeW == 5) )
      v12 = 1;
    if ( (a1 == 0) == v12 )
      v6 = UnattendSearchImplicitPath(RootPathName, a4);
LABEL_13:
    ++v7;
  }
  while ( v6 >= 0 );
  RtlSetThreadErrorMode(NewMode, nullptr);
  return (unsigned int)v6;
}
