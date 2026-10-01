// 1001ba00 RwPopCurrentMaterial [Global]
// program: RWL21.DLL

undefined4 RwPopCurrentMaterial(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  
                    /* 0x1ba00  307  RwPopCurrentMaterial */
  if (0 < DAT_1005dfd8) {
    puVar1 = *(undefined4 **)(DAT_1005dfdc + DAT_1005dfd8 * 4);
    uVar2 = puVar1[0x10];
    if (1 < uVar2) {
      if (puVar1 == (undefined4 *)0x0) {
        FUN_1000cba0(1);
      }
      else if (uVar2 < 2) {
        uVar3 = FUN_10020be0((undefined4 *)puVar1[0xf]);
        puVar1[0xf] = uVar3;
        FUN_10037010(DAT_1005ac24,puVar1);
      }
      else {
        puVar1[0x10] = uVar2 - 1;
      }
      *(undefined4 *)(DAT_1005dfdc + DAT_1005dfd8 * 4) = 0;
    }
    DAT_1005dfd8 = DAT_1005dfd8 + -1;
  }
  return *(undefined4 *)(DAT_1005dfdc + DAT_1005dfd8 * 4);
}


