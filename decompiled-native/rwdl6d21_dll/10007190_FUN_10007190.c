// 10007190 FUN_10007190 [Global]
// programa: RWDL6D21.DLL

undefined4 * FUN_10007190(int *param_1,undefined4 *param_2,uint param_3)

{
  int *piVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  byte *pbVar11;
  byte bStack_150;
  byte bStack_14f;
  byte bStack_14e;
  uint uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 *local_13c;
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
  iVar5 = param_1[7];
  param_2[8] = param_1[8];
  param_2[7] = iVar5;
  param_2[9] = 8;
  local_13c = FUN_10009d40(param_2);
  if (local_13c == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  if (*(code **)(DAT_1007bda8 + 0x298) != (code *)0x0) {
    if (((param_1[0x10] & 2U) != 0) &&
       (iVar5 = (**(code **)(DAT_1007bda8 + 0x298))(param_1), iVar5 == 0)) {
      return (undefined4 *)0x0;
    }
    if (((local_13c[0x10] & 2) != 0) &&
       (iVar5 = (**(code **)(DAT_1007bda8 + 0x298))(local_13c), iVar5 == 0)) {
      if (((param_1[0x10] & 2U) != 0) && (*(code **)(DAT_1007bda8 + 0x29c) != (code *)0x0)) {
        (**(code **)(DAT_1007bda8 + 0x29c))(param_1);
      }
      return (undefined4 *)0x0;
    }
  }
  local_11c = param_1[6];
  local_118 = local_13c[6];
  local_114 = param_3 & 1;
  local_110 = param_3 & 2;
  if ((local_114 == 0) && (*param_1 == 1)) {
    iVar5 = 0;
    pbVar11 = local_10c;
    do {
      bStack_150 = *pbVar11;
      bStack_14f = pbVar11[1];
      bStack_14e = pbVar11[2];
      if (local_110 != 0) {
        bStack_150 = (&DAT_1007c1d0)[bStack_150];
        bStack_14f = (&DAT_1007c1d0)[bStack_14f];
        bStack_14e = (&DAT_1007c1d0)[bStack_14e];
      }
      pbVar11 = pbVar11 + 3;
      iVar8 = iVar5 + 1;
      uVar6 = FUN_1000b7e0(&bStack_150);
      *(char *)((int)&iStack_100 + iVar5) = (char)uVar6;
      iVar5 = iVar8;
    } while (iVar8 < 0x100);
    iVar5 = 0;
    if (0 < param_1[8]) {
      do {
        iVar8 = 0;
        puVar9 = (undefined1 *)(local_118 + local_13c[10] * iVar5);
        pbVar11 = (byte *)(local_11c + param_1[10] * iVar5);
        if (0 < param_1[7]) {
          do {
            iVar8 = iVar8 + 1;
            *puVar9 = *(undefined1 *)((int)&iStack_100 + (uint)*pbVar11);
            puVar9 = puVar9 + 1;
            pbVar11 = pbVar11 + 1;
          } while (iVar8 < param_1[7]);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_1[8]);
    }
    if (*(code **)(DAT_1007bda8 + 0x29c) == (code *)0x0) {
      return local_13c;
    }
    if ((param_1[0x10] & 2U) != 0) {
      (**(code **)(DAT_1007bda8 + 0x29c))(param_1);
    }
    uVar6 = local_13c[0x10];
  }
  else {
    puStack_104 = (undefined4 *)(**(code **)(DAT_1007bda8 + 0x34c))((param_1[7] * 3 + 6) * 8);
    puStack_124 = puStack_104 + 3;
    iVar5 = -1;
    puStack_130 = puStack_104 + param_1[7] * 3 + 9;
    iStack_100 = 0;
    iStack_fc = 0;
    iStack_f8 = 0;
    puVar10 = puStack_104;
    if (-1 < param_1[7] + 1) {
      do {
        *puVar10 = 0;
        puVar10[1] = 0;
        iVar5 = iVar5 + 1;
        puVar10[2] = 0;
        puVar10 = puVar10 + 3;
      } while (iVar5 < param_1[7] + 1);
    }
    uStack_138 = 0;
    if (0 < param_1[8]) {
      do {
        iVar5 = -1;
        iStack_100 = 0;
        iStack_fc = 0;
        iStack_f8 = 0;
        if (-1 < param_1[7] + 1) {
          puVar10 = puStack_130 + -3;
          do {
            *puVar10 = 0;
            puVar10[1] = 0;
            iVar5 = iVar5 + 1;
            puVar10[2] = 0;
            puVar10 = puVar10 + 3;
          } while (iVar5 < param_1[7] + 1);
        }
        if ((uStack_138 & 1) == 0) {
          iVar8 = param_1[10] * uStack_138;
          iStack_134 = -1;
          iVar5 = local_13c[10] * uStack_138;
        }
        else {
          iVar8 = (param_1[9] >> 3) * (param_1[7] + -1) + param_1[10] * uStack_138;
          iStack_134 = 1;
          iVar5 = local_13c[10] * uStack_138 + local_13c[7] + -1;
        }
        puStack_120 = (undefined1 *)(iVar5 + local_118);
        puVar7 = (uint *)(local_11c + iVar8);
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
              uVar6 = *puVar7;
              puVar7 = (uint *)((int)puVar7 + iStack_108);
              pbVar11 = local_10c + (uint)(byte)uVar6 * 3;
              uStack_148 = (uint)*pbVar11;
              uStack_144 = (uint)pbVar11[1];
              uStack_140 = (uint)pbVar11[2];
            }
            else {
              if (param_1[9] == 0x18) {
                uStack_148 = (uint)(byte)*puVar7;
                uStack_144 = (uint)*(byte *)((int)puVar7 + 1);
                uStack_140 = (uint)*(byte *)((int)puVar7 + 2);
                iVar5 = -3;
                if (iStack_134 < 0) {
                  iVar5 = 3;
                }
              }
              else {
                if (param_1[9] != 0x20) goto LAB_100076d3;
                iVar5 = param_1[2];
                if (iVar5 == -0x1000000) {
                  uStack_148 = *puVar7 >> 0x18;
                }
                else if (iVar5 == 0xff00) {
                  uStack_148 = (uint)*(byte *)((int)puVar7 + 1);
                }
                else if (iVar5 == 0xff0000) {
                  uStack_148 = (*puVar7 & 0xff0000) >> 0x10;
                }
                else {
                  uStack_148 = *puVar7 & 0xff;
                }
                iVar5 = param_1[3];
                if (iVar5 == -0x1000000) {
                  uStack_144 = *puVar7 >> 0x18;
                }
                else if (iVar5 == 0xff00) {
                  uStack_144 = (uint)*(byte *)((int)puVar7 + 1);
                }
                else if (iVar5 == 0xff0000) {
                  uStack_144 = (*puVar7 & 0xff0000) >> 0x10;
                }
                else {
                  uStack_144 = *puVar7 & 0xff;
                }
                iVar5 = param_1[4];
                if (iVar5 == -0x1000000) {
                  uStack_140 = *puVar7 >> 0x18;
                }
                else if (iVar5 == 0xff00) {
                  uStack_140 = (uint)*(byte *)((int)puVar7 + 1);
                }
                else if (iVar5 == 0xff0000) {
                  uStack_140 = (*puVar7 & 0xff0000) >> 0x10;
                }
                else {
                  uStack_140 = *puVar7 & 0xff;
                }
                iVar5 = -4;
                if (iStack_134 < 0) {
                  iVar5 = 4;
                }
              }
              puVar7 = (uint *)((int)puVar7 + iVar5);
            }
LAB_100076d3:
            uStack_148 = uStack_148 * 0x100;
            uStack_144 = uStack_144 * 0x100;
            uStack_140 = uStack_140 * 0x100;
            if (local_114 != 0) {
              iStack_100 = iStack_100 + puStack_124[iStack_12c * 3];
              iStack_fc = iStack_fc + puStack_124[iStack_12c * 3 + 1];
              iStack_f8 = iStack_f8 + puStack_124[iStack_12c * 3 + 2];
              uStack_148 = uStack_148 + iStack_100;
              uStack_144 = uStack_144 + iStack_fc;
              uStack_140 = uStack_140 + iStack_f8;
              if ((int)uStack_148 < 0) {
                uStack_148 = 0;
              }
              else if (0xffff < (int)uStack_148) {
                uStack_148 = 0xffff;
              }
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
            }
            bStack_150 = uStack_148._1_1_;
            bStack_14f = uStack_144._1_1_;
            bStack_14e = uStack_140._1_1_;
            if (local_110 != 0) {
              bStack_150 = (&DAT_1007c1d0)[uStack_148._1_1_];
              bStack_14f = (&DAT_1007c1d0)[uStack_144._1_1_];
              bStack_14e = (&DAT_1007c1d0)[uStack_140._1_1_];
            }
            if ((((bStack_150 != 0) || (bStack_14f != 0)) || (bStack_14e != 0)) ||
               (uVar6 = 0, (param_3 & 8) == 0)) {
              uVar6 = FUN_1000b7e0(&bStack_150);
            }
            *puStack_120 = (char)uVar6;
            puStack_120 = puStack_120 + iStack_108;
            if (local_114 != 0) {
              if (local_110 == 0) {
                bVar2 = *(byte *)((int)&DAT_1007bec0 + uVar6);
                bVar3 = *(byte *)((int)&DAT_1007bfc0 + uVar6);
                uStack_14c = (uint)*(byte *)((int)&DAT_1007bdb0 + uVar6);
                uVar4 = uStack_14c * 0x100;
                uVar6 = uStack_14c;
              }
              else {
                uStack_14c = (uint)*(byte *)((int)&DAT_1007bec0 + uVar6);
                bVar2 = (&DAT_1007c1d0)[uStack_14c];
                uStack_14c = (uint)*(byte *)((int)&DAT_1007bfc0 + uVar6);
                bVar3 = (&DAT_1007c1d0)[uStack_14c];
                uStack_14c = (uint)*(byte *)((int)&DAT_1007bdb0 + uVar6);
                uVar4 = uStack_14c;
                uVar6 = (uint)(byte)(&DAT_1007c1d0)[uStack_14c];
              }
              uStack_14c = uVar4;
              iStack_fc = (int)(uStack_144 + (uint)bVar3 * -0x100) >> 4;
              iStack_100 = (int)(uStack_148 + (uint)bVar2 * -0x100) >> 4;
              iStack_f8 = (int)(uStack_140 + uVar6 * -0x100) >> 4;
              piVar1 = puStack_130 + (iStack_12c - iStack_134) * 3;
              *piVar1 = *piVar1 + iStack_100 * 3;
              piVar1[1] = piVar1[1] + iStack_fc * 3;
              piVar1[2] = piVar1[2] + iStack_f8 * 3;
              piVar1 = puStack_130 + iStack_12c * 3;
              *piVar1 = *piVar1 + iStack_100 * 5;
              piVar1[1] = piVar1[1] + iStack_fc * 5;
              piVar1[2] = piVar1[2] + iStack_f8 * 5;
              piVar1 = puStack_130 + (iStack_134 + iStack_12c) * 3;
              *piVar1 = puStack_130[(iStack_134 + iStack_12c) * 3] + iStack_100;
              piVar1[1] = piVar1[1] + iStack_fc;
              piVar1[2] = piVar1[2] + iStack_f8;
              iStack_100 = iStack_100 * 7;
              iStack_fc = iStack_fc * 7;
              iStack_f8 = iStack_f8 * 7;
            }
            iStack_128 = iStack_128 + 1;
          } while (iStack_128 < param_1[7]);
        }
        puVar10 = puStack_124;
        uStack_138 = uStack_138 + 1;
        puStack_124 = puStack_130;
        puStack_130 = puVar10;
      } while ((int)uStack_138 < param_1[8]);
    }
    (**(code **)(DAT_1007bda8 + 0x358))(puStack_104);
    if (*(code **)(DAT_1007bda8 + 0x29c) == (code *)0x0) {
      return local_13c;
    }
    if ((param_1[0x10] & 2U) != 0) {
      (**(code **)(DAT_1007bda8 + 0x29c))(param_1);
    }
    uVar6 = local_13c[0x10];
  }
  if ((uVar6 & 2) != 0) {
    (**(code **)(DAT_1007bda8 + 0x29c))(local_13c);
  }
  return local_13c;
}


