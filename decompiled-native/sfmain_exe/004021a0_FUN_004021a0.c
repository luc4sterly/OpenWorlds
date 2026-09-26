// 004021a0 FUN_004021a0 [Global]
// programa: sfmain.exe

void __fastcall FUN_004021a0(undefined4 param_1,int param_2)

{
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x10) >> 3 & 0x3f;
  *(undefined1 *)(param_2 + 0x18 + uVar1) = 0x80;
  if (0x3f - uVar1 < 8) {
    FUN_00408098(param_2,0);
    FUN_00402223(extraout_ECX,(int *)(param_2 + 0x18));
    param_2 = extraout_ECX_00;
  }
  FUN_00408098(param_2,0);
  *(undefined4 *)(extraout_ECX_01 + 0x50) = *(undefined4 *)(extraout_ECX_01 + 0x10);
  *(undefined4 *)(extraout_ECX_01 + 0x54) = *(undefined4 *)(extraout_ECX_01 + 0x14);
  FUN_00402223(extraout_ECX_01,(int *)(extraout_ECX_01 + 0x18));
  FUN_004080a4(extraout_ECX_02,(undefined1 *)extraout_ECX_02);
  FUN_00408098(extraout_ECX_03,0);
  return;
}


