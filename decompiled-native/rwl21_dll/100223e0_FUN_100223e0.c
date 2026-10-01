// 100223e0 FUN_100223e0 [Global]
// program: RWL21.DLL

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_100223e0(int *param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  undefined3 uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  ushort *puVar9;
  uint *puVar10;
  int iVar11;
  int iVar12;
  byte bVar13;
  undefined3 *puVar14;
  byte *pbVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  undefined4 *unaff_EBX;
  byte *pbVar19;
  uint uVar20;
  int iVar21;
  undefined3 *puVar22;
  byte *pbVar23;
  undefined1 *puVar24;
  int iVar25;
  int iVar26;
  longlong lVar27;
  longlong lVar28;
  longlong lVar29;
  int iVar30;
  undefined4 local_4a0;
  undefined4 *local_498;
  int iStack_494;
  int iStack_490;
  int iStack_48c;
  uint uStack_488;
  int iStack_484;
  int iStack_480;
  undefined4 *puStack_478;
  uint uStack_470;
  int iStack_464;
  uint uStack_460;
  int iStack_45c;
  int iStack_458;
  undefined3 *puStack_454;
  int iStack_450;
  uint uStack_44c;
  uint uStack_448;
  uint uStack_444;
  uint uStack_440;
  uint uStack_43c;
  int iStack_438;
  undefined4 *puStack_434;
  int iStack_430;
  undefined4 *puStack_42c;
  int iStack_428;
  uint uStack_424;
  undefined4 *local_420;
  uint uStack_41c;
  uint uStack_418;
  int iStack_414;
  int iStack_410;
  uint uStack_40c;
  int iStack_408;
  int iStack_404;
  undefined3 local_400 [256];
  
  local_420 = (undefined4 *)0x0;
  if (param_1 == (int *)0x0) {
    iVar30 = 1;
    goto LAB_10026bae;
  }
  if ((((*param_1 == 2) && (iVar30 = param_1[1], iVar30 != 8)) && (iVar30 != 0xf)) &&
     (((iVar30 != 0x10 && (iVar30 != 0x18)) && (iVar30 != 0x20)))) {
    return (undefined4 *)0x0;
  }
  if ((*param_1 == 1) && (param_1[0xd] == 0)) {
    iVar30 = RwGetPaletteEntries(0,0x100,(int)local_400);
    if (iVar30 == 0) {
      return (undefined4 *)0x0;
    }
    puVar22 = local_400;
    puVar14 = puVar22;
    do {
      uVar2 = *puVar22;
      puVar22 = puVar22 + 1;
      local_4a0._0_2_ = (undefined2)uVar2;
      local_4a0._2_1_ = (undefined1)((uint3)uVar2 >> 0x10);
      *(undefined2 *)puVar14 = (undefined2)local_4a0;
      *(undefined1 *)((int)puVar14 + 2) = local_4a0._2_1_;
      puVar14 = (undefined3 *)((int)puVar14 + 3);
    } while (puVar22 < &stack0x00000000);
  }
  local_498 = FUN_10037030(DAT_1005acdc);
  if (local_498 == (undefined4 *)0x0) {
    FUN_1000cba0(3);
    local_498 = (undefined4 *)0x0;
  }
  else {
    local_498[0xc] = 0;
    local_498[0xf] = 0;
    local_498[0xd] = 0;
    local_498[0xe] = 0;
    local_498[7] = 0;
    local_498[8] = 0;
    local_498[9] = 0;
    local_498[1] = 0;
    iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x2a0))(local_498);
    if (iVar30 == 0) {
      FUN_10037010(DAT_1005acdc,local_498);
      local_498 = (undefined4 *)0x0;
    }
  }
  if (local_498 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *local_498 = 2;
  local_498[1] = 0x20;
  local_498[2] = 0xff0000;
  local_498[3] = 0xff00;
  local_498[4] = 0xff;
  if ((*param_1 == 2) && (param_1[5] != 0)) {
    local_498[5] = 0xff000000;
  }
  else {
    local_498[5] = 0;
  }
  local_498[7] = param_1[7] / 2;
  iVar30 = param_1[7] * 3;
  local_498[8] = ((int)(iVar30 + (iVar30 >> 0x1f & 3U)) >> 2) * (param_1[8] / param_1[7]);
  local_498[9] = 0x20;
  local_498[10] = local_498[7] * 4;
  iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(local_498[8] * local_498[7] * 4);
  local_498[6] = iVar30;
  if (iVar30 == 0) {
    RwDestroyRaster(local_498);
    return (undefined4 *)0x0;
  }
  if ((param_1 == (int *)0x0) ||
     ((((param_1[0x10] & 2U) != 0 && (*(code **)(PTR_DAT_1005b69c + 0x298) != (code *)0x0)) &&
      (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x298))(param_1), iVar30 == 0)))) {
    FUN_1000cba0(1);
    iStack_464 = 0;
  }
  else {
    iStack_464 = param_1[6];
    param_1[0x10] = param_1[0x10] | 1;
  }
  if (iStack_464 == 0) {
LAB_10026b8b:
    (**(code **)(PTR_DAT_1005b69c + 0x358))(local_498[6]);
  }
  else {
    if ((local_498 == (undefined4 *)0x0) ||
       ((((local_498[0x10] & 2) != 0 && (*(code **)(PTR_DAT_1005b69c + 0x298) != (code *)0x0)) &&
        (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x298))(local_498), iVar30 == 0)))) {
      FUN_1000cba0(1);
      iStack_408 = 0;
    }
    else {
      local_498[0x10] = local_498[0x10] | 1;
      iStack_408 = local_498[6];
    }
    if (iStack_408 == 0) {
      if (((param_1[0x10] & 2U) != 0) && (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) {
        iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(param_1);
joined_r0x1002268c:
        if (iVar30 == 0) {
LAB_10026b81:
          FUN_1000cba0(1);
        }
      }
      goto LAB_10026b8b;
    }
    if (param_1 == (int *)0x0) {
      FUN_1000cba0(1);
      iStack_458 = -1;
    }
    else {
      iStack_458 = param_1[10];
    }
    if (local_498 == (undefined4 *)0x0) {
      FUN_1000cba0(1);
      iStack_410 = -1;
    }
    else {
      iStack_410 = local_498[10];
    }
    if (param_3 == (int *)0x0) {
      iStack_494 = 0;
      if (0 < param_1[8] / param_1[7]) {
        do {
          if (*param_1 == 1) {
            iStack_48c = 0;
            if (0 < param_1[7]) {
              do {
                puStack_454 = (undefined3 *)param_1[0xd];
                if (puStack_454 == (undefined3 *)0x0) {
                  puStack_454 = local_400;
                }
                iStack_490 = 0;
                if (0 < param_1[7]) {
                  do {
                    puStack_434 = (undefined4 *)local_498[7];
                    iVar30 = iStack_48c + param_1[7] * iStack_494;
                    pbVar8 = (byte *)((iVar30 + 1) * iStack_458 + iStack_490 + iStack_464);
                    pbVar15 = (byte *)((int)puStack_454 + (uint)pbVar8[1] * 3);
                    pbVar23 = (byte *)(iStack_464 + iStack_458 * iVar30 + iStack_490);
                    pbVar19 = (byte *)((int)puStack_454 + (uint)pbVar23[1] * 3);
                    pbVar8 = (byte *)((int)puStack_454 + (uint)*pbVar8 * 3);
                    pbVar23 = (byte *)((int)puStack_454 + (uint)*pbVar23 * 3);
                    uStack_488 = (uint)pbVar15[1];
                    iVar30 = pbVar19[1] + uStack_488;
                    uStack_488 = (uint)pbVar8[1];
                    iVar30 = iVar30 + uStack_488;
                    uStack_488 = (uint)pbVar23[1];
                    uVar4 = iVar30 + uStack_488;
                    uStack_488 = (uint)*pbVar19;
                    iVar30 = *pbVar15 + uStack_488;
                    uStack_488 = (uint)*pbVar8;
                    iStack_490 = iStack_490 + 2;
                    *(uint *)((((int)puStack_434 / 2 + (int)puStack_434) * iStack_494 +
                              iStack_48c / 2) * iStack_410 + -4 + iStack_490 * 2 + iStack_408) =
                         (uint)pbVar15[2] + (uint)pbVar19[2] + (uint)pbVar8[2] + (uint)pbVar23[2] >>
                         2 | (uVar4 & 0xfffffffc) << 6 |
                         (iVar30 + uStack_488 + (uint)*pbVar23 >> 2) << 0x10;
                  } while (iStack_490 < param_1[7]);
                }
                iStack_48c = iStack_48c + 2;
              } while (iStack_48c < param_1[7]);
            }
          }
          else {
            if (*param_1 != 2) {
              if ((((param_1[0x10] & 2U) != 0) &&
                  (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
                 (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(param_1), iVar30 == 0)) {
                FUN_1000cba0(1);
              }
              if (((local_498[0x10] & 2) == 0) ||
                 (*(code **)(PTR_DAT_1005b69c + 0x29c) == (code *)0x0)) goto LAB_10026b8b;
              iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(local_498);
joined_r0x1002365f:
              if (iVar30 != 0) goto LAB_10026b8b;
              goto LAB_10026b81;
            }
            uVar4 = param_1[2];
            if (uVar4 == 0) {
              iStack_430 = 0;
              puStack_454 = (undefined3 *)0x0;
            }
            else {
              if ((~(uVar4 * 2) & uVar4 & 0xffff0000) == 0) {
                uVar16 = ~(uVar4 * 2) & uVar4;
                if ((char)(uVar16 >> 8) == '\0') {
                  puStack_454 = (undefined3 *)((char)(&DAT_1005b7c0)[uVar16 | 1] + -1);
                }
                else {
                  puStack_454 = (undefined3 *)
                                ((char)(&DAT_1005b7c0)[~((int)(uVar4 * 2) >> 8) & (int)uVar4 >> 8] +
                                7);
                }
              }
              else {
                uVar16 = ~((int)(uVar4 * 2) >> 0x10) & (int)uVar4 >> 0x10;
                if ((char)(uVar16 >> 8) == '\0') {
                  iVar30 = (char)(&DAT_1005b7c0)[uVar16] + -1;
                }
                else {
                  iVar30 = (char)(&DAT_1005b7c0)[~((int)(uVar4 * 2) >> 0x18) & (int)uVar4 >> 0x18] +
                           7;
                }
                puStack_454 = (undefined3 *)(iVar30 + 0x10);
              }
              uVar17 = ~((int)uVar4 >> 1);
              uVar16 = (uVar17 | 0x8000ffff) & uVar4;
              if ((uVar16 & 0xffff0000) == 0) {
                if ((byte)((byte)(uVar17 >> 8) & (byte)(uVar4 >> 8)) == 0) {
                  iVar30 = (char)(&DAT_1005b7c0)[(uVar17 | 0x80000000) & uVar4] + -1;
                }
                else {
                  iVar30 = (char)(&DAT_1005b7c0)[((uVar17 | 0x800000ff) & uVar4) >> 8] + 7;
                }
              }
              else if (((uVar4 & 0xff00ffff) >> 0x10 &
                       (~((uint)((int)uVar4 >> 1) >> 0x10) | 0xffff80ff)) == 0) {
                iVar30 = (char)(&DAT_1005b7c0)[uVar16 >> 0x10] + 0xf;
              }
              else {
                iVar30 = (char)(&DAT_1005b7c0)[((uVar17 | 0x80ffffff) & uVar4) >> 0x18] + 0x17;
              }
              iStack_430 = (iVar30 - (int)puStack_454) + 1;
            }
            uVar4 = param_1[3];
            if (uVar4 == 0) {
              iStack_450 = 0;
              iStack_438 = 0;
            }
            else {
              if ((~(uVar4 * 2) & uVar4 & 0xffff0000) == 0) {
                uVar16 = ~(uVar4 * 2) & uVar4;
                if ((char)(uVar16 >> 8) == '\0') {
                  iStack_438 = (char)(&DAT_1005b7c0)[uVar16 | 1] + -1;
                }
                else {
                  iStack_438 = (char)(&DAT_1005b7c0)[~((int)(uVar4 * 2) >> 8) & (int)uVar4 >> 8] + 7
                  ;
                }
              }
              else {
                uVar16 = ~((int)(uVar4 * 2) >> 0x10) & (int)uVar4 >> 0x10;
                if ((char)(uVar16 >> 8) == '\0') {
                  iStack_438 = (char)(&DAT_1005b7c0)[uVar16] + -1;
                }
                else {
                  iStack_438 = (char)(&DAT_1005b7c0)
                                     [~((int)(uVar4 * 2) >> 0x18) & (int)uVar4 >> 0x18] + 7;
                }
                iStack_438 = iStack_438 + 0x10;
              }
              uVar17 = ~((int)uVar4 >> 1);
              uVar16 = (uVar17 | 0x8000ffff) & uVar4;
              if ((uVar16 & 0xffff0000) == 0) {
                if ((byte)((byte)(uVar17 >> 8) & (byte)(uVar4 >> 8)) == 0) {
                  iVar30 = (char)(&DAT_1005b7c0)[(uVar17 | 0x80000000) & uVar4] + -1;
                }
                else {
                  iVar30 = (char)(&DAT_1005b7c0)[((uVar17 | 0x800000ff) & uVar4) >> 8] + 7;
                }
              }
              else if (((uVar4 & 0xff00ffff) >> 0x10 &
                       (~((uint)((int)uVar4 >> 1) >> 0x10) | 0xffff80ff)) == 0) {
                iVar30 = (char)(&DAT_1005b7c0)[uVar16 >> 0x10] + 0xf;
              }
              else {
                iVar30 = (char)(&DAT_1005b7c0)[((uVar17 | 0x80ffffff) & uVar4) >> 0x18] + 0x17;
              }
              iStack_450 = (iVar30 - iStack_438) + 1;
            }
            uVar4 = param_1[4];
            if (uVar4 == 0) {
              iStack_414 = 0;
              puStack_42c = (undefined4 *)0x0;
            }
            else {
              if ((~(uVar4 * 2) & uVar4 & 0xffff0000) == 0) {
                uVar16 = ~(uVar4 * 2) & uVar4;
                if ((char)(uVar16 >> 8) == '\0') {
                  puStack_42c = (undefined4 *)((char)(&DAT_1005b7c0)[uVar16 | 1] + -1);
                }
                else {
                  puStack_42c = (undefined4 *)
                                ((char)(&DAT_1005b7c0)[~((int)(uVar4 * 2) >> 8) & (int)uVar4 >> 8] +
                                7);
                }
              }
              else {
                uVar16 = ~((int)(uVar4 * 2) >> 0x10) & (int)uVar4 >> 0x10;
                if ((char)(uVar16 >> 8) == '\0') {
                  iVar30 = (char)(&DAT_1005b7c0)[uVar16] + -1;
                }
                else {
                  iVar30 = (char)(&DAT_1005b7c0)[~((int)(uVar4 * 2) >> 0x18) & (int)uVar4 >> 0x18] +
                           7;
                }
                puStack_42c = (undefined4 *)(iVar30 + 0x10);
              }
              uVar16 = ~((int)uVar4 >> 1);
              uVar17 = (uVar16 | 0x8000ffff) & uVar4;
              if ((uVar17 & 0xffff0000) == 0) {
                if ((byte)((byte)(uVar16 >> 8) & (byte)(uVar4 >> 8)) == 0) {
                  iVar30 = (char)(&DAT_1005b7c0)[(uVar16 | 0x80000000) & uVar4] + -1;
                }
                else {
                  iVar30 = (char)(&DAT_1005b7c0)[((uVar16 | 0x800000ff) & uVar4) >> 8] + 7;
                }
              }
              else if (((uVar4 & 0xff00ffff) >> 0x10 &
                       (~((uint)((int)uVar4 >> 1) >> 0x10) | 0xffff80ff)) == 0) {
                iVar30 = (char)(&DAT_1005b7c0)[uVar17 >> 0x10] + 0xf;
              }
              else {
                iVar30 = (char)(&DAT_1005b7c0)[((uVar16 | 0x80ffffff) & uVar4) >> 0x18] + 0x17;
              }
              iStack_414 = (iVar30 - (int)puStack_42c) + 1;
            }
            uVar4 = param_1[5];
            if (uVar4 == 0) {
              uStack_460 = 0;
              uStack_488._0_1_ = 0;
            }
            else {
              if ((~(uVar4 * 2) & uVar4 & 0xffff0000) == 0) {
                uVar16 = ~(uVar4 * 2) & uVar4;
                if ((char)(uVar16 >> 8) == '\0') {
                  uStack_488._0_1_ = (&DAT_1005b7c0)[uVar16 | 1] - 1;
                }
                else {
                  uStack_488._0_1_ = (&DAT_1005b7c0)[~((int)(uVar4 * 2) >> 8) & (int)uVar4 >> 8] + 7
                  ;
                }
              }
              else {
                uVar16 = ~((int)(uVar4 * 2) >> 0x10) & (int)uVar4 >> 0x10;
                if ((char)(uVar16 >> 8) == '\0') {
                  cVar3 = (&DAT_1005b7c0)[uVar16] + -1;
                }
                else {
                  cVar3 = (&DAT_1005b7c0)[~((int)(uVar4 * 2) >> 0x18) & (int)uVar4 >> 0x18] + '\a';
                }
                uStack_488._0_1_ = cVar3 + 0x10;
              }
              uVar16 = ~((int)uVar4 >> 1);
              uVar17 = (uVar16 | 0x8000ffff) & uVar4;
              if ((uVar17 & 0xffff0000) == 0) {
                if ((byte)((byte)(uVar16 >> 8) & (byte)(uVar4 >> 8)) == 0) {
                  iVar30 = (char)(&DAT_1005b7c0)[(uVar16 | 0x80000000) & uVar4] + -1;
                }
                else {
                  iVar30 = (char)(&DAT_1005b7c0)[((uVar16 | 0x800000ff) & uVar4) >> 8] + 7;
                }
              }
              else if (((uVar4 & 0xff00ffff) >> 0x10 &
                       (~((uint)((int)uVar4 >> 1) >> 0x10) | 0xffff80ff)) == 0) {
                iVar30 = (char)(&DAT_1005b7c0)[uVar17 >> 0x10] + 0xf;
              }
              else {
                iVar30 = (char)(&DAT_1005b7c0)[((uVar16 | 0x80ffffff) & uVar4) >> 0x18] + 0x17;
              }
              uStack_460 = (iVar30 - (int)puStack_42c) + 1;
            }
            iStack_48c = 0;
            if (0 < param_1[7]) {
              do {
                iStack_490 = 0;
                if (0 < param_1[7]) {
                  puStack_434 = (undefined4 *)0x0;
                  iStack_428 = 0;
                  uStack_424 = 0;
                  do {
                    switch(param_1[1]) {
                    case 8:
                      iVar30 = iStack_48c + param_1[7] * iStack_494;
                      pbVar8 = (byte *)(iStack_464 + iStack_458 * iVar30 + iStack_490);
                      uStack_418 = (uint)*pbVar8;
                      uStack_41c = (uint)pbVar8[1];
                      pbVar8 = (byte *)(iStack_464 + (iVar30 + 1) * iStack_458 + iStack_490);
                      uVar4 = (uint)*pbVar8;
                      uStack_470 = (uint)pbVar8[1];
                      break;
                    default:
                      if ((((param_1[0x10] & 2U) != 0) &&
                          (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
                         (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(param_1), iVar30 == 0)) {
                        FUN_1000cba0(1);
                      }
                      if (((local_498[0x10] & 2) == 0) ||
                         (*(code **)(PTR_DAT_1005b69c + 0x29c) == (code *)0x0)) goto LAB_10026b8b;
                      iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(local_498);
                      goto joined_r0x1002365f;
                    case 0xf:
                    case 0x10:
                      iVar30 = iStack_48c + param_1[7] * iStack_494;
                      puVar9 = (ushort *)(uStack_424 + iStack_458 * iVar30 + iStack_464);
                      uStack_418 = (uint)*puVar9;
                      uStack_41c = (uint)puVar9[1];
                      puVar9 = (ushort *)(uStack_424 + (iVar30 + 1) * iStack_458 + iStack_464);
                      uVar4 = (uint)*puVar9;
                      uStack_470 = (uint)puVar9[1];
                      break;
                    case 0x18:
                      iVar30 = param_1[7] * iStack_494 + iStack_48c;
                      puVar24 = (undefined1 *)(iStack_428 + iStack_458 * iVar30 + iStack_464);
                      uStack_418 = (uint)CONCAT12(*puVar24,CONCAT11(puVar24[1],puVar24[2]));
                      uStack_41c = (uint)(byte)puVar24[4] << 8 | (uint)(byte)puVar24[3] << 0x10 |
                                   (uint)(byte)puVar24[5];
                      puVar24 = (undefined1 *)(iStack_428 + (iVar30 + 1) * iStack_458 + iStack_464);
                      uVar4 = (uint)CONCAT12(*puVar24,CONCAT11(puVar24[1],puVar24[2]));
                      uStack_470 = (uint)(byte)puVar24[4] << 8 | (uint)(byte)puVar24[3] << 0x10 |
                                   (uint)(byte)puVar24[5];
                      break;
                    case 0x20:
                      iVar30 = iStack_48c + param_1[7] * iStack_494;
                      puVar10 = (uint *)(iStack_458 * iVar30 + iStack_464 + (int)puStack_434);
                      uStack_418 = *puVar10;
                      uStack_41c = puVar10[1];
                      puVar10 = (uint *)((int)puStack_434 + (iVar30 + 1) * iStack_458 + iStack_464);
                      uStack_470 = puVar10[1];
                      uVar4 = *puVar10;
                    }
                    uVar17 = 0;
                    uVar16 = 0;
                    uStack_43c = 0;
                    uStack_40c = 0;
                    if (iStack_430 != 0) {
                      uVar16 = param_1[2];
                      uVar16 = ((uStack_470 & uVar16) >> ((byte)puStack_454 & 0x1f)) +
                               ((uVar4 & uVar16) >> ((byte)puStack_454 & 0x1f)) +
                               ((uStack_41c & uVar16) >> ((byte)puStack_454 & 0x1f)) +
                               ((uVar16 & uStack_418) >> ((byte)puStack_454 & 0x1f));
                      bVar13 = (byte)iStack_430;
                      if (iStack_430 < 8) {
                        uVar16 = ((uVar16 & 2) >> 1) + ((int)uVar16 >> 2) << (8 - bVar13 & 0x1f);
                        for (uVar20 = (int)uVar16 >> (bVar13 & 0x1f); uVar20 != 0;
                            uVar20 = (int)uVar20 >> (bVar13 & 0x1f)) {
                          uVar16 = uVar16 | uVar20;
                        }
                      }
                      else {
                        uVar16 = (int)(((uVar16 & 2) >> 1) + ((int)uVar16 >> 2)) >>
                                 (bVar13 - 8 & 0x1f);
                      }
                    }
                    if (iStack_450 != 0) {
                      uVar20 = ((uStack_470 & param_1[3]) >> ((byte)iStack_438 & 0x1f)) +
                               ((uVar4 & param_1[3]) >> ((byte)iStack_438 & 0x1f)) +
                               ((uStack_41c & param_1[3]) >> ((byte)iStack_438 & 0x1f)) +
                               ((param_1[3] & uStack_418) >> ((byte)iStack_438 & 0x1f));
                      if (iStack_450 < 8) {
                        uStack_40c = ((uVar20 & 2) >> 1) + ((int)uVar20 >> 2) <<
                                     (8 - (byte)iStack_450 & 0x1f);
                        for (uVar20 = (int)uStack_40c >> ((byte)iStack_450 & 0x1f); uVar20 != 0;
                            uVar20 = (int)uVar20 >> ((byte)iStack_450 & 0x1f)) {
                          uStack_40c = uStack_40c | uVar20;
                        }
                      }
                      else {
                        uStack_40c = (int)(((uVar20 & 2) >> 1) + ((int)uVar20 >> 2)) >>
                                     ((byte)iStack_450 - 8 & 0x1f);
                      }
                    }
                    if (iStack_414 != 0) {
                      uVar20 = ((uStack_470 & param_1[4]) >> ((byte)puStack_42c & 0x1f)) +
                               ((uVar4 & param_1[4]) >> ((byte)puStack_42c & 0x1f)) +
                               ((uStack_41c & param_1[4]) >> ((byte)puStack_42c & 0x1f)) +
                               ((param_1[4] & uStack_418) >> ((byte)puStack_42c & 0x1f));
                      if (iStack_414 < 8) {
                        uStack_43c = ((uVar20 & 2) >> 1) + ((int)uVar20 >> 2) <<
                                     (8 - (byte)iStack_414 & 0x1f);
                        for (uVar20 = (int)uStack_43c >> ((byte)iStack_414 & 0x1f); uVar20 != 0;
                            uVar20 = (int)uVar20 >> ((byte)iStack_414 & 0x1f)) {
                          uStack_43c = uStack_43c | uVar20;
                        }
                      }
                      else {
                        uStack_43c = (int)(((uVar20 & 2) >> 1) + ((int)uVar20 >> 2)) >>
                                     ((byte)iStack_414 - 8 & 0x1f);
                      }
                    }
                    if (uStack_460 != 0) {
                      uVar17 = param_1[5];
                      uVar4 = ((uStack_470 & uVar17) >> ((byte)uStack_488 & 0x1f)) +
                              ((uVar4 & uVar17) >> ((byte)uStack_488 & 0x1f)) +
                              ((uStack_41c & uVar17) >> ((byte)uStack_488 & 0x1f)) +
                              ((uVar17 & uStack_418) >> ((byte)uStack_488 & 0x1f));
                      bVar13 = (byte)uStack_460;
                      if ((int)uStack_460 < 8) {
                        uVar17 = ((uVar4 & 2) >> 1) + ((int)uVar4 >> 2) << (8 - bVar13 & 0x1f);
                        for (uVar4 = (int)uVar17 >> (bVar13 & 0x1f); uVar4 != 0;
                            uVar4 = (int)uVar4 >> (bVar13 & 0x1f)) {
                          uVar17 = uVar17 | uVar4;
                        }
                      }
                      else {
                        uVar17 = (int)(((uVar4 & 2) >> 1) + ((int)uVar4 >> 2)) >>
                                 (bVar13 - 8 & 0x1f);
                      }
                    }
                    puStack_434 = puStack_434 + 2;
                    *(uint *)(((local_498[7] + (int)local_498[7] / 2) * iStack_494 + iStack_48c / 2)
                              * iStack_410 + iStack_408 + uStack_424) =
                         (uVar17 << 0x10 | uStack_40c) << 8 | uVar16 << 0x10 | uStack_43c;
                    iStack_428 = iStack_428 + 6;
                    iStack_490 = iStack_490 + 2;
                    uStack_424 = uStack_424 + 4;
                  } while (iStack_490 < param_1[7]);
                }
                iStack_48c = iStack_48c + 2;
              } while (iStack_48c < param_1[7]);
            }
          }
          puStack_42c = (undefined4 *)0x0;
          for (iVar30 = param_1[7]; iVar30 != 0; iVar30 = iVar30 >> 1) {
            puStack_42c = (undefined4 *)((int)puStack_42c + 1);
          }
          iStack_45c = 2;
          if (2 < (int)puStack_42c) {
            do {
              cVar3 = (char)iStack_45c;
              if (iStack_45c < 4) {
                iVar30 = 0;
              }
              else {
                iVar30 = 1 << (cVar3 - 3U & 0x1f);
                iVar30 = (((iVar30 + -1) * local_498[7]) / iVar30) * 4;
              }
              iVar12 = local_498[7];
              iVar25 = (iVar12 + iVar12 / 2) * iStack_494;
              iVar11 = 0;
              iVar30 = ((uint)(2 < iStack_45c) * iVar12 + iVar25) * iStack_410 + iStack_408 + iVar30
              ;
              if (2 < iStack_45c) {
                iVar11 = 1 << (cVar3 - 2U & 0x1f);
                iVar11 = (((iVar11 + -1) * iVar12) / iVar11) * 4;
              }
              iVar26 = 0;
              iVar11 = (iVar12 + iVar25) * iStack_410 + iStack_408 + iVar11;
              iStack_48c = 0;
              puStack_434 = (undefined4 *)(1 << (cVar3 - 1U & 0x1f));
              if (0 < param_1[7] / (int)puStack_434) {
                iVar12 = iStack_410;
                do {
                  iVar25 = 0;
                  if (0 < param_1[7] / (int)puStack_434 << 2) {
                    iVar5 = (iStack_48c / 2) * iStack_410;
                    do {
                      iVar18 = iVar30 + iVar25;
                      *(char *)(iVar25 / 2 + iVar11 + iVar5) =
                           (char)((uint)*(byte *)(iVar12 + 4 + iVar18) +
                                  (uint)*(byte *)(iVar26 + 4 + iVar18) +
                                  (uint)*(byte *)(iVar12 + iVar18) +
                                  (uint)*(byte *)(iVar26 + iVar18) >> 2);
                      iVar18 = iVar30 + iVar25 + 1;
                      *(char *)((iVar25 + 1) / 2 + iVar11 + 1 + iVar5) =
                           (char)((uint)*(byte *)(iVar12 + 4 + iVar18) +
                                  (uint)*(byte *)(iVar26 + 4 + iVar18) +
                                  (uint)*(byte *)(iVar12 + iVar18) +
                                  (uint)*(byte *)(iVar26 + iVar18) >> 2);
                      iVar18 = iVar30 + iVar25 + 2;
                      iVar21 = iVar25 + 3;
                      *(char *)((iVar25 + 2) / 2 + iVar11 + 1 + iVar5) =
                           (char)((uint)*(byte *)(iVar12 + 4 + iVar18) +
                                  (uint)*(byte *)(iVar26 + 4 + iVar18) +
                                  (uint)*(byte *)(iVar12 + iVar18) +
                                  (uint)*(byte *)(iVar26 + iVar18) >> 2);
                      iVar18 = iVar30 + iVar21;
                      iVar25 = iVar25 + 8;
                      *(char *)(iVar21 / 2 + iVar11 + 2 + iVar5) =
                           (char)((uint)*(byte *)(iVar12 + 4 + iVar18) +
                                  (uint)*(byte *)(iVar26 + 4 + iVar18) +
                                  (uint)*(byte *)(iVar12 + iVar18) +
                                  (uint)*(byte *)(iVar26 + iVar18) >> 2);
                    } while (iVar25 < (param_1[7] / (int)puStack_434) * 4);
                  }
                  iVar26 = iVar26 + iStack_410 * 2;
                  iVar12 = iVar12 + iStack_410 * 2;
                  iStack_48c = iStack_48c + 2;
                } while (iStack_48c < param_1[7] / (int)puStack_434);
              }
              iStack_45c = iStack_45c + 1;
            } while (iStack_45c < (int)puStack_42c);
          }
          iStack_494 = iStack_494 + 1;
        } while (iStack_494 < param_1[8] / param_1[7]);
      }
LAB_10026986:
      if ((((param_1[0x10] & 2U) != 0) && (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
         (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(param_1), iVar30 == 0)) {
        FUN_1000cba0(1);
      }
      if ((((local_498[0x10] & 2) != 0) && (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
         (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(local_498), iVar30 == 0)) {
        FUN_1000cba0(1);
      }
      uVar1 = *(undefined4 *)(PTR_DAT_1005b69c + 0x14);
      puVar6 = FUN_10037030(DAT_1005acdc);
      if (puVar6 == (undefined4 *)0x0) {
        FUN_1000cba0(3);
      }
      else {
        puVar6[0xc] = 0;
        puVar6[0xf] = 0;
        puVar6[0xd] = 0;
        puVar6[0xe] = 0;
        puVar6[7] = 0;
        puVar6[8] = 0;
        puVar6[9] = uVar1;
        puVar6[1] = 0;
        iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x2a0))(puVar6);
        if (iVar30 != 0) goto LAB_10026a39;
        FUN_10037010(DAT_1005acdc,puVar6);
      }
      puVar6 = (undefined4 *)0x0;
LAB_10026a39:
      if (puVar6 == (undefined4 *)0x0) {
        (**(code **)(PTR_DAT_1005b69c + 0x358))(local_498[6]);
        RwDestroyRaster(local_498);
        if (local_420 == (undefined4 *)0x0) {
          return (undefined4 *)0x0;
        }
        RwDestroyRaster(local_420);
        return (undefined4 *)0x0;
      }
      puVar7 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x48))(local_498,puVar6,param_2);
      if (puVar7 == (undefined4 *)0x0) {
        RwDestroyRaster(puVar6);
        (**(code **)(PTR_DAT_1005b69c + 0x358))(unaff_EBX[6]);
        RwDestroyRaster(unaff_EBX);
        if (puStack_42c == (undefined4 *)0x0) {
          return (undefined4 *)0x0;
        }
        RwDestroyRaster(puStack_42c);
        return (undefined4 *)0x0;
      }
      (**(code **)(PTR_DAT_1005b69c + 0x358))(unaff_EBX[6]);
      RwDestroyRaster(unaff_EBX);
      if (puStack_42c == (undefined4 *)0x0) {
        return puVar7;
      }
      iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x2a4))(puVar7,puStack_42c);
      if (iVar30 == 0) {
        RwDestroyRaster(puStack_434);
        RwDestroyRaster(puVar7);
        return (undefined4 *)0x0;
      }
      RwDestroyRaster(puStack_434);
      return puVar7;
    }
    if ((param_3[7] != param_1[7]) || (param_3[8] != param_1[8])) {
      if (((param_1[0x10] & 2U) != 0) &&
         ((*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0 &&
          (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(param_1), iVar30 == 0)))) {
        FUN_1000cba0(1);
      }
      if (((local_498[0x10] & 2) != 0) && (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) {
        iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(local_498);
        goto joined_r0x1002268c;
      }
      goto LAB_10026b8b;
    }
    if ((param_3 == (int *)0x0) ||
       ((((param_3[0x10] & 2U) != 0 && (*(code **)(PTR_DAT_1005b69c + 0x298) != (code *)0x0)) &&
        (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x298))(param_3), iVar30 == 0)))) {
      FUN_1000cba0(1);
      iStack_484 = 0;
    }
    else {
      iStack_484 = param_3[6];
      param_3[0x10] = param_3[0x10] | 1;
    }
    if (iStack_484 == 0) {
      if ((((param_1[0x10] & 2U) != 0) && (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
         (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(param_1), iVar30 == 0)) {
        FUN_1000cba0(1);
      }
      if ((((local_498[0x10] & 2) != 0) && (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
         (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(local_498), iVar30 == 0)) {
        FUN_1000cba0(1);
      }
      (**(code **)(PTR_DAT_1005b69c + 0x358))(local_498[6]);
      RwDestroyRaster(local_498);
      return (undefined4 *)0x0;
    }
    puStack_478 = FUN_10037030(DAT_1005acdc);
    if (puStack_478 == (undefined4 *)0x0) {
      FUN_1000cba0(3);
      puStack_478 = (undefined4 *)0x0;
    }
    else {
      puStack_478[0xc] = 0;
      puStack_478[0xf] = 0;
      puStack_478[0xd] = 0;
      puStack_478[0xe] = 0;
      puStack_478[7] = 0;
      puStack_478[8] = 0;
      puStack_478[9] = 0;
      puStack_478[1] = 0;
      iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x2a0))(puStack_478);
      if (iVar30 == 0) {
        FUN_10037010(DAT_1005acdc,puStack_478);
        puStack_478 = (undefined4 *)0x0;
      }
    }
    if (puStack_478 == (undefined4 *)0x0) {
      if ((((param_3[0x10] & 2U) != 0) && (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
         (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(param_3), iVar30 == 0)) {
        FUN_1000cba0(1);
      }
      if ((((param_1[0x10] & 2U) != 0) && (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
         (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(param_1), iVar30 == 0)) {
        FUN_1000cba0(1);
      }
      if ((((local_498[0x10] & 2) != 0) && (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
         (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(local_498), iVar30 == 0)) {
        FUN_1000cba0(1);
      }
      (**(code **)(PTR_DAT_1005b69c + 0x358))(local_498[6]);
      RwDestroyRaster(local_498);
      return (undefined4 *)0x0;
    }
    *puStack_478 = 2;
    puStack_478[1] = 8;
    puStack_478[4] = 0xff;
    puStack_478[3] = 0xff;
    puStack_478[2] = 0xff;
    puStack_478[5] = 0;
    puStack_478[7] = param_1[7] / 2;
    iVar30 = param_1[7] * 3;
    puStack_478[8] = ((int)(iVar30 + (iVar30 >> 0x1f & 3U)) >> 2) * (param_1[8] / param_1[7]);
    puStack_478[9] = 8;
    puStack_478[10] = puStack_478[7];
    iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(puStack_478[8] * puStack_478[7]);
    puStack_478[6] = iVar30;
    if (iVar30 == 0) {
      RwDestroyRaster(puStack_478);
      if ((((param_3[0x10] & 2U) != 0) && (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
         (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(param_3), iVar30 == 0)) {
        FUN_1000cba0(1);
      }
      if ((((param_1[0x10] & 2U) != 0) && (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
         (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(param_1), iVar30 == 0)) {
        FUN_1000cba0(1);
      }
      if ((((local_498[0x10] & 2) != 0) && (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
         (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(local_498), iVar30 == 0)) {
        FUN_1000cba0(1);
      }
      (**(code **)(PTR_DAT_1005b69c + 0x358))(local_498[6]);
      RwDestroyRaster(local_498);
      return (undefined4 *)0x0;
    }
    if ((puStack_478 == (undefined4 *)0x0) ||
       ((((puStack_478[0x10] & 2) != 0 && (*(code **)(PTR_DAT_1005b69c + 0x298) != (code *)0x0)) &&
        (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x298))(puStack_478), iVar30 == 0)))) {
      FUN_1000cba0(1);
      iStack_414 = 0;
    }
    else {
      puStack_478[0x10] = puStack_478[0x10] | 1;
      iStack_414 = puStack_478[6];
    }
    if (iStack_414 == 0) {
      if ((((param_3[0x10] & 2U) != 0) && (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
         (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(param_3), iVar30 == 0)) {
        FUN_1000cba0(1);
      }
      if ((((param_1[0x10] & 2U) != 0) && (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
         (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(param_1), iVar30 == 0)) {
        FUN_1000cba0(1);
      }
      if ((((local_498[0x10] & 2) != 0) && (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
         (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(local_498), iVar30 == 0)) {
        FUN_1000cba0(1);
      }
      (**(code **)(PTR_DAT_1005b69c + 0x358))(local_498[6]);
      RwDestroyRaster(local_498);
      (**(code **)(PTR_DAT_1005b69c + 0x358))(puStack_478[6]);
      RwDestroyRaster(puStack_478);
      return (undefined4 *)0x0;
    }
    if (param_3 == (int *)0x0) {
      FUN_1000cba0(1);
      iStack_480 = -1;
    }
    else {
      iStack_480 = param_3[10];
    }
    if (puStack_478 == (undefined4 *)0x0) {
      FUN_1000cba0(1);
      uStack_40c = -1;
    }
    else {
      uStack_40c = puStack_478[10];
    }
    iStack_494 = 0;
    if (0 < param_1[8] / param_1[7]) {
      do {
        if (*param_1 == 1) {
          iVar30 = 0;
          if (0 < param_1[7]) {
            do {
              iStack_490 = 0;
              if (0 < param_1[7]) {
                iStack_438 = 0;
                puStack_434 = (undefined4 *)(iVar30 / 2);
                do {
                  iVar11 = *param_3;
                  if (iVar11 == 1) {
                    if (param_3[0xd] == 0) {
                      iVar12 = (param_1[7] * iStack_494 + iVar30) * iStack_480 + iStack_490;
                      lVar27 = CONCAT44(iVar12,(uint)*(byte *)(iVar12 + iStack_484));
                      goto LAB_10024266;
                    }
                    uStack_44c = (uint)*(byte *)((uint)*(byte *)((param_1[7] * iStack_494 + iVar30)
                                                                 * iStack_480 + iStack_490 +
                                                                iStack_484) * 3 + 2 + param_3[0xd]);
                  }
                  else {
                    lVar27 = __ftol();
LAB_10024266:
                    uStack_44c = (uint)lVar27;
                  }
                  if (iVar11 == 1) {
                    if (param_3[0xd] == 0) {
                      iVar12 = (param_1[7] * iStack_494 + iVar30) * iStack_480 + iStack_490;
                      lVar27 = CONCAT44(iVar12,(uint)*(byte *)(iVar12 + 1 + iStack_484));
                      goto LAB_10024405;
                    }
                    uStack_448 = (uint)*(byte *)((uint)*(byte *)((param_1[7] * iStack_494 + iVar30)
                                                                 * iStack_480 + iStack_490 + 1 +
                                                                iStack_484) * 3 + 2 + param_3[0xd]);
                  }
                  else {
                    lVar27 = __ftol();
LAB_10024405:
                    uStack_448 = (uint)lVar27;
                  }
                  if (iVar11 == 1) {
                    if (param_3[0xd] == 0) {
                      iVar12 = (param_1[7] * iStack_494 + iVar30 + 1) * iStack_480 + iStack_490;
                      lVar27 = CONCAT44(iVar12,(uint)*(byte *)(iVar12 + iStack_484));
                      goto LAB_100245a5;
                    }
                    uStack_444 = (uint)*(byte *)((uint)*(byte *)((param_1[7] * iStack_494 + iVar30 +
                                                                 1) * iStack_480 + iStack_490 +
                                                                iStack_484) * 3 + 2 + param_3[0xd]);
                  }
                  else {
                    lVar27 = __ftol();
LAB_100245a5:
                    uStack_444 = (uint)lVar27;
                  }
                  if (iVar11 == 1) {
                    if (param_3[0xd] == 0) {
                      uStack_440 = (uint)*(byte *)((param_1[7] * iStack_494 + iVar30 + 1) *
                                                   iStack_480 + iStack_490 + 1 + iStack_484);
                    }
                    else {
                      uStack_440 = (uint)*(byte *)((uint)*(byte *)((param_1[7] * iStack_494 + iVar30
                                                                   + 1) * iStack_480 + iStack_490 +
                                                                   1 + iStack_484) * 3 + 2 +
                                                  param_3[0xd]);
                    }
                  }
                  else {
                    lVar27 = __ftol();
                    uStack_440 = (uint)lVar27;
                  }
                  lVar27 = __ftol();
                  lVar28 = __ftol();
                  lVar29 = __ftol();
                  *(uint *)((int)((local_498[7] + (int)local_498[7] / 2) * iStack_494 +
                                 (int)puStack_434) * iStack_410 + iStack_408 + iStack_438) =
                       (int)lVar27 << 0x10 | (int)lVar28 << 8 | (uint)lVar29;
                  *(char *)((int)(((int)local_498[7] / 2 + local_498[7]) * iStack_494 +
                                 (int)puStack_434) * uStack_40c + iStack_490 / 2 + iStack_414) =
                       (char)(uStack_444 + uStack_440 + uStack_448 + uStack_44c >> 2);
                  iStack_438 = iStack_438 + 4;
                  iStack_490 = iStack_490 + 2;
                } while (iStack_490 < param_1[7]);
              }
              iVar30 = iVar30 + 2;
            } while (iVar30 < param_1[7]);
          }
        }
        else {
          if (*param_1 != 2) {
            if ((((puStack_478[0x10] & 2) != 0) &&
                (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
               (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(puStack_478), iVar30 == 0)) {
              FUN_1000cba0(1);
            }
            if ((((param_3[0x10] & 2U) != 0) &&
                (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
               (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(param_3), iVar30 == 0)) {
              FUN_1000cba0(1);
            }
            if ((((param_1[0x10] & 2U) != 0) &&
                (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
               (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(param_1), iVar30 == 0)) {
              FUN_1000cba0(1);
            }
            if ((((local_498[0x10] & 2) != 0) &&
                (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
               (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(local_498), iVar30 == 0)) {
              FUN_1000cba0(1);
            }
            (**(code **)(PTR_DAT_1005b69c + 0x358))(local_498[6]);
            RwDestroyRaster(local_498);
            (**(code **)(PTR_DAT_1005b69c + 0x358))(puStack_478[6]);
            local_498 = puStack_478;
            goto LAB_10026ba6;
          }
          uVar4 = param_1[2];
          if (uVar4 == 0) {
            puStack_434 = (undefined4 *)0x0;
          }
          else {
            if ((~(uVar4 * 2) & uVar4 & 0xffff0000) == 0) {
              uVar16 = ~(uVar4 * 2) & uVar4;
              if ((char)(uVar16 >> 8) == '\0') {
                iVar30 = (char)(&DAT_1005b7c0)[uVar16 | 1] + -1;
              }
              else {
                iVar30 = (char)(&DAT_1005b7c0)[~((int)(uVar4 * 2) >> 8) & (int)uVar4 >> 8] + 7;
              }
            }
            else {
              uVar16 = ~((int)(uVar4 * 2) >> 0x10) & (int)uVar4 >> 0x10;
              if ((char)(uVar16 >> 8) == '\0') {
                iVar30 = (char)(&DAT_1005b7c0)[uVar16] + -1;
              }
              else {
                iVar30 = (char)(&DAT_1005b7c0)[~((int)(uVar4 * 2) >> 0x18) & (int)uVar4 >> 0x18] + 7
                ;
              }
              iVar30 = iVar30 + 0x10;
            }
            uVar17 = ~((int)uVar4 >> 1);
            uVar16 = (uVar17 | 0x8000ffff) & uVar4;
            if ((uVar16 & 0xffff0000) == 0) {
              if ((byte)((byte)(uVar17 >> 8) & (byte)(uVar4 >> 8)) == 0) {
                iVar11 = (char)(&DAT_1005b7c0)[(uVar17 | 0x80000000) & uVar4] + -1;
              }
              else {
                iVar11 = (char)(&DAT_1005b7c0)[((uVar17 | 0x800000ff) & uVar4) >> 8] + 7;
              }
            }
            else if (((uVar4 & 0xff00ffff) >> 0x10 &
                     (~((uint)((int)uVar4 >> 1) >> 0x10) | 0xffff80ff)) == 0) {
              iVar11 = (char)(&DAT_1005b7c0)[uVar16 >> 0x10] + 0xf;
            }
            else {
              iVar11 = (char)(&DAT_1005b7c0)[((uVar17 | 0x80ffffff) & uVar4) >> 0x18] + 0x17;
            }
            puStack_434 = (undefined4 *)((iVar11 - iVar30) + 1);
          }
          uVar4 = param_1[3];
          if (uVar4 == 0) {
            uStack_43c = 0;
          }
          else {
            if ((~(uVar4 * 2) & uVar4 & 0xffff0000) == 0) {
              uVar16 = ~(uVar4 * 2) & uVar4;
              if ((char)(uVar16 >> 8) == '\0') {
                iVar30 = (char)(&DAT_1005b7c0)[uVar16 | 1] + -1;
              }
              else {
                iVar30 = (char)(&DAT_1005b7c0)[~((int)(uVar4 * 2) >> 8) & (int)uVar4 >> 8] + 7;
              }
            }
            else {
              uVar16 = ~((int)(uVar4 * 2) >> 0x10) & (int)uVar4 >> 0x10;
              if ((char)(uVar16 >> 8) == '\0') {
                iVar30 = (char)(&DAT_1005b7c0)[uVar16] + -1;
              }
              else {
                iVar30 = (char)(&DAT_1005b7c0)[~((int)(uVar4 * 2) >> 0x18) & (int)uVar4 >> 0x18] + 7
                ;
              }
              iVar30 = iVar30 + 0x10;
            }
            uVar17 = ~((int)uVar4 >> 1);
            uVar16 = (uVar17 | 0x8000ffff) & uVar4;
            if ((uVar16 & 0xffff0000) == 0) {
              if ((byte)((byte)(uVar17 >> 8) & (byte)(uVar4 >> 8)) == 0) {
                iVar11 = (char)(&DAT_1005b7c0)[(uVar17 | 0x80000000) & uVar4] + -1;
              }
              else {
                iVar11 = (char)(&DAT_1005b7c0)[((uVar17 | 0x800000ff) & uVar4) >> 8] + 7;
              }
            }
            else if (((uVar4 & 0xff00ffff) >> 0x10 &
                     (~((uint)((int)uVar4 >> 1) >> 0x10) | 0xffff80ff)) == 0) {
              iVar11 = (char)(&DAT_1005b7c0)[uVar16 >> 0x10] + 0xf;
            }
            else {
              iVar11 = (char)(&DAT_1005b7c0)[((uVar17 | 0x80ffffff) & uVar4) >> 0x18] + 0x17;
            }
            uStack_43c = (iVar11 - iVar30) + 1;
          }
          uVar4 = param_1[4];
          if (uVar4 == 0) {
            iStack_450 = 0;
          }
          else {
            if ((~(uVar4 * 2) & uVar4 & 0xffff0000) == 0) {
              uVar16 = ~(uVar4 * 2) & uVar4;
              if ((char)(uVar16 >> 8) == '\0') {
                iVar30 = (char)(&DAT_1005b7c0)[uVar16 | 1] + -1;
              }
              else {
                iVar30 = (char)(&DAT_1005b7c0)[~((int)(uVar4 * 2) >> 8) & (int)uVar4 >> 8] + 7;
              }
            }
            else {
              uVar16 = ~((int)(uVar4 * 2) >> 0x10) & (int)uVar4 >> 0x10;
              if ((char)(uVar16 >> 8) == '\0') {
                iVar30 = (char)(&DAT_1005b7c0)[uVar16] + -1;
              }
              else {
                iVar30 = (char)(&DAT_1005b7c0)[~((int)(uVar4 * 2) >> 0x18) & (int)uVar4 >> 0x18] + 7
                ;
              }
              iVar30 = iVar30 + 0x10;
            }
            uVar17 = ~((int)uVar4 >> 1);
            uVar16 = (uVar17 | 0x8000ffff) & uVar4;
            if ((uVar16 & 0xffff0000) == 0) {
              if ((byte)((byte)(uVar17 >> 8) & (byte)(uVar4 >> 8)) == 0) {
                iVar11 = (char)(&DAT_1005b7c0)[(uVar17 | 0x80000000) & uVar4] + -1;
              }
              else {
                iVar11 = (char)(&DAT_1005b7c0)[((uVar17 | 0x800000ff) & uVar4) >> 8] + 7;
              }
            }
            else if (((uVar4 & 0xff00ffff) >> 0x10 &
                     (~((uint)((int)uVar4 >> 1) >> 0x10) | 0xffff80ff)) == 0) {
              iVar11 = (char)(&DAT_1005b7c0)[uVar16 >> 0x10] + 0xf;
            }
            else {
              iVar11 = (char)(&DAT_1005b7c0)[((uVar17 | 0x80ffffff) & uVar4) >> 0x18] + 0x17;
            }
            iStack_450 = (iVar11 - iVar30) + 1;
          }
          uVar4 = param_1[5];
          if (uVar4 == 0) {
            iStack_438 = 0;
          }
          else {
            if ((~(uVar4 * 2) & uVar4 & 0xffff0000) == 0) {
              uVar16 = ~(uVar4 * 2) & uVar4;
              if ((char)(uVar16 >> 8) == '\0') {
                iVar30 = (char)(&DAT_1005b7c0)[uVar16 | 1] + -1;
              }
              else {
                iVar30 = (char)(&DAT_1005b7c0)[~((int)(uVar4 * 2) >> 8) & (int)uVar4 >> 8] + 7;
              }
            }
            else {
              uVar16 = ~((int)(uVar4 * 2) >> 0x10) & (int)uVar4 >> 0x10;
              if ((char)(uVar16 >> 8) == '\0') {
                iVar30 = (char)(&DAT_1005b7c0)[uVar16] + -1;
              }
              else {
                iVar30 = (char)(&DAT_1005b7c0)[~((int)(uVar4 * 2) >> 0x18) & (int)uVar4 >> 0x18] + 7
                ;
              }
              iVar30 = iVar30 + 0x10;
            }
            uVar17 = ~((int)uVar4 >> 1);
            uVar16 = (uVar17 | 0x8000ffff) & uVar4;
            if ((uVar16 & 0xffff0000) == 0) {
              if ((byte)((byte)(uVar17 >> 8) & (byte)(uVar4 >> 8)) == 0) {
                iVar11 = (char)(&DAT_1005b7c0)[(uVar17 | 0x80000000) & uVar4] + -1;
              }
              else {
                iVar11 = (char)(&DAT_1005b7c0)[((uVar17 | 0x800000ff) & uVar4) >> 8] + 7;
              }
            }
            else if (((uVar4 & 0xff00ffff) >> 0x10 &
                     (~((uint)((int)uVar4 >> 1) >> 0x10) | 0xffff80ff)) == 0) {
              iVar11 = (char)(&DAT_1005b7c0)[uVar16 >> 0x10] + 0xf;
            }
            else {
              iVar11 = (char)(&DAT_1005b7c0)[((uVar17 | 0x80ffffff) & uVar4) >> 0x18] + 0x17;
            }
            iStack_438 = (iVar11 - iVar30) + 1;
          }
          iStack_48c = 0;
          if (0 < param_1[7]) {
            do {
              iStack_490 = 0;
              if (0 < param_1[7]) {
                iStack_404 = 0;
                do {
                  iVar30 = *param_3;
                  if (iVar30 == 1) {
                    if (param_3[0xd] == 0) {
                      uStack_44c = (uint)*(byte *)((param_1[7] * iStack_494 + iStack_48c) *
                                                   iStack_480 + iStack_490 + iStack_484);
                    }
                    else {
                      uStack_44c = (uint)*(byte *)((uint)*(byte *)((param_1[7] * iStack_494 +
                                                                   iStack_48c) * iStack_480 +
                                                                   iStack_490 + iStack_484) * 3 + 2
                                                  + param_3[0xd]);
                    }
                  }
                  else {
                    lVar27 = __ftol();
                    uStack_44c = (uint)lVar27;
                  }
                  if (iVar30 == 1) {
                    if (param_3[0xd] == 0) {
                      uStack_448 = (uint)*(byte *)((param_1[7] * iStack_494 + iStack_48c) *
                                                   iStack_480 + iStack_490 + 1 + iStack_484);
                    }
                    else {
                      uStack_448 = (uint)*(byte *)((uint)*(byte *)((param_1[7] * iStack_494 +
                                                                   iStack_48c) * iStack_480 +
                                                                   iStack_490 + 1 + iStack_484) * 3
                                                   + 2 + param_3[0xd]);
                    }
                  }
                  else {
                    lVar27 = __ftol();
                    uStack_448 = (uint)lVar27;
                  }
                  if (iVar30 == 1) {
                    if (param_3[0xd] == 0) {
                      uStack_444 = (uint)*(byte *)((param_1[7] * iStack_494 + iStack_48c + 1) *
                                                   iStack_480 + iStack_490 + iStack_484);
                    }
                    else {
                      uStack_444 = (uint)*(byte *)((uint)*(byte *)((param_1[7] * iStack_494 +
                                                                    iStack_48c + 1) * iStack_480 +
                                                                   iStack_490 + iStack_484) * 3 + 2
                                                  + param_3[0xd]);
                    }
                  }
                  else {
                    lVar27 = __ftol();
                    uStack_444 = (uint)lVar27;
                  }
                  if (iVar30 == 1) {
                    if (param_3[0xd] == 0) {
                      uStack_440 = (uint)*(byte *)((param_1[7] * iStack_494 + iStack_48c + 1) *
                                                   iStack_480 + iStack_490 + 1 + iStack_484);
                    }
                    else {
                      uStack_440 = (uint)*(byte *)((uint)*(byte *)((param_1[7] * iStack_494 +
                                                                    iStack_48c + 1) * iStack_480 +
                                                                   iStack_490 + 1 + iStack_484) * 3
                                                   + 2 + param_3[0xd]);
                    }
                  }
                  else {
                    lVar27 = __ftol();
                    uStack_440 = (uint)lVar27;
                  }
                  switch(param_1[1]) {
                  case 8:
                    break;
                  default:
                    if ((((puStack_478[0x10] & 2) != 0) &&
                        (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
                       (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(puStack_478), iVar30 == 0))
                    {
                      FUN_1000cba0(1);
                    }
                    if ((((param_3[0x10] & 2U) != 0) &&
                        (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
                       (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(param_3), iVar30 == 0)) {
                      FUN_1000cba0(1);
                    }
                    if ((((param_1[0x10] & 2U) != 0) &&
                        (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
                       (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(param_1), iVar30 == 0)) {
                      FUN_1000cba0(1);
                    }
                    if ((((local_498[0x10] & 2) != 0) &&
                        (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
                       (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(local_498), iVar30 == 0)) {
                      FUN_1000cba0(1);
                    }
                    (**(code **)(PTR_DAT_1005b69c + 0x358))(local_498[6]);
                    RwDestroyRaster(local_498);
                    (**(code **)(PTR_DAT_1005b69c + 0x358))(puStack_478[6]);
                    local_498 = puStack_478;
                    goto LAB_10026ba6;
                  case 0xf:
                  case 0x10:
                    break;
                  case 0x18:
                    break;
                  case 0x20:
                  }
                  uVar4 = 0;
                  uStack_460 = 0;
                  puStack_42c = (undefined4 *)0x0;
                  uStack_424 = 0;
                  if (puStack_434 != (undefined4 *)0x0) {
                    lVar27 = __ftol();
                    uVar4 = (uint)lVar27;
                    bVar13 = (byte)puStack_434;
                    if ((int)puStack_434 < 8) {
                      uVar4 = ((uVar4 & 2) >> 1) + ((int)uVar4 >> 2) << (8 - bVar13 & 0x1f);
                      for (uVar16 = (int)uVar4 >> (bVar13 & 0x1f); uVar16 != 0;
                          uVar16 = (int)uVar16 >> (bVar13 & 0x1f)) {
                        uVar4 = uVar4 | uVar16;
                      }
                    }
                    else {
                      uVar4 = (int)(((uVar4 & 2) >> 1) + ((int)uVar4 >> 2)) >> (bVar13 - 8 & 0x1f);
                    }
                  }
                  if (uStack_43c != 0) {
                    lVar27 = __ftol();
                    uVar16 = (uint)lVar27;
                    if ((int)uStack_43c < 8) {
                      uStack_424 = ((uVar16 & 2) >> 1) + ((int)uVar16 >> 2) <<
                                   (8 - (byte)uStack_43c & 0x1f);
                      for (uVar16 = (int)uStack_424 >> ((byte)uStack_43c & 0x1f); uVar16 != 0;
                          uVar16 = (int)uVar16 >> ((byte)uStack_43c & 0x1f)) {
                        uStack_424 = uStack_424 | uVar16;
                      }
                    }
                    else {
                      uStack_424 = (int)(((uVar16 & 2) >> 1) + ((int)uVar16 >> 2)) >>
                                   ((byte)uStack_43c - 8 & 0x1f);
                    }
                  }
                  if (iStack_450 != 0) {
                    lVar27 = __ftol();
                    uVar16 = (uint)lVar27;
                    if (iStack_450 < 8) {
                      puStack_42c = (undefined4 *)
                                    (((uVar16 & 2) >> 1) + ((int)uVar16 >> 2) <<
                                    (8 - (byte)iStack_450 & 0x1f));
                      for (uVar16 = (int)puStack_42c >> ((byte)iStack_450 & 0x1f); uVar16 != 0;
                          uVar16 = (int)uVar16 >> ((byte)iStack_450 & 0x1f)) {
                        puStack_42c = (undefined4 *)((uint)puStack_42c | uVar16);
                      }
                    }
                    else {
                      puStack_42c = (undefined4 *)
                                    ((int)(((uVar16 & 2) >> 1) + ((int)uVar16 >> 2)) >>
                                    ((byte)iStack_450 - 8 & 0x1f));
                    }
                  }
                  if (iStack_438 != 0) {
                    lVar27 = __ftol();
                    uVar16 = (uint)lVar27;
                    bVar13 = (byte)iStack_438;
                    if (iStack_438 < 8) {
                      uStack_460 = ((uVar16 & 2) >> 1) + ((int)uVar16 >> 2) << (8 - bVar13 & 0x1f);
                      for (uVar16 = (int)uStack_460 >> (bVar13 & 0x1f); uVar16 != 0;
                          uVar16 = (int)uVar16 >> (bVar13 & 0x1f)) {
                        uStack_460 = uStack_460 | uVar16;
                      }
                    }
                    else {
                      uStack_460 = (int)(((uVar16 & 2) >> 1) + ((int)uVar16 >> 2)) >>
                                   (bVar13 - 8 & 0x1f);
                    }
                  }
                  *(uint *)((((int)local_498[7] / 2 + local_498[7]) * iStack_494 + iStack_48c / 2) *
                            iStack_410 + iStack_408 + iStack_404) =
                       (uStack_460 << 0x10 | uStack_424) << 8 | uVar4 << 0x10 | (uint)puStack_42c;
                  iStack_404 = iStack_404 + 4;
                  *(char *)(((puStack_478[7] + (int)puStack_478[7] / 2) * iStack_494 +
                            iStack_48c / 2) * uStack_40c + iStack_490 / 2 + iStack_414) =
                       (char)(uStack_444 + uStack_440 + uStack_448 + uStack_44c >> 2);
                  iStack_490 = iStack_490 + 2;
                } while (iStack_490 < param_1[7]);
              }
              iStack_48c = iStack_48c + 2;
            } while (iStack_48c < param_1[7]);
          }
        }
        puStack_42c = (undefined4 *)0x0;
        for (iVar30 = param_1[7]; iVar30 != 0; iVar30 = iVar30 >> 1) {
          puStack_42c = (undefined4 *)((int)puStack_42c + 1);
        }
        iStack_45c = 2;
        if (2 < (int)puStack_42c) {
          do {
            cVar3 = (char)iStack_45c;
            iVar30 = local_498[7];
            iVar11 = 0;
            if (2 < iStack_45c) {
              iVar11 = 1 << (cVar3 - 2U & 0x1f);
              iVar11 = ((iVar11 + -1) * iVar30) / iVar11 << 2;
            }
            iVar11 = iVar11 + ((iVar30 / 2 + iVar30) * iStack_494 + iVar30) * iStack_410 +
                              iStack_408;
            iVar30 = 0;
            if (3 < iStack_45c) {
              iVar30 = 1 << (cVar3 - 3U & 0x1f);
              iVar30 = ((iVar30 + -1) * puStack_478[7]) / iVar30;
            }
            iVar12 = puStack_478[7];
            iVar26 = (iVar12 / 2 + iVar12) * iStack_494;
            iVar30 = ((uint)(2 < iStack_45c) * iVar12 + iVar26) * uStack_40c + iStack_414 + iVar30;
            iVar25 = 0;
            if (2 < iStack_45c) {
              iVar25 = 1 << (cVar3 - 2U & 0x1f);
              iVar25 = ((iVar25 + -1) * iVar12) / iVar25;
            }
            iStack_48c = 0;
            puStack_434 = (undefined4 *)(iVar25 + (iVar26 + iVar12) * uStack_40c + iStack_414);
            iVar12 = 1 << (cVar3 - 1U & 0x1f);
            if (0 < param_1[7] / iVar12) {
              do {
                iVar25 = 0;
                if (0 < param_1[7] / iVar12 << 2) {
                  iVar26 = iStack_410 * (iStack_48c / 2);
                  do {
                    iVar21 = iStack_48c * puStack_478[10];
                    iVar5 = puStack_478[10] * (iStack_48c + 1);
                    iVar18 = iVar25 + 4 >> 2;
                    local_4a0 = (uint)*(byte *)(iVar21 + iVar30 + iVar18);
                    *(char *)((int)puStack_434 +
                             uStack_40c * (iStack_48c / 2) +
                             ((int)(iVar25 + (iVar25 >> 0x1f & 7U)) >> 3)) =
                         (char)((uint)*(byte *)(iVar30 + iVar5 + (iVar25 >> 2)) +
                                (uint)*(byte *)(iVar5 + iVar30 + iVar18) + local_4a0 +
                                (uint)*(byte *)(iVar30 + iVar21 + (iVar25 >> 2)) >> 2);
                    lVar27 = __ftol();
                    *(char *)(iVar25 / 2 + iVar11 + iVar26) = (char)lVar27;
                    lVar27 = __ftol();
                    *(char *)((iVar25 + 1) / 2 + iVar11 + 1 + iVar26) = (char)lVar27;
                    lVar27 = __ftol();
                    iVar5 = iVar25 + 3;
                    *(char *)((iVar25 + 2) / 2 + iVar11 + 1 + iVar26) = (char)lVar27;
                    lVar27 = __ftol();
                    iVar25 = iVar25 + 8;
                    *(char *)(iVar5 / 2 + iVar11 + 2 + iVar26) = (char)lVar27;
                  } while (iVar25 < (param_1[7] / iVar12) * 4);
                }
                iStack_48c = iStack_48c + 2;
              } while (iStack_48c < param_1[7] / iVar12);
            }
            iStack_45c = iStack_45c + 1;
          } while (iStack_45c < (int)puStack_42c);
        }
        iStack_494 = iStack_494 + 1;
      } while (iStack_494 < param_1[8] / param_1[7]);
    }
    if ((((puStack_478[0x10] & 2) != 0) && (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
       (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(puStack_478), iVar30 == 0)) {
      FUN_1000cba0(1);
    }
    if ((((param_3[0x10] & 2U) != 0) && (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
       (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(param_3), iVar30 == 0)) {
      FUN_1000cba0(1);
    }
    local_420 = (undefined4 *)0x0;
    uVar1 = *(undefined4 *)(PTR_DAT_1005b69c + 0x14);
    puVar6 = FUN_10037030(DAT_1005acdc);
    if (puVar6 == (undefined4 *)0x0) {
      FUN_1000cba0(3);
LAB_100268a3:
      puVar6 = (undefined4 *)0x0;
    }
    else {
      puVar6[0xc] = 0;
      puVar6[0xf] = 0;
      puVar6[0xd] = 0;
      puVar6[0xe] = 0;
      puVar6[7] = 0;
      puVar6[8] = 0;
      puVar6[9] = uVar1;
      puVar6[1] = 0;
      iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x2a0))(puVar6);
      if (iVar30 == 0) {
        FUN_10037010(DAT_1005acdc,puVar6);
        goto LAB_100268a3;
      }
    }
    if ((puVar6 == (undefined4 *)0x0) ||
       (local_420 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x48))(puStack_478,puVar6,4),
       local_420 != (undefined4 *)0x0)) {
      (**(code **)(PTR_DAT_1005b69c + 0x358))(puStack_478[6]);
      RwDestroyRaster(puStack_478);
      goto LAB_10026986;
    }
    RwDestroyRaster(puVar6);
    if ((((param_1[0x10] & 2U) != 0) && (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
       (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(param_1), iVar30 == 0)) {
      FUN_1000cba0(1);
    }
    if ((((local_498[0x10] & 2) != 0) && (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
       (iVar30 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(local_498), iVar30 == 0)) {
      FUN_1000cba0(1);
    }
    (**(code **)(PTR_DAT_1005b69c + 0x358))(local_498[6]);
    RwDestroyRaster(local_498);
    (**(code **)(PTR_DAT_1005b69c + 0x358))(puStack_478[6]);
    local_498 = puStack_478;
  }
LAB_10026ba6:
  RwDestroyRaster(local_498);
  iVar30 = 0x62;
LAB_10026bae:
  FUN_1000cba0(iVar30);
  return (undefined4 *)0x0;
}


