// 1002c570 RwAddClumpToScene [Global]
// programa: RWL21.DLL

/* WARNING: Removing unreachable block (ram,0x1002c612) */

uint RwAddClumpToScene(uint param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
                    /* 0x2c570  3  RwAddClumpToScene */
  if ((param_1 == 0) || (param_2 == 0)) {
    param_1 = 0;
  }
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    if (*(int *)(param_2 + 0x174) != 0) {
      param_1 = 0;
    }
    if (param_1 == 0) {
      FUN_1000cba0(0xf);
      return 0;
    }
    uVar4 = *(uint *)(param_2 + 0x178);
    do {
      if (uVar4 == 0) break;
      uVar1 = FUN_1002c120(param_1,uVar4);
      if (uVar1 == 0) {
        param_1 = 0;
      }
      uVar4 = *(uint *)(uVar4 + 0x184);
    } while (param_1 != 0);
    if (param_1 == 0) {
      return 0;
    }
    uVar4 = param_1;
    if (param_2 == 0) {
      uVar4 = 0;
    }
    if (uVar4 == 0) {
      FUN_1000cba0(1);
    }
    else {
      puVar2 = *(uint **)(param_2 + 0xb8);
      if ((puVar2 != (uint *)0x0) && (puVar2[6] != 0)) {
        FUN_1002baf0(puVar2);
      }
      puVar2 = *(uint **)(param_2 + 0xb8);
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
          puVar2[0x12] = param_2;
          *(uint **)(param_2 + 0xb8) = puVar2;
          uVar1 = *puVar2;
          *puVar2 = uVar1 | 2;
          *puVar2 = uVar1 & 0xfffffffe | 2;
        }
      }
      else {
        puVar2[6] = uVar4;
      }
      if (uVar4 == 0) {
        return 0;
      }
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
        *(undefined4 *)(param_2 + 0xc0) = 0;
      }
    }
    if (uVar4 == 0) {
      return 0;
    }
  }
  return param_1;
}


