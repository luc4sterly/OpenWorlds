// 1003d550 FUN_1003d550 [Global]
// programa: RWL21.DLL

undefined4 FUN_1003d550(void)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  if (DAT_1005b798 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*DAT_1005b798;
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)(PTR_DAT_1005b69c + 0x358))(*puVar2);
      FUN_10037010(DAT_1005b790,puVar2);
    }
    puVar2 = (undefined4 *)DAT_1005b798[1];
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)(PTR_DAT_1005b69c + 0x358))(*puVar2);
      FUN_10037010(DAT_1005b790,puVar2);
    }
    if (DAT_1005b798[2] != 0) {
      if (DAT_1005b798[5] != 0) {
        iVar1 = *(int *)(DAT_1005b798[2] + 8);
        uVar3 = 1;
        if (0 < iVar1) {
          do {
            if (((uint)((int *)DAT_1005b798[2])[2] < uVar3) || (uVar3 == 0)) {
              puVar2 = (undefined4 *)0x0;
            }
            else {
              puVar2 = *(undefined4 **)(*(int *)DAT_1005b798[2] + -4 + uVar3 * 4);
            }
            uVar3 = uVar3 + 1;
            RwDestroyMaterial(puVar2);
          } while ((int)uVar3 <= iVar1);
        }
      }
      puVar2 = (undefined4 *)DAT_1005b798[2];
      if (puVar2 != (undefined4 *)0x0) {
        (**(code **)(PTR_DAT_1005b69c + 0x358))(*puVar2);
        FUN_10037010(DAT_1005b790,puVar2);
      }
    }
    puVar2 = (undefined4 *)DAT_1005b798[3];
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)(PTR_DAT_1005b69c + 0x358))(*puVar2);
      FUN_10037010(DAT_1005b790,puVar2);
    }
    puVar2 = (undefined4 *)DAT_1005b798[4];
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)(PTR_DAT_1005b69c + 0x358))(*puVar2);
      FUN_10037010(DAT_1005b790,puVar2);
    }
    FUN_10037010(DAT_1005b794,DAT_1005b798);
    DAT_1005b798 = (undefined4 *)0x0;
    return 1;
  }
  return 0;
}


