void __fastcall SymCryptEntropyAccumulatorInit0(struct _KDPC *DeferredContext)
{
  SymCryptWipeAsm(DeferredContext, 384);
  KeInitializeDpc(DeferredContext + 4, (PKDEFERRED_ROUTINE)SymCryptEntropyAccumulatorDpcRoutine, DeferredContext);
}
