// 0042c3ff FUN_0042c3ff [Global]
// programa: sfmain.exe

undefined4 __fastcall FUN_0042c3ff(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 extraout_ECX;
  undefined4 unaff_EBX;
  undefined8 uVar2;
  
  uVar2 = FUN_0042c26a(unaff_EBX,param_2);
  uVar1 = 0;
  if ((int)uVar2 != 0) {
    uVar2 = FUN_0042e618(extraout_ECX,(int)((ulonglong)uVar2 >> 0x20));
    uVar1 = 0;
    if ((int)uVar2 != 0) {
      uVar1 = FUN_0042c33b((int)uVar2);
    }
  }
  return uVar1;
}


