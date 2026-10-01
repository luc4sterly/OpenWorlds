// 00404041 thunk_FUN_004059e3 [Global]
// program: gdkup.exe

longlong __fastcall thunk_FUN_004059e3(undefined4 param_1,uint param_2)

{
  LPCSTR in_EAX;
  BOOL BVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined8 uVar2;
  
  BVar1 = DeleteFileA(in_EAX);
  if (BVar1 == 0) {
    uVar2 = FUN_00405609(extraout_ECX,extraout_EDX);
    return CONCAT44(param_2,(int)uVar2);
  }
  return (ulonglong)param_2 << 0x20;
}


