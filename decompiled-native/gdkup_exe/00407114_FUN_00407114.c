// 00407114 FUN_00407114 [Global]
// programa: gdkup.exe

void __fastcall FUN_00407114(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined8 uVar2;
  
  uVar2 = (*(code *)PTR_FUN_00408b38)();
  pcVar1 = *(code **)((int)uVar2 + DAT_0040b440 + 0x10);
  if (pcVar1 == (code *)0x0) {
    FUN_004070b8(extraout_ECX,(int)((ulonglong)uVar2 >> 0x20));
    return;
  }
  (*pcVar1)(pcVar1,param_2);
  FUN_004031e8(extraout_ECX_00,1);
  return;
}


