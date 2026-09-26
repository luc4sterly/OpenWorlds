// 00402e11 FUN_00402e11 [Global]
// programa: gdkup.exe

undefined4 __fastcall FUN_00402e11(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 extraout_ECX;
  undefined4 unaff_EBX;
  undefined8 uVar2;
  
  uVar2 = FUN_00402c7c(unaff_EBX,param_2);
  uVar1 = 0;
  if ((int)uVar2 != 0) {
    uVar2 = FUN_00403a64(extraout_ECX,(int)((ulonglong)uVar2 >> 0x20));
    uVar1 = 0;
    if ((int)uVar2 != 0) {
      uVar1 = FUN_00402d4d((int)uVar2);
    }
  }
  return uVar1;
}


