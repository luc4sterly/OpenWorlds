// 10007950 FUN_10007950 [Global]
// program: rwdlmd21.dll

undefined4 * FUN_10007950(int *param_1,undefined4 *param_2,uint param_3)

{
  int *piVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined1 *puVar9;
  int iVar10;
  byte *pbVar11;
  uint *puVar12;
  byte bStack_154;
  byte bStack_153;
  byte bStack_152;
  uint uStack_150;
  int *piStack_14c;
  undefined4 *local_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  uint uStack_13c;
  uint uStack_138;
  int iStack_134;
  undefined4 *puStack_130;
  int iStack_12c;
  int iStack_128;
  undefined4 *puStack_124;
  undefined1 *puStack_120;
  int local_11c;
  int local_118;
  uint local_114;
  uint local_110;
  byte *local_10c;
  int iStack_108;
  undefined4 *puStack_104;
  int iStack_100;
  int iStack_fc;
  int iStack_f8;
  
  local_10c = (byte *)param_1[0xd];
  iVar5 = param_1[8];
  param_2[7] = param_1[7];
  param_2[9] = 8;
  param_2[8] = iVar5;
  local_148 = FUN_1000a460(param_2);
  if (local_148 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  if (*(code **)(DAT_10089de0 + 0x298) != (code *)0x0) {
    if (((param_1[0x10] & 2U) != 0) &&
       (iVar5 = (**(code **)(DAT_10089de0 + 0x298))(param_1), iVar5 == 0)) {
      return (undefined4 *)0x0;
    }
    if (((local_148[0x10] & 2) != 0) &&
       (iVar5 = (**(code **)(DAT_10089de0 + 0x298))(local_148), iVar5 == 0)) {
      if (((param_1[0x10] & 2U) != 0) && (*(code **)(DAT_10089de0 + 0x29c) != (code *)0x0)) {
        (**(code **)(DAT_10089de0 + 0x29c))(param_1);
      }
      return (undefined4 *)0x0;
    }
  }
  local_11c = param_1[6];
  local_118 = local_148[6];
  local_114 = param_3 & 1;
  local_110 = param_3 & 2;
  if ((local_114 == 0) && (*param_1 == 1)) {
    iVar5 = 0;
    pbVar11 = local_10c;
    do {
      bStack_154 = *pbVar11;
      bStack_153 = pbVar11[1];
      bStack_152 = pbVar11[2];
      if (local_110 != 0) {
        bStack_154 = (&DAT_1008a210)[bStack_154];
        bStack_153 = (&DAT_1008a210)[bStack_153];
        bStack_152 = (&DAT_1008a210)[bStack_152];
      }
      pbVar11 = pbVar11 + 3;
      iVar10 = iVar5 + 1;
      uVar6 = FUN_1000c030(&bStack_154);
      *(char *)((int)&iStack_100 + iVar5) = (char)uVar6;
      iVar5 = iVar10;
    } while (iVar10 < 0x100);
    iVar5 = 0;
    if (0 < param_1[8]) {
      do {
        iVar10 = 0;
        pbVar11 = (byte *)(param_1[10] * iVar5 + local_11c);
        puVar9 = (undefined1 *)(local_118 + local_148[10] * iVar5);
        if (0 < param_1[7]) {
          do {
            iVar10 = iVar10 + 1;
            *puVar9 = *(undefined1 *)((int)&iStack_100 + (uint)*pbVar11);
            pbVar11 = pbVar11 + 1;
            puVar9 = puVar9 + 1;
          } while (iVar10 < param_1[7]);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_1[8]);
    }
    if (*(code **)(DAT_10089de0 + 0x29c) == (code *)0x0) {
      return local_148;
    }
    if ((param_1[0x10] & 2U) != 0) {
      (**(code **)(DAT_10089de0 + 0x29c))(param_1);
    }
    uVar6 = local_148[0x10];
  }
  else {
    puStack_104 = (undefined4 *)(**(code **)(DAT_10089de0 + 0x34c))((param_1[7] * 3 + 6) * 8);
    puStack_124 = puStack_104 + 3;
    puStack_130 = puStack_104 + param_1[7] * 3 + 9;
    iVar5 = -1;
    iStack_100 = 0;
    iStack_fc = 0;
    iStack_f8 = 0;
    puVar8 = puStack_104;
    if (-1 < param_1[7] + 1) {
      do {
        *puVar8 = 0;
        puVar8[1] = 0;
        puVar8[2] = 0;
        iVar5 = iVar5 + 1;
        puVar8 = puVar8 + 3;
      } while (iVar5 < param_1[7] + 1);
    }
    uStack_138 = 0;
    uVar6 = uStack_13c;
    if (0 < param_1[8]) {
      do {
        iVar5 = -1;
        iStack_100 = 0;
        iStack_fc = 0;
        iStack_f8 = 0;
        if (-1 < param_1[7] + 1) {
          puVar8 = puStack_130 + -3;
          do {
            *puVar8 = 0;
            puVar8[1] = 0;
            iVar5 = iVar5 + 1;
            puVar8[2] = 0;
            puVar8 = puVar8 + 3;
          } while (iVar5 < param_1[7] + 1);
        }
        if ((uStack_138 & 1) == 0) {
          iVar10 = param_1[10] * uStack_138;
          iStack_134 = -1;
          iVar5 = local_148[10] * uStack_138;
        }
        else {
          iVar10 = (param_1[9] >> 3) * (param_1[7] + -1) + param_1[10] * uStack_138;
          iStack_134 = 1;
          iVar5 = local_148[10] * uStack_138 + local_148[7] + -1;
        }
        puStack_120 = (undefined1 *)(iVar5 + local_118);
        puVar12 = (uint *)(local_11c + iVar10);
        iStack_128 = 0;
        if (0 < param_1[7]) {
          iStack_108 = -1;
          if (iStack_134 < 0) {
            iStack_108 = 1;
          }
          do {
            iStack_12c = iStack_128;
            if (-1 < iStack_134) {
              iStack_12c = (param_1[7] - iStack_128) + -1;
            }
            if (*param_1 == 1) {
              pbVar11 = local_10c + (uint)(byte)*puVar12 * 3;
              puVar12 = (uint *)((int)puVar12 + iStack_108);
              uStack_144 = (uint)*pbVar11;
              uVar6 = (uint)pbVar11[2];
              uStack_140 = (uint)pbVar11[1];
            }
            else {
              if (param_1[9] == 0x18) {
                uStack_144 = (uint)(byte)*puVar12;
                uVar6 = (uint)*(byte *)((int)puVar12 + 2);
                uStack_140 = (uint)*(byte *)((int)puVar12 + 1);
                iVar5 = -3;
                if (iStack_134 < 0) {
                  iVar5 = 3;
                }
              }
              else {
                if (param_1[9] != 0x20) goto LAB_10007df0;
                iVar5 = param_1[2];
                if (iVar5 == -0x1000000) {
                  uStack_144 = *puVar12 >> 0x18;
                }
                else if (iVar5 == 0xff00) {
                  uStack_144 = (uint)*(byte *)((int)puVar12 + 1);
                }
                else if (iVar5 == 0xff0000) {
                  uStack_144 = (*puVar12 & 0xff0000) >> 0x10;
                }
                else {
                  uStack_144 = *puVar12 & 0xff;
                }
                iVar5 = param_1[3];
                if (iVar5 == -0x1000000) {
                  uStack_140 = *puVar12 >> 0x18;
                }
                else if (iVar5 == 0xff00) {
                  uStack_140 = (uint)*(byte *)((int)puVar12 + 1);
                }
                else if (iVar5 == 0xff0000) {
                  uStack_140 = (*puVar12 & 0xff0000) >> 0x10;
                }
                else {
                  uStack_140 = *puVar12 & 0xff;
                }
                iVar5 = param_1[4];
                if (iVar5 == -0x1000000) {
                  uVar6 = *puVar12 >> 0x18;
                }
                else if (iVar5 == 0xff00) {
                  uVar6 = (uint)*(byte *)((int)puVar12 + 1);
                }
                else if (iVar5 == 0xff0000) {
                  uVar6 = (*puVar12 & 0xff0000) >> 0x10;
                }
                else {
                  uVar6 = *puVar12 & 0xff;
                }
                iVar5 = -4;
                if (iStack_134 < 0) {
                  iVar5 = 4;
                }
              }
              puVar12 = (uint *)((int)puVar12 + iVar5);
            }
LAB_10007df0:
            uVar6 = uVar6 * 0x100;
            uStack_144 = uStack_144 * 0x100;
            uStack_140 = uStack_140 * 0x100;
            if (local_114 != 0) {
              iStack_100 = iStack_100 + puStack_124[iStack_12c * 3];
              iStack_fc = iStack_fc + puStack_124[iStack_12c * 3 + 1];
              iStack_f8 = iStack_f8 + puStack_124[iStack_12c * 3 + 2];
              uStack_144 = uStack_144 + iStack_100;
              uStack_140 = uStack_140 + iStack_fc;
              uVar6 = uVar6 + iStack_f8;
              if ((int)uStack_144 < 0) {
                uStack_144 = 0;
              }
              else if (0xffff < (int)uStack_144) {
                uStack_144 = 0xffff;
              }
              if ((int)uStack_140 < 0) {
                uStack_140 = 0;
              }
              else if (0xffff < (int)uStack_140) {
                uStack_140 = 0xffff;
              }
              if ((int)uVar6 < 0) {
                uVar6 = 0;
              }
              else if (0xffff < (int)uVar6) {
                uVar6 = 0xffff;
              }
            }
            bStack_154 = uStack_144._1_1_;
            bStack_153 = uStack_140._1_1_;
            bStack_152 = (byte)(uVar6 >> 8);
            if (local_110 != 0) {
              bStack_154 = (&DAT_1008a210)[uStack_144._1_1_];
              bStack_153 = (&DAT_1008a210)[uStack_140._1_1_];
              bStack_152 = (&DAT_1008a210)[bStack_152];
            }
            if ((((bStack_154 != 0) || (bStack_153 != 0)) || (bStack_152 != 0)) ||
               (uVar7 = 0, (param_3 & 8) == 0)) {
              uVar7 = FUN_1000c030(&bStack_154);
            }
            *puStack_120 = (char)uVar7;
            puStack_120 = puStack_120 + iStack_108;
            if (local_114 != 0) {
              if (local_110 == 0) {
                bVar2 = *(byte *)((int)&DAT_10089f00 + uVar7);
                bVar3 = *(byte *)((int)&DAT_1008a000 + uVar7);
                bVar4 = *(byte *)((int)&DAT_10089df0 + uVar7);
              }
              else {
                bVar2 = (&DAT_1008a210)[*(byte *)((int)&DAT_10089f00 + uVar7)];
                uStack_150 = (uint)*(byte *)((int)&DAT_1008a000 + uVar7);
                bVar3 = (&DAT_1008a210)[uStack_150];
                uStack_150 = (uint)*(byte *)((int)&DAT_10089df0 + uVar7);
                bVar4 = (&DAT_1008a210)[uStack_150];
              }
              iStack_100 = (int)(uStack_144 + (uint)bVar2 * -0x100) >> 4;
              iStack_fc = (int)(uStack_140 + (uint)bVar3 * -0x100) >> 4;
              iStack_f8 = (int)(uVar6 + (uint)bVar4 * -0x100) >> 4;
              piVar1 = puStack_130 + (iStack_12c - iStack_134) * 3;
              *piVar1 = *piVar1 + iStack_100 * 3;
              piVar1[1] = piVar1[1] + iStack_fc * 3;
              piVar1[2] = piVar1[2] + iStack_f8 * 3;
              piStack_14c = puStack_130 + iStack_12c * 3;
              *piStack_14c = *piStack_14c + iStack_100 * 5;
              piStack_14c[1] = piStack_14c[1] + iStack_fc * 5;
              piStack_14c[2] = piStack_14c[2] + iStack_f8 * 5;
              uStack_150 = (iStack_134 + iStack_12c) * 3;
              piVar1 = puStack_130 + (iStack_134 + iStack_12c) * 3;
              *piVar1 = *piVar1 + iStack_100;
              piVar1[1] = piVar1[1] + iStack_fc;
              piVar1[2] = piVar1[2] + iStack_f8;
              iStack_100 = iStack_100 * 7;
              iStack_fc = iStack_fc * 7;
              iStack_f8 = iStack_f8 * 7;
            }
            iStack_128 = iStack_128 + 1;
          } while (iStack_128 < param_1[7]);
        }
        puVar8 = puStack_124;
        uStack_138 = uStack_138 + 1;
        puStack_124 = puStack_130;
        puStack_130 = puVar8;
      } while ((int)uStack_138 < param_1[8]);
    }
    (**(code **)(DAT_10089de0 + 0x358))(puStack_104);
    if (*(code **)(DAT_10089de0 + 0x29c) == (code *)0x0) {
      return local_148;
    }
    if ((param_1[0x10] & 2U) != 0) {
      (**(code **)(DAT_10089de0 + 0x29c))(param_1);
    }
    uVar6 = local_148[0x10];
  }
  if ((uVar6 & 2) != 0) {
    (**(code **)(DAT_10089de0 + 0x29c))(local_148);
  }
  return local_148;
}


