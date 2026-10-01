// 1001d520 RwDuplicateMatrix [Global]
// program: RWL21.DLL

longlong RwDuplicateMatrix(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  uint extraout_EDX_00;
  uint extraout_EDX_01;
  uint uVar2;
  longlong lVar3;
  
                    /* 0x1d520  77  RwDuplicateMatrix */
  if (param_1 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
    uVar2 = extraout_EDX_01;
  }
  else {
    puVar1 = FUN_10037030(DAT_1005ac38);
    if (puVar1 != (undefined4 *)0x0) {
      *(undefined1 *)(puVar1 + 0x10) = 0;
      *(undefined1 *)((int)puVar1 + 0x41) = 1;
      puVar1[0xf] = 0x3f800000;
      puVar1[10] = 0x3f800000;
      puVar1[5] = 0x3f800000;
      *puVar1 = 0x3f800000;
      puVar1[0xe] = 0;
      puVar1[0xd] = 0;
      puVar1[0xc] = 0;
      puVar1[0xb] = 0;
      puVar1[9] = 0;
      puVar1[8] = 0;
      puVar1[7] = 0;
      puVar1[6] = 0;
      puVar1[4] = 0;
      puVar1[3] = 0;
      puVar1[2] = 0;
      puVar1[1] = 0;
      *(undefined1 *)((int)puVar1 + 0x41) = 1;
      *(undefined1 *)(puVar1 + 0x10) = 1;
      lVar3 = FUN_100510e0(extraout_ECX,extraout_EDX,param_1,puVar1);
      return lVar3;
    }
    FUN_1000cba0(3);
    uVar2 = extraout_EDX_00;
  }
  return (ulonglong)uVar2 << 0x20;
}


