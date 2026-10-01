// 1000b140 RwClearCameraViewport [Global]
// program: RWL21.DLL

int RwClearCameraViewport(int param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  undefined4 *puVar12;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_48;
  int local_44;
  int local_40 [16];
  
                    /* 0xb140  25  RwClearCameraViewport */
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    local_80 = 0;
    do {
      local_50 = local_80 << 5;
      local_54 = 0;
      local_44 = 1;
      local_48 = 0x20;
      uVar10 = *(uint *)(param_1 + 0x118 + local_80 * 4);
      while (uVar10 != 0) {
        iVar7 = 0;
        uVar2 = uVar10 & 1;
        if (uVar2 == 0) {
          uVar10 = uVar10 >> 1;
          local_54 = local_54 + 0x20;
        }
        else {
          while (uVar2 != 0) {
            uVar10 = uVar10 >> 1;
            iVar7 = iVar7 + 0x20;
            uVar2 = uVar10 & 1;
          }
          if ((local_44 == 0) || (uVar10 != 0)) {
            local_44 = 0;
          }
          else {
            piVar9 = (int *)(param_1 + 0x11c + local_80 * 4);
            if (*(int *)(param_1 + 0x118 + local_80 * 4) == *(int *)(param_1 + 0x11c + local_80 * 4)
               ) {
              do {
                iVar4 = *piVar9;
                local_48 = local_48 + 0x20;
                piVar9 = piVar9 + 1;
                local_80 = local_80 + 1;
              } while (iVar4 == *piVar9);
            }
          }
          bVar1 = *(byte *)(param_1 + 0x114);
          local_6c = local_54 << (bVar1 & 0x1f);
          local_68 = local_50 << (bVar1 & 0x1f);
          local_64 = iVar7 << (bVar1 & 0x1f);
          local_60 = local_48 << (bVar1 & 0x1f);
          if (*(int *)(param_1 + 0x5c) < local_64 + local_6c) {
            local_64 = *(int *)(param_1 + 0x5c) - local_6c;
          }
          if (*(int *)(param_1 + 0x60) < local_68 + local_60) {
            local_80 = 0x20;
            local_60 = *(int *)(param_1 + 0x60) - local_68;
          }
          iVar4 = *(int *)(param_1 + 0xa0);
          if (iVar4 == 0) {
switchD_1000b2cf_caseD_1:
            (**(code **)(PTR_DAT_1005b69c + 0x38))(param_1,&local_6c);
          }
          else {
            local_5c = *(int *)(param_1 + 0xb4);
            if (local_5c < 0) {
              local_5c = *(int *)(iVar4 + 0x1c) - -local_5c % *(int *)(iVar4 + 0x1c);
            }
            local_58 = *(int *)(param_1 + 0xb8);
            if (local_58 < 0) {
              local_58 = *(int *)(iVar4 + 0x20) - -local_58 % *(int *)(iVar4 + 0x20);
            }
            uVar3 = FUN_1001e8a0((int *)(param_1 + 0xa4),&local_6c);
            switch(uVar3) {
            case 1:
              goto switchD_1000b2cf_caseD_1;
            case 2:
              local_7c = (local_6c - *(int *)(param_1 + 0xa4)) + local_5c;
              local_74 = local_64;
              local_78 = (local_68 - *(int *)(param_1 + 0xa8)) + local_58;
              local_70 = local_60;
              FUN_1000b570(param_1,&local_7c,local_6c,local_68);
              break;
            case 3:
              uVar2 = FUN_1001e930((int *)(param_1 + 0xa4),&local_6c,local_40);
              if (-1 < (int)(uVar2 - 1)) {
                piVar9 = local_40 + (uVar2 - 1) * 4;
                do {
                  piVar11 = piVar9 + -4;
                  (**(code **)(PTR_DAT_1005b69c + 0x38))(param_1,piVar9);
                  piVar9 = piVar11;
                } while (local_40 <= piVar11);
              }
              local_74 = *(int *)(param_1 + 0xac);
              local_7c = local_5c;
              local_70 = *(int *)(param_1 + 0xb0);
              local_78 = local_58;
              FUN_1000b570(param_1,&local_7c,*(int *)(param_1 + 0xa4),*(int *)(param_1 + 0xa8));
              break;
            case 4:
              uVar2 = FUN_1001e930((int *)(param_1 + 0xa4),&local_6c,local_40);
              if (-1 < (int)(uVar2 - 1)) {
                piVar9 = local_40 + (uVar2 - 1) * 4;
                do {
                  piVar11 = piVar9 + -4;
                  (**(code **)(PTR_DAT_1005b69c + 0x38))(param_1,piVar9);
                  piVar9 = piVar11;
                } while (local_40 <= piVar11);
              }
              local_7c = *(int *)(param_1 + 0xa4);
              local_78 = *(int *)(param_1 + 0xa8);
              local_74 = *(int *)(param_1 + 0xac);
              local_70 = *(int *)(param_1 + 0xb0);
              iVar4 = local_7c - local_6c;
              if (iVar4 < 0) {
                local_7c = local_7c - iVar4;
                local_74 = local_74 + iVar4;
              }
              iVar4 = local_7c;
              iVar5 = local_78 - local_68;
              if (iVar5 < 0) {
                local_78 = local_78 - iVar5;
                local_70 = local_70 + iVar5;
              }
              iVar5 = local_78;
              iVar6 = ((local_74 - local_64) - local_6c) + local_7c;
              if (0 < iVar6) {
                local_74 = local_74 - iVar6;
              }
              iVar6 = ((local_78 - local_68) - local_60) + local_70;
              if (0 < iVar6) {
                local_70 = local_70 - iVar6;
              }
              local_7c = (local_5c - *(int *)(param_1 + 0xa4)) + local_7c;
              local_78 = (local_58 - *(int *)(param_1 + 0xa8)) + local_78;
              FUN_1000b570(param_1,&local_7c,iVar4,iVar5);
            }
          }
          if (*(int *)(param_1 + 0x8c) == 2) {
            (**(code **)(PTR_DAT_1005b69c + 0x40))(&local_6c);
          }
          local_54 = local_54 + iVar7;
        }
      }
      local_80 = local_80 + 1;
    } while (local_80 < 0x20);
    if ((*(uint *)(param_1 + 0x228) & 1) == 0) {
      iVar7 = 0x20;
      puVar8 = (uint *)(param_1 + 0x198);
      do {
        iVar7 = iVar7 + -1;
        *puVar8 = *puVar8 | puVar8[-0x20];
        puVar8 = puVar8 + 1;
      } while (iVar7 != 0);
    }
    puVar12 = (undefined4 *)(param_1 + 0x118);
    for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar12 = 0;
      puVar12 = puVar12 + 1;
    }
  }
  return param_1;
}


