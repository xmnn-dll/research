__int64 __fastcall UnattendFindAnswerFileWithResults(
        const WCHAR *a1,
        const unsigned __int16 **a2,
        unsigned int a3,
        const unsigned __int16 *a4,
        unsigned __int16 *a5,
        unsigned __int16 **a6,
        struct _UNATTEND_PROCESSING_RESULTS *a7)
{
  int (*v8[8])(struct UnattendFileSearchParams *); // [rsp+50h] [rbp-58h] BYREF

  v8[0] = (int (*)(struct UnattendFileSearchParams *))UnattendSearchReg;
  v8[1] = (int (*)(struct UnattendFileSearchParams *))UnattendSearchPantherUnattend;
  v8[2] = (int (*)(struct UnattendFileSearchParams *))UnattendSearchPanther;
  v8[3] = (int (*)(struct UnattendFileSearchParams *))UnattendSearchRW;
  v8[4] = (int (*)(struct UnattendFileSearchParams *))UnattendSearchRO;
  v8[5] = (int (*)(struct UnattendFileSearchParams *))UnattendSearchExePath;
  v8[6] = (int (*)(struct UnattendFileSearchParams *))UnattendSearchSysDrive;
  v8[7] = (int (*)(struct UnattendFileSearchParams *))UnattendSearchSetupSourceDrive;
  if ( a6 )
    return UnattendFindAnswerFileWithResultsEx(a1, a2, a3, v8, 8u, a4, a5, a6, a7);
  else
    return 2147942487LL;
}
