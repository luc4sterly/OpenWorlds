// 0041b670 FUN_0041b670 [Global]
// program: gamma.dll

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_0041b670(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5,undefined4 *param_6)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float *local_84;
  int local_80;
  int local_74;
  int local_70;
  float local_6c [14];
  float local_34;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar4 = -1;
  local_74 = 0;
  local_80 = -1;
  local_70 = 4;
  local_6c[0] = (float)FUN_00419950();
  local_6c[1] = (float)FUN_00419950();
  uVar2 = FUN_00419950();
  FUN_004191d0(param_2,local_6c[1]);
  FUN_00419860(local_6c[1],uVar2);
  FUN_004193c0(param_1,local_6c[0]);
  local_84 = local_6c;
  iVar5 = 0;
  iVar3 = 0;
  do {
    local_84 = local_84 + 3;
    FUN_004195e0(param_1,iVar5 + 1,local_84);
    FUN_0041a080(local_84,local_6c[0]);
    FUN_0041a080(local_84,uVar2);
    fVar1 = *(float *)((int)local_6c + iVar3 + 0x14);
    if ((byte)(fVar1 < _DAT_004708dc |
              (byte)((ushort)((ushort)(NAN(fVar1) || NAN(_DAT_004708dc)) << 10) >> 8)) == 1) {
      if (local_80 == -1) {
        local_80 = iVar5;
      }
      local_74 = local_74 + 1;
      iVar4 = iVar5;
    }
    iVar5 = iVar5 + 1;
    iVar3 = iVar3 + 0xc;
  } while (iVar5 < 4);
  if (local_74 == 4) {
    *param_5 = 0;
    *param_6 = *param_5;
    FUN_004198f0();
    FUN_004198f0();
    FUN_004198f0();
    return;
  }
  if (0 < local_74) {
    if ((iVar4 == 3) &&
       ((byte)(local_6c[5] < _DAT_004708dc |
              (byte)((ushort)((ushort)(NAN(local_6c[5]) || NAN(_DAT_004708dc)) << 10) >> 8)) == 1))
    {
      iVar4 = 0;
      iVar3 = 0;
      while (fVar1 = *(float *)((int)local_6c + iVar3 + 0x20),
            (byte)(fVar1 < _DAT_004708dc |
                  (byte)((ushort)((ushort)(NAN(fVar1) || NAN(_DAT_004708dc)) << 10) >> 8)) == 1) {
        iVar3 = iVar3 + 0xc;
        iVar4 = iVar4 + 1;
      }
    }
    if ((local_80 == 0) &&
       ((byte)(local_34 < _DAT_004708dc |
              (byte)((ushort)((ushort)(NAN(local_34) || NAN(_DAT_004708dc)) << 10) >> 8)) == 1)) {
      iVar3 = 0x24;
      local_80 = 3;
      while (fVar1 = *(float *)((int)local_6c + iVar3 + 8),
            (byte)(fVar1 < _DAT_004708dc |
                  (byte)((ushort)((ushort)(NAN(fVar1) || NAN(_DAT_004708dc)) << 10) >> 8)) == 1) {
        iVar3 = iVar3 + -0xc;
        local_80 = local_80 + -1;
      }
    }
    local_6c[2] = (float)(6 - local_74);
    if (iVar4 == local_80) {
      if (local_74 != 1) {
        FUN_00402800(s_nPortal_00470780,400);
      }
      iVar3 = 4;
      if (iVar4 < 4) {
        iVar5 = 0x30;
        do {
          iVar3 = iVar3 + -1;
          *(undefined4 *)((int)local_6c + iVar5 + 0xc) = *(undefined4 *)((int)local_6c + iVar5);
          *(undefined4 *)((int)local_6c + iVar5 + 0x10) = *(undefined4 *)((int)local_6c + iVar5 + 4)
          ;
          *(undefined4 *)((int)local_6c + iVar5 + 0x14) = *(undefined4 *)((int)local_6c + iVar5 + 8)
          ;
          iVar5 = iVar5 + -0xc;
        } while (iVar4 < iVar3);
      }
      local_70 = 5;
      iVar4 = iVar4 + 1;
    }
    iVar3 = local_80 + -1;
    if (iVar3 < 0) {
      iVar3 = local_70 + -1;
    }
    fVar1 = (_DAT_004708dc - local_6c[local_80 * 3 + 5]) /
            (local_6c[iVar3 * 3 + 5] - local_6c[local_80 * 3 + 5]);
    local_6c[local_80 * 3 + 3] =
         (local_6c[iVar3 * 3 + 3] - local_6c[local_80 * 3 + 3]) * fVar1 + local_6c[local_80 * 3 + 3]
    ;
    local_6c[local_80 * 3 + 4] =
         (local_6c[iVar3 * 3 + 4] - local_6c[local_80 * 3 + 4]) * fVar1 + local_6c[local_80 * 3 + 4]
    ;
    local_6c[local_80 * 3 + 5] = 0.025;
    iVar3 = (iVar4 + 1) % local_70;
    fVar1 = (_DAT_004708dc - local_6c[iVar4 * 3 + 5]) /
            (local_6c[iVar3 * 3 + 5] - local_6c[iVar4 * 3 + 5]);
    local_6c[iVar4 * 3 + 3] =
         (local_6c[iVar3 * 3 + 3] - local_6c[iVar4 * 3 + 3]) * fVar1 + local_6c[iVar4 * 3 + 3];
    local_6c[iVar4 * 3 + 4] =
         (local_6c[iVar3 * 3 + 4] - local_6c[iVar4 * 3 + 4]) * fVar1 + local_6c[iVar4 * 3 + 4];
    local_6c[iVar4 * 3 + 5] = 0.025;
    param_1 = FUN_00418f90();
    uVar2 = FUN_00419950();
    FUN_00419860(local_6c[0],uVar2);
    do {
      FUN_0041a080(local_6c + iVar4 * 3 + 3,local_6c[1]);
      FUN_0041a080(local_6c + iVar4 * 3 + 3,uVar2);
      FUN_00418e70(param_1,local_6c[iVar4 * 3 + 3],local_6c[iVar4 * 3 + 4],local_6c[iVar4 * 3 + 5]);
      iVar4 = (iVar4 + 1) % local_70;
    } while (iVar4 != local_80);
    FUN_0041a080(local_6c + iVar4 * 3 + 3,local_6c[1]);
    FUN_0041a080(local_6c + iVar4 * 3 + 3,uVar2);
    FUN_00418e70(param_1,local_6c[iVar4 * 3 + 3],local_6c[iVar4 * 3 + 4],local_6c[iVar4 * 3 + 5]);
    FUN_004198f0();
    local_24 = DAT_004708c8;
    uStack_20 = DAT_004708cc;
    uStack_1c = DAT_004708d0;
    uStack_18 = DAT_004708d4;
    uStack_14 = DAT_004708d8;
    FUN_00418e30(param_1,local_6c[2],&local_24);
    FUN_00418bc0(param_1,local_6c[0]);
  }
  FUN_00419670(param_1,param_2,param_3,param_4,param_5,param_6);
  if (0 < local_74) {
    FUN_004190d0(param_1);
  }
  FUN_004198f0();
  FUN_004198f0();
  FUN_004198f0();
  return;
}


