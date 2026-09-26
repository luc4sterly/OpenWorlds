// 0042cb9a FUN_0042cb9a [Global]
// programa: sfmain.exe

longlong __fastcall FUN_0042cb9a(undefined4 param_1,uint param_2)

{
  LPCSTR in_EAX;
  BOOL BVar1;
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


