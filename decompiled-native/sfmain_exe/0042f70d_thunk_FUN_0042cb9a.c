// 0042f70d thunk_FUN_0042cb9a [Global]
// programa: sfmain.exe

longlong __fastcall thunk_FUN_0042cb9a(undefined4 param_1,uint param_2)

{
  BOOL BVar1;
  LPCSTR in_EAX;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined8 uVar2;
  
  BVar1 = DeleteFileA(in_EAX);
  if (BVar1 == 0) {
    uVar2 = FUN_00430d8f(extraout_ECX,extraout_EDX);
    return CONCAT44(param_2,(int)uVar2);
  }
  return (ulonglong)param_2 << 0x20;
}


