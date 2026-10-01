// 10005ea0 FUN_10005ea0 [Global]
// program: RWDL8D21.DLL

undefined4 FUN_10005ea0(int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)

{
  byte bVar1;
  byte bVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined1 *puVar10;
  int iVar11;
  int iVar12;
  byte *pbVar13;
  ulonglong uVar14;
  int iStack_10;
  int iStack_4;
  
  if ((DAT_100751cc == (int *)0x0) || (DAT_100751e4 < *(int *)(DAT_10077da8 + 0x20))) {
    iVar11 = *(int *)(DAT_10077da8 + 0x20);
    if (DAT_100751cc == (int *)0x0) {
      piVar3 = (int *)(**(code **)(DAT_10077da8 + 0x34c))(iVar11 * 0x18);
    }
    else {
      piVar3 = (int *)(**(code **)(DAT_10077da8 + 0x354))(DAT_100751cc,iVar11 * 0x18);
    }
    if (piVar3 == (int *)0x0) {
      return 0;
    }
    DAT_100751d0 = piVar3 + iVar11;
    DAT_100751d4 = DAT_100751d0 + iVar11;
    DAT_100751d8 = DAT_100751d4 + iVar11;
    DAT_100751dc = DAT_100751d8 + iVar11;
    DAT_100751e0 = DAT_100751dc + iVar11;
    DAT_100751cc = piVar3;
    DAT_100751e4 = iVar11;
  }
  if (*(int *)(param_5 + 0x18) == 0) {
    if ((param_6 & 1) == 0) {
      *(int *)(param_5 + 0x20) = param_3;
      *(int *)(param_5 + 0x1c) = param_2;
      iVar11 = *(int *)(param_5 + 0x24) * param_2;
      uVar4 = ((int)(iVar11 + (iVar11 >> 0x1f & 7U)) >> 3) + 3U & 0xfffffffc;
      *(uint *)(param_5 + 0x28) = uVar4;
      uVar5 = (**(code **)(DAT_10077da8 + 0x350))(1,param_3 * uVar4);
      *(undefined4 *)(param_5 + 0x18) = uVar5;
    }
    else {
      iVar11 = *(int *)(DAT_10077da8 + 700);
      if ((iVar11 == 0) || (*(int *)(DAT_10077da8 + 0x20) / 2 <= param_2)) {
        uVar4 = (param_3 << 0x10) / param_2;
        if (((uVar4 & 0xffff) == 0) && (0x10000 < (int)uVar4)) {
          iVar11 = (int)uVar4 >> 0x10;
          *(undefined4 *)(param_5 + 0x1c) = *(undefined4 *)(DAT_10077da8 + 0x20);
          *(int *)(param_5 + 0x20) = *(int *)(DAT_10077da8 + 0x20) * iVar11;
          uVar9 = *(int *)(DAT_10077da8 + 0x20) * 3 + 3U & 0xfffffffc;
          *(uint *)(param_5 + 0x28) = uVar9;
          uVar5 = (**(code **)(DAT_10077da8 + 0x350))
                            (1,*(int *)(DAT_10077da8 + 0x20) * uVar9 * iVar11);
          *(undefined4 *)(param_5 + 0x18) = uVar5;
          DAT_10077b38 = (param_2 << 0x10) / *(int *)(DAT_10077da8 + 0x20);
          iVar11 = *(int *)(DAT_10077da8 + 0x24) * iVar11;
          iVar6 = *(int *)(DAT_10077da8 + 0x24) * uVar4;
        }
        else {
          *(undefined4 *)(param_5 + 0x1c) = *(undefined4 *)(DAT_10077da8 + 0x20);
          *(undefined4 *)(param_5 + 0x20) = *(undefined4 *)(DAT_10077da8 + 0x24);
          uVar4 = *(int *)(DAT_10077da8 + 0x20) * 3 + 3U & 0xfffffffc;
          *(uint *)(param_5 + 0x28) = uVar4;
          uVar5 = (**(code **)(DAT_10077da8 + 0x350))(1,*(int *)(DAT_10077da8 + 0x24) * uVar4);
          *(undefined4 *)(param_5 + 0x18) = uVar5;
          DAT_10077b38 = (param_2 << 0x10) / *(int *)(DAT_10077da8 + 0x20);
          iVar11 = *(int *)(DAT_10077da8 + 0x24);
          iVar6 = *(int *)(DAT_10077da8 + 0x24) << 0x10;
        }
        DAT_10077b3c = iVar6 / param_3;
        DAT_10077b34 = (param_3 << 0x10) / iVar11;
        uVar14 = __ftol();
        DAT_10077b28 = ((int)((longlong)
                              ((ulonglong)(uint)((int)uVar14 >> 0x1f) << 0x20 | uVar14 & 0xffffffff)
                             / (longlong)param_2) + 0x80 >> 8) * (DAT_10077b3c + 0x80 >> 8);
        iVar11 = 0;
        DAT_10077b2c = 0;
        DAT_10077b30 = 0;
        if (0 < *(int *)(DAT_10077da8 + 0x20)) {
          iVar6 = 0;
          do {
            *(undefined4 *)((int)DAT_100751cc + iVar6) = 0;
            iVar11 = iVar11 + 1;
            *(undefined4 *)((int)DAT_100751d0 + iVar6) = 0;
            *(undefined4 *)((int)DAT_100751d4 + iVar6) = 0;
            iVar6 = iVar6 + 4;
          } while (iVar11 < *(int *)(DAT_10077da8 + 0x20));
        }
      }
      else {
        uVar4 = (param_3 << 0x10) / param_2;
        if (((uVar4 & 0xffff) == 0) && (0x10000 < (int)uVar4)) {
          *(int *)(param_5 + 0x1c) = iVar11;
          iVar11 = (int)uVar4 >> 0x10;
          *(int *)(param_5 + 0x20) = *(int *)(DAT_10077da8 + 700) * iVar11;
          uVar9 = *(int *)(DAT_10077da8 + 700) * 3 + 3U & 0xfffffffc;
          *(uint *)(param_5 + 0x28) = uVar9;
          uVar5 = (**(code **)(DAT_10077da8 + 0x350))
                            (1,*(int *)(DAT_10077da8 + 700) * uVar9 * iVar11);
          *(undefined4 *)(param_5 + 0x18) = uVar5;
          DAT_10077b38 = (param_2 << 0x10) / *(int *)(DAT_10077da8 + 700);
          iVar11 = *(int *)(DAT_10077da8 + 0x2c0) * iVar11;
          iVar6 = *(int *)(DAT_10077da8 + 0x2c0) * uVar4;
        }
        else {
          *(int *)(param_5 + 0x1c) = iVar11;
          *(undefined4 *)(param_5 + 0x20) = *(undefined4 *)(DAT_10077da8 + 0x2c0);
          uVar4 = *(int *)(DAT_10077da8 + 700) * 3 + 3U & 0xfffffffc;
          *(uint *)(param_5 + 0x28) = uVar4;
          uVar5 = (**(code **)(DAT_10077da8 + 0x350))(1,*(int *)(DAT_10077da8 + 0x2c0) * uVar4);
          *(undefined4 *)(param_5 + 0x18) = uVar5;
          DAT_10077b38 = (param_2 << 0x10) / *(int *)(DAT_10077da8 + 700);
          iVar11 = *(int *)(DAT_10077da8 + 0x2c0);
          iVar6 = *(int *)(DAT_10077da8 + 0x2c0) << 0x10;
        }
        DAT_10077b3c = iVar6 / param_3;
        DAT_10077b34 = (param_3 << 0x10) / iVar11;
        uVar14 = __ftol();
        DAT_10077b28 = ((int)((longlong)
                              ((ulonglong)(uint)((int)uVar14 >> 0x1f) << 0x20 | uVar14 & 0xffffffff)
                             / (longlong)param_2) + 0x80 >> 8) * (DAT_10077b3c + 0x80 >> 8);
        iVar11 = 0;
        DAT_10077b2c = 0;
        DAT_10077b30 = 0;
        if (0 < *(int *)(DAT_10077da8 + 700)) {
          iVar6 = 0;
          do {
            *(undefined4 *)((int)DAT_100751cc + iVar6) = 0;
            iVar11 = iVar11 + 1;
            *(undefined4 *)((int)DAT_100751d0 + iVar6) = 0;
            *(undefined4 *)((int)DAT_100751d4 + iVar6) = 0;
            iVar6 = iVar6 + 4;
          } while (iVar11 < *(int *)(DAT_10077da8 + 700));
        }
      }
    }
  }
  if (*(int *)(param_5 + 0x18) == 0) {
    return 0;
  }
  if ((param_6 & 1) == 0) {
    if ((param_6 & 2) == 0) {
      iVar11 = *(int *)(param_5 + 0x28) * param_4;
    }
    else {
      iVar11 = ((param_3 - param_4) + -1) * *(int *)(param_5 + 0x28);
    }
    puVar10 = (undefined1 *)(*(int *)(param_5 + 0x18) + iVar11);
    if (*(int *)(param_5 + 0x24) == 0x18) {
      iVar11 = 0;
      if (0 < param_2 * 3) {
        do {
          iVar11 = iVar11 + 1;
          *puVar10 = *(undefined1 *)(param_1 + -1 + iVar11);
          puVar10 = puVar10 + 1;
        } while (iVar11 < param_2 * 3);
        return 1;
      }
    }
    else {
      iVar11 = 0;
      if (0 < param_2) {
        do {
          iVar11 = iVar11 + 1;
          *puVar10 = *(undefined1 *)(param_1 + -1 + iVar11);
          puVar10 = puVar10 + 1;
        } while (iVar11 < param_2);
      }
    }
  }
  else {
    iVar11 = 0;
    iStack_4 = 0;
    if (0 < *(int *)(param_5 + 0x1c)) {
      do {
        uVar4 = DAT_10077b38 * iStack_4;
        uVar9 = DAT_10077b38 + uVar4;
        if (((uVar9 ^ uVar4) & 0xffff0000) == 0) {
          iVar12 = (uVar9 & 0xffff) - (uVar4 & 0xffff);
          iVar6 = 0;
          pbVar13 = (byte *)(((int)uVar4 >> 0x10) * 3 + param_1);
          if (iVar12 == 0) {
            iVar7 = 0;
            iVar8 = 0;
          }
          else if (iVar12 == 0x10000) {
            iVar8 = (uint)*pbVar13 << 0x10;
            iVar7 = (uint)pbVar13[1] << 0x10;
            iVar6 = (uint)pbVar13[2] << 0x10;
          }
          else {
            iVar8 = (uint)*pbVar13 * iVar12;
            iVar7 = (uint)pbVar13[1] * iVar12;
            iVar6 = (uint)pbVar13[2] * iVar12;
          }
          *(int *)((int)DAT_100751d8 + iVar11) = iVar8;
          *(int *)((int)DAT_100751dc + iVar11) = iVar7;
          *(int *)((int)DAT_100751e0 + iVar11) = iVar6;
        }
        else {
          iVar6 = 0;
          *(undefined4 *)((int)DAT_100751e0 + iVar11) = 0;
          *(undefined4 *)((int)DAT_100751dc + iVar11) = *(undefined4 *)((int)DAT_100751e0 + iVar11);
          *(undefined4 *)((int)DAT_100751d8 + iVar11) = *(undefined4 *)((int)DAT_100751dc + iVar11);
          if ((uVar4 & 0xffff) != 0) {
            iVar12 = 0x10000 - (uVar4 & 0xffff);
            pbVar13 = (byte *)(((int)uVar4 >> 0x10) * 3 + param_1);
            if (iVar12 == 0) {
              iVar7 = 0;
              iStack_10 = 0;
            }
            else if (iVar12 == 0x10000) {
              iStack_10 = (uint)*pbVar13 << 0x10;
              iVar6 = (uint)pbVar13[2] << 0x10;
              iVar7 = (uint)pbVar13[1] << 0x10;
            }
            else {
              iStack_10 = (uint)*pbVar13 * iVar12;
              iVar6 = (uint)pbVar13[2] * iVar12;
              iVar7 = (uint)pbVar13[1] * iVar12;
            }
            *(int *)((int)DAT_100751d8 + iVar11) = *(int *)((int)DAT_100751d8 + iVar11) + iStack_10;
            *(int *)((int)DAT_100751dc + iVar11) = *(int *)((int)DAT_100751dc + iVar11) + iVar7;
            uVar4 = uVar4 + iVar12;
            *(int *)((int)DAT_100751e0 + iVar11) = *(int *)((int)DAT_100751e0 + iVar11) + iVar6;
          }
          for (; (int)(uVar4 & 0xffff0000) < (int)(uVar9 & 0xffff0000); uVar4 = uVar4 + 0x10000) {
            pbVar13 = (byte *)(param_1 + ((int)uVar4 >> 0x10) * 3);
            bVar1 = pbVar13[1];
            bVar2 = pbVar13[2];
            *(int *)((int)DAT_100751d8 + iVar11) =
                 *(int *)((int)DAT_100751d8 + iVar11) + (uint)*pbVar13 * 0x10000;
            *(int *)((int)DAT_100751dc + iVar11) =
                 *(int *)((int)DAT_100751dc + iVar11) + (uint)bVar1 * 0x10000;
            *(int *)((int)DAT_100751e0 + iVar11) =
                 *(int *)((int)DAT_100751e0 + iVar11) + (uint)bVar2 * 0x10000;
          }
          uVar9 = uVar9 & 0xffff;
          iVar6 = 0;
          if (uVar9 != 0) {
            pbVar13 = (byte *)(((int)uVar4 >> 0x10) * 3 + param_1);
            if (uVar9 == 0) {
              iVar7 = 0;
              iVar12 = 0;
            }
            else if (uVar9 == 0x10000) {
              iVar6 = (uint)*pbVar13 << 0x10;
              iVar12 = (uint)pbVar13[1] << 0x10;
              iVar7 = (uint)pbVar13[2] << 0x10;
            }
            else {
              iVar6 = *pbVar13 * uVar9;
              iVar12 = pbVar13[1] * uVar9;
              iVar7 = pbVar13[2] * uVar9;
            }
            *(int *)((int)DAT_100751d8 + iVar11) = *(int *)((int)DAT_100751d8 + iVar11) + iVar6;
            *(int *)((int)DAT_100751dc + iVar11) = *(int *)((int)DAT_100751dc + iVar11) + iVar12;
            *(int *)((int)DAT_100751e0 + iVar11) = *(int *)((int)DAT_100751e0 + iVar11) + iVar7;
          }
        }
        iVar11 = iVar11 + 4;
        iStack_4 = iStack_4 + 1;
      } while (iStack_4 < *(int *)(param_5 + 0x1c));
    }
    if ((int)(DAT_10077b30 + DAT_10077b3c) < 0x10000) {
      iVar6 = 0;
      iVar11 = 0;
      if (0 < *(int *)(param_5 + 0x1c)) {
        do {
          iVar6 = iVar6 + 1;
          *(int *)((int)DAT_100751cc + iVar11) =
               *(int *)((int)DAT_100751cc + iVar11) + *(int *)((int)DAT_100751d8 + iVar11);
          *(int *)((int)DAT_100751d0 + iVar11) =
               *(int *)((int)DAT_100751d0 + iVar11) + *(int *)((int)DAT_100751dc + iVar11);
          *(int *)((int)DAT_100751d4 + iVar11) =
               *(int *)((int)DAT_100751d4 + iVar11) + *(int *)((int)DAT_100751e0 + iVar11);
          iVar11 = iVar11 + 4;
        } while (iVar6 < *(int *)(param_5 + 0x1c));
      }
      DAT_10077b30 = DAT_10077b30 + DAT_10077b3c;
    }
    else {
      iVar11 = -DAT_10077b30;
      iVar6 = (iVar11 + 0x10080 >> 8) * (DAT_10077b34 + 0x80 >> 8);
      if ((iVar6 != 0) && (iVar12 = 0, 0 < *(int *)(param_5 + 0x1c))) {
        iVar7 = iVar6 + 0x80 >> 8;
        iVar6 = 0;
        do {
          iVar12 = iVar12 + 1;
          *(int *)((int)DAT_100751cc + iVar6) =
               *(int *)((int)DAT_100751cc + iVar6) +
               (*(int *)((int)DAT_100751d8 + iVar6) + 0x80 >> 8) * iVar7;
          *(int *)((int)DAT_100751d0 + iVar6) =
               *(int *)((int)DAT_100751d0 + iVar6) +
               (*(int *)((int)DAT_100751dc + iVar6) + 0x80 >> 8) * iVar7;
          *(int *)((int)DAT_100751d4 + iVar6) =
               *(int *)((int)DAT_100751d4 + iVar6) +
               (*(int *)((int)DAT_100751e0 + iVar6) + 0x80 >> 8) * iVar7;
          iVar6 = iVar6 + 4;
        } while (iVar12 < *(int *)(param_5 + 0x1c));
      }
      iVar6 = DAT_10077b2c;
      if ((param_6 & 2) != 0) {
        iVar6 = (*(int *)(param_5 + 0x20) - DAT_10077b2c) + -1;
      }
      FUN_10006b60(param_5,iVar6,DAT_100751cc,DAT_100751d0,DAT_100751d4,DAT_10077b28);
      DAT_10077b2c = DAT_10077b2c + 1;
      uVar4 = DAT_10077b3c - (iVar11 + 0x10000);
      if (0xffff < (int)uVar4) {
        iVar6 = 0;
        iVar11 = 0;
        if (0 < *(int *)(param_5 + 0x1c)) {
          do {
            iVar6 = iVar6 + 1;
            *(int *)((int)DAT_100751cc + iVar11) =
                 (*(int *)((int)DAT_100751d8 + iVar11) + 0x80 >> 8) * (DAT_10077b34 + 0x80 >> 8);
            *(int *)((int)DAT_100751d0 + iVar11) =
                 (*(int *)((int)DAT_100751dc + iVar11) + 0x80 >> 8) * (DAT_10077b34 + 0x80 >> 8);
            *(int *)((int)DAT_100751d4 + iVar11) =
                 (*(int *)((int)DAT_100751e0 + iVar11) + 0x80 >> 8) * (DAT_10077b34 + 0x80 >> 8);
            iVar11 = iVar11 + 4;
          } while (iVar6 < *(int *)(param_5 + 0x1c));
        }
        if (0xffff < (int)uVar4) {
          uVar9 = uVar4 >> 0x10;
          uVar4 = uVar4 + uVar9 * -0x10000;
          do {
            iVar11 = DAT_10077b2c;
            if ((param_6 & 2) != 0) {
              iVar11 = (*(int *)(param_5 + 0x20) - DAT_10077b2c) + -1;
            }
            FUN_10006b60(param_5,iVar11,DAT_100751cc,DAT_100751d0,DAT_100751d4,DAT_10077b28);
            DAT_10077b2c = DAT_10077b2c + 1;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
      }
      iVar11 = ((int)(uVar4 + 0x80) >> 8) * (DAT_10077b34 + 0x80 >> 8);
      DAT_10077b30 = uVar4;
      if (iVar11 == 0) {
        iVar6 = 0;
        iVar11 = 0;
        if (0 < *(int *)(param_5 + 0x1c)) {
          do {
            *(undefined4 *)((int)DAT_100751d4 + iVar11) = 0;
            iVar6 = iVar6 + 1;
            *(undefined4 *)((int)DAT_100751d0 + iVar11) =
                 *(undefined4 *)((int)DAT_100751d4 + iVar11);
            *(undefined4 *)((int)DAT_100751cc + iVar11) =
                 *(undefined4 *)((int)DAT_100751d0 + iVar11);
            iVar11 = iVar11 + 4;
          } while (iVar6 < *(int *)(param_5 + 0x1c));
        }
      }
      else {
        iVar6 = 0;
        if (0 < *(int *)(param_5 + 0x1c)) {
          iVar12 = iVar11 + 0x80 >> 8;
          iVar11 = 0;
          do {
            *(int *)((int)DAT_100751cc + iVar11) =
                 (*(int *)((int)DAT_100751d8 + iVar11) + 0x80 >> 8) * iVar12;
            iVar6 = iVar6 + 1;
            *(int *)((int)DAT_100751d0 + iVar11) =
                 (*(int *)((int)DAT_100751dc + iVar11) + 0x80 >> 8) * iVar12;
            *(int *)((int)DAT_100751d4 + iVar11) =
                 (*(int *)((int)DAT_100751e0 + iVar11) + 0x80 >> 8) * iVar12;
            iVar11 = iVar11 + 4;
          } while (iVar6 < *(int *)(param_5 + 0x1c));
        }
      }
    }
    if ((param_3 - param_4 == 1) && (DAT_10077b2c != *(int *)(param_5 + 0x20))) {
      if ((param_6 & 2) != 0) {
        FUN_10006b60(param_5,(*(int *)(param_5 + 0x20) - DAT_10077b2c) + -1,DAT_100751cc,
                     DAT_100751d0,DAT_100751d4,DAT_10077b28);
        return 1;
      }
      FUN_10006b60(param_5,DAT_10077b2c,DAT_100751cc,DAT_100751d0,DAT_100751d4,DAT_10077b28);
      return 1;
    }
  }
  return 1;
}


