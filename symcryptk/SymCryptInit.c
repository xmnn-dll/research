__int64 SymCryptInit()
{
  __int64 result; // rax
  char EnabledExtendedFeatures; // al
  char v2; // al
  const char *v3; // rcx
  struct _OSVERSIONINFOW VersionInformation; // [rsp+30h] [rbp-138h] BYREF

  result = (unsigned int)g_SymCryptFlags;
  if ( (g_SymCryptFlags & 1) == 0 )
  {
    VersionInformation.dwOSVersionInfoSize = 276;
    if ( RtlGetVersion(&VersionInformation) < 0
      || VersionInformation.dwMajorVersion < 6
      || VersionInformation.dwMajorVersion == 6 && VersionInformation.dwMinorVersion < 3 )
    {
      SymCryptFatal(0x6E737276u);
    }
    SymCryptDetectCpuFeaturesByCpuid();
    EnabledExtendedFeatures = RtlGetEnabledExtendedFeatures(0xFFFFFFFFFFFFFFFFuLL);
    if ( (EnabledExtendedFeatures & 4) == 0 )
      g_SymCryptCpuFeaturesNotPresent |= 0x10u;
    if ( (EnabledExtendedFeatures & 0xE0) == 0 )
      g_SymCryptCpuFeaturesNotPresent |= 0x1000u;
    g_SymCryptCpuFeaturesNotPresent &= ~0x20u;
    _InterlockedOr(&g_SymCryptFlags, 1u);
    v2 = aV1034120240229[0];
    v3 = "v\"103\" \".\" \"4\".1__2024-02-29T00:21:29+00:00_f70f82b_2024-03-27T21:59:18";
    while ( v2 )
      v2 = *++v3;
    result = (unsigned int)~g_SymCryptCpuFeaturesNotPresent;
    g_SymCryptCpuFeaturesPresentCheck = -1073737515;
  }
  return result;
}
