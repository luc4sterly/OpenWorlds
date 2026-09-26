// 0040b0a2 FUN_0040b0a2 [Global]
// programa: sfmain.exe

void FUN_0040b0a2(void)

{
  int iVar1;
  int iVar2;
  uint extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  int iVar4;
  int iVar3;
  
  iVar4 = 0;
  do {
    iVar1 = iVar4 + 4;
    *(undefined4 *)((int)&DAT_004424b0 + iVar4) = 0;
    *(undefined4 *)((int)&DAT_00441d38 + iVar4) = 0;
    iVar4 = iVar1;
  } while (iVar1 != 0x298);
  FUN_00408098(0x3c,0);
  FUN_0042bdf7(extraout_ECX,0);
  FUN_00408098(extraout_ECX_00,0);
  FUN_00408098(extraout_ECX_01,0);
  FUN_00408098(extraout_ECX_02,0);
  FUN_00408098(extraout_ECX_03,0);
  FUN_00408098(extraout_ECX_04,0);
  iVar4 = 0;
  do {
    iVar1 = iVar4 + 4;
    *(undefined4 *)((int)&DAT_00443390 + iVar4) = 0;
    *(undefined4 *)((int)&DAT_004406c0 + iVar4) = 0;
    iVar4 = iVar1;
  } while (iVar1 != 0x28);
  iVar4 = 0x2c;
  iVar1 = 0;
  do {
    iVar3 = iVar1 * 0x2c;
    do {
      iVar2 = iVar3 + 4;
      *(undefined4 *)((int)&DAT_004401f8 + iVar3) = 0;
      iVar3 = iVar2;
    } while (iVar2 != iVar4);
    iVar1 = iVar1 + 1;
    iVar4 = iVar4 + 0x2c;
  } while (iVar1 < 10);
  return;
}


