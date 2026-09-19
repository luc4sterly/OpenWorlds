// 10041cb0 FUN_10041cb0 [Global]
// programa: RWL21.DLL

undefined4 * FUN_10041cb0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 < 1) {
    param_1 = 0x10;
  }
  iVar3 = param_1 + 8;
  puVar1 = (undefined4 *)
           (**(code **)(PTR_DAT_1005b69c + 0x350))
                     (1,((param_1 * 8 + 0x40) * 4 + iVar3 * -3) * 4 + 0xc);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_1000cba0(3);
    return (undefined4 *)0x0;
  }
  uVar4 = 0;
  puVar2 = puVar1 + 3;
  *puVar1 = 0;
  puVar1[1] = iVar3;
  puVar1[2] = 8;
  do {
    *puVar2 = 0xff7fffff;
    if ((uVar4 & 1) == 0) {
      *puVar2 = 0x7f7fffff;
    }
    puVar2[1] = 0x7f7fffff;
    if ((uVar4 & 2) == 0) {
      puVar2[1] = 0xff7fffff;
    }
    puVar2[2] = 0x7f7fffff;
    if ((uVar4 & 4) == 0) {
      puVar2[2] = 0xff7fffff;
    }
    puVar2 = puVar2 + 0x1d;
    uVar4 = uVar4 + 1;
  } while ((int)uVar4 < 8);
  if ((int)uVar4 < iVar3) {
    iVar3 = iVar3 - uVar4;
    puVar2 = puVar1 + uVar4 * 0x1d + 0x1d;
    do {
      *puVar2 = 0x7f00;
      iVar3 = iVar3 + -1;
      puVar2[-1] = 0x7f00;
      puVar2 = puVar2 + 0x1d;
    } while (iVar3 != 0);
  }
  return puVar1;
}


