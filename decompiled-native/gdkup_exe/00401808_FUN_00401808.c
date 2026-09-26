// 00401808 FUN_00401808 [Global]
// programa: gdkup.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_00401808(undefined4 param_1,uint param_2)

{
  undefined4 *in_EAX;
  
  if ((param_2 & 4) == 0) {
    *in_EAX = &PTR_FUN_00408938;
    _DAT_0040b014 = _DAT_0040b014 + -1;
    if ((param_2 & 2) != 0) {
      FUN_004026bc();
    }
  }
  else {
    FUN_00402694();
    thunk_FUN_004026bc();
  }
  return in_EAX;
}


