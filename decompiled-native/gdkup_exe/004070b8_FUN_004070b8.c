// 004070b8 FUN_004070b8 [Global]
// program: gdkup.exe

void __fastcall FUN_004070b8(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  
  iVar2 = (*(code *)PTR_FUN_00408b38)();
  pcVar1 = *(code **)(DAT_0040b440 + 0x14 + iVar2);
  if (pcVar1 == (code *)0x0) {
    iVar2 = (*(code *)PTR_FUN_00408b38)();
    uVar3 = extraout_ECX;
    if (*(int *)(DAT_0040b440 + iVar2 + 0xc) == 0) {
      FUN_0040353b(extraout_ECX,DAT_0040b440 + iVar2);
      return;
    }
  }
  else {
    (*pcVar1)(pcVar1,param_2);
    uVar3 = extraout_ECX_00;
  }
  FUN_004031e8(uVar3,1);
  return;
}


