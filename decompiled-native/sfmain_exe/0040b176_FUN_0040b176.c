// 0040b176 FUN_0040b176 [Global]
// program: sfmain.exe

void FUN_0040b176(void)

{
  int iVar1;
  int iVar2;
  uint extraout_ECX;
  
  DAT_004433c4 = &DAT_004406e8;
  DAT_004433cc = &DAT_00442838;
  DAT_004433c8 = &DAT_00441fd0;
  DAT_004433c0 = &DAT_004412a8;
  iVar2 = 0;
  do {
    iVar1 = iVar2 + 4;
    *(undefined4 *)((int)&DAT_004406e8 + iVar2) = 0;
    *(undefined4 *)((int)&DAT_004412a8 + iVar2) = 0;
    iVar2 = iVar1;
  } while (iVar1 != 0x870);
  FUN_0042bdf7(0x2b8,0);
  FUN_0042bdf7(0x138,0);
  DAT_00441294 = 0;
  DAT_004412a0 = 0;
  DAT_00441b1c = 0;
  DAT_00441b28 = 0;
  DAT_00441298 = 0x133;
  DAT_004412a4 = 0x1ce;
  DAT_00441b20 = 0x133;
  DAT_00441b2c = 0x1ce;
  DAT_004433c0 = DAT_004433c0 + -0xb5;
  DAT_004433cc = DAT_004433cc + -100;
  DAT_004433c8 = DAT_004433c8 + -0x394;
  DAT_004433c4 = DAT_004433c4 + -0xb5;
  iVar2 = 0;
  do {
    iVar1 = iVar2 + 4;
    *(undefined4 *)((int)&DAT_00440f70 + iVar2) = 0;
    *(undefined4 *)((int)&DAT_00440f64 + iVar2) = *(undefined4 *)((int)&DAT_00440f70 + iVar2);
    *(undefined4 *)((int)&DAT_00440f58 + iVar2) = *(undefined4 *)((int)&DAT_00440f64 + iVar2);
    iVar2 = iVar1;
  } while (iVar1 != 0x28);
  FUN_0042bdf7(3,0);
  FUN_0042bdf7(0x3c,0);
  FUN_00408098(0x10,0);
  FUN_0042bdf7(extraout_ECX,0);
  return;
}


