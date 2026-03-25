__int64 __fastcall wil::details_abi::SemaphoreValue::GetValueFromSemaphore(HANDLE hHandle, int *a2)
{
  DWORD v4; // eax
  unsigned int v5; // r8d
  __int64 v6; // rdx
  const char *v7; // rax
  const char *v9; // rax
  __int64 v10; // rdx
  DWORD v11; // eax
  char *v12; // [rsp+28h] [rbp-10h]
  int v13; // [rsp+30h] [rbp-8h]
  wil::details::in1diag5 *retaddr; // [rsp+38h] [rbp+0h]
  int PreviousCount; // [rsp+50h] [rbp+18h] BYREF
  int v16; // [rsp+58h] [rbp+20h] BYREF

  v4 = WaitForSingleObject(hHandle, 0);
  if ( v4 == -1 )
  {
    v6 = 149;
LABEL_3:
    v7 = "result == WAIT_FAILED";
    return wil::details::in1diag5::Return_GetLastError(
             retaddr,
             (void *)v6,
             v5,
             "wil::details_abi::SemaphoreValue::GetValueFromSemaphore",
             v7,
             v12);
  }
  if ( !v4 || v4 == 258 )
  {
    PreviousCount = 0;
    if ( v4 )
    {
      v16 = 0;
      if ( !ReleaseSemaphore(hHandle, 1, &v16) )
      {
        v7 = "::ReleaseSemaphore(semaphore, 1, &expected)";
        v6 = 173;
        return wil::details::in1diag5::Return_GetLastError(
                 retaddr,
                 (void *)v6,
                 v5,
                 "wil::details_abi::SemaphoreValue::GetValueFromSemaphore",
                 v7,
                 v12);
      }
      if ( v16 )
      {
        v9 = "expected != 0";
        v10 = 174;
        goto LABEL_27;
      }
      if ( ReleaseSemaphore(hHandle, 1, nullptr) || GetLastError() != 298 )
      {
        v10 = 177;
        goto LABEL_26;
      }
      v11 = WaitForSingleObject(hHandle, 0);
      if ( v11 == -1 )
      {
        v6 = 180;
        goto LABEL_3;
      }
      if ( v11 )
      {
        v9 = "result != WAIT_OBJECT_0";
        v10 = 181;
        goto LABEL_27;
      }
    }
    else
    {
      if ( !ReleaseSemaphore(hHandle, 1, &PreviousCount) )
      {
        v7 = "::ReleaseSemaphore(semaphore, 1, &value)";
        v6 = 158;
        return wil::details::in1diag5::Return_GetLastError(
                 retaddr,
                 (void *)v6,
                 v5,
                 "wil::details_abi::SemaphoreValue::GetValueFromSemaphore",
                 v7,
                 v12);
      }
      ++PreviousCount;
      if ( ReleaseSemaphore(hHandle, 1, nullptr) || GetLastError() != 298 )
      {
        v10 = 163;
LABEL_26:
        v9 = "expectedFailure || (::GetLastError() != ERROR_TOO_MANY_POSTS)";
        goto LABEL_27;
      }
    }
    *a2 = PreviousCount;
    return 0;
  }
  v9 = "!((result == WAIT_OBJECT_0) || (result == WAIT_TIMEOUT))";
  v10 = 150;
LABEL_27:
  LODWORD(v12) = -2147418113;
  wil::details::in1diag5::Return_Hr(
    retaddr,
    (void *)v10,
    v5,
    "wil::details_abi::SemaphoreValue::GetValueFromSemaphore",
    v9,
    v12,
    v13);
  return 2147549183LL;
}
