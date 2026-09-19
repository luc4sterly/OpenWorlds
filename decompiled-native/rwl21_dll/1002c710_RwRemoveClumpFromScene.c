// 1002c710 RwRemoveClumpFromScene [Global]
// programa: RWL21.DLL

/* WARNING: Removing unreachable block (ram,0x1002c811) */

uint RwRemoveClumpFromScene(uint param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
                    /* 0x2c710  334  RwRemoveClumpFromScene */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if (*(uint *)(*(int *)(param_1 + 0xb8) + 0x18) == DAT_1005adb0) {
    param_1 = 0;
  }
  if (param_1 == 0) {
    FUN_1000cba0(0x1a);
    return 0;
  }
  if (*(int *)(param_1 + 0x174) != 0) {
    param_1 = 0;
  }
  if (param_1 == 0) {
    FUN_1000cba0(0xf);
    return 0;
  }
  for (iVar3 = *(int *)(param_1 + 0x178); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x184)) {
    FUN_1002c2e0(iVar3);
  }
  FUN_1002baf0(*(uint **)(param_1 + 0xb8));
  if ((DAT_1005adb0 == 0) || (uVar5 = DAT_1005adb0, param_1 == 0)) {
    uVar5 = 0;
  }
  if (uVar5 == 0) {
    iVar3 = 1;
  }
  else {
    if (*(int *)(param_1 + 0x174) != 0) {
      uVar5 = 0;
    }
    if (uVar5 != 0) {
      uVar4 = *(uint *)(param_1 + 0x178);
      do {
        if (uVar4 == 0) break;
        uVar1 = FUN_1002c120(uVar5,uVar4);
        if (uVar1 == 0) {
          uVar5 = 0;
        }
        uVar4 = *(uint *)(uVar4 + 0x184);
      } while (uVar5 != 0);
      if (uVar5 == 0) {
        return 0;
      }
      uVar4 = uVar5;
      if (param_1 == 0) {
        uVar4 = 0;
      }
      if (uVar4 == 0) {
        FUN_1000cba0(1);
LAB_1002c8d3:
        if (uVar4 != 0) goto LAB_1002c8e9;
      }
      else {
        puVar2 = *(uint **)(param_1 + 0xb8);
        if ((puVar2 != (uint *)0x0) && (puVar2[6] != 0)) {
          FUN_1002baf0(puVar2);
        }
        puVar2 = *(uint **)(param_1 + 0xb8);
        if (puVar2 == (uint *)0x0) {
          puVar2 = FUN_10037030(DAT_1005adac);
          if (puVar2 == (uint *)0x0) {
            FUN_1000cba0(3);
            uVar4 = 0;
          }
          else {
            puVar2[0x11] = 1;
            puVar2[6] = uVar4;
            puVar2[5] = 0;
            *puVar2 = 0;
            puVar2[4] = 0;
            puVar2[0x12] = param_1;
            *(uint **)(param_1 + 0xb8) = puVar2;
            uVar1 = *puVar2;
            *puVar2 = uVar1 | 2;
            *puVar2 = uVar1 & 0xfffffffe | 2;
          }
        }
        else {
          puVar2[6] = uVar4;
        }
        if (uVar4 != 0) {
          *(int *)(uVar4 + 0x20) = *(int *)(uVar4 + 0x20) + 1;
          *(int *)(uVar4 + 0x1c) = *(int *)(uVar4 + 0x1c) + 1;
          iVar3 = (**(code **)(PTR_DAT_1005b69c + 0x354))
                            (*(undefined4 *)(uVar4 + 0xc),*(int *)(uVar4 + 0x20) << 2);
          if (iVar3 == 0) {
            FUN_1000cba0(3);
            *(int *)(uVar4 + 0x20) = *(int *)(uVar4 + 0x20) + -1;
            *(int *)(uVar4 + 0x1c) = *(int *)(uVar4 + 0x1c) + -1;
            uVar4 = 0;
          }
          else {
            *(int *)(uVar4 + 0xc) = iVar3;
            *(uint **)(iVar3 + -4 + *(int *)(uVar4 + 0x1c) * 4) = puVar2;
            *(undefined4 *)(param_1 + 0xc0) = 0;
          }
          goto LAB_1002c8d3;
        }
      }
      uVar5 = 0;
      goto LAB_1002c8e9;
    }
    iVar3 = 0xf;
  }
  FUN_1000cba0(iVar3);
LAB_1002c8e9:
  if (uVar5 != 0) {
    return param_1;
  }
  return 0;
}


