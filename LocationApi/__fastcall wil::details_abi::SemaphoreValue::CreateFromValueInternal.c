__int64 __fastcall wil::details_abi::SemaphoreValue::CreateFromValueInternal(
        wil::details_abi::SemaphoreValue *this,
        const unsigned __int16 *a2,
        size_t *a3,
        unsigned __int64 a4
else
    {
      LODWORD(dwDesiredAccess) = v36;
      wil::details::in1diag5::Return_Hr(
        retaddr,
        (void *)0x89,
        v35,
        "wil::details_abi::SemaphoreValue::CreateFromValueInternal",
        "m_semaphoreHigh.create(static_cast<LONG>(highPart), static_cast<LONG>((highPart > 0) ? highPart : 1), localName)",
        dwDesiredAccess,
        pszDest[0]);
      return (unsigned int)v36;
    }
  }
  else
  {
    LODWORD(dwDesiredAccess) = LastErrorFailHr;
    wil::details::in1diag5::Return_Hr(
      retaddr,
      (void *)0x85,
      v21,
      "wil::details_abi::SemaphoreValue::CreateFromValueInternal",
      "m_semaphore.create(static_cast<LONG>(lowPart), static_cast<LONG>((lowPart > 0) ? lowPart : 1), localName)",
      dwDesiredAccess,
      pszDest[0]);
    return (unsigned int)LastErrorFailHr;
  }
}
