// 1000b740 RwShowCameraImage [Global]
// program: RWL21.DLL

/* WARNING: Variable defined which should be unmapped: param_1 */

int RwShowCameraImage(int param_1,undefined *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  code *local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  uint local_80 [32];
  
                    /* 0xb740  490  RwShowCameraImage */
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    if ((*(uint *)(*(int *)(param_1 + 0x100) + 0x40) & 4) == 0) {
      local_98 = (code *)0x0;
    }
    else {
      if (param_2 == (undefined *)0x0) {
        FUN_1000cba0(1);
        return param_1;
      }
      local_98 = (code *)param_2;
    }
    if (*(int *)(PTR_DAT_1005b69c + 0x10) != param_1) {
      if ((*(uint *)(param_1 + 0x228) & 1) == 0) {
        puVar5 = (uint *)(param_1 + 0x198);
        puVar4 = local_80;
        do {
          uVar8 = *puVar5;
          *puVar5 = 0;
          *puVar4 = puVar5[-0x20] | uVar8;
          puVar5 = puVar5 + 1;
          puVar4 = puVar4 + 1;
        } while (puVar4 < &stack0x00000000);
      }
      else {
        puVar5 = local_80;
        for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar5 = 0;
          puVar5 = puVar5 + 1;
        }
      }
      iVar7 = 0;
      do {
        local_84 = 1;
        uVar8 = local_80[iVar7];
        local_a8 = 0;
        local_9c = 0x20;
        local_a4 = iVar7 << 5;
        while (uVar8 != 0) {
          local_a0 = 0;
          uVar3 = uVar8 & 1;
          if (uVar3 == 0) {
            uVar8 = uVar8 >> 1;
            local_a8 = local_a8 + 0x20;
          }
          else {
            while (uVar3 != 0) {
              uVar8 = uVar8 >> 1;
              local_a0 = local_a0 + 0x20;
              uVar3 = uVar8 & 1;
            }
            if ((local_84 == 0) || (uVar8 != 0)) {
              local_84 = 0;
            }
            else {
              puVar5 = local_80 + iVar7 + 1;
              if (local_80[iVar7] == local_80[iVar7 + 1]) {
                do {
                  uVar3 = *puVar5;
                  local_9c = local_9c + 0x20;
                  puVar5 = puVar5 + 1;
                  iVar7 = iVar7 + 1;
                } while (uVar3 == *puVar5);
              }
            }
            bVar1 = *(byte *)(param_1 + 0x114);
            local_94 = local_a8 << (bVar1 & 0x1f);
            local_90 = local_a4 << (bVar1 & 0x1f);
            local_8c = local_a0 << (bVar1 & 0x1f);
            local_88 = local_9c << (bVar1 & 0x1f);
            if (*(int *)(param_1 + 0x5c) < local_8c + local_94) {
              local_8c = *(int *)(param_1 + 0x5c) - local_94;
            }
            if (*(int *)(param_1 + 0x60) < local_90 + local_88) {
              iVar7 = 0x20;
              local_88 = *(int *)(param_1 + 0x60) - local_90;
            }
            if (local_98 == (code *)0x0) {
              (**(code **)(PTR_DAT_1005b69c + 600))(param_1,&local_94,param_2);
            }
            else {
              (*local_98)(param_1,&local_94);
            }
            local_a8 = local_a8 + local_a0;
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < 0x20);
      local_9c = 0;
      local_a0 = 0;
      local_a4 = 0;
      local_a8 = 0;
      if (local_98 == (code *)0x0) {
        (**(code **)(PTR_DAT_1005b69c + 600))(param_1,&local_a8,param_2);
      }
    }
    if ((*(uint *)(param_1 + 0x228) & 1) != 0) {
      iVar7 = 0x20;
      puVar6 = (undefined4 *)(param_1 + 0x118);
      do {
        uVar2 = *puVar6;
        *puVar6 = puVar6[0x20];
        iVar7 = iVar7 + -1;
        puVar6[0x20] = uVar2;
        puVar6 = puVar6 + 1;
      } while (iVar7 != 0);
    }
  }
  return param_1;
}


