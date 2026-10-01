// 00446370 FUN_00446370 [Global]
// program: gamma.dll

undefined4 __fastcall FUN_00446370(undefined4 param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement((LONG *)&DAT_004a042c);
  if ((LVar1 == 0) && (DAT_0049fe10 != (HMODULE)0x0)) {
    FreeLibrary(DAT_0049fe10);
    DAT_0049fe10 = (HMODULE)0x0;
  }
  return param_1;
}


