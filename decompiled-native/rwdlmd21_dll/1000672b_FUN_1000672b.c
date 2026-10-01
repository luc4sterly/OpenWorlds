// 1000672b FUN_1000672b [Global]
// program: rwdlmd21.dll

undefined4 FUN_1000672b(void)

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
  int iVar10;
  byte *pbVar11;
  int iVar12;
  undefined1 *puVar13;
  bool in_ZF;
  ulonglong uVar14;
  int iStack00000008;
  int in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  int in_stack_0000001c;
  int in_stack_00000020;
  uint in_stack_00000024;
  
  if ((in_ZF) || (DAT_1008720c < *(int *)(DAT_10089de0 + 0x20))) {
    iVar10 = *(int *)(DAT_10089de0 + 0x20);
    if (DAT_100871f4 == (int *)0x0) {
      piVar3 = (int *)(**(code **)(DAT_10089de0 + 0x34c))(iVar10 * 0x18);
    }
    else {
      piVar3 = (int *)(**(code **)(DAT_10089de0 + 0x354))(DAT_100871f4,iVar10 * 0x18);
    }
    if (piVar3 == (int *)0x0) {
      return 0;
    }
    DAT_100871f8 = piVar3 + iVar10;
    DAT_100871fc = DAT_100871f8 + iVar10;
    DAT_10087200 = DAT_100871fc + iVar10;
    DAT_10087204 = DAT_10087200 + iVar10;
    DAT_10087208 = DAT_10087204 + iVar10;
    DAT_100871f4 = piVar3;
    DAT_1008720c = iVar10;
  }
  if (*(int *)(in_stack_00000020 + 0x18) == 0) {
    if ((in_stack_00000024 & 1) == 0) {
      *(int *)(in_stack_00000020 + 0x20) = in_stack_00000018;
      *(int *)(in_stack_00000020 + 0x1c) = in_stack_00000014;
      iVar10 = *(int *)(in_stack_00000020 + 0x24) * in_stack_00000014;
      uVar4 = ((int)(iVar10 + (iVar10 >> 0x1f & 7U)) >> 3) + 3U & 0xfffffffc;
      *(uint *)(in_stack_00000020 + 0x28) = uVar4;
      uVar5 = (**(code **)(DAT_10089de0 + 0x350))(1,in_stack_00000018 * uVar4);
      *(undefined4 *)(in_stack_00000020 + 0x18) = uVar5;
    }
    else {
      iVar10 = *(int *)(DAT_10089de0 + 700);
      if ((iVar10 == 0) || (*(int *)(DAT_10089de0 + 0x20) / 2 <= in_stack_00000014)) {
        uVar4 = (in_stack_00000018 << 0x10) / in_stack_00000014;
        if (((uVar4 & 0xffff) == 0) && (0x10000 < (int)uVar4)) {
          iVar10 = (int)uVar4 >> 0x10;
          *(undefined4 *)(in_stack_00000020 + 0x1c) = *(undefined4 *)(DAT_10089de0 + 0x20);
          *(int *)(in_stack_00000020 + 0x20) = *(int *)(DAT_10089de0 + 0x20) * iVar10;
          uVar9 = *(int *)(DAT_10089de0 + 0x20) * 3 + 3U & 0xfffffffc;
          *(uint *)(in_stack_00000020 + 0x28) = uVar9;
          uVar5 = (**(code **)(DAT_10089de0 + 0x350))
                            (1,*(int *)(DAT_10089de0 + 0x20) * uVar9 * iVar10);
          *(undefined4 *)(in_stack_00000020 + 0x18) = uVar5;
          DAT_10089b68 = (in_stack_00000014 << 0x10) / *(int *)(DAT_10089de0 + 0x20);
          iVar10 = *(int *)(DAT_10089de0 + 0x24) * iVar10;
          iVar6 = *(int *)(DAT_10089de0 + 0x24) * uVar4;
        }
        else {
          *(undefined4 *)(in_stack_00000020 + 0x1c) = *(undefined4 *)(DAT_10089de0 + 0x20);
          *(undefined4 *)(in_stack_00000020 + 0x20) = *(undefined4 *)(DAT_10089de0 + 0x24);
          uVar4 = *(int *)(DAT_10089de0 + 0x20) * 3 + 3U & 0xfffffffc;
          *(uint *)(in_stack_00000020 + 0x28) = uVar4;
          uVar5 = (**(code **)(DAT_10089de0 + 0x350))(1,*(int *)(DAT_10089de0 + 0x24) * uVar4);
          *(undefined4 *)(in_stack_00000020 + 0x18) = uVar5;
          DAT_10089b68 = (in_stack_00000014 << 0x10) / *(int *)(DAT_10089de0 + 0x20);
          iVar10 = *(int *)(DAT_10089de0 + 0x24);
          iVar6 = *(int *)(DAT_10089de0 + 0x24) << 0x10;
        }
        DAT_10089b6c = iVar6 / in_stack_00000018;
        DAT_10089b64 = (in_stack_00000018 << 0x10) / iVar10;
        uVar14 = __ftol();
        DAT_10089b58 = ((int)((longlong)
                              ((ulonglong)(uint)((int)uVar14 >> 0x1f) << 0x20 | uVar14 & 0xffffffff)
                             / (longlong)in_stack_00000014) + 0x80 >> 8) *
                       (DAT_10089b6c + 0x80 >> 8);
        iVar10 = 0;
        DAT_10089b5c = 0;
        DAT_10089b60 = 0;
        if (0 < *(int *)(DAT_10089de0 + 0x20)) {
          iVar6 = 0;
          do {
            *(undefined4 *)((int)DAT_100871f4 + iVar6) = 0;
            iVar10 = iVar10 + 1;
            *(undefined4 *)((int)DAT_100871f8 + iVar6) = 0;
            *(undefined4 *)((int)DAT_100871fc + iVar6) = 0;
            iVar6 = iVar6 + 4;
          } while (iVar10 < *(int *)(DAT_10089de0 + 0x20));
        }
      }
      else {
        uVar4 = (in_stack_00000018 << 0x10) / in_stack_00000014;
        if (((uVar4 & 0xffff) == 0) && (0x10000 < (int)uVar4)) {
          *(int *)(in_stack_00000020 + 0x1c) = iVar10;
          iVar10 = (int)uVar4 >> 0x10;
          *(int *)(in_stack_00000020 + 0x20) = *(int *)(DAT_10089de0 + 700) * iVar10;
          uVar9 = *(int *)(DAT_10089de0 + 700) * 3 + 3U & 0xfffffffc;
          *(uint *)(in_stack_00000020 + 0x28) = uVar9;
          uVar5 = (**(code **)(DAT_10089de0 + 0x350))
                            (1,*(int *)(DAT_10089de0 + 700) * uVar9 * iVar10);
          *(undefined4 *)(in_stack_00000020 + 0x18) = uVar5;
          DAT_10089b68 = (in_stack_00000014 << 0x10) / *(int *)(DAT_10089de0 + 700);
          iVar10 = *(int *)(DAT_10089de0 + 0x2c0) * iVar10;
          iVar6 = *(int *)(DAT_10089de0 + 0x2c0) * uVar4;
        }
        else {
          *(int *)(in_stack_00000020 + 0x1c) = iVar10;
          *(undefined4 *)(in_stack_00000020 + 0x20) = *(undefined4 *)(DAT_10089de0 + 0x2c0);
          uVar4 = *(int *)(DAT_10089de0 + 700) * 3 + 3U & 0xfffffffc;
          *(uint *)(in_stack_00000020 + 0x28) = uVar4;
          uVar5 = (**(code **)(DAT_10089de0 + 0x350))(1,*(int *)(DAT_10089de0 + 0x2c0) * uVar4);
          *(undefined4 *)(in_stack_00000020 + 0x18) = uVar5;
          DAT_10089b68 = (in_stack_00000014 << 0x10) / *(int *)(DAT_10089de0 + 700);
          iVar10 = *(int *)(DAT_10089de0 + 0x2c0);
          iVar6 = *(int *)(DAT_10089de0 + 0x2c0) << 0x10;
        }
        DAT_10089b6c = iVar6 / in_stack_00000018;
        DAT_10089b64 = (in_stack_00000018 << 0x10) / iVar10;
        uVar14 = __ftol();
        DAT_10089b58 = ((int)((longlong)
                              ((ulonglong)(uint)((int)uVar14 >> 0x1f) << 0x20 | uVar14 & 0xffffffff)
                             / (longlong)in_stack_00000014) + 0x80 >> 8) *
                       (DAT_10089b6c + 0x80 >> 8);
        iVar10 = 0;
        DAT_10089b5c = 0;
        DAT_10089b60 = 0;
        if (0 < *(int *)(DAT_10089de0 + 700)) {
          iVar6 = 0;
          do {
            *(undefined4 *)((int)DAT_100871f4 + iVar6) = 0;
            iVar10 = iVar10 + 1;
            *(undefined4 *)((int)DAT_100871f8 + iVar6) = 0;
            *(undefined4 *)((int)DAT_100871fc + iVar6) = 0;
            iVar6 = iVar6 + 4;
          } while (iVar10 < *(int *)(DAT_10089de0 + 700));
        }
      }
    }
  }
  if (*(int *)(in_stack_00000020 + 0x18) == 0) {
    return 0;
  }
  if ((in_stack_00000024 & 1) == 0) {
    if ((in_stack_00000024 & 2) == 0) {
      iVar10 = *(int *)(in_stack_00000020 + 0x28) * in_stack_0000001c;
    }
    else {
      iVar10 = ((in_stack_00000018 - in_stack_0000001c) + -1) * *(int *)(in_stack_00000020 + 0x28);
    }
    puVar13 = (undefined1 *)(iVar10 + *(int *)(in_stack_00000020 + 0x18));
    if (*(int *)(in_stack_00000020 + 0x24) == 0x18) {
      iVar10 = 0;
      if (0 < in_stack_00000014 * 3) {
        do {
          iVar10 = iVar10 + 1;
          *puVar13 = *(undefined1 *)(in_stack_00000010 + -1 + iVar10);
          puVar13 = puVar13 + 1;
        } while (iVar10 < in_stack_00000014 * 3);
        return 1;
      }
    }
    else {
      iVar10 = 0;
      if (0 < in_stack_00000014) {
        do {
          iVar10 = iVar10 + 1;
          *puVar13 = *(undefined1 *)(in_stack_00000010 + -1 + iVar10);
          puVar13 = puVar13 + 1;
        } while (iVar10 < in_stack_00000014);
      }
    }
  }
  else {
    iVar10 = 0;
    iStack00000008 = 0;
    if (0 < *(int *)(in_stack_00000020 + 0x1c)) {
      do {
        uVar4 = iStack00000008 * DAT_10089b68;
        uVar9 = DAT_10089b68 + uVar4;
        if (((uVar9 ^ uVar4) & 0xffff0000) == 0) {
          iVar12 = (uVar9 & 0xffff) - (uVar4 & 0xffff);
          iVar6 = 0;
          pbVar11 = (byte *)(((int)uVar4 >> 0x10) * 3 + in_stack_00000010);
          if (iVar12 == 0) {
            iVar7 = 0;
            iVar8 = 0;
          }
          else if (iVar12 == 0x10000) {
            iVar8 = (uint)*pbVar11 << 0x10;
            iVar7 = (uint)pbVar11[1] << 0x10;
            iVar6 = (uint)pbVar11[2] << 0x10;
          }
          else {
            iVar8 = (uint)*pbVar11 * iVar12;
            iVar7 = (uint)pbVar11[1] * iVar12;
            iVar6 = (uint)pbVar11[2] * iVar12;
          }
          *(int *)((int)DAT_10087200 + iVar10) = iVar8;
          *(int *)((int)DAT_10087204 + iVar10) = iVar7;
          *(int *)((int)DAT_10087208 + iVar10) = iVar6;
        }
        else {
          iVar6 = 0;
          *(undefined4 *)((int)DAT_10087208 + iVar10) = 0;
          *(undefined4 *)((int)DAT_10087204 + iVar10) = *(undefined4 *)((int)DAT_10087208 + iVar10);
          *(undefined4 *)((int)DAT_10087200 + iVar10) = *(undefined4 *)((int)DAT_10087204 + iVar10);
          if ((uVar4 & 0xffff) != 0) {
            iVar12 = 0x10000 - (uVar4 & 0xffff);
            pbVar11 = (byte *)(in_stack_00000010 + ((int)uVar4 >> 0x10) * 3);
            if (iVar12 == 0) {
              iVar7 = 0;
              iVar8 = 0;
            }
            else if (iVar12 == 0x10000) {
              iVar8 = (uint)*pbVar11 << 0x10;
              iVar7 = (uint)pbVar11[1] << 0x10;
              iVar6 = (uint)pbVar11[2] << 0x10;
            }
            else {
              iVar8 = (uint)*pbVar11 * iVar12;
              iVar7 = (uint)pbVar11[1] * iVar12;
              iVar6 = (uint)pbVar11[2] * iVar12;
            }
            *(int *)((int)DAT_10087200 + iVar10) = *(int *)((int)DAT_10087200 + iVar10) + iVar8;
            *(int *)((int)DAT_10087204 + iVar10) = *(int *)((int)DAT_10087204 + iVar10) + iVar7;
            uVar4 = uVar4 + iVar12;
            *(int *)((int)DAT_10087208 + iVar10) = *(int *)((int)DAT_10087208 + iVar10) + iVar6;
          }
          for (; (int)(uVar4 & 0xffff0000) < (int)(uVar9 & 0xffff0000); uVar4 = uVar4 + 0x10000) {
            pbVar11 = (byte *)(in_stack_00000010 + ((int)uVar4 >> 0x10) * 3);
            bVar1 = pbVar11[1];
            bVar2 = pbVar11[2];
            *(int *)((int)DAT_10087200 + iVar10) =
                 *(int *)((int)DAT_10087200 + iVar10) + (uint)*pbVar11 * 0x10000;
            *(int *)((int)DAT_10087204 + iVar10) =
                 *(int *)((int)DAT_10087204 + iVar10) + (uint)bVar1 * 0x10000;
            *(int *)((int)DAT_10087208 + iVar10) =
                 *(int *)((int)DAT_10087208 + iVar10) + (uint)bVar2 * 0x10000;
          }
          uVar9 = uVar9 & 0xffff;
          iVar6 = 0;
          if (uVar9 != 0) {
            pbVar11 = (byte *)(((int)uVar4 >> 0x10) * 3 + in_stack_00000010);
            if (uVar9 == 0) {
              iVar12 = 0;
              iVar7 = 0;
            }
            else if (uVar9 == 0x10000) {
              iVar6 = (uint)*pbVar11 << 0x10;
              iVar7 = (uint)pbVar11[1] << 0x10;
              iVar12 = (uint)pbVar11[2] << 0x10;
            }
            else {
              iVar6 = *pbVar11 * uVar9;
              iVar7 = pbVar11[1] * uVar9;
              iVar12 = pbVar11[2] * uVar9;
            }
            *(int *)((int)DAT_10087200 + iVar10) = *(int *)((int)DAT_10087200 + iVar10) + iVar6;
            *(int *)((int)DAT_10087204 + iVar10) = *(int *)((int)DAT_10087204 + iVar10) + iVar7;
            *(int *)((int)DAT_10087208 + iVar10) = *(int *)((int)DAT_10087208 + iVar10) + iVar12;
          }
        }
        iVar10 = iVar10 + 4;
        iStack00000008 = iStack00000008 + 1;
      } while (iStack00000008 < *(int *)(in_stack_00000020 + 0x1c));
    }
    if ((int)(DAT_10089b60 + DAT_10089b6c) < 0x10000) {
      iVar6 = 0;
      iVar10 = 0;
      if (0 < *(int *)(in_stack_00000020 + 0x1c)) {
        do {
          iVar6 = iVar6 + 1;
          *(int *)((int)DAT_100871f4 + iVar10) =
               *(int *)((int)DAT_100871f4 + iVar10) + *(int *)((int)DAT_10087200 + iVar10);
          *(int *)((int)DAT_100871f8 + iVar10) =
               *(int *)((int)DAT_100871f8 + iVar10) + *(int *)((int)DAT_10087204 + iVar10);
          *(int *)((int)DAT_100871fc + iVar10) =
               *(int *)((int)DAT_100871fc + iVar10) + *(int *)((int)DAT_10087208 + iVar10);
          iVar10 = iVar10 + 4;
        } while (iVar6 < *(int *)(in_stack_00000020 + 0x1c));
      }
      DAT_10089b60 = DAT_10089b60 + DAT_10089b6c;
    }
    else {
      iVar10 = -DAT_10089b60;
      iVar6 = (iVar10 + 0x10080 >> 8) * (DAT_10089b64 + 0x80 >> 8);
      if ((iVar6 != 0) && (iVar12 = 0, 0 < *(int *)(in_stack_00000020 + 0x1c))) {
        iVar7 = iVar6 + 0x80 >> 8;
        iVar6 = 0;
        do {
          iVar12 = iVar12 + 1;
          *(int *)((int)DAT_100871f4 + iVar6) =
               *(int *)((int)DAT_100871f4 + iVar6) +
               (*(int *)((int)DAT_10087200 + iVar6) + 0x80 >> 8) * iVar7;
          *(int *)((int)DAT_100871f8 + iVar6) =
               *(int *)((int)DAT_100871f8 + iVar6) +
               (*(int *)((int)DAT_10087204 + iVar6) + 0x80 >> 8) * iVar7;
          *(int *)((int)DAT_100871fc + iVar6) =
               *(int *)((int)DAT_100871fc + iVar6) +
               (*(int *)((int)DAT_10087208 + iVar6) + 0x80 >> 8) * iVar7;
          iVar6 = iVar6 + 4;
        } while (iVar12 < *(int *)(in_stack_00000020 + 0x1c));
      }
      iVar6 = DAT_10089b5c;
      if ((in_stack_00000024 & 2) != 0) {
        iVar6 = (*(int *)(in_stack_00000020 + 0x20) - DAT_10089b5c) + -1;
      }
      FUN_100073d0(in_stack_00000020,iVar6,DAT_100871f4,DAT_100871f8,DAT_100871fc,DAT_10089b58);
      DAT_10089b5c = DAT_10089b5c + 1;
      uVar4 = DAT_10089b6c - (iVar10 + 0x10000);
      if (0xffff < (int)uVar4) {
        iVar6 = 0;
        iVar10 = 0;
        if (0 < *(int *)(in_stack_00000020 + 0x1c)) {
          do {
            iVar6 = iVar6 + 1;
            *(int *)((int)DAT_100871f4 + iVar10) =
                 (*(int *)((int)DAT_10087200 + iVar10) + 0x80 >> 8) * (DAT_10089b64 + 0x80 >> 8);
            *(int *)((int)DAT_100871f8 + iVar10) =
                 (*(int *)((int)DAT_10087204 + iVar10) + 0x80 >> 8) * (DAT_10089b64 + 0x80 >> 8);
            *(int *)((int)DAT_100871fc + iVar10) =
                 (*(int *)((int)DAT_10087208 + iVar10) + 0x80 >> 8) * (DAT_10089b64 + 0x80 >> 8);
            iVar10 = iVar10 + 4;
          } while (iVar6 < *(int *)(in_stack_00000020 + 0x1c));
        }
        if (0xffff < (int)uVar4) {
          uVar9 = uVar4 >> 0x10;
          uVar4 = uVar4 + uVar9 * -0x10000;
          do {
            iVar10 = DAT_10089b5c;
            if ((in_stack_00000024 & 2) != 0) {
              iVar10 = (*(int *)(in_stack_00000020 + 0x20) - DAT_10089b5c) + -1;
            }
            FUN_100073d0(in_stack_00000020,iVar10,DAT_100871f4,DAT_100871f8,DAT_100871fc,
                         DAT_10089b58);
            DAT_10089b5c = DAT_10089b5c + 1;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
      }
      iVar10 = ((int)(uVar4 + 0x80) >> 8) * (DAT_10089b64 + 0x80 >> 8);
      DAT_10089b60 = uVar4;
      if (iVar10 == 0) {
        iVar6 = 0;
        iVar10 = 0;
        if (0 < *(int *)(in_stack_00000020 + 0x1c)) {
          do {
            *(undefined4 *)((int)DAT_100871fc + iVar10) = 0;
            iVar6 = iVar6 + 1;
            *(undefined4 *)((int)DAT_100871f8 + iVar10) =
                 *(undefined4 *)((int)DAT_100871fc + iVar10);
            *(undefined4 *)((int)DAT_100871f4 + iVar10) =
                 *(undefined4 *)((int)DAT_100871f8 + iVar10);
            iVar10 = iVar10 + 4;
          } while (iVar6 < *(int *)(in_stack_00000020 + 0x1c));
        }
      }
      else {
        iVar6 = 0;
        if (0 < *(int *)(in_stack_00000020 + 0x1c)) {
          iVar12 = iVar10 + 0x80 >> 8;
          iVar10 = 0;
          do {
            *(int *)((int)DAT_100871f4 + iVar10) =
                 (*(int *)((int)DAT_10087200 + iVar10) + 0x80 >> 8) * iVar12;
            iVar6 = iVar6 + 1;
            *(int *)((int)DAT_100871f8 + iVar10) =
                 (*(int *)((int)DAT_10087204 + iVar10) + 0x80 >> 8) * iVar12;
            *(int *)((int)DAT_100871fc + iVar10) =
                 (*(int *)((int)DAT_10087208 + iVar10) + 0x80 >> 8) * iVar12;
            iVar10 = iVar10 + 4;
          } while (iVar6 < *(int *)(in_stack_00000020 + 0x1c));
        }
      }
    }
    if ((in_stack_00000018 - in_stack_0000001c == 1) &&
       (DAT_10089b5c != *(int *)(in_stack_00000020 + 0x20))) {
      if ((in_stack_00000024 & 2) != 0) {
        FUN_100073d0(in_stack_00000020,(*(int *)(in_stack_00000020 + 0x20) - DAT_10089b5c) + -1,
                     DAT_100871f4,DAT_100871f8,DAT_100871fc,DAT_10089b58);
        return 1;
      }
      FUN_100073d0(in_stack_00000020,DAT_10089b5c,DAT_100871f4,DAT_100871f8,DAT_100871fc,
                   DAT_10089b58);
      return 1;
    }
  }
  return 1;
}


