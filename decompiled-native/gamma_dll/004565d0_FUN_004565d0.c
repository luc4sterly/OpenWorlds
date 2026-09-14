// 004565d0 FUN_004565d0 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl
FUN_004565d0(int param_1,undefined *param_2,undefined4 param_3,int *param_4,int *param_5)

{
  float fVar1;
  bool bVar2;
  bool bVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  byte *pbVar12;
  undefined4 *puVar13;
  bool bVar14;
  float10 fVar15;
  int iStack_cc;
  byte bStack_c8;
  byte bStack_c4;
  int local_c0;
  uint local_bc;
  int local_b4;
  int local_b0;
  int local_ac;
  uint uStack_a8;
  int local_a4;
  int local_9c;
  int local_94;
  int local_88;
  byte local_80 [2];
  undefined2 uStack_7e;
  byte bStack_7c;
  char acStack_7b [35];
  undefined8 local_58;
  char acStack_4c [12];
  undefined4 uStack_40;
  undefined1 uStack_3c;
  undefined4 auStack_38 [10];
  
  uVar5 = (uint)(byte)*PTR_DAT_00483770;
  local_bc = 1;
  local_ac = 0;
  local_94 = 0;
  puVar11 = &DAT_0049eaf8;
  pbVar12 = local_80;
  for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined4 *)pbVar12 = *puVar11;
    puVar11 = puVar11 + 1;
    pbVar12 = pbVar12 + 4;
  }
  *(undefined2 *)pbVar12 = *(undefined2 *)puVar11;
  bVar2 = false;
  bVar3 = false;
  local_b0 = 0;
  local_9c = 0;
  local_88 = 0;
  bVar14 = false;
  local_a4 = 0;
  sVar4 = 0;
  local_b4 = 0;
  *param_5 = 0;
  local_c0 = 1;
  uVar6 = (*(code *)param_2)(param_3,0,0);
