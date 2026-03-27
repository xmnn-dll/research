void __fastcall SymCryptEntropyAccumulatorWriteSamplesWorker(__int64 a1)
{
  void *FileHandle; // [rsp+60h] [rbp-19h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+68h] [rbp-11h] BYREF
  union _LARGE_INTEGER ByteOffset; // [rsp+98h] [rbp+1Fh] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+A0h] [rbp+27h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+B0h] [rbp+37h] BYREF

  *(&ObjectAttributes.Length + 1) = 0;
  memset(&ObjectAttributes.Attributes + 1, 0, 20);
  ByteOffset.QuadPart = 0;
  FileHandle = nullptr;
  DestinationString = 0;
  IoStatusBlock = 0;
  RtlInitUnicodeString(&DestinationString, L"\\SystemRoot\\EntropyAccumulator\\samples.dat");
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Length = 48;
  ObjectAttributes.Attributes = 576;
  ObjectAttributes.ObjectName = &DestinationString;
  if ( ZwCreateFile(&FileHandle, 0x120116u, &ObjectAttributes, &IoStatusBlock, nullptr, 0x80u, 0, 2u, 0x24u, nullptr, 0) >= 0 )
    ZwWriteFile(
      FileHandle,
      nullptr,
      nullptr,
      nullptr,
      &IoStatusBlock,
      *(PVOID *)a1,
      16 * (*(_DWORD *)(a1 + 8) + 8 * (*(_QWORD *)(a1 + 8) >> 10)),
      &ByteOffset,
      nullptr);
  if ( FileHandle )
    ZwClose(FileHandle);
  ExFreePoolWithTag(*(PVOID *)a1, 0x61654353u);
}
