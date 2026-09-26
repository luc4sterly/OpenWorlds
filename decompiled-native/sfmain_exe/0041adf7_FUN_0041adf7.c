// 0041adf7 FUN_0041adf7 [Global]
// programa: sfmain.exe

undefined8 __fastcall
FUN_0041adf7(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5
            ,undefined4 param_6,int param_7)

{
  HGLOBAL hMem;
  undefined4 *puVar1;
  DWORD DVar2;
  int iVar3;
  char *pcVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  uint local_28;
  
  hMem = GlobalAlloc(0x40,0x4f7c);
  puVar1 = GlobalLock(hMem);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00408098(extraout_ECX,0);
    *puVar1 = 1;
    puVar1[0x195] = 0;
    DVar2 = GetTickCount();
    puVar1[0x197] = DVar2;
    puVar1[0x198] = 0;
    *(undefined1 *)(puVar1 + 1) = 0;
    puVar1[3] = 0xffffffff;
    puVar1[2] = puVar1[3];
    puVar1[4] = 0;
    puVar1[0x1394] = 0;
    puVar1[0x1395] = 0;
    puVar1[5] = param_3;
    puVar1[6] = param_4;
    puVar1[7] = param_5;
    puVar1[8] = param_6;
    local_28 = (uint)(param_4 == 0);
    puVar1[400] = local_28;
    puVar1[0x4b] = 0xffffffff;
    *(undefined1 *)(puVar1 + 0x4e) = 0;
    puVar1[0x13d7] = 0;
    *(undefined2 *)(puVar1 + 0x1390) = 4;
    iVar3 = Ordinal_14(param_4);
    *(ushort *)((int)puVar1 + 0x4e42) = (ushort)(iVar3 == 0x7f000001);
    puVar1[0x1392] = 0;
    puVar1[0x1391] = puVar1[0x1392];
    puVar1[0x1396] = 0;
    *(undefined1 *)(puVar1 + 0x1397) = 0;
    *(undefined2 *)(puVar1 + 9) = 0x81e;
    puVar1[10] = 0;
    FUN_004080a4(extraout_ECX_00,&DAT_0043636b);
    puVar1[0x13db] = 0;
    if (puVar1[400] == 0) {
      *(undefined1 *)(puVar1 + 0xb) = 0x28;
      if (param_7 != 0) {
        FUN_0042c5c6(extraout_ECX_01,(char *)(param_7 + 4));
        FUN_0042caa9(extraout_ECX_02,&DAT_0043664f);
      }
      pcVar4 = (char *)Ordinal_11(puVar1[6]);
      FUN_0042caa9(extraout_ECX_03,pcVar4);
      FUN_0042caa9(extraout_ECX_04,&DAT_00436651);
    }
  }
  return CONCAT44(param_2,puVar1);
}