LAB_004570da:
  do {
    if (((param_1 < local_c0) || (uVar6 == 0xffffffff)) || ((local_bc & 0x1800) != 0)) {
      if ((local_bc & 0xe2c) == 0) {
        *param_4 = 0;
      }
      else {
        *param_4 = local_c0 + -1 + local_94;
      }
      (*(code *)param_2)(param_3,uVar6,1);
      if (local_ac != 0) {
        if (bVar14) {
          local_b4 = -local_b4;
        }
        while (((ushort)local_58 & 0xf0) != 0x10) {
          local_b4 = local_b4 + 1;
          local_58 = (double)CONCAT44(local_58._4_4_ >> 1,
                                      (uint)local_58 >> 1 | local_58._4_4_ << 0x1f);
        }
        local_b4._0_2_ = (short)local_b4 + (sVar4 + -1) * 4;
        local_58 = (double)((ulonglong)local_58 & 0xffffffffffff000f);
        local_58 = (double)CONCAT62(local_58._2_6_,
                                    (ushort)local_58 | ((short)local_b4 + 0x3ff) * 0x10);
        *param_4 = local_94 + local_88 + uStack_a8 + 1 + local_a4;
        if (((byte)((byte)((ushort)((ushort)(NAN(_DAT_00482710) || NAN(local_58)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(_DAT_00482710 == local_58) << 0xe) >> 8)) == 0x40) ||
           ((byte)(local_58 < _DAT_004823e8 |
                  (byte)((ushort)((ushort)(NAN(local_58) || NAN(_DAT_004823e8)) << 10) >> 8)) != 1))
        {
          if (_DAT_004823f0 < local_58) {
            *param_5 = 1;
            local_58 = (double)CONCAT44(DAT_004823dc,DAT_004823d8);
          }
        }
        else {
          *param_5 = 1;
          local_58 = 0.0;
        }
        if (bVar2) {
          local_58 = (double)((ulonglong)local_58 | 0x8000);
        }
        return (float10)local_58;
      }
      if (bVar3) {
        local_b0 = -local_b0;
      }
      uVar5 = (uint)bStack_7c;
      pcVar8 = acStack_7b + uVar5;
      while ((bVar14 = uVar5 != 0, uVar5 = uVar5 - 1, bVar14 &&
             (pcVar8 = pcVar8 + -1, *pcVar8 == '0'))) {
        local_9c = local_9c + 1;
      }
      bStack_7c = (char)uVar5 + '\x01';
      if (bStack_7c == '\0') {
        bStack_7c = (char)uVar5 + '\x02';
        acStack_7b[0] = '0';
      }
      local_b0 = local_b0 + local_9c;
      if ((local_b0 < -0x8000) || (0x7fff < local_b0)) {
        *param_5 = 1;
      }
      if (*param_5 == 0) {
        uStack_7e = (undefined2)local_b0;
        fVar15 = (float10)FUN_004582d0(local_80);
        local_58 = (double)fVar15;
        if (((byte)((byte)((ushort)((ushort)(NAN(_DAT_00482710) || NAN(local_58)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(_DAT_00482710 == local_58) << 0xe) >> 8)) == 0x40) ||
           ((byte)(local_58 < _DAT_004823e8 |
                  (byte)((ushort)((ushort)(NAN(local_58) || NAN(_DAT_004823e8)) << 10) >> 8)) != 1))
        {
          if (_DAT_004823f0 < local_58) {
            *param_5 = 1;
            local_58 = (double)CONCAT44(DAT_004823dc,DAT_004823d8);
          }
        }
        else {
          *param_5 = 1;
        }
        if ((bVar2) && ((local_bc & 0xe2c) != 0)) {
          local_58 = -local_58;
        }
        return (float10)local_58;
      }
      if (!bVar3) {
        if (bVar2) {
          fVar15 = -(float10)(double)CONCAT44(DAT_004823dc,DAT_004823d8);
        }
        else {
          fVar15 = (float10)(double)CONCAT44(DAT_004823dc,DAT_004823d8);
        }
        return fVar15;
      }
      return (float10)_DAT_00482710;
    }
    if (local_bc == 1) {
      if (((&DAT_00482718)[uVar6 & 0xff] & 6) == 0) {
        if (uVar6 == 0xffffffff) {
          uVar9 = 0xffffffff;
        }
        else {
          uVar9 = (uint)(byte)(&DAT_00482918)[uVar6 & 0xff];
        }
        if (uVar9 != 0x2b) {
          if (uVar9 != 0x2d) {
            if (uVar9 == 0x49) {
              local_c0 = local_c0 + 1;
              uVar6 = (*(code *)param_2)(param_3,0,0);
              local_bc = 0x4000;
            }
            else if (uVar9 == 0x4e) {
              local_c0 = local_c0 + 1;
              uVar6 = (*(code *)param_2)(param_3,0,0);
              local_bc = 0x2000;
            }
            else {
              local_bc = 2;
            }
            goto LAB_004570da;
          }
          bVar2 = true;
        }
        local_c0 = local_c0 + 1;
        uVar6 = (*(code *)param_2)(param_3,0,0);
        local_88 = 1;
        goto LAB_004570da;
      }
      uVar6 = (*(code *)param_2)(param_3,0,0);
      local_94 = local_94 + 1;
      goto LAB_004570da;
    }
    if (local_bc != 2) {
      if (local_bc == 4) {
        if (uVar6 == 0x30) {
          local_c0 = local_c0 + 1;
          uVar6 = (*(code *)param_2)(param_3,0,0);
        }
        else {
          local_bc = 8;
        }
      }
      else if (local_bc == 8) {
        if (((&DAT_00482718)[uVar6 & 0xff] & 0x10) == 0) {
          if (uVar6 == uVar5) {
            local_bc = 0x20;
            local_c0 = local_c0 + 1;
            uVar6 = (*(code *)param_2)(param_3,0,0);
          }
          else {
            local_bc = 0x40;
          }
        }
        else {
          if (bStack_7c < 0x14) {
            acStack_7b[bStack_7c] = (char)uVar6;
            bStack_7c = bStack_7c + 1;
          }
          else {
            local_9c = local_9c + 1;
          }
          local_c0 = local_c0 + 1;
          uVar6 = (*(code *)param_2)(param_3,0,0);
        }
      }
      else if (local_bc == 0x10) {
        if (((&DAT_00482718)[uVar6 & 0xff] & 0x10) == 0) {
          local_bc = 0x1000;
        }
        else {
          local_bc = 0x20;
        }
      }
      else if (local_bc == 0x20) {
        if (((&DAT_00482718)[uVar6 & 0xff] & 0x10) == 0) {
          local_bc = 0x40;
        }
        else {
          if (bStack_7c < 0x14) {
            if ((uVar6 != 0x30) || (bStack_7c != 0)) {
              acStack_7b[bStack_7c] = (char)uVar6;
              bStack_7c = bStack_7c + 1;
            }
            local_9c = local_9c + -1;
          }
          local_c0 = local_c0 + 1;
          uVar6 = (*(code *)param_2)(param_3,0,0);
        }
      }
      else if (local_bc == 0x40) {
        if (uVar6 == 0xffffffff) {
          uVar9 = 0xffffffff;
        }
        else {
          uVar9 = (uint)(byte)(&DAT_00482918)[uVar6 & 0xff];
        }
        if (uVar9 == 0x45) {
          local_bc = 0x80;
          local_c0 = local_c0 + 1;
          uVar6 = (*(code *)param_2)(param_3,0,0);
        }
        else {
          local_bc = 0x800;
        }
      }
      else if (local_bc == 0x80) {
        if (uVar6 == 0x2b) {
          local_c0 = local_c0 + 1;
          uVar6 = (*(code *)param_2)(param_3,0,0);
        }
        else if (uVar6 == 0x2d) {
          local_c0 = local_c0 + 1;
          uVar6 = (*(code *)param_2)(param_3,0,0);
          bVar3 = true;
        }
        local_bc = 0x100;
      }
      else if (local_bc == 0x100) {
        if (((&DAT_00482718)[uVar6 & 0xff] & 0x10) == 0) {
          local_bc = 0x1000;
        }
        else if (uVar6 == 0x30) {
          local_bc = 0x200;
          local_c0 = local_c0 + 1;
          uVar6 = (*(code *)param_2)(param_3,0,0);
        }
        else {
          local_bc = 0x400;
        }
      }
      else if (local_bc == 0x200) {
        if (uVar6 == 0x30) {
          local_c0 = local_c0 + 1;
          uVar6 = (*(code *)param_2)(param_3,0,0);
        }
        else {
          local_bc = 0x400;
        }
      }
      else if (local_bc == 0x400) {
        if (((&DAT_00482718)[uVar6 & 0xff] & 0x10) == 0) {
          local_bc = 0x800;
        }
        else {
          local_b0 = local_b0 * 10 + (uVar6 - 0x30);
          if (0x7fff < local_b0) {
            *param_5 = 1;
          }
          local_c0 = local_c0 + 1;
          uVar6 = (*(code *)param_2)(param_3,0,0);
        }
      }
      else {
        if (local_bc == 0x2000) {
          iVar10 = 1;
          iStack_cc = 0;
          uStack_40 = DAT_00482704;
          uStack_3c = DAT_00482708;
          puVar11 = &DAT_0049eb1e;
          puVar13 = auStack_38;
          for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar13 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar13 = puVar13 + 1;
          }
          for (; iVar10 < 4; iVar10 = iVar10 + 1) {
            if (uVar6 == 0xffffffff) {
              uVar9 = 0xffffffff;
            }
            else {
              uVar9 = (uint)(byte)(&DAT_00482918)[uVar6 & 0xff];
            }
            if ((int)*(char *)((int)&uStack_40 + iVar10) != uVar9) break;
            local_c0 = local_c0 + 1;
            uVar6 = (*(code *)param_2)(param_3,0,0);
          }
          if (1 < iVar10 - 3U) {
            local_bc = 0x1000;
            goto LAB_004570da;
          }
          if (iVar10 == 4) {
            while (iStack_cc < 0x20) {
              if ((((&DAT_00482718)[uVar6 & 0xff] & 0x10) == 0) &&
                 (((&DAT_00482718)[uVar6 & 0xff] & 0xc0) == 0)) break;
              *(char *)((int)auStack_38 + iStack_cc) = (char)uVar6;
              iStack_cc = iStack_cc + 1;
              local_c0 = local_c0 + 1;
              uVar6 = (*(code *)param_2)(param_3,0,0);
            }
            if (uVar6 != 0x29) {
              local_bc = 0x1000;
              goto LAB_004570da;
            }
            iStack_cc = iStack_cc + 1;
          }
          *(undefined1 *)((int)auStack_38 + iStack_cc) = 0;
          if (bVar2) {
            fVar15 = FUN_00459591(auStack_38);
            fVar15 = -fVar15;
          }
          else {
            fVar15 = FUN_00459591(auStack_38);
          }
          *param_4 = local_94 + iVar10 + iStack_cc + local_88;
          return (float10)(double)fVar15;
        }
        if (local_bc == 0x4000) {
          acStack_4c[0] = s_INFINITY_004826f8[0];
          acStack_4c[1] = s_INFINITY_004826f8[1];
          acStack_4c[2] = s_INFINITY_004826f8[2];
          acStack_4c[3] = s_INFINITY_004826f8[3];
          acStack_4c[4] = s_INFINITY_004826f8[4];
          acStack_4c[5] = s_INFINITY_004826f8[5];
          acStack_4c[6] = s_INFINITY_004826f8[6];
          acStack_4c[7] = s_INFINITY_004826f8[7];
          acStack_4c[8] = s_INFINITY_004826f8[8];
          for (iVar7 = 1; iVar7 < 8; iVar7 = iVar7 + 1) {
            if (uVar6 == 0xffffffff) {
              uVar9 = 0xffffffff;
            }
            else {
              uVar9 = (uint)(byte)(&DAT_00482918)[uVar6 & 0xff];
            }
            if ((int)acStack_4c[iVar7] != uVar9) break;
            local_c0 = local_c0 + 1;
            uVar6 = (*(code *)param_2)(param_3,0,0);
          }
          if ((iVar7 == 3) || (iVar7 == 8)) {
            fVar1 = _DAT_004823b4;
            if (bVar2) {
              fVar1 = -_DAT_004823b4;
            }
            *param_4 = local_94 + iVar7 + local_88;
            return (float10)fVar1;
          }
          local_bc = 0x1000;
        }
        else if (local_bc == 0x8000) {
          if (local_ac == 1) {
                    /* WARNING: Ignoring partial resolution of indirect */
            local_58._0_1_ = 0;
            uStack_a8 = 2;
            local_ac = 2;
            local_c0 = local_c0 + 1;
            uVar6 = (*(code *)param_2)(param_3,0,0);
          }
          else if (local_ac == 2) {
            if (uVar6 == 0x30) {
              local_c0 = local_c0 + 1;
              uVar6 = (*(code *)param_2)(param_3,0,0);
            }
            else {
              local_ac = 4;
            }
          }
          else {
            uVar9 = (int)uStack_a8 >> 0x1f;
            if (local_ac == 4) {
              if (((&DAT_00482718)[uVar6 & 0xff] & 0x20) == 0) {
                if (uVar6 == uVar5) {
                  local_ac = 8;
                  local_c0 = local_c0 + 1;
                  uVar6 = (*(code *)param_2)(param_3,0,0);
                }
                else {
                  local_ac = 0x10;
                }
              }
              else if ((int)uStack_a8 < 0x11) {
                sVar4 = sVar4 + 1;
                iVar7 = (int)((uStack_a8 + 1) - (uint)(uStack_a8 < 0x80000000)) >> 1;
                if (uVar6 == 0xffffffff) {
                  uVar6 = 0xffffffff;
                }
                else {
                  uVar6 = (uint)(byte)(&DAT_00482918)[uVar6 & 0xff];
                }
                if ((int)uVar6 < 0x41) {
                  uVar6 = uVar6 - 0x30;
                }
                else {
                  uVar6 = uVar6 - 0x37;
                }
                bStack_c8 = (byte)uVar6;
                if ((uStack_a8 & 1 ^ uVar9) == uVar9) {
                  bStack_c8 = (byte)((uVar6 & 0xff) << 4);
                }
                bStack_c8 = *(byte *)((int)&local_58 + iVar7) | bStack_c8;
                *(byte *)((int)&local_58 + iVar7) = bStack_c8;
                uStack_a8 = uStack_a8 + 1;
                local_c0 = local_c0 + 1;
                uVar6 = (*(code *)param_2)(param_3,0,0);
              }
              else {
                local_c0 = local_c0 + 1;
                uVar6 = (*(code *)param_2)(param_3,0,0);
              }
            }
            else if (local_ac == 8) {
              if (((&DAT_00482718)[uVar6 & 0xff] & 0x20) == 0) {
                local_ac = 0x10;
              }
              else if ((int)uStack_a8 < 0x11) {
                iVar7 = (int)((uStack_a8 + 1) - (uint)(uStack_a8 < 0x80000000)) >> 1;
                if (uVar6 == 0xffffffff) {
                  uVar6 = 0xffffffff;
                }
                else {
                  uVar6 = (uint)(byte)(&DAT_00482918)[uVar6 & 0xff];
                }
                if ((int)uVar6 < 0x41) {
                  uVar6 = uVar6 - 0x30;
                }
                else {
                  uVar6 = uVar6 - 0x37;
                }
                bStack_c4 = (byte)uVar6;
                if ((uStack_a8 & 1 ^ uVar9) == uVar9) {
                  bStack_c4 = (byte)((uVar6 & 0xff) << 4);
                }
                bStack_c4 = *(byte *)((int)&local_58 + iVar7) | bStack_c4;
                *(byte *)((int)&local_58 + iVar7) = bStack_c4;
                uStack_a8 = uStack_a8 + 1;
                local_c0 = local_c0 + 1;
                uVar6 = (*(code *)param_2)(param_3,0,0);
              }
              else {
                local_c0 = local_c0 + 1;
                uVar6 = (*(code *)param_2)(param_3,0,0);
              }
            }
            else if (local_ac == 0x10) {
              if (uVar6 == 0xffffffff) {
                uVar9 = 0xffffffff;
              }
              else {
                uVar9 = (uint)(byte)(&DAT_00482918)[uVar6 & 0xff];
              }
              if (uVar9 == 0x50) {
                local_ac = 0x20;
                local_a4 = local_a4 + 1;
                local_c0 = local_c0 + 1;
                uVar6 = (*(code *)param_2)(param_3,0,0);
              }
              else {
                local_bc = 0x800;
              }
            }
            else if (local_ac == 0x20) {
              iVar7 = local_a4 + 1;
              if (uVar6 == 0x2d) {
                bVar14 = true;
              }
              else if (uVar6 != 0x2b) {
                (*(code *)param_2)(param_3,uVar6,1);
                iVar7 = local_a4;
              }
              local_a4 = iVar7;
              local_ac = 0x40;
              local_c0 = local_c0 + 1;
              uVar6 = (*(code *)param_2)(param_3,0,0);
            }
            else if (local_ac == 0x40) {
              if (((&DAT_00482718)[uVar6 & 0xff] & 0x10) == 0) {
                local_bc = 0x1000;
              }
              else if (uVar6 == 0x30) {
                local_a4 = local_a4 + 1;
                local_ac = 0x80;
                local_c0 = local_c0 + 1;
                uVar6 = (*(code *)param_2)(param_3,0,0);
              }
              else {
                local_ac = 0x100;
              }
            }
            else if (local_ac == 0x100) {
              if (((&DAT_00482718)[uVar6 & 0xff] & 0x10) == 0) {
                local_bc = 0x800;
              }
              else {
                local_b4 = local_b4 * 10 + (uVar6 - 0x30);
                if (0x7fff < local_b0) {
                  *param_5 = 1;
                }
                local_a4 = local_a4 + 1;
                local_c0 = local_c0 + 1;
                uVar6 = (*(code *)param_2)(param_3,0,0);
              }
            }
          }
        }
      }
      goto LAB_004570da;
    }
    if (uVar6 == uVar5) {
      local_bc = 0x10;
      local_c0 = local_c0 + 1;
      uVar6 = (*(code *)param_2)(param_3,0,0);
    }
    else if (((&DAT_00482718)[uVar6 & 0xff] & 0x10) == 0) {
      local_bc = 0x1000;
    }
    else if (uVar6 == 0x30) {
      local_c0 = local_c0 + 1;
      uVar6 = (*(code *)param_2)(param_3,0,0);
      if (uVar6 == 0xffffffff) {
        uVar9 = 0xffffffff;
      }
      else {
        uVar9 = (uint)(byte)(&DAT_00482918)[uVar6 & 0xff];
      }
      if (uVar9 == 0x58) {
        local_bc = 0x8000;
        local_ac = 1;
      }
      else {
        local_bc = 4;
      }
    }
    else {
      local_bc = 8;
    }
  } while( true );
}


